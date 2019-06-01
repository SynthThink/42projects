<?PHP

function verify_existing($data, $register)
{
	if ($data != NULL)
	{
		$data = unserialize($data);
		foreach($data as $array)
		{
			if ($array['login'] == $register['login'])
				return (1);
		}
	}
	return (0);
}
if (isset($_POST))
{
		if ($_POST['submit'] == "OK" && $_POST['login'] != ""
			&& $_POST['passwd'] != "")
		{
			$path = "../htdocs/private/passwd";
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
					header('Location: index.html');
					echo "OK\n";
				}
				else
					echo "ERROR\n";
			}
			else
			{
				$var = serialize(array($register));
				file_put_contents($path, $var);
				header('Location: index.html');
				echo "OK\n";
			}
		}
		else
			echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
