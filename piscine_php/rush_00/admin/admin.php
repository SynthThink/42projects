<?PHP
session_start();
$login = NULL;
if ($_SESSION['loggued_on_user'] != NULL)
{
		$login = key($_SESSION['loggued_on_user']);
		if ($login != "admin")
			header("Location: ../index.php");
}
?>
<HTML>
<HEAD>
	<TITLE>Panneau d'administration</TITLE>
	<link rel="stylesheet" href="../homepage.css">
</HEAD>
<BODY>
	<?PHP
	include ("header_site_admin.php");
	?>
		<div style="visibility:hidden" class="left_bar">
		</div>
		<div class="body_bar">
			<H2>Bienvenue Administrateur</H2>
			Actions autorisees:
			<ul>
	  	    <li><a href="admin-users.php">Ajouter - Modifier - Supprimer : un utilisateur</a></li>
	  	    <li><a href="admin-products.php">Ajouter - Modifier - Supprimer : un chien</a></li>
	  	  <ul>
		</span>
		</div>
	<?php
	include ("right_bar_admin.php");
	?>
	</div>
</ul>
</nav>
</BODY>
</HTML>
