<?php
session_start();
if (isset($_REQUEST['clear'])) {
	session_unset();
	session_destroy();
	session_start();
}
?>

<html>
<head>
	<title>Session example</title>
</head>
<body>
<?php
if(!isset($_SESSION['counter'])) {
    $_SESSION['counter'] = 0;
	print "session variable does not exist<br>";
} else {
	$_SESSION['counter'] = $_SESSION['counter'] + 1;
	print "session variable exists!<br>";
	print("Cookie info: ");
	print_r($_COOKIE);
	print("<br>Session info: ");
	print_r($_SESSION);
	print("<br>");
}

echo "You have visited this page " . $_SESSION['counter'] . " times.<br>";

?>
	<br>
	<a href="session-example.php">Refresh page</a><br><br>

	<form action="session-example.php" method="get">
		<input type="hidden" name="clear" value="true">
		<input type="submit" value="Clear session">
	</form>
	</br>
	<a href="session-example.php?clear=true">Clear session via link</a>
	</br>
	<br>
		<a href="session-example2.php">Go to session-example2 page</a><br><br>
</body>
</html>