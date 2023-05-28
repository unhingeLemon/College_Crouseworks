

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>TA3</title>
    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>
    <link rel="stylesheet" href="style.css">
</head>
<body>
<?php 
    if(isset($_POST['submit'])){
           
            if($_POST['pass1'] == $_POST['pass2']){
                $pass = $_POST['pass1'];
                $data = array();
                $data['firstname'] = $_POST['fname'];
                $data['midname'] = $_POST['mname'];
                $data['lastname'] = $_POST['lname'];
                $data['username'] = $_POST['username'];
                $data['pass'] =  $pass;
                $data['birthday'] = $_POST['birthday'];
                $data['email'] = $_POST['email'];
                $data['contact'] = $_POST['contact'];
                include './api/MyPersonal/create.php';
                echo "<a class = 'btn btn-primary back'href=\"login.php\">Back to Login</a>";

            } else{
                $message = "PASSWORD DOES NOT MATCH";
                echo "<script type='text/javascript'>alert('$message');</script>";

            }
         

        } else{

        
    
    ?>

    
    <form class="form" method='POST' action='MyPersonal.php'>
        <h2>My Personal Information</h2>
        <a class='link-tag'href="login.php">Back</a>
        <div class="mb-3">
            <label class="form-label">First Name</label>
            <input type="text"placeholder="Firs Name"class="form-control" required name='fname'>
        </div>
        <div class="mb-3">
            <label class="form-label">Middle Name</label>
            <input type="text"placeholder="Middle Name"class="form-control" required name='mname'>
        </div>
        <div class="mb-3">
            <label class="form-label">Last Name</label>
            <input type="text"placeholder="Last Name"class="form-control" required name='lname'>
        </div>

        <div class="mb-3">
            <label class="form-label">Username</label>
            <input type="text"placeholder="Username"class="form-control" required name='username'>
        </div>
        <div class="mb-3">
            <label class="form-label">Password</label>
            <input type="password" placeholder="Password" class="form-control" required name='pass1'>
        </div>
        <div class="mb-3">
            <label class="form-label">Confirm Password</label>
            <input type="password" placeholder="Confirm Password" class="form-control" required name='pass2'>
        </div>
        <div class="mb-3">
            <label class="form-label">Birthday</label>
            <input type="text" placeholder="Birthday" class="form-control" required name='birthday'>
        </div>
        <div class="mb-3">
            <label for="exampleInputEmail1" class="form-label" >Email address</label>
            <input type="email" placeholder="email@example.com" class="form-control" required name='email'>
        </div>
        <div class="mb-3">
            <label class="form-label">Contact Number</label>
            <input type="text" placeholder="Contact Number" class="form-control" required name='contact'>
        </div>
        <button type="submit" name = 'submit'class="btn btn-primary">Submit</button>
    </form>
   
    <?php } ?>
</body>
</html>