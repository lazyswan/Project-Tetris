/*
 * FallingObjects.cpp
 *
 *  Created on: 11-Nov-2018
 *      Author: scsap
 */

#include <FallingObjects.h>
#include <time.h>
//#include "io.hpp" // All IO Class definitions
//#include "bio.h"
//#include "adc0.h"
//#define AS Acceleration_Sensor::getInstance()
FallingObjects::FallingObjects()
{   //srand(adc0_get_reading(BIO_LIGHT_ADC_CH_NUM));
   srand(time(NULL));
   oX=(rand()%25)+3;
    //oX=28;
    oY=31;
    height=valArray[rand()%2];
    widht=valArray[rand()%2];
    speed=(rand() % 3)+1;       //Speed Can be 1,2,3
    ePower magicalPow=static_cast<ePower>(rand() % 4);  //0:: NormalEgg| 1::FireEgg _gameOver | 2::Magic Egg_ Size of Basket Increases
    uint8_t r=(rand()%8);
    uint8_t g=(rand()%8);
    uint8_t b=(rand()%8);
    status=1;

}
