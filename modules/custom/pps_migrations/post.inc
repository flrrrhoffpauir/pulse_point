<?php

class PPSPostMigration extends XMLMigration {
	public function __construct() {
		parent::__construct();
		$this->description = t('Migration of posts');
		$this->dependencies = array('PPSUser');

		$fields = array(
			'title' => t('Title'),
			'creator' => t('Wordpress username of creator'),
			'content' => t('Post Content'),
			'summary' => t('Summary of Content'),
			'post_id' => t('WP Post ID'),
			'post_date_gmt' => t('Posting date/time GMT'),
			'status' => t('Publish status'),
			'post_type' => t('WP Post Type'),
			'tags' => t('Categories from WP'),
		);

		$this->map = new MigrateSQLMap(
			$this->machineName,
			array(
				'post_id' => array(
					'type' => 'varchar',
					'length' => 255,
					'not null' => TRUE
				)
			),
			MigrateDestinationNode::getKeySchema()
		);

		$xml_folder = $_SERVER['DOCUMENT_ROOT'] .'/sites/default/files/';
		$data_url = $xml_folder .'content.xml';
		$item_xpath = '//item[wp:post_type=\'post\']'; // only get posts
		$item_id_xpath = 'wp:post_id';
		$items_class = new MigrateItemsXML($data_url, $item_xpath, $item_id_xpath);

		$this->source = new MigrateSourceMultiItems($items_class, $fields);
		$this->destination = new MigrateDestinationNode('blog');

		$this->addFieldMapping('title', 'title')
			->xpath('title');
		$this->addFieldMapping('uid', 'creator')
			->xpath('dc:creator')
			->sourceMigration('PPSUser');
		$this->addFieldMapping('created', 'post_date')
			->xpath('wp:post_date');
		$this->addFieldMapping('status', 'status');
		$this->addFieldMapping('promote')->defaultValue(0);
		$this->addFieldMapping('sticky')->defaultValue(0);
		$this->addFieldMapping('field_body', 'content');
		$this->addFieldMapping('field_body:format')->defaultValue('full_html'); // needed for caption styles
		$this->addFieldMapping('field_body:language')->defaultValue('und');
		$this->addFieldMapping('field_summary', 'summary');
		$this->addFieldMapping('field_summary:format')->defaultValue('filtered_html');
		$this->addFieldMapping('field_summary:language')->defaultValue('und');
		$this->addFieldMapping('field_tag', 'tags');
		$this->addFieldMapping('field_tag:source_type');
		$this->addFieldMapping('field_tag:create_term')->defaultValue(TRUE);
		$this->addFieldMapping('field_tag:ignore_case')->defaultValue(TRUE);
		$this->addFieldMapping('field_pulse_point')->defaultValue(0);
		$this->addFieldMapping('field_accelerator')->defaultValue(0);

		$this->addUnmigratedDestinations(array(
			'revision', 'log', 'language', 'tnid',
			'translate', 'revision_uid', 'is_new',
			'changed',

			'field_thumbnail', 'field_thumbnail:file_class', 'field_thumbnail:language',
			'field_thumbnail:destination_dir', 'field_thumbnail:destination_file',
			'field_thumbnail:file_replace', 'field_thumbnail:preserve_files',
			'field_thumbnail:source_dir', 'field_thumbnail:alt',
			'field_thumbnail:title',

			'field_author', // replaced by UID

			'path', 'metatag_title', 'metatag_description',
			'metatag_abstract', 'metatag_keywords', 'metatag_robots',
			'metatag_news_keywords', 'metatag_generator',
			'metatag_copyright', 'metatag_image_src', 'metatag_canonical',
			'metatag_shortlink',  'metatag_publisher', 'metatag_author',
			'metatag_original-source', 'metatag_fb:admins',
			'metatag_fb:app_id', 'metatag_og:site_name', 'metatag_og:title',
			'metatag_og:description', 'metatag_og:type', 'metatag_og:image',
			'metatag_og:url', 'metatag_og:latitude', 'metatag_og:longitude',
			'metatag_og:street-address', 'metatag_og:locality',
			'metatag_og:region', 'metatag_og:postal-code', 'metatag_og:country-name',
			'metatag_og:email', 'metatag_og:phone_number', 'metatag_og:fax_number',
			'metatag_og:video', 'metatag_og:video:secure_url', 'metatag_og:video:width',
			'metatag_og:video:height', 'metatag_og:video:type', 'comment', 'pathauto',
		));
		$this->addUnmigratedSources(array(

		));
	}

