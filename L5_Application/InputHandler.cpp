/*
 * InputHandler.cpp
 *
 *  Created on: 12-Nov-2018
 *      Author: scsap
 */

#include <InputHandler.h>

InputHandler::InputHandler(Basket& bskObj)
{
    dir=STOP;
    // TODO Auto-generated constructor stub

}

void InputHandler::getBoardOrientation(Basket& bskObj)
{
    //printf("getBoardOrientation: \n");
    x_coordiante=AS.getX();
    y_coordiante=AS.getY();
    z_coordiante=AS.getZ();
    //right
    if ((y_coordiante>x_coordiante )&(y_coordiante>z_coordiante)){
       // printf("getBoardOrientation: Right \n");
        boardOrientation=right;
        if(y_coordiante>=500){
            bskObj.speed=3;

        }
        else if(y_coordiante<500 && y_coordiante>200){
            bskObj.speed=2;
        }
        else{
            bskObj.speed=1;
        }

    }
    //left
    else if(((0-y_coordiante)>x_coordiante )&((0-y_coordiante)>z_coordiante)){
       // printf("getBoardOrientation: Left \n");
        boardOrientation=left;

        if(0-y_coordiante>900){
            bskObj.speed=3;
        }
        else if(0-y_coordiante>400){
            bskObj.speed=2;
        }
        else{
            bskObj.speed=1;
        }

    }

    else{

        boardOrientation=invalid;
        //printf("getBoardOrientation: invalid \n");
        //uart0_puts("Inside boardOrientation_invalid \n");
    }


}

void InputHandler::getInput(Basket& bskObj)
{

    getBoardOrientation(bskObj);
    //uart0_puts("Inside getInput \n");

   // printf("getInput:direction-%i,boarOrientaion-%i \n",(int)dir,y_coordiante);

    //--------------INPUT LOGIC--------------------
    switch(boardOrientation){
        case right:
            dir=RIGHT;
            //printf("dir: RIGHT \n");
            break;
        case left:
            dir=LEFT;
            //printf("dir: LEFT \n");
            break;

        case invalid:
        default:
            dir=STOP;
            //printf("dir: STOP \n");
            break;

            //--------------INPUT LOGIC ENDS--------------------


    }
}

void InputHandler::callInputDaddy(Basket& bskObj)
{
   // printf("inputDaddy: \n");

    getInput(bskObj) ;
}

InputHandler::~InputHandler()
{
    // TODO Auto-generated destructor stub
}

