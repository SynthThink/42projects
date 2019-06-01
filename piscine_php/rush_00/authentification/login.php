<?PHP
function ft_error()
{
	$_SESSION['loggued_on_user'] = "";
	$_SESSION['login_failed'] = 1;
	header("Location: ../authentification/connexion.php");
}
include ("auth.php");
session_start();
if (isset($_POST['login']) && isset($_POST['passwd']) && strcmp($_POST['login'], "") != 0)
{
	if (auth($_POST['login'],$_POST['passwd']) == True)
	{
		$_SESSION['loggued_on_user'] = array($_POST['login'] => $_POST['passwd']);
		header("Location: ../index.php");
	}
	else
	{
		ft_error();
	}
}
else
	ft_error();
?>
