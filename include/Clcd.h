#pragma once

#include "Wire.h"
#include <LiquidCrystal_I2C.h>
#include "Arduino.h"


class Clcd
{
    

//BASIC SINGLETON START
public:
    static Clcd &getInstance()
    {
        static Clcd S;
        return S;
    }

    Clcd(const Clcd &) = delete;
    void operator=(Clcd const &) = delete;

private:
    Clcd();
    ~Clcd();
//BASIC SINGLETON END


private:
    //Init LCD Display
    LiquidCrystal_I2C *m_pLcd;
    
    //Storarge of the current showing strings
    String m_Line[2];


    int m_DisplayFlag;
    const int m_CountOfRows = 2;
    const int m_CountOfSignsPerRows = 16 ;

    const String mClearLineStr = "                ";

public:

    LiquidCrystal_I2C *getLCDInstance();
    
    void init(__uint8_t _sda_pin, __uint8_t _scl_pin);

    void setLine(String *_pText, int _lineNumber);
    void setLineA(String *_pText);
    void setLineB(String *_pText);

    void showManualON();
    void showManualOFF();

    void showWaterIsNotEmpty(String *_ptext);
    void showWaterIsEmpty(String *_pTime);

    void setDisplayText(String *_pTextA, String *_pTextB);

    void showMenu();
    void showWaterIsNotEmptySinceTime();

    void turnOffBackLight();
    
};