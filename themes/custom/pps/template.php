<?php

function pps_preprocess_html(&$vars)
{
	$viewport = array(
		'#tag' => 'meta',
		'#attributes' => array(
		'name' => 'viewport',
		'content' => 'width=device-width, initial-scale=1, maximum-scale=1',
		)
	);

	drupal_add_html_head($viewport, 'viewport');
}

function pps_preprocess_page(&$vars, $hook)
{
	if(!empty($vars['node']))	{
		$vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type;
	}

	if ((isset($vars['node']) &&
		in_array($vars['node']->type, array('blog', 'service')))) {
		$vars['theme_hook_suggestions'][] = 'page__title_alt';
	}

	if (drupal_get_path_alias() == 'services/social-media-accelerator') {
		$vars['theme_hook_suggestions'][] = 'page__title_none';
	}
}


/**
 * Call function to preprocess content type
 * Example pps_preprocess_node_NODE_NAME()
 */
function pps_preprocess_node(&$vars, $hook)
{
	// Create
	$function = __FUNCTION__ . '_' . $vars['node']->type;
  	if (function_exists($function))
	{
    	$function($vars, $hook);
  	}

  	// add node--TYPE--MODE.tpl.php template suggestions
  	$vars['theme_hook_suggestions'][] = 'node__'. $vars['type'] .'__'. $vars['view_mode'];
}

function pps_preprocess_block(&$vars)
{
	$vars['title_attributes_array']['class'][] = 'block-title';
}

function pps_preprocess_node_carousel_slide(&$vars, $hook) {
	if (count($vars['field_style'])) {
		$vars['classes_array'][] = 'slideStyle-'. $vars['field_style']['und'][0]['value'];
	}

	if (count($vars['field_url'])) {
		if (isset($vars['field_url']['und'][0])) {
			$vars['slide_link'] = $vars['field_url']['und'][0]['url'];
		}
	}
}

/**
 * Theme main menu
 */
function pps_preprocess_region(&$vars, $hook)
{
	$vars['logo'] = theme_get_setting('logo');
	if($vars['region'] == 'header') {
		// theme main-menu links
		$vars['nav__main_top'] = theme('links', array(
		'links' => menu_main_menu(),
		'attributes' => array(),
		'heading' => array(
			'text' => t(''),
			'level' => 'h2',
			'class' => array('hide'),
			),
		));
	}
}

/**
 * Render user forms in tpl
 */
function pps_theme() {

	$items = array();

	$items['user_register_form'] = array(
		'render element' => 'form',
		'template' => 'templates/user-forms',
	);

	$items['user_login'] = array(
		'render element' => 'form',
		'template' => 'templates/user-forms',
	);

	$items['user_pass'] = array(
		'render element' => 'form',
		'template' => 'templates/user-forms',
	);

	$items['contact_personal_form'] = array(
		'render element' => 'form',
		'template' => 'templates/user-forms',
	);

	return $items;
}

function pps_youtube_video($variables) {
	$patch = "&autohide=1&modestbranding=1&showinfo=0";
	$output = theme_youtube_video($variables);
	$output = preg_replace('/<iframe(.*?)\ssrc\=\"(.*?)\"(.*?)>/is', '<iframe$1 src="$2'.$patch.'"$3>', $output);

	return $output;
}

/**
 * Add placeholder text to webforms and hide their label (still accessible)
 */
function pps_form_alter(&$form, &$form_state, $form_id) {
    if(substr($form_id, 0, 20) == 'webform_client_form_') { // All webforms
      foreach ($form["submitted"] as $key => $value) {
          if (in_array($value["#type"], array("textfield", "webform_email", "textarea"))) {
              $form["submitted"][$key]['#attributes']["placeholder"] = t($value["#title"]);
              $form["submitted"][$key]['#title_display'] = 'invisible';
          }
      }
  }
}

/**
 * implements hook_views_pre_renders
 */
function pps_views_pre_render(&$view) {
	if ($view->name == 'blog_tags') {
		// the taxonomy filter creates duplicate results, one for every term.
		// this now assumes that you have terms and we do NOT filter based on that
		// after getting results from the DB, we remove if there are no terms.
		$result = $view->result;
		if (!count($result)) return; // nothing to see here

		if (!isset($result[0]->field_field_tag) ||
			count($result[0]->field_field_tag) === 0) {
			unset($view->result[0]);
		}
	}
}

function pps_preprocess_pager_next(&$vars) {
	if($vars['text'] == 'next ›')
		$vars['text'] = 'next';
}

function pps_preprocess_pager_previous(&$vars) {
	if($vars['text'] == '‹ previous')
		$vars['text'] = 'previous';
}

// video filters
function pps_preprocess_video_filter_flash(&$variables) {
	$args = array(
		'autohide' => 1,
	    'modestbranding' => 1,
	    'showinfo' => 0,
	);
	$variables['video']['source'] .= '&amp;'. http_build_query($args, '', '&amp;');
	$variables['video']['width'] = 559;
}

function pps_preprocess_video_filter_iframe(&$variables) {
	$args = array(
		'autohide' => 1,
	    'modestbranding' => 1,
	    'showinfo' => 0,
	);
	$variables['video']['source'] .= '&amp;'. http_build_query($args, '', '&amp;');
	$variables['video']['width'] = 561;
}

