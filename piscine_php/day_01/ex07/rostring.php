#!/usr/bin/php
<?PHP
function ft_clean($str)
{
	$i = 0;
	$u = 0;
	$str = trim($str);
	$cleaned = "";
	while ($str[$i] != NULL)
	{
		if ($str[$i] != ' ')
			$cleaned[$u++] = $str[$i];
		else if ($str[$i + 1] != ' ')
			$cleaned[$u++] = $str[$i];
		$i++;
	}
 	$cleaned = implode("", $cleaned);
	return $cleaned;
}
$i = 0;
foreach($argv as $av)
{
	if ($i++ != 1)
		continue;
	if ($av == NULL)
		continue;
	$av = ft_clean($av);
	$tab = explode(' ',$av);
	$tmp = "";
	$i = 0;
	while ($tab[$i] != NULL)
	{
		if ($i == 0)
			$tmp = $tab[$i];
		else
			echo $tab[$i]." ";
		$i++;
	}
	echo $tmp."\n";
}
?>
