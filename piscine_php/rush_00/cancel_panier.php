<?PHP
session_start();
if (isset($_SESSION))
{
	$_SESSION['panier'] = NULL;
	header("location: panier.php");
}
?>
