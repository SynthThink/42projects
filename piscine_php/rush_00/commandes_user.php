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
		<span style="text-align:center;">
		<?php
		echo "<H2>Vos commandes</H2>";
		include ("connect_db.php");
		$login_verif = mysqli_real_escape_string($dblink, $login);
		$request = "SELECT * FROM orders WHERE client = '$login_verif';";
		$res = mysqli_query($dblink, $request);
		if (mysqli_num_rows($res) > 0)
		{
			while ($row = mysqli_fetch_assoc($res))
			{
				echo "<table style='margin-left:130px;'>";
				echo "<tr><th>N' de commande</th><th>Chien</th><th>Quantité</th><th>Prix</th><tr/>";
				$id_order = $row['id_order'];
				$total = 0;
				foreach ($row as $key => $field)
				{
					if (substr($key, 0, 5) == "nb_id" && $field > 0)
					{
						$id = mysqli_real_escape_string($dblink, substr($key, 5, 4));
							$ITEM_QUERY = "SELECT race, prix FROM chiens WHERE id = $id";
						$item_result = mysqli_query($dblink, $ITEM_QUERY);
						$item = mysqli_fetch_assoc($item_result);
						$total += $item[prix] * $field;
						echo "<tr><td class=cases>$id_order</td><td class=cases>$item[race]</td><td class=cases>$field</td><td class=cases>$item[prix] €</td><tr/>";
					}
				}
				echo "<tr><td style='background:None;'></td><td style='background:None;'></td><td class=cases style = 'border-radius:50px'>Total</td><td class=cases style = 'border-radius:50px'>$total €</td><tr/>";
				echo "</table>";
				echo "<br \>";
			}
		}
		else
			echo "<p style='text-align:center;'>Vous n'avez effectué aucune commande. <br />Pour valider une commande veuillez accéder a votre panier.</p>";
		?>
		</span>
		<br /> <br /> <br /> <br />
		</div>
		<?php
		include ("right_bar.php");
		?>
	</div>
</ul>
</nav>
</BODY>
</HTML>
