#!/usr/bin/php
<?PHP
function ft_clean($str)
{
	$i = 0;
	$u = 0;
	$str = trim($str);
	$len = strlen($str);
	$cleaned = "";
	while ($len > 0)
	{
		if ($str[$i] != ' ' && $str[$i] != "\t")
			$cleaned[$u++] = $str[$i];
		else if ($str[$i + 1] != ' ' && $str[$i] != "\t")
			$cleaned[$u++] = $str[$i];
		$i++;
		$len--;
	}
	if ($cleaned == NULL)
		$cleaned = '0';
	else
 		$cleaned = implode("", $cleaned);
	return $cleaned;
}

function check_char($av)
{
	$i = 0;
	$len = strlen($av);
	while ($av[$i] != ':' && $i < $len)
		$i++;
	if ($av[$i] != ':')
		return False;
	if ($i == $len - 1)
		return False;
	return True;
}

$numb = array();
$search = 0;
$dict = array();
if ($argc <= 2)
	return;
else
{
	$c = 0;
	$numb = array();
	$op = "";
	foreach($argv as $av)
	{
		if ($c == 0)
		{
			$c = 1;
			continue;
		}
		if ($c++ == 1)
		{
			$search = $av;
			continue;
		}
		if (check_char($av) == False)
			continue;
		else
		{
			$i = 0;
			$len = strlen($av);
			while ($av[$i] != ':' && $i < $len)
				$i++;
			$key = substr($av, 0, $i);
			$value = substr($av, $i + 1);
			$i++;
			$dict[$key] = $value;
		}
	}
	if ($search == NULL)
		exit;
	echo $dict[$search];
	if ($dict[$search] != NULL)
		echo "\n";
}
?>
