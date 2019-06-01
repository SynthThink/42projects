<?PHP session_start(); ?>
<?PHP


if ($_POST['login'] != "" && $_POST['login'] != "admin"
	&& $_POST['submit'] == "OK")
{

		$crypt = file_get_contents("../private/passwd");
		$un_crypt = unserialize($crypt);
		$i = 0;

		foreach ($un_crypt as $elem)
		{
			if ($elem['login'] == $_POST['login'])
			{
				$un_crypt[$i]['login'] = $_POST['newmail'];
				$crypt = serialize($un_crypt);
				file_put_contents("../private/passwd", $crypt);
				$_SESSION['flag_modif_users'] = "OK";
				echo "<meta http-equiv='refresh' content='0,url=admin-users.php'>";
			}
			$i++;
		}
		$crypt = serialize($un_crypt);
		file_put_contents("../private/passwd", $crypt);
		if ($_SESSION['flag_modif_users'] != "OK")
			$_SESSION['flag_modif_users'] = "KO";
		echo "<meta http-equiv='refresh' content='0,url=admin-users.php'>";

}
else
{
	$_SESSION['flag_modif_users'] = "KO";
	echo "<meta http-equiv='refresh' content='0,url=admin-users.php'>";
}
?>
