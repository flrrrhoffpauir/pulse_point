<?php
/**
 * @file
 * clients.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function clients_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-clients-block_1'] = array(
    'cache' => -1,
    'css_class' => 'small-12 columns',
    'custom' => 0,
    'delta' => 'clients-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'clients',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pps' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'pps',
        'weight' => -36,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 1,
  );

  return $export;
}
