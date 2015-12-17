<?php
?>
<!doctype html>
<html>
    <head>
        <title>Controllo remoto del circuito</title>
        <link rel="stylesheet" href="css/general.css" />
        <script type="text/javascript" src="js/AJAX.js"></script>
    </head>
    <body>
        <div id="container" class="arrotondato">
            <h1>Controllo dei led in remoto tramite la App Web su Azure - 1</h1>
            <p> Seleziona un bottone qui sotto per accendere il led associato a quel numero</p>
            <p>
                <a href="#" id="bottone1">1</a>
                <a href="#" id="bottone2">2</a>
                <a href="#" id="bottone3">3</a>
                <a href="#" id="bottone4">4</a>
                <a href="#" id="bottone5">5</a>
                <p id="stato">&nbsp;</p>
            </p>
        </div>
        <script type="text/javascript" src="js/azioni.js"></script>
    </body>
</html>
