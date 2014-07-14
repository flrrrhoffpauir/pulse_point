(function($) {

	Drupal.behaviors.pps_mods_share = {};
	Drupal.behaviors.pps_mods_share.attach = function(context, settings) {
		if (!$.browser.msie) return; // only need to fix iframe for IE

		$('.ppsShare', context).live('mouseenter', function() {
			$(this).addClass('hover');
		});
		$('.ppsShare iframe', context).live('mouseenter', function() {
			$(this).parents('.ppsShare').addClass('hover');
		});
		$('.ppsShare').live('mouseleave', function() {
			$(this).removeClass('hover');
		});
	}

})(jQuery);