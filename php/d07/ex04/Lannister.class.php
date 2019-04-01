<?php
class Lannister {
    public function sleepWith($target) {
        if (get_parent_class($this) == get_parent_class($target))
            print("Not even if I'm drunk !". PHP_EOL);
        else
            print("Let's do this.".PHP_EOL);
    }
}
?>
