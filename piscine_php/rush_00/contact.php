<?PHP
session_start();
$login = NULL;
if ($_SESSION['loggued_on_user'] != NULL)
		$login = key($_SESSION['loggued_on_user']);
?>
<HTML>
<HEAD>
	<TITLE>Homepage</TITLE>
	<link rel="stylesheet" href="homepage.css">
</HEAD>
<BODY>
</div>
	<?PHP
	include ("header_site.php");
	?>
		<div style="visibility:hidden" class="left_bar">
		</div>
		<div class="body_bar">
		<span style="text-align:center">
			<H1> Nous contacter </H1>
		Vous hésitez dans le choix de votre futur compagnon ou vous souhaitez plus d'informations concernant un animal ?<br />
		Contactez-nous par téléphone nos conseillers de vente sont à votre disposition du lundi au vendredi de 8h00 à 21h00,<br />
		le samedi de 9h00 à 18h00 et les dimanches et jours fériés de 10h00 à 18h00 (sauf le 25 décembre et le 1er janvier).
		<br /><br /><br />
		Vous pouvez aussi nous contacter par mail à l'adresse suivante: <span style="font-style: bold;font-size:20px">doglovers@woufmail.com.</span>
		<br/><br /><br />
		<H2>A bientôt sur Doggo Land !</H2>
		<IMG style="margin-left:125px; border: 1px solid black; border-radius:50px" src="images/bye.jpg"/>
		</span>
		</div>
		<?php
		include ("right_bar.php");
		?>
	</div>
</ul>
</nav>
</BODY>
</HTML>
