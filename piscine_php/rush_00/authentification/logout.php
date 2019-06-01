<?PHP
session_start();
if (isset($_SESSION))
{
	$_SESSION['loggued_on_user'] = NULL;
	header("refresh:3;url=../index.php");
}
?>
<html>
<HEAD>
	<TITLE>Deconnexion</TITLE>
	<link rel="stylesheet" href="connexion.css">
</HEAD>
<body>
	<span style='color:black;font-size:28px;'>Vous avez été déconnecté, vous serez redirigé vers la <a style='color:blue; text-decoration: underline;font-size:32px;' href='../index.php'>page d'accueil</a> dans 3 secondes...</span>
</body>
</html>
