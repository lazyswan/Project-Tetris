/*
 * FallingObjects.h
 *
 *  Created on: 11-Nov-2018
 *      Author: scsap
 */

#ifndef FALLINGOBJECTS_H_
#define FALLINGOBJECTS_H_
#include <stdint.h>
#include <stdlib.h>
enum eSpeed{
    SLOW=0,
    MEDIUM,
    FAST
};
enum ePower{
    NO=0,
    DESTROY,
    INCREASE
};
class FallingObjects {

public:

    int16_t oX;
    int16_t oY;
    int16_t height;
    int16_t widht;
    int8_t speed;       //Speed Can be 1,2,3
    ePower magicalPow;  //0:: NormalEgg| 1::FireEgg _gameOver | 2::Magic Egg_ Size of Basket Increases
    int16_t valArray[2]={2,3};
    uint8_t r;
    uint8_t g;
    uint8_t b;
    int status;//1=active and 0=dead;
    FallingObjects();

};

#endif /* FALLINGOBJECTS_H_ */
