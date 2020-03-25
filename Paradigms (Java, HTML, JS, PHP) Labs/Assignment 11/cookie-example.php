<?php
if (isset($_GET['cookieOn'])) {
	setcookie("user", $_GET['name'], time()+3600);
}

if (isset($_GET['cookieOff'])) {
	setcookie("user", "", time()-3600);
}

?>

<html>
	<head>
		<title>Cookie example</title>
	</head>
	<body>

<?php
if (isset($_GET['name'])) {
	echo "Welcome " . $_GET['name'] . " (from GET request)!<br>";
} else if (isset($_COOKIE["user"])) {
  echo "Welcome " . $_COOKIE["user"] . " (from cookie)!<br>";
  //print_r($_COOKIE);
} else {
  echo "Welcome guest!<br>";
}
?>
		<br>
		<a href="cookie-example.php">Refresh page</a><br>

		<br>
		<form name="form1" action="cookie-example.php" method="get">
			Name: <input type="text" name="name">
			<input type="hidden" name="cookieOn" value="on"><br>
			<input type="submit" value="Turn cookie on">
		</form>
		
		<form name="form1" action="cookie-example.php" method="get">
			<input type="hidden" name="cookieOff" value="off">
			<input type="submit" value="Turn cookie off">
		</form>

	</body>
</html>
