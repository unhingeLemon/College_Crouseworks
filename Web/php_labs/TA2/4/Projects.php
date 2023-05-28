<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="style.css">
    <script src="https://use.fontawesome.com/3e0c1d6310.js"></script>

    <title>Projects</title>
</head>
<body>
<?php require("Nav.php");?>
<section id="projects" class="d-flex flex-column align-items-center justify-content-center">

<h2>Projects</h2>
<?php 

$project1 = "E-Commerce App";
$project2 = "Project Manager";
$project3 = "Github Finder";
$project4 = "COVID-19 Tracker";
?>

<div class="row">
  <div class="col-lg card">
    <img src="./tindahan.jpg" class="card-img-top " alt="...">

    <div class="infos">
      <h5>
      <?php echo $project1 ?>
      </h5>
      <p>
        An e-commerce app made in MERN Stack mentored by Brad Traversy.
      </p>
      <button type="button" 
      onclick="window.open('https://tindahan-ecommerce.herokuapp.com/','_blank')"
       class="btn btn-primary">Visit
      </button>
    </div>


  </div>

  <div class="col-lg card" >
    <img src="./projectmanager.jpg" class="card-img-top" alt="...">
    <div class="infos">
      <h5>
      <?php echo $project2 ?>
      </h5>
      <p>
        A list-making Application just like Trello.
      </p>
      <button type="button" 
      onclick="window.open('https://project-manager-s.herokuapp.com/','_blank')"
       class="btn btn-primary">Visit
      </button>
    </div>
  </div>
  


</div>
<div class="row">
  
  <div class="col-lg card" >
    <img src="./githubfinder.jpg" class="card-img-top" alt="...">
    <div class="infos">
      <h5>
      <?php echo $project3 ?>
      </h5>
      <p>
        A github user finder using github REST API.
      </p>
      <button type="button" 
      onclick="window.open('https://github-finderrr.netlify.app/','_blank')"
       class="btn btn-primary">Visit
      </button>
    </div>


    
  </div>

  <div class="col-lg card" >
    <img src="./covidtracker.jpg" class="card-img-top" alt="...">
    <div class="infos">
      <h5>
      <?php echo $project4 ?>
      </h5>
      <p>
        Made in Python using Tkinter module and using REST API to get the datas.
      </p>
      <button type="button" 
      onclick="window.open('https://github.com/unhingeLemon/COVID-19-Tracker','_blank')"
       class="btn btn-primary">Visit
      </button>
    </div>
  </div>

</div>



</section>
</body>
</html>