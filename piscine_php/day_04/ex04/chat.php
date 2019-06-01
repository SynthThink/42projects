<?PHP
$path = "../htdocs/private/chat";
date_default_timezone_set('europe/paris');
if (file_exists($path))
{
	$fd = fopen($path, "r");
	flock($fd, LOCK_SH);
	$str = unserialize(file_get_contents($path));
	flock($fd, LOCK_UN);
	fclose($fd);
	foreach($str as $array)
	{
		echo date("[G:i]", $array['time'])." ";
		echo "<b>".$array['login']."</b>: ".$array['msg']."<br />\n";
	}
}
else
	$str = "";
?>
