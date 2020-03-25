<html>
<body>
<title>Zack Fravel</title>

<?php
	if(isset($_REQUEST['answer']) && $_REQUEST['guess'] == $_REQUEST['answer'])
	{
?>
	You Got it!
<?php
	}
	else if(isset($_REQUEST['answer']) && $_REQUEST['guess'] != $_REQUEST['answer'])
	{
?>
	Try Again.
	<form name="numForm" action="Assignment10.php" method="post">
		Your Guess: <input type="text" name="guess"><input type="submit"></br>
		<input type="hidden" name="answer" value="<?php 
			if(!(isset($_REQUEST['answer'])))
			{
				echo($answer);
			}else{
				echo($_REQUEST['answer']);
			}
		?>">
	</form>
<?php
	}
	else if(isset($_GET["fname"]))
	{
		echo("Hi, ");
		echo($_GET["fname"]);
		echo(" ");
		echo($_GET["lname"]);
		echo("!");
		$answer = mt_rand(1,5);
?>

	</br>
	</br>
	Guess a number between 1 and 5!</br></br>
	<form name="numForm" action="Assignment10.php" method="post">
		Your Guess: <input type="text" name="guess"><input type="submit"></br>
		<input type="hidden" name="answer" value="<?php 
			if(!(isset($_REQUEST['answer'])))
			{
				echo($answer);
			}else{
				echo($_REQUEST['answer']);
			}
		?>">
	</form>

<?php
	}else{
?>
	<h1>Zack Fravel's Assignment 10</h1>
	Please fill out the form below.</br></br>
	<form name="infoForm" action="Assignment10.php" method="get" onsubmit="return validateForm();">
		First name: <input type="text" name="fname" value="Zack"></br>
		Last name: <input type="text" name="lname" value="Fravel"></br>
		Email Address: <input type="text" name="email" value="zpfravel@uark.edu"></br>
		<input type="submit">
	</form>

<?php
	}
?>

<script>
function validateForm()
{
	var a = document.forms["infoForm"]["fname"].value
	var b = document.forms["infoForm"]["lname"].value
	var c = document.forms["infoForm"]["email"].value

	console.log("Validating Form");

	if(a == "" || b == "" || c == ""){
		alert("Empty Form is Invalid!");
		return false;
	}

	if(c.indexOf("@") == -1)
	{
		alert("No '@' in email address!");
		return false;
	}

	if(c.indexOf(".") == -1)
	{
		alert("No '.' in email address!");
		return false;
	}

	console.log("first name: " + a);
	console.log("last name: " + b);
	console.log("email: " + c);
}
</script>



</body>
</html>