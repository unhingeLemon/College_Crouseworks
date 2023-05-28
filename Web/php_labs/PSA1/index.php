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

    <nav class="navbar sticky-top  navbar-expand-lg navbar-dark" >
        <div class="container-fluid ">
          <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav" aria-controls="navbarNav" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
          </button>
          <div class="collapse navbar-collapse " id="navbarNav">
            <ul class="navbar-nav">
              <li class="nav-item">
                <a class="nav-link "  href="#home"><?php echo $nav1?></a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#about"><?php echo $nav2?></a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#projects"><?php echo $nav3?></a>
              </li>
              <li class="nav-item">
                <a class="nav-link" href="#contact"><?php echo $nav4?></a>
              </li>
            </ul>
          </div>
        </div>
      </nav>



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
          <div  class="d-flex justify-content-evenly" style="width: 100vw">
            <div class="skills">
              <h6>Proficient in:</h6>
              <ul>
                <?php 
                
                    foreach ($skills1 as $skill) {
                        echo "<li> {$skill} </li>";
                    };
                ?>

              </ul>
            </div>
            <div class="skills">
              <h6>I also have a knowledge on:</h6>
              <ul>
              <?php 
                
                foreach ($skills2 as $skill) {
                    echo "<li> {$skill} </li>";
                };
            ?>
              </ul>
            </div>
          </div>
        
        </div>
        
      </section>


      <section id="projects" class="d-flex flex-column align-items-center justify-content-center">

        <h2>Projects</h2>

        
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

      
      <section id="contact" >

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