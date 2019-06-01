<?php
$content = file_get_contents('list.csv');
if ($content != NULL)
{
	echo $content;
}
?>
