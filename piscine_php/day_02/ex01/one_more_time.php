#!/usr/bin/php
<?PHP
if ($argc <= 1)
	exit;
$pattern = '#^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche)+ +(([1-9])|([0-2][0-9])|(3[0-1])) +([Jj]anvier|[Ff][eé]vrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]o[uû]t|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd][ée]cembre) +[0-9]{4} +(([0-1][0-9])|([2][0-3])):[0-5][0-9]:[0-5][0-9]$#';
if (!preg_match($pattern, $argv[1]))
	echo "Wrong Format\n";
else
{
	$tab = explode(' ', $argv[1]);
	$numeric = array('01', '02', '03', '04', '05', '06', '07', '08', '09', '10', '11', '12');
	$mois = array('/[Jj]anvier/', '/[Ff][eé]vrier/', '/[Mm]ars/', '/[Aa]vril/', '/[Mm]ai/', '/[Jj]uin/', '/[Jj]uillet/', '/[Aa]o[uû]t/', '/[Ss]eptembre/', '/[Oo]ctobre/', '/[Nn]ovembre/', '/[Dd][ée]cembre/');
	$tab[2] = preg_replace($mois, $numeric, $tab[2]);
	date_default_timezone_set('europe/paris');
	#tab 1 = jour, tab 2 = mois, tab 3 = annee tab 4 = timestamp
	if (strlen($tab[1]) == 1)
		$tab[1] = '0'.$tab[1];
	$seconds = strtotime("$tab[3]/$tab[2]/$tab[1]/$tab[4]");
	if (!$seconds){
	  echo "Wrong Format\n";
	  return 0;
	}
	echo $seconds."\n";
}
?>
