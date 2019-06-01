<?php
if (isset($_GET['name']) && isset($_GET['msg']))
{
	$content = file_get_contents('list.csv');
	$search = $_GET['name'].";".$_GET['msg']."\n";
	if (strstr($content, $search) == False)
	{
		$content .= $_GET['name'].";".$_GET['msg']."\n";
		file_put_contents('list.csv', $content);
	}
}
?>
