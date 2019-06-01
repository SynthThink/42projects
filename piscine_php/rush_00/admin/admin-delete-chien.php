<?PHP
if ($_POST['submit'] == "Envoyer")
{
	session_start();
	include ("../connect_db.php");
	if ($dblink == NULL)
	{
		$_SESSION['no-chien-to-delete'] = "ko";
	}
	else
	{
		$id_del = mysqli_real_escape_string($dblink, $_POST['id']);
		$DELETE_QUERY = "DELETE FROM chiens WHERE id = $id_del;";
		$res = mysqli_query($dblink, $DELETE_QUERY);
		if ($res == False)
		{
			$_SESSION['no-chien-to-delete'] = "ko";
		}
		else
			$_SESSION['flag_suppression_chien'] = "ok";
		header('Location: admin-products.php');
	}
	header('Location: admin-products.php');
}
?>
