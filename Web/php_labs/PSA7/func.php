<?php

    $login_result = array();
    $rec = array();
    $add_status = "";
    $update_success = "";
    function connectToDb(){
        $servername = "localhost";
        $username = "root";
        $password = "";

        // Create connection
        $conn = new mysqli($servername, $username, $password);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
    
        // Create database
        $sql = "CREATE DATABASE m7DB";
        
        if ($conn->query($sql) === TRUE) {
            // echo "Database created successfully";
        } else {
            // echo "Error creating database: " . $conn->error;
        }
        $conn->close();


    }

    function createTable(){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "m7DB";
        
        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
          die("Connection failed: " . $conn->connect_error);
        }

        // sql to create table
        $sql = "CREATE TABLE USERS (
            id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
            email VARCHAR(50) NOT NULL,
            username VARCHAR(50) NOT NULL,
            pass VARCHAR(50) NOT NULL,
            stat VARCHAR(50) DEFAULT 'active',
            userlevel VARCHAR(50) DEFAULT 'user'
            
            )";
            
            if ($conn->query($sql) === TRUE) {
               // echo "Table USERS created successfully";
             
            } else {
               // echo "Error creating table: " . $conn->error;
           
            }

        $conn->close();    
    }


    function insertData($name,$pass,$email,$stat,$userlevel){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "m7DB";

        // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
        }

        $sql = "INSERT INTO USERS (username,pass,email,stat,userlevel)
        VALUES ('$name', '$pass', '$email','$stat','$userlevel')";
       

        if ($conn->query($sql) === TRUE) {
            // echo "New record created successfully";
            $GLOBALS['add_status'] = "Success";
        } else {
            // echo "Error: " . $sql . "<br>" . $conn->error;
            $GLOBALS['add_status'] = "Failed";
        }

        $conn->close();
    }
    
    function login($name,$pass){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "m7DB";

            // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        //WHERE username='$name' && pass='$pass'
        $sql = "SELECT * FROM USERS WHERE username='$name' && pass='$pass'";
        $result = $conn->query($sql);
       
        if ($result->num_rows > 0) {
        // output data of each row
        while($row = $result->fetch_assoc()) {
            //echo "id: " . $row["id"]. " - Name: " . $row["username"]. " " . $row["email"]. "<br>";
            array_push($GLOBALS['login_result'],$row);
        }
        } else {
            //echo "0 results";
        }
        $conn->close();
        
    }
    //connectToDb();
    //createTable();
    //insertData("username2","password2","email2@email.com","active","user");
    // login("username1","password1");
    
    // print_r($login_result[0]);


    function getRecords(){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "m7DB";

            // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        //WHERE username='$name' && pass='$pass'
        $sql = "SELECT * FROM USERS";
        $result = $conn->query($sql);
       
        if ($result->num_rows > 0) {
        // output data of each row
        while($row = $result->fetch_assoc()) {
            //echo "id: " . $row["id"]. " - Name: " . $row["username"]. " " . $row["email"]. "<br>";
            array_push($GLOBALS['rec'],$row);
        }
        } else {
            //echo "0 results";
        }
        $conn->close();
        
    }

     
    function updatePass($name,$newpass){
        $servername = "localhost";
        $username = "root";
        $password = "";
        $dbname = "m7DB";

            // Create connection
        $conn = new mysqli($servername, $username, $password, $dbname);
        // Check connection
        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        }
        //WHERE username='$name' && pass='$pass'
        $sql = "UPDATE USERS
                SET pass='$newpass'
        WHERE username='$name'";
        $result = $conn->query($sql);
       
        if ($conn->query($sql) === TRUE) {
            //echo "Record updated successfully";
           
            $GLOBALS['update_success'] = 'Success';
        } else {
            //echo "Error updating record: " . $conn->error;
            $GLOBALS['update_success'] = 'Failed';
        }
        $conn->close();
        
    }
   
?>  
