#include "Adafruit_mfGFX.h"
#include "tasks.hpp"
#include "examples/examples.hpp"
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#include "i2c2.hpp"
#include "printf_lib.h"
#include "LabPWM.hpp"
#include "LabGPIO.hpp"
#include "RGBmatrixPanel.h"
#include "lpc_rit.h"
#include <math.h>
#include "utilities.h"
//#include <time.h>
#include "FallingObjects.h"


#include "acceleration_sensor.hpp"
#include "uart0_min.h"
#include "Water.h"
#include "Objects.h"
#include "Basket.h"
#include "InputHandler.h"
#include "DisplayHandler.h"
#include "LogicHandler.h"

const uint8_t boardLength_x=32;
const uint8_t boardWidth_y=32;
//#define AS Acceleration_Sensor::getInstance()
#define PI  3.14159265


//------------------------LED_Board Configurations:---------------------------------------
LabGPIO  P_addrA(0,0,1); //addrA
LabGPIO  P_addrB(0,1,1); //addrB
LabGPIO  P_addrC(2,6,1); //addrC
LabGPIO  P_addrD(2,7,1); //addrD
LabGPIO  P_LATCH(1,29,1); //LATCH
LabGPIO  P_OE(1,28,1); //OE
LabGPIO  P_CLOCK(1,19,1); //CLOCK
LabGPIO  P_R1(1,22,1); //R1
LabGPIO  P_G1(0,26,1); //G1
LabGPIO  P_B1(1,23,1); //B1
LabGPIO  P_R2(1,30,1); //R2
LabGPIO  P_G2(1,31,1); //G2
LabGPIO  P_B2(2,5,1); //B2

RGBmatrixPanel matrix(true, 32);
//------------------------LED_Board Configurations ENDS---------------------------------------

void setup()//Only Call Once
{
    //--------------------Initializing LED Board Settings:-----------------------------------
    P_addrA.setAsOutput();
    P_addrB.setAsOutput();
    P_addrC.setAsOutput();
    P_addrD.setAsOutput();
    P_LATCH.setAsOutput();
    P_OE.setAsOutput();
    P_CLOCK.setAsOutput();
    P_R1.setAsOutput();
    P_G1.setAsOutput();
    P_B1.setAsOutput();
    P_R2.setAsOutput();
    P_G2.setAsOutput();
    P_B2.setAsOutput();

    //--------------------Initializing LED Board Settings ENDS-----------------------------------
    matrix.begin();
}


void gameBegin(void *p)
{
    setup();
    //RGBmatrixPanel matrix(true, 32);



    Game myGame(boardLength_x,boardWidth_y);
    Water waterObj(myGame);
    Objects obj;
    Basket bskObj(myGame,waterObj);
    InputHandler iphObj(bskObj);
    DisplayHandler dspObj;
    LogicHandler lhObj;
    while (!myGame.isGameOver)
    {


        iphObj.callInputDaddy(bskObj);//getInput();| Working::Tested
        lhObj.callLogicDaddy(iphObj,bskObj,myGame,waterObj,lhObj.objArr);
        dspObj.callDisplayDaddy(waterObj,bskObj,lhObj.objArr,myGame,matrix);
        // waterObj.waterLevel++;
        //drawGame();
        //matrix.swapBuffers(false);
        vTaskDelay(100);
    }
    while(myGame.isGameOver){
        //Logic To Display ScoreScreen| ExitScreen..etc
    }
}



int main(void)
{

    //LED_Board Configration
    scheduler_add_task(new terminalTask(PRIORITY_HIGH));
    srand(time(NULL));

    xTaskCreate(
            gameBegin,      // Function that implements the task.
            "catchmeIfUcan",                // Text name for the task.
            2048,               // Stack size in words, not bytes.
            NULL,                     // Parameter passed into the task.
            3,                        // Priority at which the task is created.
            NULL);                    // Used to pass out the created task's handle.



    scheduler_start(); ///< This shouldn't return
    return -1;
}

