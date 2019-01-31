#include <VirtualWire.h>
const int transmit_pin = 10;
const int recieve_pin = 11;
int a=A0;
int b=A1;
int c=A2;
char msg[3];
void setup()
{
  pinMode(a,INPUT);
  pinMode(b,INPUT);
  pinMode(c,INPUT);
  Serial.begin(9600);
  vw_setup(2000);
  vw_set_tx_pin(transmit_pin);
}
void loop() {
int x,y,z;
x=analogRead(a);
itoa(x,msg,10);
Serial.println(msg);
vw_send((uint8_t*)msg,3);
vw_wait_tx();
y=analogRead(b);
itoa(y,msg,10);
vw_send((uint8_t*)msg,3);
vw_wait_tx();
z=analogRead(c);
itoa(z,msg,10);
vw_send((uint8_t*)msg,3);
vw_wait_tx();
Serial.println(x);
Serial.println(y);
Serial.println(z);
delay(1000);
}
