<?php

function pps_migrations_migrate_api() {
	$api = array(
		'api' => 2,
		'migrations' => array(
			'PPSUser' => array('class_name' => 'PPSUserMigration'),
			'PPSPost' => array('class_name' => 'PPSPostMigration'),
		)
	);

	return $api;
}