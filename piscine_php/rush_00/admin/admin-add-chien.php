<?PHP
if ($_POST['submit'] == "Envoyer")
{
	session_start();
	if ((isset($_POST['race']) && $_POST['race'] != NULL) &&
	  (isset($_POST['prix']) && $_POST['prix'] != NULL) &&
	  (isset($_POST['taille']) && $_POST['taille'] != NULL) &&
	  (isset($_POST['image']) && $_POST['image'] != NULL))
	  {
			include ("../connect_db.php");
		  	if ($dblink == NULL)
		  	{
		  		$_SESSION['flagcreation'] = "ko";
		  	}
			else
			{
				$race = mysqli_real_escape_string($dblink, $_POST['race']);
				$prix = mysqli_real_escape_string($dblink, $_POST['prix']);
				$taille = mysqli_real_escape_string($dblink, $_POST['taille']);
				$image = mysqli_real_escape_string($dblink, $_POST['image']);
				$ADD_QUERY = "
				INSERT INTO chiens (race, taille, img, prix)
				VALUES
				('$race','$taille','$image','$prix');";
				$res = mysqli_query($dblink, $ADD_QUERY);
				if ($res == False)
				{
					$_SESSION['flagcreation'] = "ko";
				}
				else
					$_SESSION['flagcreation'] = "ok";
				$GET_ID_QUERY = "
				SELECT id FROM chiens
				WHERE race='$race' and taille='$taille' and img='$image' and prix='$prix';";
				$res = mysqli_query($dblink, $GET_ID_QUERY);
				if (mysqli_num_rows($res) > 0)
				{
					$row = mysqli_fetch_assoc($res);
					$new_filed = "nb_id"."$row[id]";
				}
				$MODIF_QUERY = "
				ALTER TABLE orders
				ADD $new_filed INT DEFAULT 0 NOT NULL;";
				$res = mysqli_query($dblink, $MODIF_QUERY);
				header('Location: admin-products.php');
			}
			header('Location: admin-products.php');
	  }
	  else
	  {
	    $_SESSION['flagchamps'] = "ko";
	    header('Location: admin-products.php');
	  }
}
?>
