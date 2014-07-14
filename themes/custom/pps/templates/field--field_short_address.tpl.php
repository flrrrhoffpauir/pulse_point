<?php

/**
 * @file field.tpl.php
 * Default template implementation to display the value of a field.
 *
 * This file is not used and is here as a starting point for customization only.
 * @see theme_field()
 *
 * Available variables:
 * - $items: An array of field values. Use render() to output them.
 * - $label: The item label.
 * - $label_hidden: Whether the label display is set to 'hidden'.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - field: The current template type, i.e., "theming hook".
 *   - field-name-[field_name]: The current field name. For example, if the
 *     field name is "field_description" it would result in
 *     "field-name-field-description".
 *   - field-type-[field_type]: The current field type. For example, if the
 *     field type is "text" it would result in "field-type-text".
 *   - field-label-[label_display]: The current label position. For example, if
 *     the label position is "above" it would result in "field-label-above".
 *
 * Other variables:
 * - $element['#object']: The entity to which the field is attached.
 * - $element['#view_mode']: View mode, e.g. 'full', 'teaser'...
 * - $element['#field_name']: The field name.
 * - $element['#field_type']: The field type.
 * - $element['#field_language']: The field language.
 * - $element['#field_translatable']: Whether the field is translatable or not.
 * - $element['#label_display']: Position of label display, inline, above, or
 *   hidden.
 * - $field_name_css: The css-compatible field name.
 * - $field_type_css: The css-compatible field type.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess_field()
 * @see theme_field()
 *
 * @ingroup themeable
 */
?>

<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>:&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
      	<?php // PHP in the template, in know, in know
		$img_url = "http://maps.googleapis.com/maps/api/staticmap?";
		$link_url = "https://www.google.com/maps/preview?hl=en&q=";
		$iframe_url = "https://www.google.com/maps?z=11&amp;f=d&amp;output=embed&amp;iwloc=near&amp;q=";

		$escaped_address = $item['#markup'];
		$width = 520;
		$height = 300;

		$img_params = array();
		$img_params['center'] = $escaped_address;
		$img_params['zoom'] = 15;
		$img_params['size'] = $width .'x'. $height;
		$img_params['maptype'] = "roadmap";
		$img_params['markers'] =
			"icon:http://www.pulsepointgroup.com/sites/all/themes/custom/pps/images/location-marker.png" ."|".
			"shadow:false" ."|".
			$escaped_address;
		$img_params['sensor'] = 'false';

		$image_src = $img_url . http_build_query($img_params);
		$link_href = $link_url . $escaped_address;
		$iframe_src = $iframe_url . $escaped_address;
		?>

		<div class="show-for-small">
			<a href="<?php print $link_href ?>" target="_blank">
				<img src="<?php print $image_src ?>" width="<?php print $width ?>" height="<?php print $height ?>" />
			</a>
		</div>
		<div class="hide-for-small">
			<iframe
				name="mapframe"
				frameborder="0"
				width="600"
				height="350"
				src="<?php print $iframe_src ?>">
			</iframe>
		</div>
      </div>
    <?php endforeach; ?>
  </div>
</div>

