<?php
/**
 * @file
 * author_content_type.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function author_content_type_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_author';
  $strongarm->value = array();
  $export['menu_options_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_author';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_author';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_author'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_author';
  $strongarm->value = 0;
  $export['node_submitted_author'] = $strongarm;

  return $export;
}
