<?PHP
function filter_spec($var)
{
	return ($var !== NULL && $var !== FALSE && $var !== '');
}
function ft_split($char)
{
	$char = array_filter(explode(' ', $char), "filter_spec");
	asort($char);
	return ($char);
}
?>
