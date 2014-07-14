<?php

class PPSUserMigration extends XMLMigration {
	public function __construct() {
		parent::__construct();
		$this->description = t('Migration of users');

		$fields = array(
			'author_id' => t('WP Author ID'),
			'author_login' => t('WP Author Username'),
			'author_email' => t('WP Author Email'),
			'author_display_name' => t('WP Author Name'),
			'author_first_name' => t('WP Author First Name'),
			'author_last_name' => t('WP Author Last Name'),
		);

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'author_login' => array(
					'type' => 'varchar',
					'length' => 255,
					'not null' => TRUE
				)
			),
			MigrateDestinationUser::getKeySchema()
		);

		$xml_folder = $_SERVER['DOCUMENT_ROOT'] .'/sites/default/files/';
		$data_url = $xml_folder .'content.xml';
		$item_xpath = '//wp:author';
		$item_id_xpath = 'wp:author_login';
		$items_class = new MigrateItemsXML($data_url, $item_xpath, $item_id_xpath);

		$this->source = new MigrateSourceMultiItems($items_class, $fields);
		$this->destination = new MigrateDestinationUser();

		$this->addFieldMapping('name', 'wp:author_login')
			->xpath('wp:author_login')
			->dedupe('users', 'name');
		$this->addFieldMapping('mail', 'wp:author_email')
			->xpath('wp:author_email');
		$this->addFieldMapping('roles')
			->defaultValue(DRUPAL_AUTHENTICATED_RID);
		$this->addFieldMapping('status')
			->defaultValue(1);

		$this->addUnmigratedDestinations(array(
			'pass', 'theme', 'signature', 'signature_format',
			'created', 'access', 'login', 'timezone', 'language',
			'picture', 'init', 'is_new'
		));

		$this->addUnmigratedSources(array(
			'wp:author_display_name', 'wp:author_first_name',
			'wp:author_last_name', 'wp:author_id'
		));
	}
}