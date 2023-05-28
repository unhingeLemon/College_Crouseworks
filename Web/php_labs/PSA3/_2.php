<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <title>2. USING ARRAYS</title>
</head>
<style>
    body{
        background-color: #212529;
    }
    img{
        width:100px;
   
    }
    .table{
        width: 50vw;
        margin: 200px 25vw;
    }

</style>


<body>
    <?php 
        $arr = array(1,2,3,4,5,6,7,8,9,10);
        $add = 0;
        $sub = 0;
        $mult = 0;
        $div = 0.0;
        foreach($arr as $val){
            
            if($mult == 0 and $div == 0){
                $mult = $val;
                $div = $val;
                
        
            } else{
                $mult *= $val;
                $div /= $val;
            }

            if($add == 0 and $sub == 0){
                $add = $val;
                $sub = $val;
                
        
            } else{
                $add += $val;
                $sub -= $val;
            }
           
        }
    ?>
    <table class="table table-dark thead-light table-striped">

        <tr>
            <th scope="col" colspan="2">
                <?php 
                    echo "Array List: ";
                    foreach($arr as $val){
                    echo $val . ", ";
                    }
                ?>
            </th>
        </tr scope="row">
            <?php 
                echo "<td>Addition</td>";
                echo "<td>".$add."</td>";
            ?>
        <tr>
        </tr scope="row">
            <?php 
               echo "<td>Subtraction</td>";
               echo "<td>".$sub."</td>";
            ?>
        <tr>
        </tr scope="row">
            <?php 
                echo "<td>Multiplication</td>";
                echo "<td>".$mult."</td>";
            ?>
        <tr>
        </tr scope="row">
            <?php 
                echo "<td>Division</td>";
                echo "<td>".$div."</td>";
            ?>
        <tr>

        </tr>
    </table>
</body>
</html>