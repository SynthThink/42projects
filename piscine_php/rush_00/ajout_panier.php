<?PHP
session_start();
if (!isset($_SESSION['panier']))
	$_SESSION['panier'] = array();

$_SESSION['panier'][$_POST['chien']] += 1;
header('Location: ../boutique.php');
?>
