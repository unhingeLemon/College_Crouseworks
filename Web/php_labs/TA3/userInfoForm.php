<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>User Information Form</title>

    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

  <link rel="stylesheet" href="style.css">
</head>
<body>
    <?php

        session_start();


        if(isset($_POST['submit']) ){
            include_once './api/MyPersonal/read_single.php';
            
            $_SESSION["id"] = $personalinfo_arr['id'];
            $_SESSION["firstname"] = $personalinfo_arr['firstname'];
            $_SESSION["midname"] = $personalinfo_arr['midname'];
            $_SESSION["lastname"] = $personalinfo_arr['lastname'];
            $_SESSION["username"] = $personalinfo_arr['username'];
            $_SESSION["pass"] = $personalinfo_arr['pass'];
            $_SESSION["birthday"] = $personalinfo_arr['birthday'];
            $_SESSION["email"] = $personalinfo_arr['email'];
            $_SESSION["contact"] = $personalinfo_arr['contact'];
    
    
            if(!$personalinfo_arr['id']==null){

    
    
    ?>
    

    <div class='user-form'>
        <h3>
        User Infromation Form</h3>
        <div class="links">
            <a href="login.php">Log-out</a>
        </div>
        <div class="welcome">
            <strong>Welcome</strong>
            <p><?php echo $_SESSION['firstname']." ". $_SESSION['midname']." ". $_SESSION['lastname'];?></p>
            <strong>Birthday:</strong>
            <p><?php echo $_SESSION['birthday']; ?></p>
            <strong>Contact Details:</strong>
            <p></p>
            <strong>Email:</strong>
            <p><?php echo $_SESSION['email'] ;?></p>
            <strong>Contact:</strong>
            <p><?php echo $_SESSION['contact'] ;?></p>
        </div>

        <br>

        <form class="reset-form" method='POST' action='userInfoForm.php'>
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
            <button type="submit" name="oldsubmit" class="btn btn-primary">Submit</button>
        </form>
    </div>
    <?php  
           } else{
            echo "<a class = 'btn btn-primary back'href=\"login.php\">Back to Login</a>";
           }
        }
        
        
        if( isset($_POST['oldsubmit'])){
 
            if($_POST['newpass1'] == $_POST['newpass2']){
                if($_POST['oldpass'] == $_SESSION["pass"]) {
                    $data['id'] = $_SESSION['id'];
                    $data['pass'] = $_POST['newpass1'];
                    include_once './api/MyPersonal/update.php';
                    echo "<a class = 'btn btn-primary back'href=\"login.php\">Back to Login</a>";
                } else{
                    $message = "Old password Invalid";
                    echo "<script type='text/javascript'>alert('$message');</script>";

                }
                
            } else{
                $message = "New password and Re-Enter new password should be the same.";
                echo "<script type='text/javascript'>alert('$message');</script>";
            }
        }
        
        ?>

        
</body>
</html>



