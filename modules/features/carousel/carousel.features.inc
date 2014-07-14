<?php
/**
 * @file
 * carousel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function carousel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function carousel_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function carousel_image_default_styles() {
  $styles = array();

  // Exported image style: slideshow_image.
  $styles['slideshow_image'] = array(
    'name' => 'slideshow_image',
    'label' => 'Slideshow Image',
    'effects' => array(),
  );

  // Exported image style: slideshow_thumbnail.
  $styles['slideshow_thumbnail'] = array(
    'name' => 'slideshow_thumbnail',
    'label' => 'Slideshow Thumbnail',
    'effects' => array(),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function carousel_node_info() {
  $items = array(
    'carousel_slide' => array(
      'name' => t('Carousel Slide'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}
