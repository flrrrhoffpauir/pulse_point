<?php
/**
 * @file
 * my_blog_posts.features.inc
 */

/**
 * Implements hook_views_api().
 */
function my_blog_posts_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
