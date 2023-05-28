<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <title>Result Color</title>
</head>

<style>
    body{
        background-color: #212529;
        color:white;
    }
    .form{
        display:flex;
        flex-direction: column;
        width:25vw;
        align-items: space-around;
        margin: 0 auto;
        margin-top: 50px;
    }
    .item{
        display:flex;
        flex-direction: row;
        justify-content:space-between;
        margin: 5px
    }

    h4{
        text-align:center;
    }

</style>
<body>
    <?php 
       if(isset($_GET['submit'])){
        $_SESSION['c1'] = $_GET['c1'];
        $_SESSION['c2'] = $_GET['c2'];
        $_SESSION['c3'] = $_GET['c3'];
        $_SESSION['c4'] = $_GET['c4'];
        $_SESSION['c5'] = $_GET['c5'];
        
    ?>

   
   <div class='form'>
        <h4>ResultColor.php</h4>

        <div class='item form-group'>
            <label for="c1">Favorite Color 1: </label>
            <?php echo "<p>". $_SESSION['c1']."</p>" ?>
        </div>
        <div class='item form-group'>
            <label for="c2">Favorite Color 2: </label>
            <?php echo "<p>". $_SESSION['c2']."</p>" ?>
        </div>
        <div class='item form-group'>
            <label for="c3">Favorite Color 3: </label>
            <?php echo "<p>". $_SESSION['c3']."</p>" ?>
        </div class='item form-group'>

        <div class='item form-group'> 
        <label for="c4">Favorite Color 4: </label>
        <?php echo "<p>". $_SESSION['c4']."</p>" ?>
        </div>


       <div class='item form-group'>        
            <label for="c5">Favorite Color 5: </label>
            <?php echo "<p>". $_SESSION['c5']."</p>" ?>
       </div>

   </div>

   <?php
    }else{
        echo "<h4>INVALID GATEWAY, PLEASE GO TO /FavoriteColor </h4>";
    }
    session_unset(); 
 
   ?>
</body>
</html>