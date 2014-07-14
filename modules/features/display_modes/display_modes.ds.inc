<?php
/**
 * @file
 * display_modes.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function display_modes_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'home_page_teaser';
  $ds_view_mode->label = 'Home Page Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $export['home_page_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'sidebar_teaser';
  $ds_view_mode->label = 'Sidebar Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
    'user' => 'user',
  );
  $export['sidebar_teaser'] = $ds_view_mode;

  return $export;
}
