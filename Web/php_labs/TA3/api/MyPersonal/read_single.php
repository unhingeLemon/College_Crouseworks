<?php 


  include_once 'config/Database.php';
  include_once 'models/PersonalInfo.php';

  // Instantiate DB & connect
  $database = new Database();
  $db = $database->connect();

  $personalinfo = new PersonalInfo($db);

  

  if(isset($_POST['pass']) && isset($_POST['username'])){
    $personalinfo->username = $_POST['username'] ;
    $personalinfo->pass = $_POST['pass'];
  } else{
    if(isset( $_SESSION['pass']) && isset($_SESSION['username'])){
      $personalinfo->username = $_SESSION['username'] ;
      $personalinfo->pass = $_SESSION['pass'];
    } else{
      die();
    }
    die();
  }

  // Get post
  $personalinfo->read_single();

  // Create array
  $personalinfo_arr = array(
    'id' => $personalinfo->id,
    'firstname' => $personalinfo->firstname,
    'midname' => $personalinfo->midname,
    'lastname' => $personalinfo->lastname,
    'username' => $personalinfo->username,
    'pass' => $personalinfo->pass,
    'birthday' => $personalinfo->birthday,
    'email' => $personalinfo->email,
    'contact' => $personalinfo->contact
  );

  
?>