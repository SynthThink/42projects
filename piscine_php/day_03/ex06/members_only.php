<?PHP
	if ($_SERVER['PHP_AUTH_USER'] == 'zaz' && $_SERVER['PHP_AUTH_PW'] == 'jaimelespetitsponeys')
	{
		echo "<html><body>\nBonjour Zaz<br />\n";
		echo "<img src='data:image/png;base64,".base64_encode(file_get_contents("../img/42.png"))."'>";
		echo "\n</body></html>\n";
	}
	else {
		header('WWW-Authenticate: Basic realm=\'\'Espace membres\'\'');
		header('HTTP/1.0 401 Unauthorized');
		$str = "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
		header("Content-length:83");
		header("Connection: close");
		header("Content-Type: text/html");
		echo($str);
	}
?>
