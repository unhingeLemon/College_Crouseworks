<?php
    $name = "Hi, I am Mark";
    $intro = "A self-taught web developer.";
    $title = "Mark - Full Stack Developer";

    $nav1 = "Home";
    $nav2 = "About";
    $nav3 = "Projects";
    $nav4 = "Contact Me";

    $skills1[0] = "Mongo DB";
    $skills1[1] = "Express";
    $skills1[2] = "React.js";
    $skills1[3] = "Node.js";

    $skills2[0] = "C++";
    $skills2[1] = "Python";
    $skills2[2] = "Java";
    $skills2[3] = "Web Design";

    $contact1 = "angelocapili44@gmail.com";
    $contact2 = "linkedin.com/in/markangeloc";
    $contact3 = "fb.me/cmarkangelo";
    $contact4 = "@unhingeLemon";

    $project1 = "E-Commerce App";
    $project2 = "Project Manager";
    $project3 = "Github Finder";
    $project4 = "COVID-19 Tracker";

    $quote = "Breathing, learning, & upgrading one step at a time";

?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="style.css">
    <script src="https://use.fontawesome.com/3e0c1d6310.js"></script>

    <title><?php echo $title ?></title>
</head>
<body>
  <?php require("Nav.php");?>



      <section id="home">
        <div class="d-flex justify-content-between about">
            <div class="d-flex align-items-center intro">
                <h1 class="container"><?php echo $name ?></h1>
                <p class="container-fluid"><?php echo $intro ?></p>

              
            </div>
    
            <div >
            
                <img class="img " src="./lines.svg" alt="Lines" srcset="">
            </div>
        </div>
      </section>

      <section id="about" class="d-flex flex-column align-items-center ">

        <h2 class="about2">Who am I?</h2>
        <div class="d-flex flex-column align-items-center">
          <p class="short-desc">I am <strong>Mark Angelo Capili</strong> currently studying Computer Science in FEU Institute of Technology.</p>
          
        </div>
        
      </section>


     

     
</body>
</html>