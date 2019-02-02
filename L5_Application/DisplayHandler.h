/*
 * DisplayHandler.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef DISPLAYHANDLER_H_
#define DISPLAYHANDLER_H_
#include "Water.h"
#include "Basket.h"
#include "Objects.h"
#include "RGBmatrixPanel.h"


//BITSETS of Objects
const uint8_t egg[] = {
        0x60,
        0xf0,
        0xf0,
        0xf0,
        0x60
};

const uint8_t eggOutlet[] = {
        0x78,
        0x84
};

const uint8_t eggbasket[] = {
        0x84,
        0x48,
        0x30
};
class DisplayHandler {
public:
    DisplayHandler();
    void callDisplayDaddy(Water& waterObj,Basket& bskObj,Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix);
    void displayWater(Water& waterObj,RGBmatrixPanel& matrix);
    void displayBasket(Basket& bskObj,RGBmatrixPanel& matrix);
    void displayObject(Objects (&obj)[30],Game& gameObj,RGBmatrixPanel& matrix);
    void refreshScreen(RGBmatrixPanel& matrix);
    void drawegg(int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b,RGBmatrixPanel& matrix);
    void draweggoutlet(int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b,RGBmatrixPanel& matrix);
    void draweggbasket(int16_t x, int16_t y, uint8_t r, uint8_t g, uint8_t b,RGBmatrixPanel& matrix);


    virtual ~DisplayHandler();
};

#endif /* DISPLAYHANDLER_H_ */
