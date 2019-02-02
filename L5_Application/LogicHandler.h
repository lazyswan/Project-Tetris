/*
 * LogicHandler.h
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#ifndef LOGICHANDLER_H_
#define LOGICHANDLER_H_
#include "InputHandler.h"
#include "Basket.h"
#include "Game.h"
#include "Objects.h"
#include "Water.h"
class LogicHandler {
public:

    Objects objArr[30];
    int8_t maxOnscreenObj;
    LogicHandler();
    //Objects objarr[30];//Array of Objs
    void callLogicDaddy(InputHandler& ipObj,Basket& bskObj,Game & gameObj,Water& waterObj,Objects(&obj)[OBJECT_ARRAY_SIZE]);
    void slideBasket(InputHandler& ipObj,Basket& bskObj,Game & gameObj);
    void stopSlidingAtEdge(Basket& bskObj,Game & gameObj);
    void checkIfGameOver(Game & gameObj,Basket& bskObj, Water& waterObj);
    void updateBskHeightAsPerWaterLevel(Basket& bskObj,Water& waterObj);
    void objectFreeFallLogic(Objects(&obj)[OBJECT_ARRAY_SIZE]);
    void genearateRandomObjects(Game & gameObj);//call it periodically not always
    void checkifCaughtMiss(Objects(&obj)[OBJECT_ARRAY_SIZE],Basket& bskObj,Game& gameObj,Water& waterObj);
    virtual ~LogicHandler();
};

#endif /* LOGICHANDLER_H_ */
