<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Add Record</title>

    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

  <link rel="stylesheet" href="style.css">
</head>
<body>
  <?php 
    include('func.php');  

    if(isset($_POST['email']) && $_POST['username'] && $_POST['pass'] && $_POST['stat'] &&  $_POST['userlevel'] ){

        insertData($_POST['username'],$_POST['pass'],$_POST['email'],
        strtolower($_POST['stat']) , 
        strtolower($_POST['userlevel']));
        if($add_status == "Success"){
          echo "<h4>Success</h4>";
        } else{
          echo "<h4>Failed</h4>";
        }
      
    } 
  ?>

  <form class="form" method='POST' action='admin_add.php'>
    <h2>Add Record</h2>
    <a class='link-tag'href="admin_user.php">Back</a>
    <div class="mb-3">
      <label for="exampleInputEmail1" class="form-label" >Email address</label>
      <input type="email" placeholder="email@example.com" class="form-control" required name='email'>
    </div>
    <div class="mb-3">
      <label class="form-label">Username</label>
      <input type="text"placeholder="Username"class="form-control" required name='username'>
    </div>
    <div class="mb-3">
      <label class="form-label">Password</label>
      <input type="password" placeholder="Password" class="form-control" required name='pass'>
    </div>
    <div class="mb-3">
      <label class="form-label">User Level</label>
      <input type="text" placeholder="Admin/User" class="form-control" required name='userlevel'>
    </div>
    <div class="mb-3">
      <label class="form-label">Status</label>
      <input type="text" placeholder="Active/Disable" class="form-control" required name='stat'>
    </div>
    <button type="submit" class="btn btn-primary">Submit</button>
  </form>
</body>
</html>



