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

function ft_error()
{
	echo "Incorrect Parameters\n";
	exit;
}

function ft_syntax()
{
	echo "Syntax Error\n";
	exit;
}


function check_char($av)
{
	$i = 0;
	while ($av[$i])
	{
		if (!(($av[$i] >= '0' && $av[$i] <= '9') || ($av[$i] == '+'
		|| $av[$i] == '-' || $av[$i] == '*' || $av[$i] == '/'
		|| $av[$i] == '%')))
			ft_syntax();
		$i++;
	}
	$i = 0;
	if ($av[$i] == '-' || $av[$i] == '+')
		$i++;
	if (!($av[$i] >= '0' && $av[$i] <= '9'))
		ft_syntax();
	while ($av[$i] >= '0' && $av[$i] <= '9')
		$i++;
	if (!($av[$i] == '+' || $av[$i] == '-' || $av[$i] == '*' || $av[$i] == '/'
	|| $av[$i] == '%'))
		ft_syntax();
	$i++;
	if ($av[$i] == '-' || $av[$i] == '+')
		$i++;
	if (!($av[$i] >= '0' && $av[$i] <= '9'))
		ft_syntax();
	while ($av[$i] >= '0' && $av[$i] <= '9')
		$i++;
	if ($av[$i] != NULL)
		ft_syntax();
}

$numb = array();
if ($argc != 2)
	ft_error();
else
{
	$c = 0;
	$numb = array();
	$op = "";
	foreach($argv as $av)
	{
		if ($c++ == 0)
			continue;
		$av = ft_clean($av);
		check_char($av);
		$i = 0;
		$numb[0] = intval($av);
		if ($av[$i] == '-' || $av[$i] == '+')
			$i++;
		while ($av[$i] >= '0' && $av[$i] <= '9')
			$i++;
		$op = $av[$i++];
		$tmp = substr($av, $i);
		$numb[1] = intval($tmp);
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
