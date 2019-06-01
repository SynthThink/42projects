<?php
require_once 'Color.class.php';
class Vertex {
	private $_x = 0;
	private $_y = 0;
	private $_z = 0;
	private $_w = 1.0;
	private $_color = 0;
	public static $verbose = False;

	public function __construct ($array){
		if (!(array_key_exists("x", $array)
		 && array_key_exists("y", $array)
		 && array_key_exists("z", $array)))
			return NULL;
		$this->_x = $array['x'];
		$this->_y = $array['y'];
		$this->_z = $array['z'];
		if (array_key_exists("w", $array) == True)
			$this->_w = $array['w'];
		if (array_key_exists("color", $array) == True && $array['color'] instanceof Color)
			$this->_color = $array['color'];
		else
			$this->_color = new Color( array('red' => 255, 'green' => 255, 'blue' => 255 ) );
		if (self::$verbose == True)
		{
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) constructed\n",
			$this->_x, $this->_y, $this->_z, $this->_w,
			$this->_color->red, $this->_color->green, $this->_color->blue);
		}
	}
	public function __get($att) {
		return ($this->$att);
	}
	public function __set($_x, $value) {
		$this->$_x = $value;
	}
	public function __destruct (){
		if (self::$verbose == True)
		{
			printf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) ) destructed\n",
			$this->_x, $this->_y, $this->_z, $this->_w,
			$this->_color->red, $this->_color->green, $this->_color->blue);
		}
	}
	public function __toString(){
		if (self::$verbose == False)
		{
			return (sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f )",
				$this->_x, $this->_y, $this->_z, $this->_w));
		}
		else
		{
			return (sprintf("Vertex( x: %.2f, y: %.2f, z:%.2f, w:%.2f, Color( red: %3d, green: %3d, blue: %3d ) )",
				$this->_x, $this->_y, $this->_z, $this->_w,
				$this->_color->red, $this->_color->green, $this->_color->blue));
		}
	}
	public static function doc(){
		$data = file_get_contents("Vertex.doc.txt");
		print($data);
	}
}
 ?>
