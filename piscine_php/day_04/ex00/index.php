<?PHP
session_start();
$login = "";
$passwd = "";

if (isset($_GET['submit']))
{
	$_SESSION['save_login'] = $_GET['login'];
	$_SESSION['save_passwd'] = $_GET['passwd'];
}

if (isset($_SESSION))
{
	if (isset($_SESSION['save_login']))
		$login = $_SESSION['save_login'];
	if (isset($_SESSION['save_passwd']))
		$passwd = $_SESSION['save_passwd'];
}
?>

<html><body>
<form action = "index.php" method = "get">
	Identifiant: <input name="login" value="<?PHP echo $login?>" />
	<br />
	Mot de passe: <input name="passwd" value="<?PHP echo $passwd?>" />
	<input type="submit" name="submit" value="OK" />
</form>
</body></html>
