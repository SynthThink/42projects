<?php
if (isset($_GET['name']) && isset($_GET['msg']))
{
	$content = file_get_contents('list.csv');
	$search = $_GET['name'].";".$_GET['msg']."\n";
	$content = str_replace($search, "", $content);
	file_put_contents('list.csv', $content);
}
?>
