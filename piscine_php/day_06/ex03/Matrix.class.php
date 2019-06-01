<?php
require_once 'Vector.class.php';
class Matrix {
	const IDENTITY =	[[1, 0, 0, 0],
						[ 0, 1, 0, 0],
						[ 0, 0, 1, 0],
						[ 0, 0, 0, 0]];
	const RX =			[[1.0, 0.0, 0.0,  0.0],
						[ 0.0, 1.0, -1.0, 0.0],
						[ 0.0, 1.0, 1.0,  0.0],
						[ 0.0, 0.0, 0.0,  1.0]];

	const RY =			[[1.0, 0.0, 1.0, 0.0],
						[ 0.0, 1.0, 0.0, 0.0],
						[-1.0, 0.0, 1.0, 0.0],
						[ 0.0, 0.0, 0.0, 1.0]];

	const RZ =			[[1.0,-1.0, 0.0, 0.0],
						[ 1.0, 1.0, 0.0, 0.0],
						[ 0.0, 0.0, 1.0, 0.0],
						[ 0.0, 0.0, 0.0, 1.0]];

	const TRANSLATION =	[[1, 0, 0, 1],
						[ 0, 1, 0, 1],
						[ 0, 0, 1, 1],
						[ 0, 0, 0, 1]];
	const SCALE = 		[[1, 0, 0, 0],
						[ 0, 1, 0, 0],
						[ 0, 0, 1, 0],
						[ 0, 0, 0, 1]];
	const PROJECTION =	[[1.0, 0.0, 1.0, 0.0],
						[ 0.0, 1.0, 1.0, 0.0],
						[ 0.0, 0.0, 1.0, 1.0],
						[ 0.0, 0.0, 1.0, 0.0]];

	static public $verbose = False;
	private $_mx;

	public function __construct ($array){
		if (array_key_exists("custom", $array))
			$this->_mx = $array['custom'];
		else if ($array['preset'] == self::IDENTITY)
		{
			$this->_mx = self::IDENTITY;
			$this->_mx[3][3] += 1;
			if (self::$verbose == True)
				printf("Matrix IDENTITY instance constructed\n");
		}
		else if ($array['preset'] == self::TRANSLATION)
		{
			$this->_mx = self::TRANSLATION;
			$this->_mx[0][3] *= $array['vtc']->_x;
			$this->_mx[1][3] *= $array['vtc']->_y;
			$this->_mx[2][3] *= $array['vtc']->_z;
			if (self::$verbose == True)
				printf("Matrix TRANSLATION preset instance constructed\n");
		}
		else if ($array['preset'] == self::SCALE)
		{
			$this->_mx = self::SCALE;
			$this->_mx[0][0] *= $array['scale'];
			$this->_mx[1][1] *= $array['scale'];
			$this->_mx[2][2] *= $array['scale'];
			if (self::$verbose == True)
				printf("Matrix SCALE preset instance constructed\n");
		}
		else if ($array['preset'] == self::RX)
		{
			$this->_mx = self::RX;
			$this->_mx[1][1] *= cos($array['angle']);
			$this->_mx[1][2] *= sin($array['angle']);
			$this->_mx[2][1] *= sin($array['angle']);
			$this->_mx[2][2] *= cos($array['angle']);
			if (self::$verbose == True)
				printf("Matrix Ox ROTATION preset instance constructed\n");
		}
		else if ($array['preset'] == self::RY)
		{
			$this->_mx = self::RY;
			$this->_mx[0][0] *= cos($array['angle']);
			$this->_mx[0][2] *= sin($array['angle']);
			$this->_mx[2][0] *= sin($array['angle']);
			$this->_mx[2][2] *= cos($array['angle']);
			if (self::$verbose == True)
				printf("Matrix Oy ROTATION preset instance constructed\n");
		}
		else if ($array['preset'] == self::RZ)
		{
			$this->_mx = self::RZ;
			$this->_mx[0][0] *= cos($array['angle']);
			$this->_mx[0][1] *= sin($array['angle']);
			$this->_mx[1][0] *= sin($array['angle']);
			$this->_mx[1][1] *= cos($array['angle']);
			if (self::$verbose == True)
				printf("Matrix Oz ROTATION preset instance constructed\n");
		}
		else if ($array['preset'] == self::PROJECTION)
		{
			$this->_mx = self::PROJECTION;
			$fov = $array['fov'] * M_PI / 180.0 ;
			$ratio = $array['ratio'];
			$f = $array['far'];
			$n = $array['near'];
			$t = tan($fov / 2.0) * $n;
			$r = $t * $ratio;
			$b = -$t;
			$l = -$t * $ratio;
			$this->_mx[0][0] *= (2 * $n) / ($r - $l);
			$this->_mx[0][2] *= ($r + $l) / ($r - $l);
			$this->_mx[1][1] *= (2 * $n) / ($t - $b);
			$this->_mx[1][2] *= ($t + $b) / ($t - $b);
			$this->_mx[2][2] *= -($f + $n) / ($f - $n);
			$this->_mx[2][3] *= -(2 * $f * $n) / ($f - $n);
			$this->_mx[3][2] *= -1;
			if (self::$verbose == True)
				printf("Matrix PROJECTION preset instance constructed\n");
		}
	}

