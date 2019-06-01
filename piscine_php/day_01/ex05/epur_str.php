#!/usr/bin/php
<?PHP
$i = 0;
$c = 0;
foreach($argv as $av)
{
	if ($c++ == 0)
		continue;
	$av = trim($av);
	while ($av[$i] != NULL)
	{
		if ($av[$i] != ' ')
			echo $av[$i];
		else if ($av[$i + 1] != ' ')
			echo $av[$i];
		$i++;
	}
	if ($av != NULL)
		echo "\n";
	break;
}
?>
