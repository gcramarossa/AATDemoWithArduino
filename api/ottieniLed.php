<?php
    $led = "0";
    if (file_exists("led.txt"))
    {
        $led = file_get_contents("led.txt");
        unlink("led.txt");
    }
    
    echo $led;
?>