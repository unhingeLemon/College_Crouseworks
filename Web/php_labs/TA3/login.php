

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

    <form class="form" method='POST' action='userInfoForm.php'>
        <h2>Log-in Form</h2>
       
        <div class="mb-3">
            <label class="form-label">Username</label>
            <input type="text"placeholder="Username"class="form-control" required name='username'>
        </div>
        <div class="mb-3">
            <label class="form-label">Password</label>
            <input type="password" placeholder="Password" class="form-control" required name='pass'>
        </div>
        <button type="submit" name = 'submit'class="btn btn-primary">Submit</button>
        <a style="width:100%; text-align:right;" href="MyPersonal.php">REGISTER HERE</a>
    </form>

</body>
</html>