<?php
include("connect_db.php");
if (!$dblink) {
    echo "Erreur : Impossible de se connecter à MySQL." . PHP_EOL;
    echo "Errno de débogage : " . mysqli_connect_errno() . PHP_EOL;
    echo "Erreur de débogage : " . mysqli_connect_error() . PHP_EOL;
    exit;
}
else {
	echo "Succès : Une connexion correcte à MySQL a été faite! La base de donnée my_db est génial." . PHP_EOL;
	echo "Information d'hôte : " . mysqli_get_host_info($dblink) . PHP_EOL;
}

$CREATE_CATEGORIES = "
	CREATE TABLE categories (
	id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	nom VARCHAR(255) DEFAULT 'Autres' NOT NULL,
	type ENUM('VARCHAR(255)', 'INT') DEFAULT 'VARCHAR(255)' NOT NULL,
	valeur_default VARCHAR(255) DEFAULT 'Autres' NOT NULL,
	filter INT DEFAULT 0 NOT NULL);";

$INSERT_CATEGORIES = "
	INSERT INTO categories (nom, type, valeur_default, filter)
	VALUES
	('race', 'VARCHAR(255)', 'corgi', 1),
	('taille', 'VARCHAR(255)', 'petit', 1),
	('img', 'VARCHAR(255)', 'corgi.jpg', 0),
	('prix', 'INT', '1', 0);";

$CREATE_DOGS = "
	CREATE TABLE chiens (
	id INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	race VARCHAR(255) DEFAULT 'petit' NOT NULL,
	taille VARCHAR(255) DEFAULT 'corgi' NOT NULL,
	img VARCHAR(255) DEFAULT 'corgi.jpg' NOT NULL,
	prix INT DEFAULT 1 NOT NULL);";

$INSERT_DOGS = "
	INSERT INTO chiens (race, taille, img, prix)
	VALUES
	('Corgi', 'petit', 'corgi.jpg', 1800),
	('Jack Russel', 'petit', 'jack_russel.jpg', 500),
	('Fox Terrier', 'moyen', 'fox_terrier.jpg', 700),
	('Border Collie', 'moyen', 'border_collie.jpg', 2000),
	('Braque de Weimar', 'grand', 'braque.jpg', 1400),
	('Epagneul Breton', 'grand', 'epagneul.jpg', 1200);";

$CREATE_ORDERS = "
	CREATE TABLE orders (
	id_order INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	client VARCHAR(255) DEFAULT 'john doe' NOT NULL,
	nb_id1 INT DEFAULT 0 NOT NULL,
	nb_id2 INT DEFAULT 0 NOT NULL,
	nb_id3 INT DEFAULT 0 NOT NULL,
	nb_id4 INT DEFAULT 0 NOT NULL,
	nb_id5 INT DEFAULT 0 NOT NULL,
	nb_id6 INT DEFAULT 0 NOT NULL);";

$result = mysqli_query($dblink, $CREATE_CATEGORIES);
if ($result == FALSE)
	echo "ECHEC CREATION categories\n";
$result = mysqli_query($dblink, $INSERT_CATEGORIES);
if ($result == FALSE)
	echo "ECHEC INSERTION categories\n";

$result = mysqli_query($dblink, $CREATE_DOGS);
if ($result == FALSE)
	echo "ECHEC CREATION chiens\n";
$result = mysqli_query($dblink, $INSERT_DOGS);
if ($result == FALSE)
	echo "ECHEC INSERTION chiens\n";
$result = mysqli_query($dblink, $CREATE_ORDERS);
if ($result == FALSE)
	echo "ECHEC CREATION orders\n";


// $result = mysqli_query($dblink, $INSERT_CATEGORIES);
// if ($result == FALSE)
// 	echo "ECHEC INSERTION CATEGORIES\n";
// $filter = "petit";
// $request = "SELECT race, taille, img from categories
// WHERE taille = 'petit' OR race = 'Border Collie';";
// $res = mysqli_query($dblink, $request);
// if (mysqli_num_rows($res) > 0)
// {
// 	while($row = mysqli_fetch_assoc($res)) {
// 		echo $row['race']."\n";
// 	}
// }
?>
