<?php
/**
 * @file
 * accelerator_resources_block.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function accelerator_resources_block_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-accelerator_resources'] = array(
    'cache' => -1,
    'css_class' => 'block-resources',
    'custom' => 0,
    'machine_name' => 'accelerator_resources',
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
        'weight' => -28,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Whitepapers & Other Resources:',
    'visibility' => 1,
  );

  return $export;
}
