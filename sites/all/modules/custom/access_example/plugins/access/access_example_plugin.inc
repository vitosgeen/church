<?php

/**
 * @file
 * Describes ctools access example plugin.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  // Plugin user-friendly name.
  'title' => t('Eldership rule'),
  // Plugin description.
  'description' => t('Controls access depends on eldership'),
  // Without required context plugin will now be shown in Panels UI.
  'required context' => array(new ctools_context_required(t('User'), 'user')),
  // Function which will allow or restrict access.
  'callback' => 'access_example_who_elder_access',
  // Plugin settings form.
  'settings form' => 'access_example_who_elder_access_settings_form',
  // Provides a summary descriptions depends on settings selected.
  'summary' => 'access_example_who_elder_access_summary',
);

/**
 * Settings form for our access plugin.
 */
function access_example_who_elder_access_settings_form(&$form, &$form_state, $conf) {
  $form['settings']['eldership'] = array(
    '#type' => 'checkbox',
    '#title' => t('Eldership'),
    '#description' => t('Will provide access if current user has been registered before user from context'),
    '#default_value' => !empty($conf['eldership']) ? TRUE : FALSE,
  );
  return $form;
}

/**
 * Check for access.
 */
function access_example_who_elder_access($conf, $context) {
  global $user;
  // There should always be a context at this point, but this
  // is safe.
  if (empty($context[0]) || empty($context[0]->data)) {
    return FALSE;
  }
  // We should ignore this access rule in case user is viewing his own profile.
  if ($user->uid == $context[0]->data->uid) {
    return TRUE;
  }
  if ($user->created < $context[0]->data->created) {
    return TRUE;
  }
  return FALSE;
}

/**
 * Provide a summary description based on selected settings.
 */
function access_example_who_elder_access_summary($conf, $context) {
  return !empty($conf['eldership']) ?
  t('Will grant access if current user has been registered earlier then context user') :
  t('Will grant access if current user has been registered later then context user');
}

