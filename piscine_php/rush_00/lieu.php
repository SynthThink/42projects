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
			<H1> Le lieu </H1>
		<H2>Élevage familiale</H2>
		Nous sommes éleveurs professionnels et responsables, en élevage familial, titulaire du certificat de capacité n° 23012, notre chenil et nos installations d’élevage sont classés en préfecture de la Creuse.
		Nous produisons 25 à 45 chiots par an. Il est fortement conseillé de prévoir vos réservations avant, car nos chiots ne sont pas longtemps disponibles à la vente.
		Notre élevage est ouvert aux visites de préférence sur rendez-vous pour vous faire découvrir nos petits loups.
		<br /><br />
		Nous nous situons sur la commune de Bonnat en Creuse, région nouvelle Aquitaine, proche de Limoges, Montluçon et Châteauroux. Pratiquement et idéalement situé au centre de la France.
		<br /><br /><br />
		<IMG style="margin-left:125px; border: 1px solid black; border-radius:50px;width: 500px;" src="images/chenil.jpg"/>
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
