<?php 
  // Headers


  include_once 'config/Database.php';
  include_once 'models/PersonalInfo.php';

  // Instantiate DB & connect
  $database = new Database();
  $db = $database->connect();

  // Instantiate blog post object
  $personalinfo = new PersonalInfo($db);

  // Set ID to update
  $personalinfo->pass = $data['pass'];
  $personalinfo->id = $data['id'];

  // Update post
  if($personalinfo->update()) {
    $message = "Password Updated";
    echo "<script type='text/javascript'>alert('$message');</script>";
  } else {
    $message = "Password update Failed";
    echo "<script type='text/javascript'>alert('$message');</script>";
  }