	function prepareRow($row) {
		// Status
		$row->status = (string)current($row->xml->xpath('wp:status'));
		if ($row->status == 'publish') {
			$row->status = 1;
		} else if ($row->status == 'trash') {
			return FALSE; // cancel importing
		} else {
			$row->status = 0; // unpublished
		}

		// Content/SUmmary
		$row->summary = "";
		$row->content = (string)current($row->xml->xpath('content:encoded'));
		$row->content = $this->_rewrite_images($row->content);
		$row->content = $this->_replaceCaptions($row->content);

		$split_content = explode('<!--more-->', $row->content);
		if (!$row->summary && count($split_content) == 2) {
			$row->summary = $split_content[0];
			$row->content = $split_content[1];
		}

		// Tags
		$row->tags = array();
		foreach($row->xml->xpath('category') as $category) {
			$row->tags[] = (string)$category;
		}
		if (count($row->tags)) {
			$row->tags[] = 'uncategorized';
		}
	}


	function _rewrite_images($content) {
		$patterns = array(
			'/<img(.*?)src="(http:\/\/www.pulsepointgroup.com\/)(.*?)"/i',
			'/<img(.*?)src="(http:\/\/pulsepointgroup-stage.murphyandco.com\/)(.*?)"/i',
		);

		$results = $content;
		foreach($patterns as $pattern) {
			$results = preg_replace_callback($pattern, "self::_processImageMatch", $results);
		}

		return $results;
	}

	function _processImageMatch($match) {
		$root_path = $_SERVER['DOCUMENT_ROOT'];
		$files_path = '/sites/default/files/old_images/';

		$save_path = $root_path . $files_path . $match[3];
		$old_image_src = $match[2] . $match[3];
		$new_image_src = $files_path . $match[3];

		// $this->queueMessage("$old_image_src => $new_image_src<br/>", MigrationBase::MESSAGE_INFORMATIONAL);

		// download $2$3 to $destination
		$this->_make_subdirs($save_path);
		if (!file_exists($save_path)) {
			file_put_contents($save_path, file_get_contents($old_image_src));
		}
		return '<img'. $match[1] .'src="'. $new_image_src .'"';
	}

	function _make_subdirs($string, $has_file = TRUE) {
		$folders = explode('/', $string);
		$location = '';
		if ($has_file) {
			array_pop($folders);
		}

		foreach($folders as $folder) {
			$location .= '/'. $folder;
			if (!is_dir($location)) {
				mkdir($location);
			}
		}
	}

	function _replaceCaptions($content) {
		return preg_replace_callback('|(\[caption.*?\])(.*?)(\[/caption\])|i', 'self::_processCaptionMatch',
			$content);
	}

	protected function _processCaptionMatch(array $matches) {
		$caption_open = $matches[1];
		$content = $matches[2];
		$caption_close = $matches[3];

		preg_match('|width="(.*?)"|i', $caption_open, $matches);
		$width = (int)$matches[1] + 10;
		$style = "width: {$width}px;";

		preg_match('|align="(.*?)"|i', $caption_open, $matches);
		$align = $matches[1];
		switch ($align) {
			case 'aligncenter':
				$style .= "display:block;margin:0 auto;";
			break;
			case 'alignleft':
				$style .= "float:left;";
				break;
			case 'alignright':
				$style .= "float:right;";
				break;
			default:
				break;
		}

		preg_match('|caption="(.*?)"|i', $caption_open, $matches);
		$caption = $matches[1];

		$result = '<div style="' . $style . '">';
		$result .= $content;
		$result .= "<p>$caption</p></div>";

		return $result;
	}

}
