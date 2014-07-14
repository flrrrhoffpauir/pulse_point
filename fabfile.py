import ntpath
import os
from fabric.api import env, sudo, run, local, settings
from fabric.context_managers import cd
from fabric.operations import prompt
from fabric.decorators import roles
from datetime import datetime
from time import strftime


env.roledefs = {
    'dev' : ['dev@pp.smithandrobot.com'],
    'prod' : ['ec2-user@107.21.244.177'],
}

## checking
env.key_filename = os.path.join(os.getenv("HOME"), '.ssh', 'pulsepoint.pem')

'''
******* Production Server Automation ********
'''
@roles('prod')
def cc_prod():
    with cd('/var/www/current/'):
        run('drush cc all')

@roles('prod')
def prod_deploy():
    with cd('/var/www/current/sites/all'):
        run('git pull origin master')
        run('drush cc all')
        run('drush fra -y')

@roles('prod')
def sync_prod_files_with_dev():
    with cd('/var/www/current/sites/all'):
        run('drush -y rsync @pp-dev:%files/ @self:%files --mode=rz')

@roles('prod')
def sync_prod_db_with_dev():
    with cd('/var/www/current/sites/all'):
        run('drush sql-sync @pp-dev @self --create-db --temp -y')

@roles('prod')
def backup_prod():
    cc_prod()
    date_str = run('(date +%Y-%m-%d-%H.%M.%S)');
    run('mysqldump -u root -pDishy012 pulsepoint_production | gzip > /var/www/databases/pp-{0}.sql.zip'.format(date_str))

@roles('prod')
def prod_sync():
    prod_deploy()
    backup_prod()
    sync_prod_db_with_dev()
    sync_prod_files_with_dev()
    cc_prod()
    set_caching()

@roles('prod')
def set_caching():
    with cd('/var/www/current/sites/all'):
        run('drush vset cache 1')
        # run('drush vset block_cache 1')
        run('drush vset cache_lifetime \'86400\'')
        run('drush vset page_cache_maximum_age \'86400\'')
        run('drush vset page_compression 1')
        run('drush vset preprocess_css 1')
        run('drush vset preprocess_js 1')
        run('drush vset disqus_developer 0')
        run('drush en googleanalytics -y')
        run('drush vset googleanalytics_account \'UA-29604878-1\'')
        run('drush vset webform_default_from_address \'tbryant@pulsepointgroup.com\'')

'''
******* Dev Server Automation ********
'''

'''
Syncs Development server's repo to dev branch.
'''
@roles('dev')
def dev_deploy():
    with cd('/var/www/current/sites/all'):
        run('git pull origin dev')
        run('drush cc all')
        run('drush fra -y')

'''
Clear Drupal cache on remote development server
'''
@roles('dev')
def cc_dev():
    with cd('/var/www/current/'):
        run('drush cc all')

'''
Backup remote development server's database
'''
@roles('dev')
def backup_dev():
    current_dir = local('pwd', True)
    cc_dev()
    date_str = run('(date +%Y-%m-%d-%H.%M.%S)');
    run('mysqldump -u root -psm1thr0b0t pulse_point | gzip > /var/www/databases/pp-dev-{0}.sql.zip'.format(date_str))

'''
This syncs your local default/files to the remote server's default/files
'''
def sync_files_dev_to_local():
    local('drush rsync @pp-dev:%files/ @self:%files --mode=rz')

'''
This syncs the remote server's files to your local default/files
'''
@roles('dev')
def sync_files_local_to_dev():
    local('drush rsync @self:%files/ @pp-dev:%files/ --mode=rz --exclude=".DS_Store" --no-o --progress --chmod=ugo=rwX')
    # Clean up permissions
    sudo('chmod -R 775 /var/www/current/sites/default/files')
    sudo('chown -R apache:apache /var/www/current/sites/default/files')

'''
This syncs your local database to the dev server database
'''
def sync_local_db_to_dev_db():
    local('drush sql-sync @pp-dev @self --create-db --temp -y')

'''
This syncs the remote dev server's database to your local database
'''
@roles('dev')
def sync_dev_db_to_local_db():
    print 'You are syncing the dev server\'s database to your local database. Backing up development server\'s database now....'
    backup_dev()
    local('drush sql-sync @self @pp-dev --create-db --temp -y')

'''
Pull contents of the dev database and files system
'''
def pull_dev():
    sync_files_dev_to_local()
    sync_local_db_to_dev_db()
    local('drush cc all')

