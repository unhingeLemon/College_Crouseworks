<?php 
  class PersonalInfo {
    // DB stuff
    private $conn;
    private $table = 'personalinfo';
    
    // Post Properties
    public $id;
    public $firstname;
    public $midname;
    public $lastname;
    public $username;
    public $pass;
    public $birthday;
    public $email;
    public $contact;

    // Constructor with DB
    public function __construct($db) {
      $this->conn = $db;
    }

    // Get Single Post
    public function read_single() {
          // Create query
          $query = 'SELECT * FROM PersonalInfo WHERE username = :username and pass = :pass';
  

          // Prepare statement
          $stmt = $this->conn->prepare($query);

          // Bind ID
          $stmt->bindParam(':username', $this->username);
          $stmt->bindParam(':pass', $this->pass);
          // Execute query
          $stmt->execute();

          $row = $stmt->fetch(PDO::FETCH_ASSOC);

          if($row){
            $this->id = $row['id'];
            $this->firstname = $row['firstname'];
            $this->midname = $row['midname'];
            $this->lastname = $row['lastname'];
            $this->pass = $row['pass'];
            $this->birthday = $row['birthday'];
            $this->email = $row['email'];
            $this->contact = $row['contact'];
          } else{
            $message = "INVALID CREDENTIALS";
            echo "<script type='text/javascript'>alert('$message');</script>";
          }
          // Set properties
          
    }

    // Create Post
    public function create() {
          // Create query
          $query = 'INSERT INTO ' . $this->table . ' SET 
          firstname = :firstname, 
          midname = :midname, 
          lastname = :lastname, 
          username = :username, 
          pass = :pass,
          birthday = :birthday,
          email = :email,
          contact = :contact
          ';

          // Prepare statement
          $stmt = $this->conn->prepare($query);

          // Bind data
          $stmt->bindParam(':firstname', $this->firstname);
          $stmt->bindParam(':midname', $this->midname);
          $stmt->bindParam(':lastname', $this->lastname);
          $stmt->bindParam(':username', $this->username);
          $stmt->bindParam(':pass', $this->pass);
          $stmt->bindParam(':birthday', $this->birthday);
          $stmt->bindParam(':email', $this->email);
          $stmt->bindParam(':contact', $this->contact);

          // Execute query
          if($stmt->execute()) {
            return true;
      }

      // Print error if something goes wrong
      printf("Error: %s.\n", $stmt->error);

      return false;
    }

    // Update Post
    public function update() {
          // Create query
          $query = 'UPDATE ' . $this->table . '
                                SET 
                                pass = :pass
                                WHERE id = :id';

          // Prepare statement
          $stmt = $this->conn->prepare($query);

    

          // Bind data
          $stmt->bindParam(':pass', $this->pass);
          $stmt->bindParam(':id', $this->id);
          
          // Execute query
          if($stmt->execute()) {
            return true;
          }

          // Print error if something goes wrong
          printf("Error: %s.\n", $stmt->error);

          return false;
    }


    }
    
  