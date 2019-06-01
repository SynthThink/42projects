<?PHP
session_start();
$login = NULL;
if ($_SESSION['loggued_on_user'] != NULL)
{
		$login = key($_SESSION['loggued_on_user']);
		if ($login != "admin")
			header("Location: ../index.php");
}
?>
<HTML>
<HEAD>
	<TITLE>Panneau d'administration: Utilisateurs</TITLE>
	<link rel="stylesheet" href="../homepage.css">
</HEAD>
<body>
	<?PHP
	include ("header_site_admin.php");
	?>
  <div style="margin-left:210px;"class="body_bar"	>
    <br/>
    <a href="admin.php" class="admin-users">Retourner à la liste</a><br/><br/>
    <h2>Liste des chiens disponibles</h2>
	    <?PHP
		include ("../connect_db.php");
		echo "<table style='margin-left:100px;' id='formulaire_panier'>";
		echo "<tr><th>Id</th><th>Race du chien</th><th>Taille</th><th>Image</th><th>Prix</th><tr/>";
		$request = "SELECT id,race,taille,img,prix FROM chiens;";
		$res = mysqli_query($dblink, $request);
		if (mysqli_num_rows($res) > 0)
		{
			while ($row = mysqli_fetch_assoc($res))
				echo "<tr><td class=cases>$row[id]</td><td class=cases>$row[race]</td><td class=cases>$row[taille]</td><td class=cases>$row[img]</td><td>$row[prix] €</td><tr/>";
		}
		echo "</table>";
	    ?>
    <br/>
    <h2>Ajouter un chien</h2>
    <div id="add-user">
      <p> Veuillez indiquer le chien à rajouter :</p>
      <br/>
      <form method="post" action="admin-add-chien.php">
        Race : <input type="text" name="race"/><br/><br/>
        Prix : <input type="text" name="prix"/><br/><br/>
        Taille : <input type="text" name="taille"/><br/><br/>
        Chemin image : <input type="text" name="image"/><br/><br/>
        <input type="submit" name = "submit" value="Envoyer" />
      </form>
    </div>
	    <?php
	    if ($_SESSION['flagchamps'] == "ko")
	    {
	      echo "<p id='error'>Erreur : vous devez remplir tous les champs\n</p>";
	      $_SESSION['flagchamps'] = NULL;
	    }
	    else if ($_SESSION['flagcreation'] == "ok")
	    {
	      echo "<div id='inscription-ok'>Félicitation ! Un nouveau chien a été ajouté!</div>";
	      $_SESSION['flagcreation'] = NULL;
	    }
	    ?>
    <br/><h2>Modifier un chien</h2>
    <p>Entrez l'identifiant du chien que vous souhaitez modifier,
      ainsi que les modifications que vous souhaitez apporter :</p><br/>
    <form method="post" action="admin-modif-chien.php">
      Identifiant du chien : <input type="text" name="id"/><br/><br/>
      Race : <input type="text" name="race"/><br/><br/>
      Prix : <input type="text" name="prix"/><br/><br/>
      Taille : <input type="text" name="taille"/><br/><br/>
	  Chemin image : <input type="text" name="image"/><br/><br/>
      <input type="submit" name = "submit" value="Envoyer" />
    </form>

		<?PHP
		if ($_SESSION['flag_modif_chien'] == "ko")
		{
		  echo "<p id='error'>Erreur : aucun chien trouvé avec cet identifiant</p>";
		  $_SESSION['flag_modif_chien'] = "";
		}
		else if ($_SESSION['flag_champs_modif_chien'] == "ko")
		{
		  echo "<p id='error'>Erreur : Vous devez remplir tous les champs !</p>";
		  $_SESSION['flag_champs_modif_chien'] = "";
		}
		else if ($_SESSION['flag_modif_chien'] == "ok")
		{
		  echo "<p id='inscription-ok'>Votre chien a bien été modifié !</p>";
		  $_SESSION['flag_modif_chien'] = "";
		}
		?>
    <br/><h2>Supprimer un chien</h2>
    <p>Entrez l'identifiant du chien que vous souhaitez supprimer :</p><br/>
    <form method="post" action="admin-delete-chien.php">
      Identifiant du chien : <input type="text" name="id"/>
      <input type="submit" name = "submit" value="Envoyer" />
    </form>
    <?php
    if ($_SESSION['no-chien-to-delete'] == "ko")
    {
      echo "<p id='error'>Erreur : aucun chien présent dans la base de données</p>";
      $_SESSION['no-chien-to-delete'] = "";
    }
    else {
      if ($_SESSION['flag_suppression_chien'] == "ok")
      {
        echo "<p id='inscription-ok'>Adieu le chien !</p>";
        $_SESSION['flag_suppression_chien'] = "";
      }
      else if ($_SESSION['flag_suppression_chien'] == "ko")
      {
        echo "<p id='error'>Erreur : aucun chien trouvé avec cet identifiant</p>";
        $_SESSION['flag_suppression_chien'] = "";
      }
    }
    ?>
  </div>
  <?php
	include ("right_bar_admin.php");
	?>
</div>
  </ul>
</nav>

</body>
<br/><br/><br/>

<footer>
</footer>
</html>
