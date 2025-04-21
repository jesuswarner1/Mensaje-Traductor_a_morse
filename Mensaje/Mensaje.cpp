#include <Arduino.h>
#include "Mensaje.h"

//constantes

char* Mensaje::letrasMorse[26] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

char* Mensaje::numerosMorse[10] = {
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----."
};


Mensaje::Mensaje(int pinLed, int pinBuzzer){ //constructor

    this->pinLed = pinLed;
    this->pinBuzzer = pinBuzzer;

    pinMode(pinLed, OUTPUT); //inicializo el pin del led como salida

};

void Mensaje::traductorMorse(){
    char ch;
    if (Serial.available() > 0){
        ch = Serial.read();

        if(ch >= 'a' && ch <= 'z'){
            secuenciaFlash(letrasMorse[ch - 'a']);
        }

        else if(ch >= 'A' && ch <= 'Z'){
            secuenciaFlash(letrasMorse[ch - 'A']);
        }
        else if(ch >= '0' && ch <= '9'){
            secuenciaFlash(numerosMorse[ch - '0']);
        }
        else if(ch == ' '){
            delay(4 * tiempoPunto); //espacio entre palabras
        }

    }
}

void Mensaje::traductorMorseCompleto(){

    while (Serial.available() > 0) {
      char ch = Serial.read();
  
      // Si se recibe un Enter (salto de línea)
      if (ch == '\n' || ch == '\r') {

        mensaje.trim(); // limpia espacios innecesarios
  
        for (int i = 0; i < mensaje.length(); i++) {
          char c = mensaje[i];
  
          if (c >= 'a' && c <= 'z') {
            secuenciaFlash(letrasMorse[c - 'a']);
          }
          else if (c >= 'A' && c <= 'Z') {
            secuenciaFlash(letrasMorse[c - 'A']);
          }
          else if (c >= '0' && c <= '9') {
            secuenciaFlash(numerosMorse[c - '0']);
          }
          else if (c == ' ') {
            delay(4 * tiempoPunto); // espacio entre palabras
          }
        }
  
        mensaje = ""; // limpia el buffer para el siguiente mensaje
      } else {
        mensaje += ch; // va construyendo el mensaje letra por letra
      }
    }
  }

void Mensaje::secuenciaFlash(char* secuencia){

    int i = 0;
    while(secuencia[i] != '\0'){
        
        FlasheaDotorDash(secuencia[i]);
        i++;
    }

    delay(3 * tiempoPunto); //es el espacio entre letras

};

void Mensaje::FlasheaDotorDash(char dotOrDash){

    if(pinLed != NO_PIN) digitalWrite(pinLed, HIGH);
    if(pinBuzzer != NO_PIN) tone(pinBuzzer, 800); // es para el sonido del buzzer

    if(dotOrDash == '.'){

        delay(tiempoPunto); //esto es el delay por si es un punto en morse

    }
    else{

        delay(tiempoPunto * 3); //si no es . es una - asi que el delay es 3 veces .

    }

    if(pinLed != NO_PIN) digitalWrite(pinLed, LOW);
    if(pinBuzzer != NO_PIN) noTone(pinBuzzer); //apaga el buzzer
    delay(tiempoPunto); //El tiempo entre flasheos
};
