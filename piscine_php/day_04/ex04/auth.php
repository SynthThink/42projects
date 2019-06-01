<?PHP
function auth($login, $passwd)
{
	$passwd = hash("whirlpool", $passwd);
	if(file_exists("../htdocs/private/passwd"))
	{
		$data = unserialize(file_get_contents("../htdocs/private/passwd"));
		foreach ($data as $array)
		{
			if ($array['login'] == $login)
			{
				if ($array['passwd'] == $passwd)
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
