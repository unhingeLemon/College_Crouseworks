<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <title>1. USING ARRAYS</title>
</head>

<style>
    body{
        background-color: #212529;
    }
    img{
        width:100px;S
   
    }
    .table{
        width: 50vw;
        margin: 20px 25vw;
    }

</style>

<?php 

    $arr = array(
        array("Mark Angelo Capili","1.png",21,"09577886335","September 16, 2000"),
        array("Zion Bruce","2.jpg",20,"09335566448","September 2, 2000"),
        array("Dante Foley","3.jpg",23,"09663355447","September 3, 2000"),
        array("Tiana Scott","4.jpg",22,"09115566448","September 4, 2000"),
        array("Jamarcus Fernandez","5.jpg",21,"09566887742","September 5, 2000"),
        array("Amira Bass","6.jpg",19,"09665588772","September 6, 2000"),
        array("Alicia Travis","7.jpg",18,"0956489335","September 7, 2000"),
        array("Alonso Mejia","8.jpg",24,"095662255884","September 8, 2000"),
        array("Serena Lawrence","9.jpg",25,"097712472774","September 8, 2000"),
        array("John Cena","10.jpg",17,"09888224224","September 10, 2000")
        
    );

    //SORTING
    $columns = array_column($arr, 0);
    array_multisort($columns, SORT_ASC, $arr);




?>
<table class="table table-dark thead-light table-striped">
  <tr>
    <th scope="col">No.</th>
    <th scope="col">Name</th>
    <th scope="col">Image</th>
    <th scope="col">Age</th>
    <th scope="col">Contact No.</th>
    <th scope="col">Birthday</th>
  </tr>
 
  <?php 
    for ($x = 0; $x < 10; $x++) {
        
      echo "<tr scope=\"row\" >";
      echo "<td>". ($x+1). "</td>";
        for ($y = 0; $y < 5; $y++) {
           
            if($y==1){
                
                echo "<td>" . "<img src=\"" . $arr[$x][$y] . "\"alt=\"1\">"."</td>";
            }else{
                echo "<td>".$arr[$x][$y]."</td>";
            }
          }
        echo "</tr>";
      }
  ?>



</table>



<body>
    
</body>
</html>