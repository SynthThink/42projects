#!/usr/bin/php
<?PHP
if ($argc <= 1)
	exit;

function upper_match($array)
{
	return $array[1].strtoupper($array[2]);
}

function upper_match2($array)
{
	return $array[1].strtoupper($array[2]).$array[3];
}
$str = file_get_contents($argv[1]);
$pattern = "/^(.+<a[^<]+>)([^<]+)/m";
$str = preg_replace_callback($pattern, "upper_match", $str);
$pattern2 = "/(^.+<[\s]*a.+title=.)(.+)([\'\"].+$)/mi";
$str = preg_replace_callback($pattern2, "upper_match2", $str);
print $str;
?>
