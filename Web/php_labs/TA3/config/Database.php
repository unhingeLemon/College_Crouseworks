<?php 
  class Database {
    // DB Params
    private $host = 'localhost';
    private $db_name = 'ta3db';
    private $username = 'root';
    private $password = '';
    private $conn;
    
    public function createTable(){
        $conn = new mysqli($this->host, $this->username, $this->password,$this->db_name);
        $sql = "CREATE TABLE personalinfo (
          id INT(6) UNSIGNED AUTO_INCREMENT PRIMARY KEY,
          firstname VARCHAR(30) NOT NULL,
          midname VARCHAR(30) NOT NULL,
          lastname VARCHAR(30) NOT NULL,
          username VARCHAR(30) NOT NULL UNIQUE,
          pass VARCHAR(30) NOT NULL,
          birthday VARCHAR(30) NOT NULL,
          contact VARCHAR(30) NOT NULL,
          email VARCHAR(50) NOT NULL
          )";

        $conn->query($sql);
    }



    // DB Connect
    public function connect() {
      $conn = new mysqli($this->host, $this->username, $this->password);
      $sql = "CREATE DATABASE ". $this->db_name;
      $conn->query($sql);

      $this->createTable();

      
      try { 
        $this->conn = new PDO('mysql:host=' . $this->host . ';dbname=' . $this->db_name, $this->username, $this->password);
        $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
      } catch(PDOException $e) {
        echo 'Connection Error: ' . $e->getMessage();
      }

      return $this->conn;
    }
  }
?>