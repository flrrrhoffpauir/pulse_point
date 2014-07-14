<div class="<?php print $classes; ?> clearfix"><div>
	<?php if ($logo): ?>
	<div id="block-logo-block-logo" class="">
		<a href="/" title="<?php print t('Home') ?>">
			<img src="<?php print $logo ?>" alt="<?php print t('Home') ?>" />
		</a>
	</div>
	<?php endif; ?>

		<div class="regionToggle-toggle">
			<label for="regionHeader-blocks">
				<img src="/<?php print path_to_theme(); ?>/images/mobile-nav-toggle.png" />
			</label>
		</div>

		<!-- onclick for < ios6 -->
		<input type="checkbox" id="regionHeader-blocks" class="regionToggle-checkbox" onclick />
		<div class="regionToggle-container smallOnly">
	    	<?php print $content; ?>
		</div>
</div></div><!-- /.region -->