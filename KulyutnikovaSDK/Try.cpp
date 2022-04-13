#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <cmath>
#include <sstream>
#include "KulyutnikovaLib.h"

using namespace std ;

void SceneFirst  ();
void SceneSecond ();

void GirlAndTruck (int xG, int yG, double scaleG, int width, int xT, int yT, double scaleT, int xP, int yP, double scaleP);
void IgorAndTram  (double xB, double yB, double scaleB, int width, double xT, double yT, double scaleT, double xP, double yP, double scaleP, int xM, int yM);

int main ()
    {
    txCreateWindow (1200, 800);
    //SceneFirst ();
    SceneSecond();

    //Background_Third();
    //Maxim(250, 250, 1, 1, 1, 1);
    return 0;
    }

//-------------------------
void SceneFirst ()
    {
    Background_First ();
    GirlAndTruck (792, 439, 0.9, 1, 230, -100, 0.4, 725, 419, 1);
    txSleep (760);
    }

//-------------------------
void SceneSecond ()
    {
    Background_Second();
    //Igor(40, 200, 0.65, 1, 1, 1);
    //Tram(900, 200, 0.65, 2);
    //Tram(700, 333, 0.65, 1);

    IgorAndTram (380, 420, 0.65, 1, -200, 480, 0.65, 1500, 83, 0.65, 800, 500);
    txSleep (760);
    }

void GirlAndTruck (int xG, int yG, double scaleG, int width, int xT, int yT, double scaleT, int xP, int yP, double scaleP)
    {
    int i = 0;
    int w = 1;
    txPlaySound ("—цена1.wav");
    while ( pow( (pow(xG - xT, 2) + pow(yG - yT, 2) ), 0.5) >= 100 )
        {
        Background_First ();
        int a = 1;
        if ( (pow( (pow(xG - xT, 2) + pow(yG - yT, 2)), 0.5) ) <= 500 ) a = 2;

        xG += i * 3;
        yG -= i * 3;
        xT += i * 21;
        yT += i * 15;

        i += 1;
        if (i % 2 == 0) w = 1;
        else w = 2;

        Truck (xT, yT, scaleT + 0.06*i);
        Girl  (xG, yG, scaleG - 0.021*i, width, 2 - 4*(i % 2), -2 * (2 - 4*(i % 2)));
        TrafficLight (750, 435, 1, w, 1);

        people_woman (xP - 520 + i*6*a, yP + 190 - i*6*a, scaleP*1  , 5 - 3*(i % 4));
        people_woman (xP +  30 - i*8,   yP       - i*8,   scaleP*0.5, 3 - 3*(i % 4));
        people_woman (xP + 450 - i*5,   yP + 391 - i*5,   scaleP*1  , 4 - 3*(i % 4));
        people_woman (xP + 190 - i*4,   yP + 150 - i*4,   scaleP*1  , 3 - 3*(i % 4));
        people_woman (xP + 330,         yP - 209,         scaleP*0.5, 1);

        people_man (xP + 405,         yP - 159,         scaleP*0.5, 1);
        people_man (xP - 575 + i*4*a, yP + 241 - i*4*a, scaleP*1,   2 - 3*(i % 4));
        people_man (xP - 200 + i*3,   yP -  51 - i*3,   scaleP*1,   3 - 3*(i % 4));

        txSleep (750);
        }

     if ( pow( (pow(xG - xT, 2) + pow(yG - yT, 2) ), 0.5) <= 200 )
        {
        txSetFillColor (RGB(0, 0, 0));
        txRectangle (0, 0, 1200, 800);

        txSelectFont ("DS Eraser Cyr", 75, 25, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 0, 0));
        txTextOut (470, 50, "¬нимание!");
        txSelectFont ("DS Eraser Cyr", 75, 18, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 255, 255));
        txTextOut (350, 200, "ќтвлекись от телефона,");
        txTextOut (275, 265, "сделай музыку в наушниках тише.");
        txTextOut (230, 430, "—леди за тем, что происходит на дороге!");
        }

    }

void IgorAndTram  (double xI, double yI, double scaleI, int width, double xT1, double yT1, double scaleT1, double xT2, double yT2, double scaleT2, int xM, int yM)
    {
    for(int i = 0; i <= 25; i++)
        {
        Background_Second();

        xT2 -= i * 3;
        yT2 += i * 0.6;
        xT1 += i * 6;
        yT1 -= i * 0.95;

        i += 1;

        Tram (xT2, yT2, scaleT2, 2);
        Tram (xT1, yT1, scaleT1, 1);

        //Tram_Door_Left(ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Left(ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Left(ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Left(ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);

        //Tram_Door_Right(ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Right(ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Right(ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        //Tram_Door_Right(ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);

        txSleep (750);
        }

    for(int i = 0; i <= 15; i++)
        {
        Background_Second();
        Tram_Door_Left(ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), ROUND((xT1 + 408 - i * 3) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), ROUND((xT1 - 460 - i * 3) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), ROUND((xT1 + 885 - i * 3) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), ROUND((xT1 -  14 - i * 3) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);

        Tram_Door_Right(ROUND((xT1 + 408 + i * 3) * 0.65), ROUND((yT1 + 169) * 0.65), ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 - 460 + i * 3) * 0.65), ROUND((yT1 + 315) * 0.65), ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 + 885 + i * 3) * 0.65), ROUND((yT1 +  98) * 0.65), ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 -  14 + i * 3) * 0.65), ROUND((yT1 + 245) * 0.65), ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);

        i += 1;

        txSleep (750);
        }

    for(int i = 0; i <= 10; i++)
        {
        Background_Second();

        xI += i * 2.3;
        yI += i * 3.1;

        Igor  (xI, yI, scaleI, width, 2, 5 - 3*(i % 4));

        people_woman(xM - i*6      , yM + i*1.5      , 0.75, 5 - 3*(i % 4));
        people_woman(xM - 600      , yM - 300        , 0.65, 2);
        people_woman(xM - 700 + i*2, yM + 200 + i*2  , 0.5 , 2 - 3*(i % 4));

        people_man(xM - 550      , yM - 300      , 0.65, 2);
        people_man(xM - 350 - i*3, yM + 250 - i*3, 0.5 , 3 - 3*(i % 4));

        i += 1;

        txSleep (750);
        }

    for(int i = 0; i <= 15; i++)
        {
        Background_Second();

        xI -= i * 2.3;
        xT2 -= i * 3;
        yT2 += i * 0.6;

        Igor_Reverse  (xI, yI, scaleI, width, 2, 5 - 3*(i % 4));

        people_woman(xM - i*6      , yM + i*1.5      , 0.75, 5 - 3*(i % 4));
        people_woman(xM - 600      , yM - 300        , 0.65, 2);
        people_woman(xM - 700 + i*2, yM + 200 + i*2  , 0.5 , 2 - 3*(i % 4));

        people_man(xM - 550      , yM - 300      , 0.65, 2);
        people_man(xM - 350 - i*3, yM + 250 - i*3, 0.5 , 3 - 3*(i % 4));

        Tram (xT2, yT2, scaleT2, 2);

        i += 1;

        txSleep (750);
        }

    while ( pow( (pow(xI - xT2, 2) + pow(yI - yT2, 2) ), 0.5) >= 300 )
        {
        int i = 1;
        Background_Second();

        xI += i * 0.5;
        yI -= i * 3;

        xT2 -= i * 2;
        yT2 += i * 0.6;

        Igor_Reverse  (xI, yI, scaleI, width, 2, 5 - 3*(i % 4));

        Tram (xT2, yT2, scaleT2, 2);

        i += 1;

        txSleep (750);
        }
    }
