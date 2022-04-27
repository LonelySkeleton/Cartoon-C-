#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <cmath>
#include <sstream>
#include "KulyutnikovaLib.h"

using namespace std ;

void SceneFirst  ();
void SceneSecond ();
void SceneThird ();

void GirlAndTruck     (int xG, int yG, double scaleG, int width, int xT, int yT, double scaleT, int xP, int yP, double scaleP);
void IgorAndTram      (int xB, int yB, double scaleB, int width, int xT, int yT, double scaleT, int xP, int yP, double scaleP, int xM, int yM);
void MaximAndScooter  (int xMax, int yMax, double scaleMax, int width, int height, int dist, int xS, int yS, double scaleS, int type, int xC, int yC, double scaleC, int xM, int yM);

int main ()
    {
    txCreateWindow (1200, 800);

    //SceneFirst ();
    //SceneSecond();
    SceneThird();

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

    IgorAndTram (286, 419, 0.65, 1, 700, 323, 0.7, 900, 190, 0.7, 800, 500);

    txSleep (760);
    }

//-------------------------
void SceneThird ()
    {
    Background_Third();

    MaximAndScooter (0, 680, 1, 1, 1, 1, 50, 623, 1, 1, 0, 190, 1, 800, 500);

    txSleep (760);
    }

//=======================

void GirlAndTruck (int xG, int yG, double scaleG, int width, int xT, int yT, double scaleT, int xP, int yP, double scaleP)
    {
    int i = 0;
    int w = 1;
    txPlaySound ("Сцена1.wav");
    while (pow((pow(xG - xT, 2) + pow(yG - yT, 2)), 0.5) >= 100 )
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
        txTextOut (470, 150, "Внимание!");
        txSelectFont ("DS Eraser Cyr", 75, 18, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 255, 255));
        txTextOut (350, 300, "Отвлекись от телефона,");
        txTextOut (275, 365, "сделай музыку в наушниках тише.");
        txTextOut (230, 530, "Следи за тем, что происходит на дороге!");
        txSleep (7500);
        }

    }

//-------------------------

void IgorAndTram  (int xI, int yI, double scaleI, int width, int xT1, int yT1, double scaleT1, int xT2, int yT2, double scaleT2, int xM, int yM)
    {
    int m = 1;
    int b = 1;
    int b1 = 1;
    int b2 = 1;
    int d = 6;
    int t = 0;
    int counter = 0;
    txPlaySound ("Сцена2.wav");
    while (pow((pow(xI - xT2, 2) + pow(yI - yT2, 2)), 0.5) >= 100 )
        {
        Background_Second();

        xI += b * 1.3;
        yI += b * 3.1;

        xI -= b1 * 4.3;
        yI += b1 * 1.1;

        xI -= b2 * 0.3;
        yI -= b2 * 2.1;

        xT1 += t * 3;
        yT1 -= t * 0.6;

        xT2 -= t * 5;
        yT2 += t * 0.6;

        people_woman(xM - m*6      , yM + m*1.5    , 0.75, 5 - 3*(m % 4));
        people_woman(xM - 600      , yM - 300      , 0.65, 2);
        people_woman(xM - 700 + m*2, yM + 200 + m*2, 0.5 , 2 - 3*(m % 4));

        people_man(xM - 550      , yM - 300      , 0.65, 2);
        people_man(xM - 350 - m*3, yM + 250 - m*3, 0.5 , 3 - 3*(m % 4));

        Tram(xT2, yT2, scaleT2, 2);
        Tram(xT1, yT1, scaleT1, 1);

        if (counter <= 10)
        {
        Tram_Door_Left(ROUND(1108 * 0.65), ROUND(502 * 0.65), ROUND(1108 * 0.65 - d * 3), ROUND(502 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Left(ROUND( 240 * 0.65), ROUND(648 * 0.65), ROUND( 240 * 0.65 - d * 3), ROUND(648 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Left(ROUND(1585 * 0.65), ROUND(431 * 0.65), ROUND(1585 * 0.65 - d * 3), ROUND(431 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Left(ROUND( 686 * 0.65), ROUND(578 * 0.65), ROUND( 686 * 0.65 - d * 3), ROUND(578 * 0.65), 0.65 + 0.00003 * 6);

        Tram_Door_Right(ROUND(1108 * 0.65 + d * 3), ROUND(502 * 0.65), ROUND(1108 * 0.65), ROUND(502 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Right(ROUND( 240 * 0.65 + d * 3), ROUND(648 * 0.65), ROUND( 240 * 0.65), ROUND(648 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Right(ROUND(1585 * 0.65 + d * 3), ROUND(431 * 0.65), ROUND(1585 * 0.65), ROUND(431 * 0.65), 0.65 + 0.00003 * 6);
        Tram_Door_Right(ROUND( 686 * 0.65 + d * 3), ROUND(578 * 0.65), ROUND( 686 * 0.65), ROUND(578 * 0.65), 0.65 + 0.00003 * 6);
        }


        Igor_Reverse  (xI, yI, scaleI, width, 2, 2 - 3*(counter % 4));
        if (counter >  8) {Igor_Reverse  (xI, yI, scaleI, width, 2, 2 - 3*(counter % 4)); d = 0; b1 += 1; if (counter % 5 == 0) {t += 1;}}
        if (counter > 16) {Igor_Reverse  (xI, yI, scaleI, width, 2, 2 - 3*(counter % 4)); b1 = 0; b2 += 1; if (counter % 2 !=0) {txRectangle(0, 0, 1200, 8000);}}

        if (counter >= 30)
        {
        txSetFillColor (RGB(0, 0, 0));
        txRectangle (0, 0, 1200, 800);

        txSelectFont ("DS Eraser Cyr", 75, 25, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 0, 0));
        txTextOut (470, 350, "Внимание!");
        txSelectFont ("DS Eraser Cyr", 75, 18, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 255, 255));
        txTextOut (350, 150, "Так Игорь стал инвалидом: ");
        txTextOut (275, 200, "его сбил трамвай, и оторвало ногу");
        txTextOut (230, 530, "Следи за тем, что происходит на дороге!");
        txSleep (750);
        }


        m += 1;
        counter += 1;
        if (counter <= 8) {b += 1; d = 6;}
        else {b = 0;}
        txSleep (750);
        }
    }

//-------------------------

void MaximAndScooter  (int xMax, int yMax, double scaleMax, int width, int height, int dist, int xS, int yS, double scaleS, int type, int xC, int yC, double scaleC, int xM, int yM)
    {
    int s = 1;
    int maxim = 1;
    int counter = 0;

    //txPlaySound ("Сцена3.wav");

    while (counter <= 25)
        {
        Background_Third();

        if (counter <= 21)
            {
            xS += s * 19.6;
            yS -= s * 22;

            xMax += maxim * 19.6;
            yMax -= maxim * 22;

            Scooter(xS, yS, scaleS, type);
            Maxim(xMax, yMax, scaleMax, width, height, dist);
            }

        if (counter >= 22 and counter <= 25)
            {

            xS += s * 50;
            yS -= s * 22;

            xMax -= maxim * 25;
            yMax -= maxim * 22;

            Scooter(xS, yS, scaleS, 2);
            Maxim(xMax, yMax, scaleMax, width, height, dist);
            }

        people_man(xM,       yM,      0.75, 0);
        people_man(xM + 100, yM,      0.75, 0);
        people_man(xM +  50, yM - 90, 0.75, 0);


        counter += 1;

        txSleep (750);
        }

    txSetFillColor (RGB(0, 0, 0));
    txRectangle (0, 0, 1200, 800);

    }
