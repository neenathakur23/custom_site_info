<?php

function _custom_site_information_json_output($siteapikey,$nid) {
  $output = "";
  
  /* check if Site API Key is valid */
  if($siteapikey==variable_get('siteapikey')){
  	$node = node_load($nid);
	
	/* check if nid is valid and it is of node type "Basic Page" */  
	if($node && $node->type=='page'){
	  $output = drupal_json_output($node);
  	  return $output;	
	}else{
		_custom_site_information_access_denied();
	}  	
  }else{
  	_custom_site_information_access_denied();
  }
  
}

function _custom_site_information_form_submit(&$form, &$form_state){
  $siteapikey = variable_get('siteapikey');
  $current_siteapikey = $form_state['input']['siteapikey'];
  
  /* check if Site API Key has been altered */	
  if($siteapikey!=$current_siteapikey){		
    $message = t('Site API Key '.$current_siteapikey.' is saved.');
    drupal_set_message($message);
  }	
}

/* To display content of access denied */
function _custom_site_information_access_denied(){
  drupal_access_denied();
  module_invoke_all('exit');
  exit();
}
