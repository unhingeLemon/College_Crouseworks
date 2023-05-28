<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Skills</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-BmbxuPwQa2lc/FVzBcNJ7UAyJxM6wuqIj61tLrc4wSX0szH/Ev+nYRRuWlolflfl" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-beta2/dist/js/bootstrap.bundle.min.js" integrity="sha384-b5kHyXgcpbZJO/tY9Ul7kGkf1S0CWuKcCD38l8YkeH8z8QjE0GmW1gYU5S9FOnJ0" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="style.css">
    <script src="https://use.fontawesome.com/3e0c1d6310.js"></script>
</head>

<style>
    .skill{
        margin: 0 0;
        padding: 50px 45vw;
        width: 100vw;
        padding-top: 100px;
        
    }
    
</style>
<body>
  <?php require("Nav.php");?>
    <?php 
        $skills1[0] = "Mongo DB";
        $skills1[1] = "Express";
        $skills1[2] = "React.js";
        $skills1[3] = "Node.js";
    
        $skills2[0] = "C++";
        $skills2[1] = "Python";
        $skills2[2] = "Java";
        $skills2[3] = "Web Design";
        
    
    ?>
    <h1 class='skill'>SKILLS</h1>
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
</body>
</html>