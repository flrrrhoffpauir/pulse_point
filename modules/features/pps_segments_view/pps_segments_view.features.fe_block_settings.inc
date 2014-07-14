<?php
/**
 * @file
 * pps_segments_view.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function pps_segments_view_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-tool_tips-block'] = array(
    'cache' => -1,
    'css_class' => 'show-for-small',
    'custom' => 0,
    'delta' => 'tool_tips-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'services/social-media-accelerator',
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
        'weight' => -30,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Segments:',
    'visibility' => 1,
  );

  $export['views-tool_tips-block_1'] = array(
    'cache' => -1,
    'css_class' => 'show-for-medium-up',
    'custom' => 0,
    'delta' => 'tool_tips-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'services/social-media-accelerator',
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
        'weight' => -32,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Segments:',
    'visibility' => 1,
  );

  $export['views-tool_tips_ipad-block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'tool_tips_ipad-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'services/social-media-accelerator',
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
        'weight' => -31,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Segments:',
    'visibility' => 1,
  );

  return $export;
}
