//
//  mesure Batterie Level
//
//  Created by    : Bruno FROGER
//  creation date : 2018-12-14
//
// Pour Arduino Feather
// processeur ATMega328P (old Bootloader)
//


#include <arduino.h>
#include "afficheur.hpp"

#define MAIN_LOOP_DELAY 1000

handzDisplay myDisplay;
//*********************************************
//*
//*       S E T U P
//*
//*********************************************
void setup(){

    // initialize serial communication
    Serial.begin(38400);
    int timeoutInitSerial = 100;
    while (timeoutInitSerial-- > 0)
    {
        if (Serial)
            break;
        delay(10);
    }
    Serial.println("Serial initialized");
    myDisplay.init();
}


//*********************************************
//*
//*       L O O P
//*
//*********************************************
void loop(){
    int valMesure = analogRead(A0);
    myDisplay.displayBatterie(valMesure);
    delay(MAIN_LOOP_DELAY);
}
