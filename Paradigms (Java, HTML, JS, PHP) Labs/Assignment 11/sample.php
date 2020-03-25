<?php

function getNames() {
	$file = fopen("input.txt", "r") or exit("Unable to open file!");
	while (!feof($file)) {
		$line = fgets($file);
		$line = trim($line);
		if (strlen($line) > 0) {
			$arr = explode(";", $line);
			echo "Username: " . $arr[0] . ", full name: " . $arr[2] . "</br>";
		}
	}
}

?>

<html>
<body>
	<h1>File reading example</h1>

<?php
	getNames();

?>
</body>
</html>