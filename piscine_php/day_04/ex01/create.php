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
			$register = array("login" => $_POST['login'], "passwd" => hash("whirlpool", $_POST['passwd']));
			$ok = file_exists("../htdocs/private/passwd");
			$data = NULL;
			if ($ok == True)
			{
				$data = file_get_contents("../htdocs/private/passwd");
				if (verify_existing($data, $register) == 0)
				{
					$data = unserialize($data);
					$data[] = $register;
					file_put_contents("../htdocs/private/passwd", serialize($data));
					echo "OK\n";
				}
				else
					echo "ERROR\n";
			}
			else if ($ok == False)
			{
				$var = serialize(array($register));
				file_put_contents("../htdocs/private/passwd", $var);
				echo "OK\n";
			}
		}
		else
			echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
