<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/js/bootstrap.min.js" integrity="sha384-skAcpIdS7UcVUC05LJ9Dxay8AXcDYfBJqt1CJ85S/CFujBsIzCIv+l9liuYLaMQ/" crossorigin="anonymous"></script>
    <title>Personal Information Website</title>
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
    .form2{
        display:flex;
        flex-direction: column;
        width:25vw;
        align-items: space-around;
        margin: 0 auto;

    }
    .form2 > .item{
        height: 20px;
    }
</style>
<body>
    
   <form class='form form-group' action="<?php echo $_SERVER['PHP_SELF'] ?>" method="GET">
        <h4>GET METHOD</h4>

        <div class='item form-group'>
            <label for="fname">First Name: </label>
            <input type="text" name="fname" id="" required>
        </div>
        <div class='item form-group'>
            <label for="mname">Middle Name: </label>
            <input type="text" name="mname" id="" required>
        </div>
        <div class='item form-group'>
            <label for="lname">Last Name: </label>
            <input type="text" name="lname" id="" required>
        </div class='item form-group'>

        <div class='item form-group'> 
        <label for="dob">Date of Birth: </label>
       <input type="text " name="dob" id="" required>
        </div>


       <div class='item form-group'>        
            <label for="address">Address: </label>
            <input type="text" name="address" id="" required>
       </div>

       <button class='btn btn-primary'type="submit" name='submit'>Submit</button>
   </form>

    <?php 
        if(isset($_GET['submit'])){
    ?>
    <div class='form2'>
        <div class='item '>
            <label for="">First Name:</label>
            <?php if(isset($_GET['fname'])){
                echo "<p>".$_GET['fname']."</p>";
            } else{
                echo "<p>No Input</p>";
            }
            ?>
        </div>
        <div class='item'>
        <label for="">Middle Name:</label>
            <?php if(isset($_GET['mname'])){
                echo "<p>".$_GET['mname']."</p>";
            } else{
                echo "<p>No Input</p>";
            }
            ?>
        </div>
        <div class='item'>
        <label for="">Last Name:</label>
            <?php if(isset($_GET['lname'])){
                echo "<p>".$_GET['lname']."</p>";
            } else{
                echo "<p>No Input</p>";
            }
            ?>    
        </div>
        <div class='item'>
        <label for="">Date of Birth:</label>
            <?php if(isset($_GET['dob'])){
                echo "<p>".$_GET['dob']."</p>";
            } else{
                echo "<p>No Input</p>";
            }
            ?>    
        </div>
        <div class='item'>
        <label for="">Address:</label>
            <?php if(isset($_GET['address'])){
                echo "<p>".$_GET['address']."</p>";
            } else{
                echo "<p>No Input</p>";
            }
            ?>
        </div>
        
    </div>
    <?php }?>
</body>
</html>