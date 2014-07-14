<?php
/**
 * @file
 * blog_index_view.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function blog_index_view_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['tagclouds-3'] = array(
    'cache' => 8,
    'css_class' => 'accordion-block',
    'custom' => 0,
    'delta' => 3,
    'module' => 'tagclouds',
    'node_types' => array(),
    'pages' => 'points-of-view/blog
points-of-view/blog/*
tag
tag/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pps' => array(
        'region' => 'sidebar',
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
    'title' => 'Tags',
    'visibility' => 1,
  );

  $export['views-archive_block-block'] = array(
    'cache' => -1,
    'css_class' => 'block-bordered t-blog__block-links accordion-block',
    'custom' => 0,
    'delta' => 'archive_block-block',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'points-of-view/blog
points-of-view/blog/*',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'pps' => array(
        'region' => 'sidebar',
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
    'title' => 'Archives',
    'visibility' => 1,
  );

  return $export;
}
