<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <title>Favorite Color</title>
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
    button{
        margin: 20px 20px
    }
    h4{
        text-align:center;
    }

</style>
<body>
    <?php  session_start(); ?>
    
   <form class='form form-group' action="ResultColors.php" method="GET">
        <h4>ENTER YOUR FAVORITE COLOR</h4>

        <div class='item form-group'>
            <label for="c1">Favorite Color 1: </label>
            <input type="text" name="c1" id="" required>
        </div>
        <div class='item form-group'>
            <label for="c2">Favorite Color 2: </label>
            <input type="text" name="c2" id="" required>
        </div>
        <div class='item form-group'>
            <label for="c3">Favorite Color 3: </label>
            <input type="text" name="c3" id="" required>
        </div class='item form-group'>

        <div class='item form-group'> 
        <label for="c4">Favorite Color 4: </label>
       <input type="text " name="c4" id="" required>
        </div>


       <div class='item form-group'>        
            <label for="c5">Favorite Color 5: </label>
            <input type="text" name="c5" id="" required>
       </div>

       <button class='btn btn-primary'type="submit" name='submit'>Send Colors</button>
   </form>

</body>
</html>