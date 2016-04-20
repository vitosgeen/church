<?php

/**
 * @file
 *
 * Plugin to provide a timestamp is odd
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('timestamp_is_odd'),
  'description' => t('Returns TRUE/FALSE based on current Unix timestamp (time() function) so that if timestamp is odd it returns TRUE, and FALSE if even.'),
  'context' => 'ctools_timestamp_is_odd',
  'context name' => 'timestamp_is_odd',
  'keyword' => 'timestamp_is_odd',
  'convert list' => 'timestamp_is_odd_convert_list',
  'convert' => 'timestamp_is_odd_convert',
);

function ctools_timestamp_is_odd($empty, $data = NULL, $conf = FALSE) {
  $context = new ctools_context('timestamp_is_odd');
  $context->plugin = 'timestamp_is_odd';
  if ($empty) {
    return $context;
  }
  if ($data !== FALSE ) {
    $context->title = ($conf) ? check_plain($data['identifier']) : check_plain($data);
	$ts_odd = ((time()%2)==0);
    $context->data = $ts_odd;
    return $context;
  }
} 

function timestamp_is_odd_convert_list() {
  return array(
    'value' => t('value'),
  );
}
function timestamp_is_odd_convert($context, $type) {
  return $context->data;
}