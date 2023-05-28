<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>2. String Function</title>
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.bundle.min.js" integrity="sha384-/bQdsTh/da6pkI1MST/rWKFNjaCP5gBSY4sEBT38Q/9RBh9AH40zEOg7Hlq2THRZ" crossorigin="anonymous"></script>
</head>

<style>
    body{
        background-color: #212529;
    }
  
    .table{
        width: 50vw;
        margin: 20px 25vw;
    }
    .listNames{
        text-align: center;
    }
    td{
        text-align: center;
    }

</style>


<body>
    <table class="table table-dark thead-light table-striped">
    <tr>
        <th scope="col" class="listNames"  colspan="6">List of Names</th>
    </tr>
    <tr>
        <th scope="col">Name</th>
        <th scope="col">Number of Characters</th>
        <th scope="col">Uppercase first character</th>
        <th scope="col">Replace vowels with @</th>
        <th scope="col">Check Poisition of character "a"</th>
        <th scope="col">Reverse Name</th>
    </tr>
    <?php 
        $names= array("shantae","yong","rosann" ,"modesto","merrilee","kym","Latanya","Star","Rafael","Julie","Marybelle","Herta","Sabrina","Marquitta","Jolene","Kathern","Laurene","Dario","Latrice","Grazyna");
    ?>
   
 
        <?php
            

            foreach($names as $val){
                $newString = "";
                echo "<tr>";
                echo "<td>".$val."</td>";
                echo "<td>".strlen($val)."</td>";
                echo "<td>".ucfirst($val)."</td>";
                $length =  strlen($val);
                for($i = 0; $i < $length;$i++){
                    if($val[$i] == "a" ||
                    $val[$i] == "a" ||
                    $val[$i] == "e" ||
                    $val[$i] == "o" ||
                    $val[$i] == "u" ||
                    $val[$i] == "A" ||
                    $val[$i] == "E" ||
                    $val[$i] == "I" ||
                    $val[$i] == "O" ||
                    $val[$i] == "U"){
                        $newString .= "@";
                    } else{
                        // .= concanetation assignment operator
                        $newString .= $val[$i];
                    }
                }
                echo "<td>".$newString."</td>";
                echo "<td>".strpos($val, "a")."</td>";
                echo "<td>".strrev($val)."</td>";
                
                
                echo "</tr>";
            }
        
        ?>
    


    </table>
</body>
</html>