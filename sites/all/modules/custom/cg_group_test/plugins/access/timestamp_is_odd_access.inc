<?php

/**
 * @file
 * Plugin to provide access control based on timestamp is odd context.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("timestamp is odd"),
  'description' => t('Control access by timestamp is odd context.'),
  'callback' => 'timestamp_is_odd_access_check',
  'required context' => new ctools_context_required(t('timestamp is odd'), 'timestamp_is_odd'),
  'summary' => 'timestamp_is_odd_access_summary',
  'defaults' => array('timestamp_is_odd' => TRUE),
);

/**
 * Check for access
 */
function timestamp_is_odd_access_check($conf, $context) {
  return $context->data;
}

/**
 * Provide a summary description based on selected settings.
 */
function timestamp_is_odd_access_summary($conf, $context) {
  return t('timestamp is odd');
}