<?PHP
session_start();
function error()
{
	$_SESSION['modification_failed'] = 1;
	header('Location: ../modif_page.php');
}
function verify_existing($data, $register)
{
	if ($data != NULL)
	{
		$data = unserialize($data);
		foreach($data as $array)
		{
			if (strcmp($array['login'], $register['login']) == 0)
			{
				if (strcmp($array['passwd'], $register['oldpw']) == 0)
					return (1);
			}
		}
	}
	return (0);
}
if (isset($_POST))
{
		if (strcmp($_POST['submit'], "OK") == 0 && strcmp($_POST['login'], "") != 0
			&& strcmp($_POST['oldpw'], "") && strcmp($_POST['newpw'], "") != 0)
		{
			$register = array("login" => $_POST['login'], "oldpw" => hash("whirlpool", $_POST['oldpw']), "newpw" => hash("whirlpool", $_POST['newpw']));
			$data = NULL;
			if (file_exists("../private/passwd"))
			{
				$data = file_get_contents("../private/passwd");
				if (verify_existing($data, $register) == 1)
				{
					$data = unserialize($data);
					$key_modif = NULL;
					foreach ($data as $key => $tab)
					{
						if (strcmp($tab['login'], $register['login']) == 0)
						{
							$key_modif = $key;
							break;
						}
					}
					$data[$key]['passwd'] = $register['newpw'];
					file_put_contents("../private/passwd", serialize($data));
					$_SESSION['modification_failed'] = 0;
					header('Location: ../authentification/connexion.php');
				}
				else
					error();
			}
			else
				error();
		}
		else
			error();
}
else
	error();
?>
