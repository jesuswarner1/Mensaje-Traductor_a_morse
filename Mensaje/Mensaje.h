#include <WString.h>

#ifndef MENSAJE_H
#define MENSAJE_H
#define NO_PIN -1 //para los que no tengan pin

class Mensaje{
    public:

    Mensaje(int pinLed = NO_PIN, int pinBuzzer = NO_PIN); //constructor
    void traductorMorse();
    void traductorMorseCompleto();
    int tiempoPunto = 200;

    
    private:

    int pinLed;
    int pinBuzzer;

    static char* letrasMorse[26]; //Son las letras en morse
    static char* numerosMorse[10]; //Son los numeros en morse

    String mensaje = "";

    void secuenciaFlash(char* secuencia); //funcion que traduce el mensaje a morse y lo envia al led y al buzzer
    void FlasheaDotorDash(char dotOrDash); //Mira si es un punto o una linea
};

#endif