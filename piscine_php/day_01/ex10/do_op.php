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
		if ($str[$i] != ' ' && $str[$i] != "\t")
			$cleaned[$u++] = $str[$i];
		else if ($str[$i + 1] != ' ' && $str[$i] != "\t")
			$cleaned[$u++] = $str[$i];
		$i++;
	}
	if ($cleaned == NULL)
		$cleaned = '0';
	else
 		$cleaned = implode("", $cleaned);
	return $cleaned;
}

function ft_error()
{
	echo "Incorrect Parameters\n";
	exit;
}

if ($argc != 4)
	ft_error();
else
{
	$i = 0;
	$numb = array();
	$op = "";
	foreach($argv as $av)
	{
		if ($i++ == 0)
			continue;
		$av = ft_clean($av);
		if ($i == 2 || $i == 4)
		{
			if (is_numeric($av) == 0)
				ft_error();
			else
				array_push($numb, $av);
		}
		else if ($i == 3)
		{
			if ($av != '%' && $av != '+' && $av != '-' && $av != '/'
				&& $av != '*')
				ft_error();
			else
				$op = $av;
		}
	}
	if ($op == '%')
		echo ($numb[0] % $numb[1])."\n";
	else if ($op == '+')
		echo ($numb[0] + $numb[1])."\n";
	else if ($op == '*')
		echo ($numb[0] * $numb[1])."\n";
	else if ($op == '/')
		echo ($numb[0] / $numb[1])."\n";
	else if ($op == '-')
		echo ($numb[0] - $numb[1])."\n";
}
?>
