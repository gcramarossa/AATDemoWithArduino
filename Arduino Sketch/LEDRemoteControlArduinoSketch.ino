#include <SPI.h>
#include <Ethernet.h>

#define LED1 8
#define LED2 7
#define LED3 6
#define LED4 5
#define LED5 3

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };

// insert your website here

char server[] = "provaled1.azurewebsites.net";


EthernetClient client;
char carattere;
void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(9600);
  // Imposta la scheda di rete
  Ethernet.begin(mac);
  // L'attesa è necessaria affinchè la scheda si inizializzi correttamente
  delay(1000);
}

void loop() {
  byte ledDaAccendere;
  // connessione al server 
  if (client.connect(server, 80)) {
    // Invia una richiesta HTTP
	client.print("GET http://");
	client.print(server);
    client.println("/LedRemoteControl/api/ottieniLed.php HTTP/1.1");
    client.print("Host: ");
    client.println(server);
    client.println("Connection: close");
    client.println();
  }
  /*
   * Legge dal server un carattere alla volta.
   * Ci servirà solo l'ultimo carattere
   */
  do
  {
    carattere = client.read();
  } while(client.available());
  

  // Se il server è disconnesso, ferma il client
  if (!client.connected()) 
  {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    if (carattere != '0')
    {
      switch (carattere)
      {
        case '1':
          ledDaAccendere = LED1;
          break;
        case '2':
          ledDaAccendere = LED2;
          break;
        case '3':
          ledDaAccendere = LED3;
          break;
        case '4':
          ledDaAccendere = LED4;
          break;
        default:
          ledDaAccendere = LED5;
      }
      if (ledDaAccendere == LED1 || ledDaAccendere == LED2) {
        // pin digitali
        digitalWrite(ledDaAccendere, HIGH);
        delay(500);
        digitalWrite(ledDaAccendere, LOW);
      }
      else
      {
        // pin PWM
        analogWrite(ledDaAccendere, 255);
        delay(500);
        analogWrite(ledDaAccendere, 0);
      }      
    }
  }
}
