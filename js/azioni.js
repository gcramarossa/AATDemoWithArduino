/**
 * 
 */

for (var i = 1; i < 6; i++)
{
	document.getElementById("bottone" + i).onclick = function()
	{
		AJAX.riceviDati("stato", "api/accendiLed.php?led=" + this.id.replace("bottone", ""), "");
	}
}