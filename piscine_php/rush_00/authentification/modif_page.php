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
				<H2>Modification du mot de passe</H2>
				<form action = "modif.php" method = "post">
					Identifiant: <input name="login" value="" />
					<br />
					Ancien mot de passe: <input name="oldpw" value="" />
					<br />
					Nouveau mot de passe: <input name="newpw" value="" />
					<input type="submit" name="submit" value="OK" />
				</form>
				<?php
				if ($_SESSION['modification_failed'] == 1)
				{
					echo "<p>We cannot find an account with that login and password</p></br>";
					$_SESSION['modification_failed'] = 0;
				}
				?>
				<br /><a href="connexion.php">Se connecter</a><br /><br />
				</form>
			</div>
	</div>
</ul>
</body>
</html>
