<?PHP
class House {
    public function introduce() {
        print("House ".$this->getHouseName()." of ".$this->getHouseSeat());
        print(" : \"".$this->getHouseMotto()."\"\n");
    }
}
?>