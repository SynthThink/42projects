#!/usr/bin/php
<?PHP
date_default_timezone_set('Europe/Paris');
$fd = fopen("/var/run/utmpx", "rb");
$tri = array();
if ($fd != False)
{
	while ($str = fread($fd, 628))
	{
		$test = unpack("a256login/a4b/a32c/id/itype/I2f", $str);
		if ($test['type'] == 7 && preg_match("#malluin#", $test['login']))
			array_push($tri, $test);
	}
	foreach($tri as $array)
	{
		echo trim($array['login']);
		echo "  ";
		echo trim($array[c]);
		echo "  ";
		echo date("M d H:i", $array[f1]);
		echo " \n";
	}
}
?>
