<?PHP
session_start();
function error()
{
	$_SESSION['delete_failed'] = 1;
	header('Location: delete_page.php');
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
				if (strcmp($array['passwd'], $register['passwd']) == 0)
					return (1);
			}
		}
	}
	return (0);
}
if (isset($_POST) && $_POST['submit'] == "SUPPRIMER")
{
			$data = NULL;
			if (file_exists("../private/passwd"))
			{
				$data = file_get_contents("../private/passwd");
				$key = key($_SESSION['loggued_on_user']);
				$key_remove = "";
				$register = array("login" => $key, "passwd" => hash("whirlpool",($_SESSION['loggued_on_user'][$key])));
				if (verify_existing($data, $register) == 1)
				{
					$data = unserialize($data);
					foreach ($data as $key => $tab)
					{
						if (strcmp($tab['login'], $register['login']) == 0)
						{
							$key_remove = $key;
							break;
						}
					}
					if ($key_remove !== "")
					{
						unset($data[$key_remove]);
					}
					file_put_contents("../private/passwd", serialize($data));
					$_SESSION['loggued_on_user'] = 0;
					header('Location: ../index.php');
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
