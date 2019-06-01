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
		<div class="left_bar">
			<H2 style="text-align:center">Gestion panier</H2>
			<form action='cancel_panier.php' method='post'>
			<input style='margin-left:35px;font-size:30px;' type='submit' name='cancel_panier' value='Vider la panier'/><br />
			</form>
		</div>
		<div class="body_bar">
		<span style="text-align:center;">
		<?php
		include ("connect_db.php");
		$total = 0;
		echo "<H2>Votre panier</H2>";
		if (is_array($_SESSION['panier']))
		{
			$order = "";
			echo "<table style='margin-left:200px;' id='formulaire_panier'>";
			echo "<tr><th>Nom du chien</th><th>Quantite</th><th>Prix</th><tr/>";
			foreach($_SESSION['panier'] as $key => $item)
			{
				$filter = mysqli_real_escape_string($dblink, $key);
				$request = "SELECT id, prix FROM chiens WHERE race = '$filter';";
				$res = mysqli_query($dblink, $request);
				if (mysqli_num_rows($res) > 0)
				{
					$row = mysqli_fetch_assoc($res);
					$prix = $row['prix'] * $item;
					$order[] = array("id" => $row['id'], "race" => $key, "nb" => $item, "prix" => $row['prix']);
				}
				else
					$prix = "1";
				echo "<tr><td class=cases>$key</td><td class=cases>$item</td><td class=cases>$prix €</td><tr/>";
				$total += $prix;
			}
			echo "<tr><td style='background:None;'></td><td class=cases style='border-radius:50px'>Total</td><td class=cases style='border-radius:50px'>$total €</td><tr/>";
			echo "</table>";
			$order = serialize($order);
			echo "<form action='archive_order.php' method='post'>";
			echo "<input type='hidden' name='order' value='$order'><br/>";
			echo "<input style='margin-left:35px;font-size:30px;' type='submit' name='submit' value='Commander'/><br />";
			echo "</form>";
		}
		else
		{
			echo "Votre panier est vide.<br /> Allez dans la rubrique 'Adopte un ami' pour commander.";
		}
		?>
		</span>
		<br /> <br /> <br /> <br />
		<IMG style="margin-left:225px; border: 1px solid black; border-radius:50px;width:300px;"  src="images/caddie.jpg"/>
		</div>
		<?php
		include ("right_bar.php");
		?>
	</div>
</ul>
</nav>
</BODY>
</HTML>
