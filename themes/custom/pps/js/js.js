jQuery.noConflict();
(function($) {
    $(document).ready(function() {
        // init owl carousel
        $(".owl-carousel .view-content").owlCarousel({
            slideSpeed : 800,
            paginationSpeed : 800,
            singleItem: true,
            addClassActive: true,
            navigation: true,
            navigationText: ['', ''],


            beforeMove: false, // function () { ... }
            afterMove: false, // function() { ... }
        });

        $('.view-our-people-carousel .view-content').owlCarousel({
            items: 8,
            itemsDesktop: [1440, 6],
            itemsDesktopSmall: [1080, 4],
            itemsTablet: [768, 4],
            itemsTabletSmall: [750, 3],
            itemsMobile: [479, 2],
            stopOnHover: true,
            scrollPerPage: true,
            paginationSpeed: 2200,
            pagination: false,
            addClassActive: true,
            navigation: true,
            rewindNav: true,
            navigationText: false
        });

        var is_touch_device = 'ontouchstart' in document.documentElement;
        $('html').addClass((is_touch_device)? 'touch' : 'no-touch');

        $('#page').fitVids();
        $('#block-views-home-page-carousel-block .owl-item-textContainer h2').fitText();

         // mobile menu accordion
        $('.menuSkin-mobile .menu-block-wrapper > ul.menu').each(function() {
            var $this = $(this),
                parents = $this.find('> .expanded');

            parents.find('> ul.menu').hide(); // hide submenus initially
            parents.on('click', function(e) {
                if ($(e.target.parentElement).hasClass('expanded')) {
                    e.preventDefault(); // don't follow link
                    $(this).find('> ul.menu').slideToggle(100);
                }
            });
        });

        // resize using JS instead of max-height if js is available
        $('.regionToggle-toggle').each(function() {
            var $toggle = $(this),
                $checkbox = $toggle.siblings('.regionToggle-checkbox'),
                $container = $toggle.siblings('.regionToggle-container');

            $checkbox.remove();
            $container.hide();
            $container.css('max-height', 'none');
            $toggle.click(function() {
                $container.slideToggle(200);
            });
        });

        $('.accordion-block')
            .find('.content').hide().end()
            .find('.block-title').click(function() {
                var $this = $(this),
                    $content = $this.siblings('.content');

                $this.parents('.block').toggleClass('is-open');
                $content.slideToggle(200);
            });

        // relocate quote on mobile devices
        var $quote = $('#block-views-service-quote-block'),
            $sidebar = $('.region-sidebar'),
            $title = $('#page-title'),
            $window = $(window),
            relocateQuote = function() {
                var width = $window.width();

                $quote.remove();
                if (width > 768) {
                    $sidebar.prepend($quote);
                } else {
                    $quote.insertAfter($title);
                }
            };

        // don't add resize handler if there is no quote
        if ($quote.length) {
            relocateQuote();
            $window.resize(relocateQuote);
        }

        $(function() {
            var $container = $('.view-tool-tips-ipad.view-display-id-block'),
                $content = $container.find('> .view-content'),
                $titles = $container.find('.view-header, .view-footer').find('.tt-title'),
                $bodies = $content.find('.views-row.tt-body');

            // get the unique nid
            $titles.each(function() {
                var $title = $(this),
                    klasses = $title.attr('class').split(/\s+/);
                $.each(klasses, function (index, item) {
                    if (item.indexOf('tt-node-') === 0) {
                        $title.data('nid-class', item);
                    }
                });
            });

            $titles.click(function() {
                $bodies.hide();
                $content.find('.' + $(this).data('nid-class') + '.tt-body').show();
            });

        });
    });

    $('html')
        .addClass('js')
        .removeClass('no-js');
})(jQuery);

(function($) {

    Drupal = Drupal || {};
    Drupal.behaviors.pps = {};
    Drupal.behaviors.pps.attach = function(context) {
        updatePollBars(context);
    };

    var updatePollBars = function(context) {
        $('.poll', context).each(function() {
            var $this = $(this),
                $bars = $this.find('.barContainer'),
                maxVotes = 0,
                handleResize = function() {
                    var width = $this.width() - 75; // space for %age
                    $bars.each(function() {
                        var $bar = $(this);
                        $bar.width(width * $bar.data('voteWidth')/100);

                    });
                };

            $bars.each(function(index, bar) {
                maxVotes = Math.max(maxVotes, $(bar).data('votes'));
            });

            $bars.each(function(index, bar) {
                var $bar = $(bar),
                    newWidth = $bar.data('votes')/maxVotes * 100;
                $bar.css('width', newWidth +'%');
                $bar.data('voteWidth', newWidth);
            });

            handleResize();
            $(window).resize(handleResize);
        });
    };

})(jQuery);