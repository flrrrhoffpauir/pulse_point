<?php
/**
 * @file
 * block_settings.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function block_settings_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'About Section Title';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'about_title';
  $fe_block_boxes->body = '<div class="page-title">About Us</div>';

  $export['about_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Current Page Title';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'current_page_title';
  $fe_block_boxes->body = '<h1 class="title page-title left" id="page-title"><span>[current-page:title]</span></h1>';

  $export['current_page_title'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Top Social Media';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'top_social_media_block';
  $fe_block_boxes->body = '<div class="menu-icons"><ul class="menu"><li><a href="https://www.facebook.com/PulsePointGroup" target="_blank"><img src="/sites/all/themes/custom/pps/images/icon-facebook.png" title="Facebook" /></a></li><li><a href="https://twitter.com/PulsePointGroup" target="_blank"><img src="/sites/all/themes/custom/pps/images/icon-twitter.png" title="Twitter" /></a></li><li><a href="http://www.youtube.com/user/pulsepointgroup" target="_blank"><img src="/sites/all/themes/custom/pps/images/icon-youtube.png" title="Youtube" /></a></li><li><a href="http://www.linkedin.com/company/pulsepoint-group" target="_blank"><img src="/sites/all/themes/custom/pps/images/icon-linkedin.png" title="LinkedIn" /></a></li><li><a href="/feed" target="_blank"><img src="/sites/all/themes/custom/pps/images/icon-rss.png" title="RSS Feed" /></a></li></ul></div>';

  $export['top_social_media_block'] = $fe_block_boxes;

  return $export;
}
