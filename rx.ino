#include <VirtualWire.h>
const int transmit_pin = 10;
const int recieve_pin = 11;
void setup()
{ delay(1000);
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_rx_pin(recieve_pin);
  vw_rx_start();
}
void loop()
{
 
  char buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;
    
    if (vw_get_message(buf, &buflen)) 
    {      
      int i;
      Serial.print("Telemetry data :");
      { 
       for (i = 0; i < buflen; i++)
       {
        Serial.print(buf[i]);
       }
       Serial.print(' ');
      }
      Serial.println();
     }
     
}
