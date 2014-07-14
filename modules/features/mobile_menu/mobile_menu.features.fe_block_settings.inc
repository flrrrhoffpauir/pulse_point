<?php
/**
 * @file
 * mobile_menu.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function mobile_menu_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['menu_block-6'] = array(
    'cache' => -1,
    'css_class' => 'menu-vertical menuSkin-mobile show-for-small cleared',
    'custom' => 0,
    'delta' => 6,
    'module' => 'menu_block',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pps' => array(
        'region' => 'header',
        'status' => 1,
        'theme' => 'pps',
        'weight' => -35,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
