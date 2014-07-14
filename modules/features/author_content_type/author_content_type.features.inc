<?php
/**
 * @file
 * author_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function author_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
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
function author_content_type_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function author_content_type_image_default_styles() {
  $styles = array();

  // Exported image style: author_image.
  $styles['author_image'] = array(
    'name' => 'author_image',
    'label' => 'Author Image',
    'effects' => array(),
  );

  // Exported image style: author_thumbnail.
  $styles['author_thumbnail'] = array(
    'name' => 'author_thumbnail',
    'label' => 'Author Thumbnail',
    'effects' => array(
      8 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => 440,
          'height' => 248,
          'upscale' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
