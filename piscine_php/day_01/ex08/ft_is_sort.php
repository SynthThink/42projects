<?PHP

function ft_is_sort($array)
{
	if ($array == NULL)
		return True;
	$sort_array = $array;
	sort($sort_array);
	if ($sort_array[0] != $array[0])
	{
		$sort_array = $array;
		rsort($sort_array);
		print_r($sort_array);
	}
	$i = 0;
	while ($array[$i] != NULL)
	{
		if ($array[$i] != $sort_array[$i])
			return False;
		$i++;
	}
	return True;
}
?>
