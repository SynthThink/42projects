<?PHP
function auth($login, $passwd)
{
	$passwd = hash("whirlpool", $passwd);
	if(file_exists("../private/passwd"))
	{
		$data = unserialize(file_get_contents("../private/passwd"));
		foreach ($data as $array)
		{
			if (strcmp($array['login'], $login) == 0)
			{
				if (strcmp($array['passwd'], $passwd) == 0)
					return (True);
				else
					return (False);
			}
		}
	}
	else
		return (False);
}
?>
