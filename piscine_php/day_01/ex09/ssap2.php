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

function ft_is_alpha($c)
{
	if (($c >= 'a' && $c <= 'z') || ($c >= 'A' && $c <= 'Z'))
		return True;
	return False;
}

function ft_is_num($c)
{
	if ($c >= '0' && $c <= '9')
		return True;
	return False;
}

function ft_sort_spec($str, $str2)
{
	$i = 0;
	$str = strtolower($str);
	$str2 = strtolower($str2);
	while ($str[$i] != NULL && $str2[$i] != NULL)
	{
		if (ft_is_alpha($str[$i]))
		{
			if (!ft_is_alpha($str2[$i]))
				return (-1);
			else if ($str[$i] != $str2[$i])
				return (strcmp($str[$i],$str2[$i]));
		}
		else if (ft_is_num($str[$i]))
		{
			if (ft_is_alpha($str2[$i]))
				return (1);
			else if (!ft_is_num($str2[$i]))
				return (-1);
			else if ($str[$i] != $str2[$i])
				return ($str[$i] - $str2[$i]);
		}
		else
		{
			if (!(ft_is_alpha($str2[$i])) && !(ft_is_num($str2[$i])))
			{
				if ($str[$i] != $str2[$i])
					return (ord($str[$i]) - ord($str2[$i]));
			}
			else
				return (1);
		}
		$i++;
	}
	if ($str[$i] == NULL && $str2[$i] != NULL)
		return (-1);
	else if ($str2[$i] == NULL && $str[$i] != NULL)
		return (1);
	return 0;
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
	usort($table, ft_sort_spec);
	// usort($table, ft_sort_spec);
	foreach($table as $value)
		echo $value."\n";
}
?>
