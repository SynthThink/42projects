<?PHP
if (!isset($_POST['order']) || $_POST['order'] == "")
	header('Location: ../panier.php');
session_start();
$array = unserialize($_POST['order']);
$commande = array();
$cats = "(client, ";
include ("connect_db.php");
$login = '"'.mysqli_real_escape_string($dblink, key($_SESSION['loggued_on_user'])).'"';
$contents = "(".$login.", ";
$c = 0;
foreach($array as $article)
{
	if ($c != 0)
	{
		$cats .=", ";
		$contents .= ", ";
	}
	$cats .= "nb_id".$article['id'];
	$contents .= $article['nb'];
	$c++;
}
$cats .= ")";
$contents .= ")";
$cats = mysqli_real_escape_string($dblink, $cats);
$INSERT_ORDER = "
	INSERT INTO orders $cats
	VALUES
	$contents;";
$result = mysqli_query($dblink, $INSERT_ORDER);
header("refresh:4;url=index.php");
?>
<html>
<HEAD>
	<TITLE>Enregistrement commande</TITLE>
	<link rel="stylesheet" href="homepage.css">
</HEAD>
<body>
	<?php
	if ($result == FALSE)
		echo "<span style='color:black;font-size:28px;'>Veuillez nous excuser mais un probleme technique a eu lieu, veuillez attendre quelques minutes et recommencer. Vous serez redirigé vers la <a style='color:blue; text-decoration: underline;font-size:32px;' href='../index.php'>page d'accueil</a> dans 3 secondes...</span>";
	else
	{
		echo "<span style='color:black;font-size:28px;'>Votre commande a bien été enregistrée, vous allez etre redirigé vers la <a style='color:blue; text-decoration: underline;font-size:32px;' href='../index.php'>page d'accueil</a> dans 3 secondes...</span>";
		$_SESSION['panier'] = NULL;
	}
	 ?>

</body>
</html>
