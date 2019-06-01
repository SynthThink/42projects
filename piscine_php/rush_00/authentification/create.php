<?PHP
session_start();
function verify_existing($data, $register)
{
	if ($data != NULL)
	{
		$data = unserialize($data);
		foreach($data as $array)
		{
			if (strcmp($array['login'], $register['login']) == 0)
				return (1);
		}
	}
	return (0);
}
function ft_error($var_to_set)
{
	$_SESSION[$var_to_set] = 1;
	header('Location: ../authentification/create_page.php');
}
if (isset($_POST))
{
		if (strcmp($_POST['submit'], "OK") == 0 && strcmp($_POST['login'], "") != 0
			&& strcmp($_POST['passwd'], "") != 0)
		{
			$path = "../private/passwd";
			$register = array("login" => $_POST['login'], "passwd" => hash("whirlpool", $_POST['passwd']));
			$data = NULL;
			if (file_exists($path))
			{
				$data = file_get_contents($path);
				if (verify_existing($data, $register) == 0)
				{
					$data = unserialize($data);
					$data[] = $register;
					file_put_contents($path, serialize($data));
					$_SESSION['login_already_exist'] = NULL;
					header('Location: ../authentification/connexion.php');
					echo "OK\n";
				}
				else
				{
					ft_error('login_already_exist');
				}
			}
			else
			{
				$var = serialize(array($register));
				file_put_contents($path, $var);
				header('Location: ../authentification/connexion.php');
				echo "OK\n";
			}
		}
		else
			ft_error('empty_fields');
}
else
	ft_error('form_not_set');
?>
