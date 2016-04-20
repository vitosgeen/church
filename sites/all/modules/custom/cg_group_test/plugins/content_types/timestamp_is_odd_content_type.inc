<?php

/**
 * @file
 *
 * Plugin to provide a timestamp is odd content type
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t('timestamp is odd content type'),
  'content_types' => 'timestamp_is_odd_content_type',
  'required context' => new ctools_context_required(t('timestamp_is_odd'), 'timestamp_is_odd'),
  'render callback' => 'timestamp_is_odd_content_type_render',
  'category' => array(t('timestamp'), -9), 
);

function timestamp_is_odd_content_type_render($subtype, $conf, $args, $context) {
  $data = $context->data;
  $block = new stdClass();
  $str_boolean = 'FALSE';
  if($context->data){
    $str_boolean = 'TRUE';
  }
  
  $block->title = "";
  $block->content = $str_boolean;
  return $block; 
} 