<?PHP
session_start();
$login = NULL;
if ($_SESSION['loggued_on_user'] != NULL)
		$login = key($_SESSION['loggued_on_user']);
if (!isset($_POST['filter_submit']))
{
    $_POST['filters_taille'] = array("petit", "moyen", "grand");
    $_POST['filters_race'] = array("Corgi", "Jack Russel", "Fox Terrier", "Border Collie", "Braque de Weimar", "Epagneul Breton");
}
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
				<form action="boutique.php" method="post">
				<H2>Catégories</H2><br />
				<?php
				include ("connect_db.php");
				$QUERY_CATEGORIES = "SELECT nom FROM categories WHERE filter = 1;";
				$menu_data = mysqli_query($dblink, $QUERY_CATEGORIES);
				$menu_array = array();
				if (mysqli_num_rows($menu_data) > 0)
					while($row = mysqli_fetch_assoc($menu_data))
							$menu_array[] = $row['nom'];
				foreach($menu_array as $cat)
				{
					echo ucfirst($cat)." de chien:<br />";
					$cat = mysqli_real_escape_string($dblink, $cat);
					$QUERY_SUBCATEGORIES = "SELECT DISTINCT $cat FROM chiens;";
					$submenu_data = mysqli_query($dblink, $QUERY_SUBCATEGORIES);
					$submenu_array = array();
					if (mysqli_num_rows($submenu_data) > 0)
					{
						while($row = mysqli_fetch_assoc($submenu_data))
						{
							$filter_name = "filters_".$cat."[]";
							$subname = ucfirst($row[$cat]);
							echo "<input type='checkbox' name='$filter_name' value='$row[$cat]' checked/>$subname<br />";
						}
					}
					echo "<br />";
				}
				?>
				<input type="submit" name="filter_submit" value="Filtrer" />
				</form>
			</div>
			<div class="body_bar">
			<?php
			if (!$dblink)
				echo "Veuillez nous excuser mais il n'y a pas de chiens correspondant a ces critères.";
			else {
				$data = array();
				$filter_taille = "('".implode("', '", $_POST[filters_taille])."')";
				$filter_race = "('".implode("', '", $_POST[filters_race])."')";
				$request = "SELECT race, taille, img, prix from chiens
				WHERE (taille in $filter_taille) AND (race IN $filter_race);";
				$res = mysqli_query($dblink, $request);
				if (mysqli_num_rows($res) > 0)
				{
					while($row = mysqli_fetch_assoc($res)) {
						$data[] = $row;
					}
				}
				if ($data == NULL)
					echo "Veuillez nous excuser mais il n'y a pas de chiens correspondant a ces critères.";
				foreach($data as $dog)
				{
					echo "<div style='margin-left:250px'>";
					echo "<H2>$dog[race]: $dog[prix] €</H2>";
					echo "<IMG width = 170px style='border-radius:50px' src=images/$dog[img] alt = '$dog[race]'/>";
					echo "<form action='ajout_panier.php' method='post'>";
					echo "<input type='hidden' name='chien' value='$dog[race]'><br/>";
					echo "<input style ='margin-left:45px' type='submit' name='submit' value='Adopte-moi !'/><br />";
					echo "</form></div>";
				}
			}
			?>
			</div>
			<?php
			include ("right_bar.php");
			?>
		</div>

	</ul>
	</nav>
</BODY>
</HTML>
