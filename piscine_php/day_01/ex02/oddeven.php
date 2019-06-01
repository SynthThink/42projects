#!/usr/bin/php
<?PHP

$handle = fopen ("php://stdin","r");
while (1)
{
	echo "Entrez un nombre: ";
	$line = fgets($handle);
	if ($line == FALSE)
		break;
	$line = rtrim($line);
	if (is_numeric($line))
	{
		if ($line % 2 == 0)
			echo "Le chiffre ".$line." est Pair\n";
		else
			echo "Le chiffre ".$line." est Impair\n";
	}
	else
	{
		print "'";
		print $line;
		print "' n'est pas un chiffre\n";
	}
}
echo "\n";
?>
