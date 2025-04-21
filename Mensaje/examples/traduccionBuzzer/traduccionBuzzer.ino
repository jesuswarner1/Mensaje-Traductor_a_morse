#include <Arduino.h>
#include "Mensaje.h"

int pinLed = 13; //el pin que quieras ver el codigo morse
int pinBuzzer = 3; //si tienes un buzzer, agrega tu pin aqui

Mensaje traductor(NO_PIN, pinBuzzer); //como es con BUZZER, agregar NO_PIN = -1

void setup(){
    Serial.begin(9600);
    traductor.tiempoPunto = 80; //para variar el tiempo del codigo morse
}

void loop(){
   
    traductor.traductorMorse();             //Traduce en vivo lo que pongas en el Serial Terminal

    //traductor.traductorMorseCompleto();  //Traduce despues de enviar un enter (mensajes comletos)
}