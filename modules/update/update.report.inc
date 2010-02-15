<?php
// $Id: update.report.inc,v 1.10.2.6 2009/11/06 07:26:21 goba Exp $

/**
 * @file
 * Code required only when rendering the available updates report.
 */

/**
 * Menu callback. Generate a page about the update status of projects.
 */
function update_status() {
  if ($available = update_get_available(TRUE)) {
    module_load_include('inc', 'update', 'update.compare');
    $data = update_calculate_project_data($available);
    return theme('update_report', $data);
  }
  else {
    return theme('update_report', _update_no_data()