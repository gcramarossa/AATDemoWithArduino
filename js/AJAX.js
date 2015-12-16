/**
 * Permette di effettuare richieste asincrone al server
 */

var AJAX = 
{
	_provaCreazioneAjax: function()
	{
		var richiesta;
		try
		{
			richiesta = new XMLHttpRequest();
		}
		catch(eccezione)
		{
			alert("richiesta non inviata");
		}
		return richiesta;
	},
	
	riceviDati: function(oggetto, pagina)
	{
		var richiesta = AJAX._provaCreazioneAjax();
		richiesta.open("GET", pagina, true);
		richiesta.onreadystatechange = function()
		{
			if (richiesta.readyState == 4)
			{
				if (richiesta.status == 200 || richiesta.status == 304)
				{
					document.getElementById("" + oggetto).innerHTML = richiesta.responseText;
				}
				else
				{
					document.getElementById("" + oggetto).innerHTML = "Elaborazione della richiesta in corso...";
				}
			}
			else
			{
				document.getElementById("" + oggetto).innerHTML = "Elaborazione della richiesta in corso...";
			}
		}
		richiesta.send(null);
	}
	
	
};