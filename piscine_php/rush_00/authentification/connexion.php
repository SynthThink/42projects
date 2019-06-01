<?php
session_start();
?>
<html>
<HEAD>
	<TITLE>Connexion</TITLE>
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
					<form action = "login.php" method = "post">
						<H2>Identifiez-vous</H2>
						Identifiant: <input name="login" value="" />
						<br />
						Mot de passe: <input name="passwd" value="" />
						<input type="submit" name="submit" value="OK" />
					</form>
					<?php
					if ($_SESSION['login_failed'] == 1)
					{
						echo "<p>Aucun compte ne corresponds a ces identifiants.</p></br>";
						$_SESSION['login_failed'] = 0;
					}
					?>
					<a style="text-align:center" href="create_page.php">Créer un compte</a> <br />
					<a style="text-align:center" href="modif_page.php">Modifier mot de passe</a><br />
			</div>
	</div>
</ul>
</body>
</html>
