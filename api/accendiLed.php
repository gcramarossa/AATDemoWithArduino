<?php
    if (isset($_GET["led"]))
    {
        if (!file_exists("led.txt"))
        {
            $led = (int) $_GET["led"];
            $file = fopen("led.txt", "w+");
            fwrite($file, $led);
            fclose($file); 
            echo "LED ". $led . " aggiuto alla coda di accensione";           
        }
        else 
        {
            echo "Errore. Coda piena oppure Arduino spento";
        }
    }
?>