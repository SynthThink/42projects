<?php
abstract class Fighter {
    public $type = 'fighter';
    function __construct($name)
    {
        $this->type = $name;
    }

    abstract function fight($target);
}
?>