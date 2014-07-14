<div class="ds-mediablock <?php print $classes ?> clearfix">

	<?php if (isset($title_suffix['contextual_links'])): ?>
	<?php print render($title_suffix['contextual_links']); ?>
	<?php endif; ?>

	<?php if ($header): ?>
	<div class="ds-mediablock-header">
		<?php print $header ?>
	</div>
	<?php endif; ?>

	<div class="ds-mediablock-body">
		<?php if ($media || $media_caption): ?>
			<div class="ds-mediablock-mediaContainer">
				<?php if ($media): ?>
				<div class="ds-mediablock-media">
					<?php print $media; ?>
				</div>
				<?php endif; ?>

				<?php if ($media_caption): ?>
				<div class="ds-mediablock-mediaCaption">
					<?php print $media_caption; ?>
				</div>
				<?php endif; ?>
			</div>
		<?php endif; ?>

		<div class="ds-mediablock-contentContainer">
			<?php if ($content_header): ?>
			<div class="ds-mediablock-contentHeader">
				<?php print $content_header ?>
			</div>
			<?php endif; ?>

			<?php if ($content_body): ?>
			<div class="ds-mediablock-contentBody">
				<?php print $content_body ?>
			</div>
			<?php endif; ?>

			<?php if ($content_footer): ?>
			<div class="ds-mediablock-contentFooter">
				<?php print $content_footer ?>
			</div>
			<?php endif; ?>
		</div>
	</div>

	<?php if ($footer): ?>
	<div class="ds-mediablock-footer">
		<?php print $footer; ?>
	</div>
	<?php endif; ?>

</div>

<?php if (!empty($drupal_render_children)): ?>
	<?php print $drupal_render_children ?>
<?php endif; ?>