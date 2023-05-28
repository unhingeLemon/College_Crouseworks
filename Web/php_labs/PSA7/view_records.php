<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>View Records</title>

    <!-- CSS only -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <!-- JavaScript Bundle with Popper -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>

  <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class='view-rec'>
        <h4>View Records</h4>
        <a href="admin_user.php">Back</a>
        <br>
        <table class="table table-dark">
            <tr>
                <th scope="col">ID</th>
                <th scope="col">Email</th>
                <th scope="col">Username</th>
                <th scope="col">Password</th>
                <th scope="col">User level</th>
                <th scope="col">Status</th>
            </tr>

            <?php 
                include('func.php'); 
                getRecords();
               for ($x = 0; $x < count($rec);$x++){

                    echo "<tr>";
                    echo "<th>".$rec[$x]['id']."</th>";
                    echo "<th>".$rec[$x]['email']."</th>";
                    echo "<th>".$rec[$x]['username']."</th>";
                    echo "<th>".$rec[$x]['pass']."</th>";
                    echo "<th>".$rec[$x]['userlevel']."</th>";
                    echo "<th>".$rec[$x]['stat']."</th>";
                

                    echo "</tr>";
               }

            ?>
        
         </table>
    </div>
   
    
</body>
</html>



