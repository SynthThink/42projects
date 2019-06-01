<?PHP
if ($_GET['action'] ==  "set")
	setcookie($_GET['name'], $_GET['value']);
else if ($_GET['action'] == "get")
{
	if (isset($_COOKIE[$_GET['name']]))
		echo($_COOKIE[$_GET['name']])."\n";
}
else if ($_GET['action'] == "del")
{
	setcookie($_GET['name'], NULL, time() - 3600);
}
?>
