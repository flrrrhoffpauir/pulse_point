<?php
/**
 * @file
 * accelerator_resources_block.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function accelerator_resources_block_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Accelerator Resources';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'accelerator_resources';
  $fe_block_boxes->body = '<div class="row"><div class="large-3 small-6 columns"><div class="t-sma__resource"><div><a href="/sites/default/files/SEE_Paper_4_27.pdf"><img src="/sites/all/themes/custom/pps/images/Executive-Summary.png" /></a></div><div><a href="/sites/default/files/SEE_Paper_4_27.pdf">Socially Engaged Enterprise Executive Summary</a></div></div></div><div class="large-3 small-6 columns"><div class="t-sma__resource"><div><a href="/sites/default/files/PRESS%20RELEASE%20FOR%20WEBSITE.pdf"><img src="/sites/all/themes/custom/pps/images/Press-Release.png" /></a></div><div><a href="/sites/default/files/PRESS%20RELEASE%20FOR%20WEBSITE.pdf">Socially Engaged Enterprise Press Release</a></div></div></div><div class="large-3 small-6 columns"><div class="t-sma__resource"><div><a href="/sites/default/files/AP-Presentation-4_27_12.pdf"><img src="/sites/all/themes/custom/pps/images/Presentation.png" /></a></div><div><a href="/sites/default/files/AP-Presentation-4_27_12.pdf">Socially Engaged Enterprise Presentation</a></div></div></div><div class="large-3 small-6 columns"><div class="t-sma__resource"><div><a href="/sites/default/files/socially_engaged_enterprise_paper-3_2_12.pdf"><img src="/sites/all/themes/custom/pps/images/WhitePaper.png" /></a></div><div><a href="/sites/default/files/socially_engaged_enterprise_paper-3_2_12.pdf">Socially Engaged Enterprise Whitepaper</a></div></div></div></div><p>&nbsp;</p>';

  $export['accelerator_resources'] = $fe_block_boxes;

  return $export;
}
