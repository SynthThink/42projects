<?PHP
include ("auth.php");
session_start();
if (isset($_POST['login']) && isset($_POST['passwd']) && $_POST['login'] != "")
{
	if (auth($_POST['login'],$_POST['passwd']) == True)
	{
		$_SESSION['loggued_on_user'] = array($_POST['login'] => $_POST['passwd']);
		echo "<iframe name=\"chat\" src=\"chat.php\" width=\"100%\" height=550px style=\"border:2px solid black\"></iframe><br/>\n";
		echo "<iframe name=\"speak\" src=\"speak.php\" width=\"100%\" height=50px style=\"border:2px solid black\"></iframe>\n";
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
