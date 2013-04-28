<?php

/**
 * @file
 * Convert Y/N taxonomy field into the term name from field title.
 */
$plugin = array(
  'form'  =>  'feeds_tamper_taxonomy_yn_form',
  'callback'  =>  'feeds_tamper_taxonomy_yn_callback',
  'name'  =>  'Taxonomy Y/N',
  'multi'  =>  'loop',
  'category'  =>  'Other',
  'default description'  =>  'Convert Taxonomy Y/N',
);

function feeds_tamper_taxonomy_yn_form($importer, $element_key, $settings) {
  $form = array();
  $form['help'] = array(
    '#markup'  =>  t('Converts this field from a Y/N to the term name from the field title.'),
  );
  return $form;
}

function feeds_tamper_taxonomy_yn_callback($result, $item_key, $element_key, &$field, $settings) {
  $new_field = array();
  
  $categories = array('bakedgoods', 'cheese', 'crafts', 'flowers', 'eggs', 'seafood', 
    'herbs', 'vegetables', 'honey', 'jams', 'maple', 'meat', 'nursery', 'nuts', 
    'plants', 'poultry', 'prepared', 'soap', 'trees', 'wine');
  
  foreach ($categories as $category) {
    if ($result->items[$item_key][$category] == 'Y') {
      $new_field[] = $category;
    }
  }
  
  $field = $new_field;
}

