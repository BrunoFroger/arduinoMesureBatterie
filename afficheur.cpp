

//   afficheur.cpp

#include <arduino.h>
#include "afficheur.hpp"


int decalage = 64;

//*********************************************
//*
//*       Constructor
//*
//*********************************************
handzDisplay::handzDisplay()
{
}

//*********************************************
//*
//*       Destructor
//*
//*********************************************
handzDisplay::~handzDisplay()
{
}

//*********************************************
//*
//*       afficheurInit
//*
//*********************************************
void handzDisplay::init(void){
    Serial.println("OLED FeatherWing test");
    // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x32)

    somme = analogRead(A0)*nbVal;
    moyenne = somme / nbVal;
    display.clearDisplay();
    display.display();
}

//*********************************************
//*
//*       displayBatterie
//*
//*********************************************
void handzDisplay::displayBatterie(int valeur){
    somme = somme - moyenne + valeur;
    moyenne = somme / nbVal;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(10,0);
    display.print("Batterie (");
    display.print(moyenne);
    display.println(")");
    display.setTextSize(1);
    display.setCursor(10,8);
    display.print("Volts  = ");
    //float valVolt = (float) (moyenne - 205) / 100;
    float valVolt = (float) moyenne  / 151.5;
    display.print(valVolt);
    display.println("V");
    int charge = map(moyenne,480,625,0,100);
    display.setCursor(10,16);
    display.print("charge = ");
    display.print(charge);
    display.println("%");
    display.setCursor(10,24);
    display.print("charge = [");
    for (int i = 0 ; i <= 90 ; i +=20 ){
        if (i <= charge ){
            display.print("*");
        }else {
            display.print(" ");
        }
    }
    display.println("]");
    display.display();
}

