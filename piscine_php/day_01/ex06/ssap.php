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
$table = NULL;
$i = 0;
foreach($argv as $av)
{
	if ($i++ == 0)
		continue;
	if ($av == NULL)
		continue;
	$av = ft_clean($av);
	$tabtmp = explode(' ', $av);
	if ($table != NULL)
		$table = array_merge($table, $tabtmp);
	else
		$table = $tabtmp;
}
if ($table != NULL)
{
	sort($table);
	foreach($table as $value)
		echo $value."\n";
}
?>