	public function __destruct (){
	if (self::$verbose == True)
		printf("Matrix instance destructed\n");
	}

	public function mult (Matrix $rhs) {
		$new =  [[$this->_mx[0][0], $this->_mx[0][1], $this->_mx[0][2], $this->_mx[0][3]],
				[ $this->_mx[1][0], $this->_mx[1][1], $this->_mx[1][2], $this->_mx[1][3]],
				[ $this->_mx[2][0], $this->_mx[2][1], $this->_mx[2][2], $this->_mx[2][3]],
				[ $this->_mx[3][0], $this->_mx[3][1], $this->_mx[3][2], $this->_mx[3][3]]];
		foreach($new as $i => $row)
		{
			foreach($new as $j => $col)
			{
				$c = 0;
				$tmp = 0.0;
				while ($c < 4)
				{
					$tmp += $this->_mx[$i][$c] * $rhs->_mx[$c][$j];
					$c++;
				}
				$new[$i][$j] = $tmp;
			}
		}
		return (new Matrix (array ('custom' => $new)));
	}

	public function transformVertex (Vertex $vt) {
		$x = $vt->_x * $this->_mx[0][0] + $vt->_y * $this->_mx[0][1]
			+ $vt->_z * $this->_mx[0][2] + $vt->_w * $this->_mx[0][3];
		$y = $vt->_x * $this->_mx[1][0] + $vt->_y * $this->_mx[1][1]
			+ $vt->_z * $this->_mx[1][2] + $vt->_w * $this->_mx[1][3];
		$z = $vt->_x * $this->_mx[2][0] + $vt->_y * $this->_mx[2][1]
			+ $vt->_z * $this->_mx[2][2] + $vt->_w * $this->_mx[2][3];
		$w = $vt->_x * $this->_mx[3][0] + $vt->_y * $this->_mx[3][1]
			+ $vt->_z * $this->_mx[3][2] + $vt->_w * $this->_mx[3][3];
		return (new Vertex(array('x' => $x, 'y' => $y, 'z' => $z, 'w' => $w)));
	}

	public function __toString(){
		if (self::$verbose == True)
		{
			$string = sprintf("M | vtcX | vtcY | vtcZ | vtxO\n" );
			$string .= "-----------------------------\n";
			$string .= sprintf("x | %.2f | %.2f | %.2f | %.2f\n", $this->_mx[0][0], $this->_mx[0][1], $this->_mx[0][2], $this->_mx[0][3]);
			$string .= sprintf("y | %.2f | %.2f | %.2f | %.2f\n", $this->_mx[1][0], $this->_mx[1][1], $this->_mx[1][2], $this->_mx[1][3]);
			$string .= sprintf("z | %.2f | %.2f | %.2f | %.2f\n", $this->_mx[2][0], $this->_mx[2][1], $this->_mx[2][2], $this->_mx[2][3]);
			$string .= sprintf("w | %.2f | %.2f | %.2f | %.2f", $this->_mx[3][0], $this->_mx[3][1], $this->_mx[3][2], $this->_mx[3][3]);
			return ($string);
		}
	}
	public static function doc(){
		$data = file_get_contents("Matrix.doc.txt");
		print($data);
	}
}
?>
