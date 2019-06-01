#!/usr/bin/php
<?PHP
if ($argc <= 1)
	exit;
$curl = curl_init();
preg_match("/(?:(http[s]?):[\/]{2})?(.+[.][\w]{0,3})/i", $argv[1], $verif);
curl_setopt($curl, CURLOPT_URL, $argv[1]);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, TRUE);
if (strcmp($verif[1], "https") == 0)
	curl_setopt($curl, CURLOPT_SSL_VERIFYPEER, false);
$rep = $verif[2];
if (!file_exists($rep))
	if (!mkdir($rep))
		echo "\nEchec de la creation du repertoire ".$rep.".\n";
$str = curl_exec($curl);
preg_match_all("/^.+<img.+src=['\"]([^\s]*)['\"][\s].*$/mi", $str, $matches);
$matches[1] = array_unique($matches[1]);
foreach($matches[1] as $img)
{
	if (preg_match("/.+[.](svg|jpg|jpeg|gif|gmp|ico|png|tiff)$/", $img) == NULL)
		continue;
	$ch = curl_init();
	curl_setopt($ch, CURLOPT_URL, $img);
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);
	$data = curl_exec($ch);
	preg_match("/(?:(http[s]?):[\/]{2})?.+[^\w]([\w]+[.](svg|jpg|jpeg|gif|gmp|ico|png|tiff))/i", $img, $dec);
	$img = $dec[2];
	if (($file = @fopen("$rep/$img", "w")) != False)
		fputs($file, $data);
	curl_close($ch);
}
curl_close($curl);
?>
