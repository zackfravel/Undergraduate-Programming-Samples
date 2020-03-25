<html>
<body>
<title>Welcome to Zack Fravel's Assignment 11 PHP page!</title>

<h1>Welcome to Zack Fravel's Assignment 11 PHP page!</h1>
<br>
<br>
If you have an existing account, log in here!</br></br>
<form name="existingLogin" action="Assignment11.php" method="get">
	User name: <input type="text" name="existingUser"></br>
	Password: <input type="text" name="existingPass"></br>
	<input type="submit" value="Log In"></br>
</form>
<br>
<br>
___________________________________________________________________________________
<br>
<br>
<br>
Otherwise, create a new account here!</br></br>
<form name="createAccount" action="Assignment11.php" method="get">
	User name: <input type="text" name="newUser"></br>
	Password: <input type="text" name="newPass"></br>
	First Name: <input type="text" name="newfname"></br>
	Last Name: <input type="text" name="newlname"></br>
	<input type="submit" value="Create Account"></br>

<?php	
	getNames();
?>

<?php
	function getNames() {
	$file = fopen("input.txt", "r") or exit("Unable to open file!");
	while (!feof($file)) {
		$line = fgets($file);
		$line = trim($line);
		if (strlen($line) > 0) {
			$arr = explode(";", $line);
			echo "Username: " . $arr[0] . ", Password: " . $arr[1] . "</br>";
		}
	}
}

?>

</body>
</html>