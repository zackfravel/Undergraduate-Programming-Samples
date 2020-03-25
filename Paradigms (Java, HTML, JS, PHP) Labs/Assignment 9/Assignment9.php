<html>
<body>
<?php
	if($_REQUEST==null)
	{
		echo "<title>Assignment 9: no query string</title>";
		echo "Hello world!</br>Zack Fravel's assignment 9.</br>The query string is null.";
		phpinfo();
	}else{
		echo "<title>Assignment 9: with a query string</title>";
		echo "Hello world!</br>Zack Fravel's assignment 9.</br>The query string is ";
		echo var_dump($_REQUEST);
		phpinfo();
	}

?>
</body>
</html>