<?PHP
session_start();
if (isset($_SESSION))
{
	if ($_SESSION['loggued_on_user'] != "")
	{
		foreach($_SESSION['loggued_on_user'] as $key => $val)
		{
			echo $key."\n";
			break;
		}
	}
	else
		echo "ERROR\n";
}
else
	echo "ERROR\n";
?>
