<?php 

  include_once('config/Database.php');
  include_once('models/PersonalInfo.php');

  // Instantiate DB & connect
  $database = new Database();
  $db = $database->connect();

  $personalinfo = new PersonalInfo($db);


  $personalinfo->firstname = $data['firstname'];
  $personalinfo->midname = $data['midname'];
  $personalinfo->lastname = $data['lastname'];
  $personalinfo->username = $data['username'];
  $personalinfo->pass = $data['pass'];
  $personalinfo->birthday = $data['birthday'];
  $personalinfo->email = $data['email'];
  $personalinfo->contact = $data['contact'];

  // Create post
  if($personalinfo->create()) {
    $message = "REGISTER SUCCESS";
    echo "<script type='text/javascript'>alert('$message');</script>";

  } else {
    $message = "REGISTER FAILED ";
    echo "<script type='text/javascript'>alert('$message');</script>";
  }

  
?>
