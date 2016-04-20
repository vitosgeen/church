/*global Drupal: false, jQuery: false */
/*jslint devel: true, browser: true, maxerr: 50, indent: 2 */
(function($) {
  "use strict";

  Drupal.yashare.initWidgets = function (context, settings) {
    $.each(settings.yashare, function (index, value) {
      $('#' + index + ':not(.yashare-processed)', context).addClass('yashare-processed').each(function () {
        new Ya.share(value);
      });
    });
  };

  Drupal.behaviors.yashare = {};
  Drupal.behaviors.yashare.attach = function (context, settings) {
    Drupal.yashare.initialize(Drupal.yashare.initWidgets, context, settings);
  };

})(jQuery);
