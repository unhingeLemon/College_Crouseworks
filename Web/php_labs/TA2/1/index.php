<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Calendar</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<div class="month">
  <ul>

    <li>September<br><span style="font-size:18px">2021</span></li>
  </ul>
</div>
<?php 
    for($i = 0;$i <30 ;$i++){
       $arr[$i] = $i + 1;
    }
?>
<ul class="weekdays">
  <li>Mo</li>
  <li>Tu</li>
  <li>We</li>
  <li>Th</li>
  <li>Fr</li>
  <li>Sa</li>
  <li>Su</li>
</ul>

<ul class="days">
    <?php 

        for($i = 0;$i < 4;$i++){

                echo "<li>" ." ". "</li>";
 
        
        
        }
        foreach($arr as $val){
            if($val == 16 || $val == 24){
                echo "<li><span class=\"active\">".$val. "</span></li>";
            } else{
                echo "<li>" .$val. "</li>";
            }
          
           
        }
    ?>


</ul>
</body>
</html>