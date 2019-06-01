<?php
session_start();
?>
<html>
<HEAD>
	<TITLE>Suppression d'un compte</TITLE>
	<link rel="stylesheet" href="connexion.css">
</HEAD>
<body>
	<ul>
		<div class="content_mid">
		<IMG class="banniere" src="../images/banner.jpg"/>
			<div class="menu_bar">
				<li class="menu"><a href="../index.php" >Accueil</a></li>
				</li>
			</div>
			<div class="body_bar">
				<H2>Suppression du compte</H2>
				<form action = "../authentification/delete.php" method = "post">
					Etes vous sur de vouloir supprimer votre compte ?
					<br/><br/>
					<input type="submit" name="submit" value="SUPPRIMER" />
				</form>
			</div>
	</div>
</ul>
</body>
</html>
