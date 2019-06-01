<?php
class Color {
	public $red = 0;
	public $green = 0;
	public $blue = 0;
	static public $verbose = False;

	static function doc()
	{
		$data = file_get_contents("Color.doc.txt");
		print($data);
	}

	function __construct($array) {
		if (sizeof($array) != 1 && sizeof($array) != 3)
			return ;
		if (sizeof($array) == 1)
		{
			$this->red = ($array['rgb'] >> 16 ) & 0x0000FF;
			$this->green = ($array['rgb'] >> 8) & 0x0000FF;
			$this->blue = $array['rgb'] & 0x0000FF;
		}
		else if (sizeof($array) == 3)
		{
			$this->red = $array['red'] & 0x0000FF;
			$this->green = $array['green'] & 0x0000FF;
			$this->blue = $array['blue'] & 0x0000FF;
		}
		if (self::$verbose == True)
			printf("Color( red: %3d, green: %3d, blue: %3d ) constructed.\n", $this->red, $this->green, $this->blue);
	}

	function __destruct() {
		if (self::$verbose == True)
			printf("Color( red: %3d, green: %3d, blue: %3d ) destructed.\n", $this->red, $this->green, $this->blue);
	}

	function add($color_to_add) {
		if ($color_to_add instanceof Color)
		{
			return new Color(array('red' => $this->red + $color_to_add->red,
			'green' => $this->green + $color_to_add->green,
			'blue' => $this->blue + $color_to_add->blue));
		}
	}

	function sub($color_to_sub) {
		if ($color_to_sub instanceof Color)
		{
			return new Color(array('red' => $this->red - $color_to_sub->red,
			'green' => $this->green - $color_to_sub->green,
			'blue' => $this->blue - $color_to_sub->blue));
		}
	}

	function mult($mult) {
			return new Color(array('red' => ($this->red * $mult),
			'green' => ($this->green * $mult),
			'blue' => ($this->blue * $mult)));
	}

	function __toString(){
		return sprintf("Color( red: %3d, green: %3d, blue: %3d )", $this->red, $this->green, $this->blue);
	}
}
?>
