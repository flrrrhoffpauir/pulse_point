<?php
/**
 * @file
 * carousel.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function carousel_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-home_page_carousel-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'home_page_carousel-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pps' => array(
        'region' => 'fp_carousel',
        'status' => 1,
        'theme' => 'pps',
        'weight' => -23,
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
