<?php
/**
 * @file
 * accelerator_videos_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function accelerator_videos_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-accelerator_videos'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'machine_name' => 'accelerator_videos',
    'module' => 'block',
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
        'weight' => -29,
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
