<?php
/**
 * @file
 * default_metatags.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function default_metatags_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: global.
  $config['global'] = array(
    'instance' => 'global',
    'config' => array(
      'title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'description' => array(
        'value' => 'PulsePoint Group is a management and digital consulting firm that provides insight, strategy development and strategic execution for communications and marketing management challenges, with a special focus on social and digital engagement.',
      ),
      'abstract' => array(
        'value' => '',
      ),
      'keywords' => array(
        'value' => '',
      ),
      'robots' => array(
        'value' => array(
          'index' => 0,
          'follow' => 0,
          'noindex' => 0,
          'nofollow' => 0,
          'noarchive' => 0,
          'nosnippet' => 0,
          'noodp' => 0,
          'noydir' => 0,
        ),
      ),
      'news_keywords' => array(
        'value' => '',
      ),
      'generator' => array(
        'value' => '',
      ),
      'copyright' => array(
        'value' => '',
      ),
      'image_src' => array(
        'value' => '',
      ),
      'canonical' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'shortlink' => array(
        'value' => '[current-page:url:unaliased]',
      ),
      'publisher' => array(
        'value' => '',
      ),
      'author' => array(
        'value' => '',
      ),
      'original-source' => array(
        'value' => '',
      ),
      'fb:admins' => array(
        'value' => '',
      ),
      'fb:app_id' => array(
        'value' => '',
      ),
      'og:site_name' => array(
        'value' => '[site:name]',
      ),
      'og:title' => array(
        'value' => '[current-page:title] | [site:name]',
      ),
      'og:description' => array(
        'value' => 'PulsePoint Group is a management and digital consulting firm that provides insight, strategy development and strategic execution for communications and marketing management challenges, with a special focus on social and digital engagement.',
      ),
      'og:type' => array(
        'value' => 'website',
      ),
      'og:image' => array(
        'value' => 'http://www.pulsepointgroup.com/sites/default/files/logo/PP-logo-social.png',
      ),
      'og:url' => array(
        'value' => '[current-page:url:absolute]',
      ),
      'og:latitude' => array(
        'value' => '',
      ),
      'og:longitude' => array(
        'value' => '',
      ),
      'og:street-address' => array(
        'value' => '',
      ),
      'og:locality' => array(
        'value' => '',
      ),
      'og:region' => array(
        'value' => '',
      ),
      'og:postal-code' => array(
        'value' => '',
      ),
      'og:country-name' => array(
        'value' => '',
      ),
      'og:email' => array(
        'value' => '',
      ),
      'og:phone_number' => array(
        'value' => '',
      ),
      'og:fax_number' => array(
        'value' => '',
      ),
      'og:video' => array(
        'value' => '',
      ),
      'og:video:secure_url' => array(
        'value' => '',
      ),
      'og:video:width' => array(
        'value' => '',
      ),
      'og:video:height' => array(
        'value' => '',
      ),
      'og:video:type' => array(
        'value' => '',
      ),
    ),
  );

  // Exported Metatag config instance: node.
  $config['node'] = array(
    'instance' => 'node',
    'config' => array(
      'title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'description' => array(
        'value' => '[node:field_summary]',
      ),
      'og:title' => array(
        'value' => '[node:title] | [site:name]',
      ),
      'og:description' => array(
        'value' => '[node:field_summary]',
      ),
    ),
  );

  // Exported Metatag config instance: user.
  $config['user'] = array(
    'instance' => 'user',
    'config' => array(
      'title' => array(
        'value' => '[user:field_first_name] [user:field_last_name] | [site:name]',
      ),
      'description' => array(
        'value' => '[user:field_summary]',
      ),
      'og:title' => array(
        'value' => '[user:name] | [site:name]',
      ),
      'og:description' => array(
        'value' => '[user:field_summary]',
      ),
      'og:type' => array(
        'value' => 'profile',
      ),
      'og:image' => array(
        'value' => '[user:field_thumbnail]',
      ),
    ),
  );

  return $config;
}
