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
    tr{
        text-align: center;
    }

</style>


<body>
    <table class="table table-dark thead-light table-striped">
    <tr>
        <th scope="col" class="listNames"  colspan="6">String Functions</th>
    </tr>
    <tr>
        <th scope="col">No.</th>
        <th scope="col">Desctiption</th>
        <th scope="col">Output</th>
    </tr>
    <?php 
        $s= " an online guide to html form <input> tag ";
        $string = str_replace(array('<', '>'), array('&lt;', '&gt;') ,$s);
        $t= "<INPUT>";
        $tag = str_replace(array('<', '>'), array('&lt;', '&gt;') ,$t);
    
    ?>
    <tr>
        <td>1</td>
        <td>Original Value of a $string</td>
        <td>*<?php echo $string;?>*</td>
    </tr>
    <tr>
        <td>2</td>
        <td>Number of characters</td>
        <td>*<?php echo strlen($string);?>*</td>
    </tr>
    <tr>
        <td>3</td>
        <td>Number of Words</td>
        <td>*<?php echo str_word_count($s) ?>*</td>
    </tr>
    <tr>
        <td>4</td>
        <td>First Character to Uppercase</td>
        <td>*<?php echo ucfirst($string);?>*</td>
    </tr>
    <tr>
        <td>5</td>
        <td>First character of each word to uppercase</td>
        <td>*<?php echo ucwords($string);?>*</td>
    </tr>
    <tr>
        <td>6</td>
        <td>To lowercase</td>
        <td>*<?php echo strtolower($string);?>*</td>
    </tr>
    <tr>
        <td>7</td>
        <td>To uppercase</td>
        <td>*<?php echo strtoupper($string);?>*</td>
    </tr>
    <tr>
        <td>8</td>
        <td>Without leading spaces</td>
        <td>*<?php echo ltrim($string);?>*</td>
    </tr>
    <tr>
        <td>9</td>
        <td>Without trailing spaces</td>
        <td>*<?php echo rtrim($string);?>*</td>
    </tr>
    <tr>
        <td>10</td>
        <td>Without leading and trailing spaces</td>
        <td>*<?php echo trim($string);?>*</td>
    </tr>
    <tr>
        <td>11</td>
        <td>MD5 value of $string</td>
        <td>*<?php echo md5($string);?>*</td>
    </tr>
    <tr>
        <td>12</td>
        <td>Base64 value of $string</td>
        <td>*<?php echo base64_encode($string);?>*</td>
    </tr>
    <tr>
        <td>13</td>
        <td>First 16 value of string</td>
        <td>*<?php echo substr($string,0,16);?>*</td>
    </tr>
    <tr>
        <td>14</td>
        <td>Last 4 characters/td>
        <td>*<?php echo substr($string,-4);?>*</td>
    </tr>
    <tr>
        <td>15</td>
        <td>4 characters starting from the 20th position</td>
        <td>*<?php echo substr($string,20,4);?>*</td>
    </tr>
        <td>16</td>
        <td>Position of the word "guide"td>
        <td>*<?php echo "int(".strpos($string,"guide").")";?>*</td>
    </tr>
        <td>17</td>
        <td>Position of the word "UE"</td>
        <td>*<?php echo strpos($string,"UE") == false ? "bool(false)" : "bool(true)"; ?>*</td>
    </tr>
 
    </tr>
        <td>18</td>
        <td>"HTML" word in upercase</td>
        <td>*<?php 
                echo str_replace("html",strtoupper("html"),$string);
        ?>*</td>
    </tr>
 
    </tr>
        <td>19</td>
        <td><?php echo $tag; ?> word in upercase</td>
        <td>*<?php 
            echo str_replace("input",strtoupper("input"),$string);
            
         
         
        ?>*</td>
    </tr>
 
    </tr>
        <td>20</td>
        <td>String converter to an array</td>
        <td>*<?php 
            $parts = explode(' ', $string);
            foreach($parts as $val){
                echo $val."<br>";
            }
        ?>*</td>
    </tr>

    


    </table>
</body>
</html>