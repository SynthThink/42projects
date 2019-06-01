<?PHP
include ("auth.php");
session_start();
if (isset($_GET['login']) && isset($_GET['passwd']) && $_GET['login'] != "")
{
	if (auth($_GET['login'],$_GET['passwd']) == True)
	{
		echo "OK\n";
		$_SESSION['loggued_on_user'] = array($_GET['login'] => $_GET['passwd']);
	}
	else
	{
		echo "ERROR\n";
		$_SESSION['loggued_on_user'] = "";
	}
}
else
	echo "ERROR\n";
?>
