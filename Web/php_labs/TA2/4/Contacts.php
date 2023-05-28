<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Contact</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="style.css">
    <script src="https://use.fontawesome.com/3e0c1d6310.js"></script>
</head>
<body>
<?php require("Nav.php");?>
 
<section id="contact" >

<?php

    $contact1 = "angelocapili44@gmail.com";
    $contact2 = "linkedin.com/in/markangeloc";
    $contact3 = "fb.me/cmarkangelo";
    $contact4 = "@unhingeLemon";

    $quote = "Breathing, learning, & upgrading one step at a time";

?>

<h4>"<?php echo $quote ?>"</h4>
<h5>Reach out to me via:</h5>

<div>
 
  <div class="contact_info">
    <div class="icon"
    ><i class="fa fa-envelope-o"></i></div>
    <span class="badge bg-dark"><?php echo $contact1 ?></span>
  </div>
  
  <div class="contact_info">
    <div class="icon"
    onclick="window.open('https://www.linkedin.com/in/markangeloc/','_blank')"
    ><i class="fa fa-linkedin"></i></div>
    <span class="badge bg-dark"><?php echo $contact2 ?></span>
  </div>

  <div class="contact_info">
    <div class="icon"
    onclick="window.open('https://www.facebook.com/cmarkangelo/','_blank')"
    ><i class="fa fa-facebook"></i></div>
    <span class="badge bg-dark"><?php echo $contact3 ?></span>
  </div>

  <div class="contact_info">
    <div class="icon" 
    onclick="window.open('https://github.com/unhingeLemon','_blank')"
    ><i class="fa fa-github"></i></div>
    <span class="badge bg-dark"><?php echo $contact4 ?></span>
  </div>

</div>



</section>

</body>
</html>