<?php
require_once 'Vertex.class.php';
class Vector {
	private $_x = 0;
	private $_y = 0;
	private $_z = 0;
	private $_w = 0.0;
	static public $verbose = False;

	public function __construct ($array){
		if (!(array_key_exists("dest", $array)))
			return NULL;

		if (array_key_exists("orig", $array) == True)
			$orig = $array['orig'];
		else
			$orig = new Vertex(array('x' => 0.0, 'y' => 0.0, 'z' => 0.0, 'w' => 1.0));
		$this->_x = $array['dest']->_x - $orig->_x;
		$this->_y = $array['dest']->_y - $orig->_y;
		$this->_z = $array['dest']->_z - $orig->_z;
		$this->_w = $array['dest']->_w - $orig->_w;
		if (self::$verbose == True)
		{
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) constructed\n",
			$this->_x, $this->_y, $this->_z, $this->_w);
		}
	}

	public function magnitude () {
		$magnitude = sqrt(pow($this->_x, 2) + pow($this->_y, 2) + pow($this->_z, 2));
		return ($magnitude);
	}
	public function normalize () {
		$magnitude = $this->magnitude();
		if ($magnitude == 0)
			$magnitude = 1;
		$nx = $this->_x / $this->magnitude();
		$ny = $this->_y / $this->magnitude();
		$nz = $this->_z / $this->magnitude();
		if ($nx == $this->_x && $ny == $this->_y && $nz == $this->_z)
			return (clone $this);
		else {
			return (new Vector(array('dest' => new Vertex( array( 'x' => $nx, 'y' => $ny, 'z' => $nz)))));
		}
	}
	public function add ($vector) {
		$dest = new Vertex(array(
		'x' => ($this->_x + $vector->_x),
		'y' => ($this->_y + $vector->_y),
		'z' => ($this->_z + $vector->_z)));
		return (new Vector(array('dest' => $dest)));
	}
	public function sub ($vector) {
		$dest = new Vertex(array(
		'x' => ($this->_x - $vector->_x),
		'y' => ($this->_y - $vector->_y),
		'z' => ($this->_z - $vector->_z)));
		return (new Vector(array('dest' => $dest)));
	}
	public function opposite () {
		$dest = new Vertex(array(
		'x' => (-$this->_x),
		'y' => (-$this->_y),
		'z' => (-$this->_z)));
		return (new Vector(array('dest' => $dest)));
	}
	public function scalarProduct ($scalar) {
		$dest = new Vertex(array(
		'x' => ($this->_x * $scalar),
		'y' => ($this->_y * $scalar),
		'z' => ($this->_z * $scalar)));
		return (new Vector(array('dest' => $dest)));
	}
	public function dotProduct ($vector) {
		$dot = ($this->_x * $vector->_x) +
		($this->_y * $vector->_y) +
		($this->_z * $vector->_z);
		return ($dot);
	}
	public function crossProduct ($vector) {
		$dest = new Vertex(array(
		'x' => ($this->_y * $vector->_z - $this->_z * $vector->_y),
		'y' => ($this->_z * $vector->_x - $this->_x * $vector->_z),
		'z' => ($this->_x * $vector->_y - $this->_y * $vector->_x)));
		return (new Vector(array('dest' => $dest)));
	}
	public function cos($vector) {
		$cos = $this->dotProduct($vector) / ($this->magnitude() * $vector->magnitude());
		return ($cos);
	}
	public function __destruct (){
	if (self::$verbose == True)
		{
			printf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f ) destructed\n",
			$this->_x, $this->_y, $this->_z, $this->_w);
		}
	}

	public function __toString(){
		if (self::$verbose == True)
		{
			return (sprintf("Vector( x:%.2f, y:%.2f, z:%.2f, w:%.2f )",
				$this->_x, $this->_y, $this->_z, $this->_w));
		}
	}

	public function __get($att) {
		return ($this->$att);
	}
	public static function doc(){
		$data = file_get_contents("Vector.doc.txt");
		print($data);
	}
}
?>
