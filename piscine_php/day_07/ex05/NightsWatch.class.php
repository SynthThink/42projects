<?php

class NightsWatch {
    public $_fighters = array();

    public function recruit($candidate) {
        if ($candidate instanceof IFighter)
           $this->_fighters[] = $candidate;
    }
    public function fight() {
        foreach($this->_fighters as $fighter)
            $fighter->fight();
    }
}
?>
