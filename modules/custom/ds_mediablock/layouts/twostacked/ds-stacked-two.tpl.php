<div class="t-people__person">

	<?php if (isset($title_suffix['contextual_links'])): ?>
	<?php print render($title_suffix['contextual_links']); ?>
	<?php endif; ?>

	<?php if ($top): ?>
		<?php print $top ?>
	<?php endif; ?>

	<?php if ($bottom): ?>
	<div class="details">
		<?php print $bottom; ?>
	</div>
	<?php endif; ?>

</div>

<?php if (!empty($drupal_render_children)): ?>
	<?php print $drupal_render_children ?>
<?php endif; ?>