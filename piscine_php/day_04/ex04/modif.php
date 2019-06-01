<?PHP

function verify_existing($data, $register)
{
	if ($data != NULL)
	{
		$data = unserialize($data);
		foreach($data as $array)
		{
			if ($array['login'] == $register['login'])
			{
				if ($array['passwd'] == $register['oldpw'])
					return (1);
			}
		}
	}
	return (0);
}
if (isset($_POST))
{
		if ($_POST['submit'] == "OK" && $_POST['login'] != ""
			&& $_POST['oldpw'] != "" && $_POST['newpw'] != "")
		{
			$register = array("login" => $_POST['login'], "oldpw" => hash("whirlpool", $_POST['oldpw']), "newpw" => hash("whirlpool", $_POST['newpw']));
			$data = NULL;
			if (file_exists("../htdocs/private/passwd"))
			{
				$data = file_get_contents("../htdocs/private/passwd");
				if (verify_existing($data, $register) == 1)
				{
					$data = unserialize($data);
					$key_modif = NULL;
					foreach ($data as $key => $tab)
					{
						if ($tab['login'] == $register['login'])
						{
							$key_modif = $key;
							break;
						}
					}
					$data[$key]['passwd'] = $register['newpw'];
					file_put_contents("../htdocs/private/passwd", serialize($data));
					header('Location: index.html');
					echo "OK\n";
				}
				else
					echo "ERROR\n";
			}
			else
				echo "ERROR\n";
		}
		else
			echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
