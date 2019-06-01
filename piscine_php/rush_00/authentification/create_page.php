<?php
session_start();
?>
<html>
<HEAD>
	<TITLE>Création d'un compte</TITLE>
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
				<H2>Créez votre compte</H2>
				<form action = "create.php" method = "post">
					Identifiant: <input name="login" value="" />
					<br />
					Mot de passe: <input name="passwd" value="" />
					<input type="submit" name="submit" value="OK" />
					<br />
					<?php
					if ($_SESSION['login_already_exist'] == 1)
					{
						echo "<p>Cet identifiant existe deja merci de choisir autre chose.</p>";
						$_SESSION['login_already_exist'] = 0;
					}
					else if ($_SESSION['form_not_set'] == 1)
					{
						echo "<p>Merci de saisir des informations valides.</p>";
						$_SESSION['form_not_set'] = 0;
					}
					?>
					<br /><a href="connexion.php">Se connecter</a><br /><br />
				</form>
			</div>
	</div>
</ul>
</body>
</html>
