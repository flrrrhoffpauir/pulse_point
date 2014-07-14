<?php
/**
 * @file
 * menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:node/4
  $menu_links['main-menu:node/4'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/4',
    'router_path' => 'node/%',
    'link_title' => 'Organizational Design & Change Management',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu_icon',
          1 => 'menu-485',
        ),
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 1,
        'path' => 'public://menu_icons/menu_icon_485.png',
        'path_hover' => 'public://menu_icons/menu_icon_hover_485.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'node/4',
  );
  // Exported menu link: main-menu:node/5
  $menu_links['main-menu:node/5'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/5',
    'router_path' => 'node/%',
    'link_title' => 'Brand & Reputation Management',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu_icon',
          1 => 'menu-484',
        ),
      ),
      'menu_icon' => array(
        'enable' => 1,
        'path' => 'public://menu_icons/menu_icon_484.png',
        'path_hover' => 'public://menu_icons/menu_icon_hover_484.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/4',
  );
  // Exported menu link: main-menu:node/574
  $menu_links['main-menu:node/574'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/574',
    'router_path' => 'node/%',
    'link_title' => 'Careers',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'node/575',
  );
  // Exported menu link: main-menu:node/575
  $menu_links['main-menu:node/575'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/575',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -50,
  );
  // Exported menu link: main-menu:node/576
  $menu_links['main-menu:node/576'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/576',
    'router_path' => 'node/%',
    'link_title' => 'Our People',
    'options' => array(
      'alter' => FALSE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'parent_path' => 'node/575',
  );
  // Exported menu link: main-menu:node/577
  $menu_links['main-menu:node/577'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/577',
    'router_path' => 'node/%',
    'link_title' => 'Clients',
    'options' => array(),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
  );
  // Exported menu link: main-menu:node/6
  $menu_links['main-menu:node/6'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'node/6',
    'router_path' => 'node/%',
    'link_title' => 'Digital & Marketing Transformation',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'menu_icon',
          1 => 'menu-483',
        ),
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 1,
        'path' => 'public://menu_icons/menu_icon_483.png',
        'path_hover' => 'public://menu_icons/menu_icon_hover_483.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'parent_path' => 'node/4',
  );
  // Exported menu link: main-menu:points-of-view/blog
  $menu_links['main-menu:points-of-view/blog'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'points-of-view/blog',
    'router_path' => 'points-of-view/blog',
    'link_title' => 'Blog',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'parent_path' => 'points-of-view/blog',
  );
  // Exported menu link: menu-about-menu:menu-position/1
  $menu_links['menu-about-menu:menu-position/1'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => 'menu-position/1',
    'router_path' => 'menu-position/%',
    'link_title' => 'Our People (menu position rule)',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'menu-position-link',
        ),
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'path_hover' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu_position',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/576',
  );
  // Exported menu link: menu-about-menu:node/574
  $menu_links['menu-about-menu:node/574'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => 'node/574',
    'router_path' => 'node/%',
    'link_title' => 'Careers',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'path_hover' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
  );
  // Exported menu link: menu-about-menu:node/575
  $menu_links['menu-about-menu:node/575'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => 'node/575',
    'router_path' => 'node/%',
    'link_title' => 'Who We Are',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'path_hover' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: menu-about-menu:node/576
  $menu_links['menu-about-menu:node/576'] = array(
    'menu_name' => 'menu-about-menu',
    'link_path' => 'node/576',
    'router_path' => 'node/%',
    'link_title' => 'Our People',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'path_hover' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
  );
  // Exported menu link: menu-points-of-view-menu:points-of-view/blog
  $menu_links['menu-points-of-view-menu:points-of-view/blog'] = array(
    'menu_name' => 'menu-points-of-view-menu',
    'link_path' => 'points-of-view/blog',
    'router_path' => 'points-of-view/blog',
    'link_title' => 'Blog',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'menu_icon' => array(
        'enable' => 0,
        'path' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'path_hover' => 'sites/all/modules/contrib/menu_icons/images/default_icon.png',
        'image_style' => 'menu_icon',
        'image_style_hover' => 'menu_icon',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
  );
  // Exported menu link: navigation:filter/tips
  $menu_links['navigation:filter/tips'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'filter/tips',
    'router_path' => 'filter/tips',
    'link_title' => 'Compose tips',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:node/add
  $menu_links['navigation:node/add'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add',
    'router_path' => 'node/add',
    'link_title' => 'Add content',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
  );
  // Exported menu link: navigation:node/add/basic-page
  $menu_links['navigation:node/add/basic-page'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/basic-page',
    'router_path' => 'node/add/basic-page',
    'link_title' => 'Basic Page',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/blog
  $menu_links['navigation:node/add/blog'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/blog',
    'router_path' => 'node/add/blog',
    'link_title' => 'Blog',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/carousel-slide
  $menu_links['navigation:node/add/carousel-slide'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/carousel-slide',
    'router_path' => 'node/add/carousel-slide',
    'link_title' => 'Carousel Slide',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/client
  $menu_links['navigation:node/add/client'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/client',
    'router_path' => 'node/add/client',
    'link_title' => 'Client',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/location
  $menu_links['navigation:node/add/location'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/location',
    'router_path' => 'node/add/location',
    'link_title' => 'Location',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/service
  $menu_links['navigation:node/add/service'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/service',
    'router_path' => 'node/add/service',
    'link_title' => 'Service',
    'options' => array(),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:node/add/webform
  $menu_links['navigation:node/add/webform'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'node/add/webform',
    'router_path' => 'node/add/webform',
    'link_title' => 'Webform',
    'options' => array(
      'attributes' => array(
        'title' => 'Create a new form or questionnaire accessible to users. Submission results and statistics are recorded and accessible to privileged users.',
      ),
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'parent_path' => 'node/add',
  );
  // Exported menu link: navigation:search
  $menu_links['navigation:search'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'search',
    'router_path' => 'search',
    'link_title' => 'Search',
    'options' => array(),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About');
  t('Add content');
  t('Basic Page');
  t('Blog');
  t('Brand & Reputation Management');
  t('Careers');
  t('Carousel Slide');
  t('Client');
  t('Clients');
  t('Compose tips');
  t('Digital & Marketing Transformation');
  t('Location');
  t('Organizational Design & Change Management');
  t('Our People');
  t('Our People (menu position rule)');
  t('Search');
  t('Service');
  t('Webform');
  t('Who We Are');


  return $menu_links;
}
