<?php

function google_plus_admin() {
	$item = array();

	$item['product_name'] = array(
		'#type' => 'textfield',
    '#title' => t('Product Name'),
    '#default_value' => variable_get('google_plus_product_name', ''),
	);

	$item['redirect_uri'] = array(
		'#type' => 'textfield',
    '#title' => t('Redirect URI'),
    '#default_value' => variable_get('google_plus_redirect_uri', ''),
	);

	$item['submit'] = array(
		'#type' => 'submit',
    '#value' => t('Save'),
	);

	return $item;
}

function google_plus_admin_validate($form, $form_state) {
	if (empty($form_state['values']['product_name'])) {
		form_set_error('product_name', t('You must set a product name for this Drupal installation.'));
	}

  if (!valid_url($form_state['values']['redirect_uri'], TRUE)) {
    form_set_error('redirect_uri', t('Invalid Request URI.'));
  }
}

function google_plus_admin_submit($form, $form_state) {
	variable_set('google_plus_product_name', $form_state['values']['product_name']);
	variable_set('google_plus_redirect_uri', $form_state['values']['redirect_uri']);
}