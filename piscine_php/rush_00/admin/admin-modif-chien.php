<?PHP
if ($_POST['submit'] == "Envoyer")
{
	session_start();
	if ((isset($_POST['id']) && $_POST['id'] != NULL) &&
	(isset($_POST['race']) && $_POST['race'] != NULL) &&
	  (isset($_POST['prix']) && $_POST['prix'] != NULL) &&
	  (isset($_POST['taille']) && $_POST['taille'] != NULL) &&
	  (isset($_POST['image']) && $_POST['image'] != NULL))
	  {
			include ("../connect_db.php");
		  	if ($dblink == NULL)
		  	{
		  		$_SESSION['flag_modif_chien'] = "ko";
		  	}
			else
			{
				$id_dog = mysqli_real_escape_string($dblink, $_POST['id']);
				$race = mysqli_real_escape_string($dblink, $_POST['race']);
				$prix = mysqli_real_escape_string($dblink, $_POST['prix']);
				$taille = mysqli_real_escape_string($dblink, $_POST['taille']);
				$image = mysqli_real_escape_string($dblink, $_POST['image']);
				$MODIF_QUERY = "
				UPDATE chiens
				SET race='$race', taille='$taille',img='$image',prix='$prix'
				WHERE id=$id_dog;";
				$res = mysqli_query($dblink, $MODIF_QUERY);
				if ($res == False)
					$_SESSION['flag_modif_chien'] = "ko";
				else
					$_SESSION['flag_modif_chien'] = "ok";
				header('Location: admin-products.php');
			}
			header('Location: admin-products.php');
	  }
	  else
	  {
	    $_SESSION['flag_modif_chien'] = "ko";
	    header('Location: admin-products.php');
	  }
}
?>
