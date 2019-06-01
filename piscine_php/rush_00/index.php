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
	<?PHP
	include ("header_site.php");
	?>
		<div style="visibility:hidden" class="left_bar">
		</div>
		<div class="body_bar">
		<span style="text-align:center">
			<H1> Bienvenu sur Doggo Land !</H1><br />
			<div style="text-align: center">Le site numero UN de l'adoption en ligne de chiens !
			<br />
			<br /> Ci-dessous quelqu'uns de nos chers compagnons qui n'attendent que toi:</div>
			<br /><br />
			<IMG style="margin-left:190px; border-radius:50px;" width = 120px src="images/corgi.jpg"/>
			<IMG style="border-radius:50px;" width = 120px src="images/epagneul.jpg"/>
			<IMG style="border-radius:50px;" width = 120px src="images/fox_terrier.jpg"/>
			<br /><br /><br />
			<IMG style="margin-left:180px" width = 400px src="images/welcome.jpg"/>
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
