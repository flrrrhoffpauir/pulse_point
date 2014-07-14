Pulse Point
================

Automated Deployment 
---
* __Dev Server__
  * Make sure your changes are committed and pushed to dev branch.
  * Change to repo root directory and run ```fab dev_deploy```
* __Production Server__
  * Make sure your changes are committed and pushed to master branch.
  * TBD

Backing Up Remote Server Databases 
---
* __Dev Server__
  * Databases are zipped into /var/www/databases
  * Change to repo root directory and run ```fab dev_backup```

* __Production Server__
  * TBD

Syncing Local Database to Remote Server Database
---
__Warning:__ You may want to back up your local database before running this command.
* __Dev Server__
  * Change to repo root directory and run ```fab sync_local_db_to_dev_db```

* __Production Server__
  * TBD

Automated Tests 
---
Tests use Behat framework. http://behat.org/    
Installation:    
* Change directory into 'tests'
* Rename behat.default.yml to behat.yml and change the base_url to your local dev environment
* Run these commands
  * ```curl http://getcomposer.org/installer | php```
  * ```php composer.phar install```
  * ```bin/behat --init```

Running Tests:    
Tests have to be run from the 'tests' directory
* __Local__
  * Run all tests: ```bin/behat```
  * Run a test by name: ```bin/behat --name <name of test>```
* __Dev Server__
  * TBD
* __Production Server__
  * TBD

Rollback
---
* Dev Server
  * TBD
* Production Server
  * TBD