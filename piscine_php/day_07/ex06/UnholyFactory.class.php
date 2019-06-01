<?php
class UnholyFactory {
    private $_absorbed = array(); 

    function absorb($soldier)
    {
        if ($soldier instanceof Fighter)
        {
            $type = $soldier->type;
            if (in_array($soldier, $this->_absorbed) == False)
            {
                print("(Factory absorbed a fighter of type ".$type.")".PHP_EOL);
                $this->_absorbed[$type] = $soldier;
            }
            else
                print("(Factory already absorbed a fighter of type ".$type.")".PHP_EOL);
        }
        else
            print("(Factory can't absorb this, it's not a fighter)".PHP_EOL);
    }

    function fabricate($soldier)
    {
        if (!array_key_exists($soldier, $this->_absorbed))
        {
            print("(Factory hasn't absorbed any fighter of type ".$soldier.")".PHP_EOL);
        }
        else
        {
            print("(Factory fabricates a fighter of type ".$soldier.")".PHP_EOL);
            return ($this->_absorbed[$soldier]);
        }
    }
}
?>