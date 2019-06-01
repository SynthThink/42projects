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
		<div style="margin-left:210px;"class="body_bar">
		<a href="admin.php" class="admin-users">Retourner à la liste</a><br/><br/>
	    <h2>Liste des utilisateurs</h2>
		    <?PHP
			    $path = "../private";
			    $file = $path."/passwd";
			    if (!file_exists($file))
			    {
			      echo "<p>Aucun utilisateur n'est inscrit actuellement</p>";
			    }
			    else
			    {
					$unserialized = unserialize(file_get_contents($file));
					echo "<table>";
					echo "<tr><th>Identifiant</th></tr>";
					foreach ($unserialized as $elem)
					echo "<tr><td>".$elem['login']."</td></tr>";
					echo "</table>";
				}
			?>
	    <br/>
	    <h2>Ajouter un utilisateur</h2>
		    <div id="add-user">
		      <p> Veuillez remplir le formulaire. Tous les champs sont obligatoires</p>
		    <form method="post" action="admin-add.php">
		      Identifiant : <input type="text" name="login"/><br /><br />
		      Mot de passe : <input type="password" name="passwd1"/><br /><br />
		      Répéter le mot de passe : <input type="password" name="passwd2"/><br /><br />
		    	<input type="submit" name = "submit" value="Envoyer" />
		    </form>
		    </div>
		    <?php
		      if ($_SESSION['flagchamps'] == "ko")
		      {
		        echo "<p id='error'>Erreur : vous devez remplir tous les champs\n</p>";
		        $_SESSION['flagchamps'] = NULL;
		      }
		      else if ($_SESSION['flagmail'] == "ko")
		      {
		    	  echo "<p id='error'>Erreur : un compte existe déjà avec cet Identifiant\n</p>";
		        $_SESSION['flagmail'] = NULL;
		      }
		      else if ($_SESSION['flagpasswd'] == "ko")
		      {
		    	  echo "<p id='error'>Erreur : veuillez recopier votre mot de passe a l'identique\n</p>";
		        $_SESSION['flagpasswd'] = NULL;
		      }
		      else if ($_SESSION['flagcreation'] == "ok")
		        {
		          echo "<div id='inscription-ok'>Inscription terminée !</div>";
		          $_SESSION['flagcreation'] = NULL;
		        }
		    ?>

		<br/><h2>Modifier un utilisateur</h2>
	 	<p>Entrez l'identifiant de l'utilisateur que vous souhaitez modifier,
	      etles modifications que vous souhaitez apporter:</p>
		<form method="post" action="admin-modif-users.php">
		<p>Vous devez remplir tous les champs, si vous ne souhaitez pas modifier un element, renseignez l'ancien element a la place.</p>
	      Identifiant de l'utilisateur : <input type="text" name="login"/><br/><br/>
	      Nouvel Identifiant de l'utilisateur : <input type="text" name="newmail"/><br/><br/>
	        <input type="submit" name = "submit" value="OK" />
	    </form>
			 <?php
			      if ($_SESSION['flag_modif_users'] == "KO")
			      {
			        echo "<p id='error'>Les informations renseignees sont incorrectes\n</p>";
					$_SESSION['flag_modif_users'] = "";
					unset($_SESSION['flag_modif_users']);
				  }
				  else if ($_SESSION['flag_modif_users'] == "KO-OK") //a virer
			      {
			        echo "<p id='error'>bllaaaaaaaaaaaaaaaaaaaaaaaaaaague\n</p>";
					$_SESSION['flag_modif_users'] = "";
					unset($_SESSION['flag_modif_users']);
				  }
				 else if ($_SESSION['flag_modif_users'] == "OK")
			      {
			          echo "<div id='inscription-ok'>La modification a bien ete apportee a l'utilisateur</div>";
					$_SESSION['flag_modif_users'] = "";
					unset($_SESSION['flag_modif_users']);
			      }

			    ?>
	    <br/><h2>Supprimer un utilisateur</h2>
	    <p>Entrez l'identifiant de l'utilisateur que vous souhaitez supprimer :</p>
		    <form method="post" action="admin-delete.php">
		      Identifiant: <input type="text" name="Identifiant"/>
		      <input type="submit" name = "submit" value="Envoyer" />
		    </form>
		    <?php
		    if ($_SESSION['no-user-to-delete'] == "ko")
		    {
		      echo "<p id='error'>Erreur : aucun utilisateur présent dans la base de données</p>";
		      $_SESSION['no-user-to-delete'] = "";
		    }
		    else {

		      if ($_SESSION['flag_suppression_user'] == "ok")
		      {
		        echo "<p id='inscription-ok'>Utilisateur supprimé</p>";
		        $_SESSION['flag_suppression_user'] = "";
		      }
		      else if ($_SESSION['flag_suppression_user'] == "ko")
		      {
		        echo "<p id='error'>Erreur : aucun utilisateur trouvé avec cet Identifiant</p>";
		        $_SESSION['flag_suppression_user'] = "";
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
</html>
