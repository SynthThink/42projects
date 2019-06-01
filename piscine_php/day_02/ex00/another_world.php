#!/usr/bin/php
<?PHP
$i = 0;
if ($argc <= 1)
	exit;
foreach($argv as $av)
{
	if ($i++ != 1)
		continue;
	$pattern = '/(\s|\t)+/';
	$tmp = preg_replace($pattern, ' ', $av);
	$tmp = preg_replace("#^( |\t)|( |\t)$#", '', $tmp);
	echo $tmp."\n";
}
?>
