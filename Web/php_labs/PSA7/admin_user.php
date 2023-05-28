<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Login</title>

    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

  <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php
        include('func.php'); 

        session_start();
        if(isset($_POST['username']) && isset($_POST['pass'])){
            $_SESSION["username"] = $_POST['username'];
            $_SESSION["pass"] = $_POST['pass'];
        } 

        if(isset($_SESSION['username']) && isset($_SESSION['pass'])){
            login($_SESSION['username'],$_SESSION['pass']);
            if(count($login_result) >= 1){
                



                

    
    ?>
    <?php ?>

    <div class='admin-form'>
        <h3>
            <?php 
                if ($login_result[0]['userlevel'] == 'admin'){
                    echo "Admin";
                } else{
                    echo "User";
                }
            ?> 
        Account</h3>
        <div class="links">
            <?php 
                if ($login_result[0]['userlevel'] == 'admin'){
                    echo "<a href=\"index.php\">Log-out</a>".
                        "<a href=\"view_records.php\">View Records</a>".
                        "<a href=\"admin_add.php\">Add-Records</a>";
                } else{
                    echo "<a href=\"index.php\">Log-out</a>";
                }
            ?> 



            
        </div>
        <div class="welcome">
            <strong>Welcome</strong>
            <p><?php echo $login_result[0]['username'] ;?></p>
            <strong>User Level:</strong>
            <p><?php echo $login_result[0]['userlevel']; ?></p>
            <strong>Email:</strong>
            <p><?php echo $login_result[0]['email'] ;?></p>
        </div>

        <br>

        <form class="reset-form" method='POST' action='admin_user.php'>
            <h5>Reset Password</h2>
            <div class="mb-3">
                <label class="form-label">Enter Current Password</label>
                <input type="password" placeholder="Old Password" class="form-control" name='oldpass'>
            </div>
            <div class="mb-3">
                <label class="form-label">Enter New Password</label>
                <input type="password" placeholder="New Password" class="form-control" name='newpass1'>
            </div>
            <div class="mb-3">
                <label class="form-label">Re-Enter New Password</label>
                <input type="password" placeholder="New Password" class="form-control" name='newpass2'> 
            </div>
            <button type="submit" class="btn btn-primary">Submit</button>
        </form>
    </div>

    <?php 
    
            }
            else{
                echo" <h1>INVALID CREDENTIAL!</h1>";
            }
        } else{
            echo" <h1>ERROR!</h1>";
        }

        if(isset($_POST['oldpass']) && isset($_POST['newpass1'])  && isset($_POST['newpass2'])){

            if($_SESSION["pass"] == $_POST['oldpass']  ){
                if($_POST['newpass1'] == $_POST['newpass2'] )  {
                    updatePass($_SESSION["username"],$_POST['newpass1']);
                    $_SESSION['pass'] = $_POST['newpass1'];
                    if( $GLOBALS['update_success'] == "Success"){
                        $message = "RESET PASSWORD SUCCESS";
                        echo "<script type='text/javascript'>alert('$message');</script>";
                    } else{
              
                        $message = "RESET PASSWORD FAILED";
                        echo "<script type='text/javascript'>alert('$message');</script>";
                    }
                } else{
      
                    $message = "Password1 and Password2 do not match";
                    echo "<script type='text/javascript'>alert('$message');</script>";
                }
            } else{
                $message = "PASSWORD DOES NOT MATCH";
                echo "<script type='text/javascript'>alert('$message');</script>";
            }
        }
    ?>
</body>
</html>



