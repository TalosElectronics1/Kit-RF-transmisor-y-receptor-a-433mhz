/*Talos Electronics 2015
   Rafael Lozano Rolon
   Receptor a 433 Mhz
*/
#include <VirtualWire.h>  //incluimos la libreria de virtualwire
int led = 12; //Asignamos el 12 a la variable led

void setup()
{
  vw_set_ptt_inverted(true);  // Requerido por el modulo RF
  vw_setup(7000);        //Seleccionamos la velocidad de transmision de datos
  vw_set_rx_pin(11);         // Pin en el que conectamos la patilla data del receptor
  vw_rx_start();         //Iniciamos la comunicación
  pinMode(led, OUTPUT);  //Asignamos la variable led como salida
}

void loop()
{
  uint8_t msg[VW_MAX_MESSAGE_LEN];
  uint8_t len = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(msg, &len))  //Condicion para ver si hay mensaje
  {
    if ( msg[0] == 'E') //Si el mensaje es una E
    {
      digitalWrite(led, HIGH);         //Encendemos el LED
    }
    else if (msg[0] == 'A')         // Si es una A
    {
      digitalWrite(led, LOW);        //Apagamos el led
    }
  }
}
