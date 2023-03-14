<?php
$servername = "stor01.rehzzo.net";
$username = "ghizzo-web";
$password = "AL5Drh2ePRO6sbBn";
$db = "www.ghizzo.fr";

try
{
   $conn = new PDO("mysql:host=$servername;dbname=myDB", $username, $password, $db);
   $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
   echo "Connected successfully";
}
catch(PDOException $e)
{
   echo "Connection failed: " . $e->getMessage();
}
?>
