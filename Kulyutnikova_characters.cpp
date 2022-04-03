#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std ;

void Background_First ();
void Road         (int x, int y);
void Polosa       (int x, int y);
void Pavement     (int x, int y, int choice);
void Houses       (int x, int y, int choice);
void TrafficLight (int x, int y, int first, int second, int third);

void Background_Second ();
void Rails (int x, int y);
void Stop (int x, int y, int type);

void Background_Third ();
void Highway (int x, int y);
void Curb (int x, int y);
void Grass (int x, int y);
void Footpath (int x, int y);
void Lawn (int x, int y);

void Girl         (int x, int y, double scale, double width, int height, int dist);
void Empress      (int x, int y, double scale, double width, int distance);
void Cat          (int x, int y, double scale, double width, int height);
void Truck        (int x, int y, double scale);

void Igor            (int x, int y, double scale, double width, int height, int dist);
void Tram            (int x, int y, double scale, int type);
void Tram_Door_Left  (int x, int y, double scale);
void Tram_Door_Right (int x, int y, double scale);

void Maxim   (int x, int y, double scale, double width, int height, int dist);
void Scooter (int x, int y, double scale, int type);

void people_woman (int x, int y, double scale, double dist);
void people_men   (int x, int y, double scale, double dist);

void SceneFirst ();
void SceneSecond ();

void GirlAndTruck (int xG, int yG, double scaleG, double width, int xT, int yT, double scaleT, int xP, int yP, double scaleP);
void IgorAndTram  (int xB, int yB, double scaleB, double width, int xT, int yT, double scaleT, int xP, int yP, double scaleP);

int main ()
    {
    txCreateWindow (1200, 800);
    //SceneFirst ();
    SceneSecond();

    //Background_Third();
    //Maxim(250, 250, 1, 1, 1, 1);
    //Igor(550, 250, 1, 1, 1, 1);
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
    Igor(40, 200, 0.65, 1, 1, 1);
    //Tram(900, 200, 0.65, 2);
    //Tram(700, 333, 0.65, 1);

    people_woman(800, 500, 0.75, 2);
    people_woman(200, 200, 0.65, 2);
    people_woman(100, 700, 0.5, 2);
    people_men(250, 200, 0.65, 2);
    people_men(450, 750, 0.5, 2);

    IgorAndTram (1, 1, 1, 1, -200, 480, 0.65, 1500, 100, 0.65);
    txSleep (760);
    }

void GirlAndTruck (int xG, int yG, double scaleG, double width, int xT, int yT, double scaleT, int xP, int yP, double scaleP)
    {
    int i = 0;
    int w = 1;
    txPlaySound ("Сцена1.wav");
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

        people_men (xP + 405,         yP - 159,         scaleP*0.5, 1);
        people_men (xP - 575 + i*4*a, yP + 241 - i*4*a, scaleP*1,   2 - 3*(i % 4));
        people_men (xP - 200 + i*3,   yP -  51 - i*3,   scaleP*1,   3 - 3*(i % 4));

        txSleep (750);
        }

     if ( pow( (pow(xG - xT, 2) + pow(yG - yT, 2) ), 0.5) <= 200 )
        {
        txSetFillColor (RGB(0, 0, 0));
        txRectangle (0, 0, 1200, 800);

        txSelectFont ("DS Eraser Cyr", 75, 25, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 0, 0));
        txTextOut (470, 50, "Внимание!");
        txSelectFont ("DS Eraser Cyr", 75, 18, FW_BOLD, true, false, false, 0);
        txSetColor (RGB(255, 255, 255));
        txTextOut (350, 200, "Отвлекись от телефона,");
        txTextOut (275, 265, "сделай музыку в наушниках тише.");
        txTextOut (230, 430, "Следи за тем, что происходит на дороге!");
        }

    }
void IgorAndTram  (int xB, int yB, double scaleB, double width, int xT1, int yT1, double scaleT1, int xT2, int yT2, double scaleT2)
    {
    for(int i = 0; i <= 25; i++)
        {
        Background_Second();

        xT2 -= i * 3;
        yT2 += i * 0.6;
        xT1 += i * 6;
        yT1 -= i * 0.95;

        i += 1;

        Tram (xT2, yT2, scaleT2 + 0.0006*i, 2);
        Tram (xT1, yT1, scaleT1 + 0.00003*i, 1);

        Tram_Door_Left(ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Left(ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);

        Tram_Door_Right(ROUND((xT1 + 408) * 0.65), ROUND((yT1 + 169) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 - 460) * 0.65), ROUND((yT1 + 315) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 + 885) * 0.65), ROUND((yT1 +  98) * 0.65), 0.65 + 0.00003*i);
        Tram_Door_Right(ROUND((xT1 -  14) * 0.65), ROUND((yT1 + 245) * 0.65), 0.65 + 0.00003*i);
        txSleep (750);
        }







        //Igor  (xG, yG, scaleG - 0.021*i, width, 2 - 4*(i % 2), -2 * (2 - 4*(i % 2)));

        //people_woman (xP - 520 + i*6*a, yP + 190 - i*6*a, scaleP*1  , 5 - 3*(i % 4));
        //people_woman (xP +  30 - i*8,   yP       - i*8,   scaleP*0.5, 3 - 3*(i % 4));
        //people_woman (xP + 450 - i*5,   yP + 391 - i*5,   scaleP*1  , 4 - 3*(i % 4));
        //people_woman (xP + 190 - i*4,   yP + 150 - i*4,   scaleP*1  , 3 - 3*(i % 4));
        //people_woman (xP + 330,         yP - 209,         scaleP*0.5, 1);

       //people_men (xP + 405,         yP - 159,         scaleP*0.5, 1);
       // people_men (xP - 575 + i*4*a, yP + 241 - i*4*a, scaleP*1,   2 - 3*(i % 4));
       // people_men (xP - 200 + i*3,   yP -  51 - i*3,   scaleP*1,   3 - 3*(i % 4));


    }

//||||||||||||||BACKGROUND FIRST|||||||||||||
//-------------------------
void Background_First ()
    {
    txClear ();

    txSetFillColor (RGB(220, 220, 220));
    txRectangle (0, 0, 1200, 800);
    Road (114, -45);

    Polosa (820, 390);
    Polosa (870, 355);
    Polosa (920, 320);
    Polosa (970, 285);

    Pavement (700, 400, 1);

    Houses (15, 45, 1);
    }

//============ELEMENTS BACKGROUND FIRST=======

//-------------------------
void Road (int x, int y)
    {
    txSetColor (TX_BLACK, 4);
    txSetFillColor (TX_WHITE);
    POINT road[4] = { {x,        y      }, {x + 126,  y - 105},
                      {x + 1236, y + 450}, {x + 1086, y + 735} };
    txPolygon (road, 4);
    txLine (x + 481, y + 195, x +  571, y + 245);
    txLine (x + 331, y +  95, x +  421, y + 145);
    txLine (x + 631, y + 295, x +  721, y + 345);
    txLine (x + 931, y + 495, x + 1021, y + 545);
    }

//-----------------------------------------------
void Polosa (int x, int y)
    {
    txSetColor (TX_BLACK, 2);
    txSetFillColor (TX_BLACK);
    POINT polosa[4] = { {x,       y      }, {x +  20, y - 10},
                        {x + 155, y + 70 }, {x + 135, y + 80} };
    txPolygon (polosa, 4);
    }

//-----------------------------------------------
void Pavement (int x, int y, int choice)
    {
    if (choice == 1)
        {txSetFillColor (TX_GRAY);
        POINT pavement1[6] = { {x,       y      }, {x +  34, y + 145},
                               {x - 580, y + 400}, {x - 700, y + 400},
                               {x - 700, y + 200}, {x,       y      } };
        txPolygon (pavement1, 6);
        POINT pavement2[6] = { {x - 694, y - 445}, {x - 586, y - 445},
                               {x + 500, y + 290}, {x + 500, y + 400},
                               {x + 350, y + 400}, {x - 694, y - 445} };
        txPolygon (pavement2, 6);
        POINT pavement3[5] = { {x - 460, y - 550}, {x - 400, y - 550},
                               {x + 600, y - 110}, {x + 650, y +  50},
                               {x - 460, y - 550}  };
        txPolygon (pavement3, 5);
        }
    if (choice == 2)
        {txSetFillColor (RGB(154, 205, 50));
        POINT pavement1[3] = { {x       , y      }, {x + 1200, y - 200},
                               {x + 1200, y + 800}               };
        txPolygon (pavement1, 3);

        }
    }

//-----------------------------------------------
void Houses (int x, int y, int choice)
    {
    if (choice == 1)
        {
          //house1
        txSetFillColor (TX_GRAY);
        txRectangle (x, y, x  + 180, y + 305);
            //window1
        txSetFillColor (TX_YELLOW);
        txRectangle (x  +  15, y +  30,  x +  60, y +  80);
        txRectangle (x  +  75, y +  30,  x + 115, y +  80);
        txRectangle (x  + 129, y +  30,  x + 165, y +  80);
        txRectangle (x  +  15, y + 125,  x +  60, y + 185);
        txRectangle (x  +  75, y + 125,  x + 115, y + 185);
        txRectangle (x  + 129, y + 125,  x + 165, y + 185);
            //house2
        txSetFillColor (TX_GRAY);
        txRectangle (x  + 134, y + 15, x  + 180 + 134, y + 305 + 15);
            //window2
        txSetFillColor (TX_YELLOW);
        txRectangle (x  +  41 + 104, y  +  30 + 15, x  +  96 + 104,  y  +  75 + 15);
        txRectangle (x  + 116 + 104, y  +  30 + 15, x  + 200 + 104,  y  +  75 + 15);
        txRectangle (x  +  38 + 104, y  +  90 + 15, x  +  65 + 104,  y  + 141 + 15);
        txRectangle (x  +  86 + 104, y  +  90 + 15, x  + 136 + 104,  y  + 147 + 15);
        txRectangle (x  + 176 + 104, y  +  90 + 15, x  + 211 + 104,  y  + 147 + 15);
        txRectangle (x  +  41 + 104, y  + 165 + 15, x  + 100 + 104,  y  + 219 + 15);
        txRectangle (x  + 131 + 104, y  + 165 + 15, x  + 211 + 104,  y  + 255 + 15);
            //house3
        txSetFillColor (TX_GRAY);
        txRectangle (x  + 120, y  + 155, x  + 165 + 120, y  + 225 + 155);
            //window3
        txSetFillColor (TX_YELLOW);
        txRectangle (x  + 15 + 120, y  +  30 + 155, x  +  60 + 120, y  +  45 + 155);
        txRectangle (x  + 75 + 120, y  +  27 + 155, x  + 120 + 120, y  +  72 + 155);
        txRectangle (x  + 12 + 120, y  + 102 + 155, x  +  72 + 120, y  + 138 + 155);
        txRectangle (x  + 90 + 120, y  + 102 + 155, x  + 135 + 120, y  + 138 + 155);
        txRectangle (x  + 75 + 120, y  + 153 + 155, x  + 111 + 120, y  + 210 + 155);
        txRectangle (x  + 30 + 120, y  + 165 + 155, x  +  60 + 120, y  + 221 + 155);
            //house4
        txSetFillColor (TX_GRAY);
        txRectangle (x  + 1000, y  - 195, x  + 180 + 1000, y  + 305 - 195);
            //window4
        txSetFillColor (TX_YELLOW);
        txRectangle (x  - 150 + 1175, y  + 150 - 195,  x  - 130 + 1175, y  + 240 - 195);
        txRectangle (x  - 100 + 1175, y  + 133 - 195,  x  -  50 + 1175, y  + 185 - 195);
        }
    if (choice == 2)
        {
        txSetFillColor (TX_GRAY);
        POINT house[4] = {{x, y}, {x, y + 305}, {x + 380, y + 250}, {x + 380, y}};
        txPolygon(house, 4);

        POINT wall[4] = {{x, y}, {x, y + 305}, {x - 60, y + 220}, {x - 60, y}};
        txPolygon(wall, 4);

        POINT house2[4] = {{x + 380, y}, {x + 380, y + 250}, {x + 580, y + 218}, {x + 580, y}};
        txPolygon(house2, 4);

        }

    }

//----------------------------------------
void TrafficLight (int x, int y, int first, int second, int third)
    {
    txSetFillColor (TX_GRAY);
    txRectangle (x,      y,      x + 15, y -  60);
    txRectangle (x - 12, y - 60, x + 24, y - 129);

    if (first == 1)
        {txSetFillColor (TX_BLACK);}
    else
        {txSetFillColor (RGB(255, 0, 0));}
    txCircle (x + 9, y - 114, 8);

    if (second == 1)
        {txSetFillColor (TX_BLACK);}
    else
        {txSetFillColor (RGB(255, 215, 0));}
    txCircle (x + 9, y - 96, 8);

    if (third == 1)
        {txSetFillColor (TX_BLACK);}
    else
        {txSetFillColor (TX_GREEN);}
    txCircle (x + 9, y - 78, 8);
    }

//||||||||||BACKGROUND SECOND||||||||||||||||
void Background_Second ()
    {
    txClear ();

    txSetFillColor (RGB(220, 220, 220));
    txRectangle (0, 0, 1200, 800);

    for (int i = 1; i <= 1200; i++)
        {
        //txLine(0 * i, 1200 - 5 * i, 0 + 25 * i, 1200 + 55 * i);
        }

    Rails (0, 450);
    Stop (900, 600, 1);
    Stop (700, 200, 2);

    Houses(50, -150, 2);

    Pavement (0, 900, 2);

    }

//============ELEMENTS BACKGROUND SECOND=======

void Rails (int x, int y)
    {
    txSetColor (TX_BLACK, 2);
    txLine(x, y     , x + 1200, y - 200);
    txLine(x, y + 50, x + 1200, y - 150);

    txLine(x, y + 100, x + 1200, y - 100);
    txLine(x, y + 150, x + 1200, y -  50);
/*
    int k = 1;
    for (int i = 1; i <= 15; i++)
        {
        txLine(x      * k, y -  5 * k, x + 25 * k, y +  55 * k);
        txLine(x + 25 * k, y + 90 * k, x + 50 * k, y + 155 * k);
        k += 50;
        }
        */
    }

//----------------------------------------
void Stop (int x, int y, int type)
    {
    txSetColor(RGB(0, 0, 0), 2);

    if (type == 2)
            {
            txSetFillColor(RGB(224, 255, 255));
            POINT back[4] = {{ROUND(x + 0.1 * 2.25),  ROUND(y - 60 * 2.25)}, {ROUND(x + 0.1 * 2.25), ROUND(y + 0.1 * 2.25)},
                             {ROUND(x +  80 * 2.25),  ROUND(y - 10 * 2.25)}, {ROUND(x +  80 * 2.25), ROUND(y - 70  * 2.25)}};
            txPolygon(back, 4);
            }

    txSetFillColor(RGB(224, 255, 255));

    POINT side[4] = {{ROUND(x + 0.1 * 2.25), ROUND(y  + 0.1 * 2.25)}, {ROUND(x + 0.1 * 2.25),  ROUND(y - 60 * 2.25)},
                     {ROUND(x + 20  * 2.25), ROUND(y - 35   * 2.25)}, {ROUND(x + 20  * 2.25),  ROUND(y + 25 * 2.25)}};
    txPolygon(side, 4);


    POINT side2[4] = {{ROUND(x + 100 * 2.25), ROUND(y + 15 * 2.25)}, {ROUND(x + 100 * 2.25),  ROUND(y - 45 * 2.25)},
                      {ROUND(x +  80 * 2.25), ROUND(y - 70 * 2.25)}, {ROUND(x +  80 * 2.25),  ROUND(y - 10 * 2.25)}};
    txPolygon(side2, 4);

    if (type == 1)
    {
    txSetFillColor(RGB(224, 255, 255));
    POINT back[4] = {{ROUND(x +  20 * 2.25), ROUND(y - 35  * 2.25)}, {ROUND(x +  20 * 2.25),  ROUND(y + 10 * 2.25)},
                     {ROUND(x + 100 * 2.25), ROUND(y + 0.1 * 2.25)}, {ROUND(x + 100 * 2.25),  ROUND(y - 45 * 2.25)}};
    txPolygon(back, 4);
    }

    txSetFillColor(RGB(0, 0, 128));

    POINT roof[4] = {{ROUND(x + 100 * 2.25), ROUND(y - 45 * 2.25)}, {ROUND(x +  80 * 2.25), ROUND(y - 70 * 2.25)},
                     {ROUND(x + 0.1 * 2.25), ROUND(y - 60 * 2.25)}, {ROUND(x +  20 * 2.25), ROUND(y - 35 * 2.25)}};
    txPolygon(roof, 4);
    }
//||||||||||||||BACKGROUND THIRD|||||||||||||
//-------------------------
void Background_Third ()
    {
    Highway(0, 0);
    Curb(0, 0);
    Lawn(0, 0);
    Grass(566, 751);
    Grass(728, 629);
    Grass(795, 417);
    Grass(1109, 85);
    Grass(1180, 179);
    Grass(982, 257);
    Grass(1105, 323);
    Grass(1133, 513);
    Grass(960, 523);
    Grass(1090, 647);
    Grass(908, 749);
    Grass(1156, 776);
    Footpath(0, 0);
    }
//============ELEMENTS BACKGROUND THIRD=======

void Highway (int x, int y)
    {
    txSetColor (RGB(192, 192, 192));
    txSetFillColor (RGB(192, 192, 192));
    POINT road[3] = {{ROUND(x + 0.1), ROUND(y + 0.1)}, {ROUND(x + 643),  ROUND(y + 0.1)},
                     {ROUND(x + 0.1), ROUND(y + 645 )}};
    txPolygon(road, 3);
    txSetFillColor (RGB(255, 255, 255));
    txSetColor (RGB(255, 255, 255), 4);
    txLine(x + 0.1, y + 207, x +  58, y + 158);
    txLine(x + 212, y +  54, x + 273, y + 0.1);
    }
//----------------------------------------
void Curb (int x, int y)
    {
    txSetColor (RGB(105, 105, 105));
    txSetFillColor (RGB(105, 105, 105));
    POINT curb1[4] = {{ROUND(x + 0.1), ROUND(y + 646)}, {ROUND(x + 0.1),  ROUND(y + 667)},
                      {ROUND(x + 665), ROUND(y + 0.1)}, {ROUND(x + 644),  ROUND(y + 0.1)}};
    txPolygon(curb1, 4);
    POINT curb2[4] = {{ROUND(x +  385), ROUND(y + 800)}, {ROUND(x + 403),  ROUND(y + 800)},
                      {ROUND(x + 1070), ROUND(y + 0.1)}, {ROUND(x + 1054),  ROUND(y + 0.1)}};
    txPolygon(curb2, 4);
    }
//----------------------------------------
void Grass (int x, int y)
    {
    txSetColor (RGB(0, 100, 0));
    txSetFillColor (RGB(0, 100, 0));
    POINT grass1[4] = {{ROUND(x + 0.1), ROUND(y + 0.1)}, {ROUND(x - 7),  ROUND(y - 27)},
                       {ROUND(x - 3  ), ROUND(y - 27 )}, {ROUND(x + 3),  ROUND(y -  1)}};
    txPolygon(grass1, 4);
    POINT grass2[4] = {{ROUND(x + 6), ROUND(y +  2)}, {ROUND(x + 5),  ROUND(y - 25)},
                       {ROUND(x + 9), ROUND(y - 25)}, {ROUND(x + 9),  ROUND(y +  2)}};
    txPolygon(grass2, 4);
    POINT grass3[4] = {{ROUND(x + 14), ROUND(y -  1)}, {ROUND(x + 16),  ROUND(y - 29)},
                       {ROUND(x + 19), ROUND(y - 30)}, {ROUND(x + 17),  ROUND(y +  1)}};
    txPolygon(grass3, 4);
    }
//----------------------------------------
void Footpath (int x, int y)
    {
    txSetColor (RGB(211, 211, 211));
    txSetFillColor (RGB(211, 211, 211));
    POINT footpath[5] = {{ROUND(x + 0.1 ), ROUND(y + 668)}, {ROUND(x + 666), ROUND(y + 0.1)},
                         {ROUND(x + 1054), ROUND(y + 0.1)}, {ROUND(x + 384), ROUND(y + 800)},
                         {ROUND(x + 0.1 ), ROUND(y + 800)}};
    txPolygon(footpath, 5);
    }
//----------------------------------------
void Lawn (int x, int y)
    {
    txSetColor (RGB(154, 205, 50));
    txSetFillColor (RGB(154, 205, 50));
    POINT lawn[4] = {{ROUND(x + 404),  ROUND(y + 800)}, {ROUND(x + 1071), ROUND(y + 0.1)},
                     {ROUND(x + 1200), ROUND(y + 0.1)}, {ROUND(x + 1200), ROUND(y + 800)}};
    txPolygon(lawn, 4);
    }
//===============CROWD SCENE===========
//----------------------------------------
void people_woman (int x, int y, double scale, double dist)
    {
    txSetFillColor (TX_BLACK);
    txCircle (ROUND(x + 0.5 *scale), ROUND(y + 0.5 *scale), ROUND(23 *scale));

    POINT body[4] = { {x                  , ROUND(y + 23*scale)}, {ROUND(x + 27*scale), ROUND(y + 95*scale)},
                      {ROUND(x - 27*scale), ROUND(y + 95*scale)}, {x                  , ROUND(y + 23*scale)} };
    txPolygon (body, 4);

    txLine (x - 5, ROUND(y + 95*scale), ROUND(x - dist - 5), ROUND(y + 115*scale));
    txLine (x + 5, ROUND(y + 95*scale), ROUND(x + dist + 5), ROUND(y + 115*scale));
    }
//-----------------------------------------------
void people_men (int x, int y, double scale, double dist)
    {
    txSetFillColor (TX_BLACK);
    txCircle (ROUND(x + 0.5 *scale), ROUND(y + 0.5 *scale), ROUND(23 *scale));

    txRectangle (x + 18, ROUND(y + 95*scale), x - 16, ROUND(y + 24*scale));

    txLine (x - 5, ROUND(y + 95*scale), ROUND(x - 5 + dist), ROUND(y + 115*scale));
    txLine (x + 5, ROUND(y + 95*scale), ROUND(x + 5 - dist), ROUND(y + 115*scale));
    }

//==================MAIN CHARACTER FIRST=======

//{-------------------------------------------------------
//!     Процедура рисования девочки
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём руки
//! dist    == расстояние между ногами
//!
//}------------------------------------------------------

void Girl (int x, int y, double scale, double width, int height, int dist)
    {
    //phone
    txSetFillColor (RGB(0, 255, 255));
    POINT phone[4] = { {ROUND(x + 27 *scale), ROUND(y + 27 + height *scale)}, {ROUND(x + 27 *scale), ROUND(y + 56 + height *scale)},
                       {ROUND(x + 18 *scale), ROUND(y + 54 + height *scale)}, {ROUND(x + 18 *scale), ROUND(y + 29 + height *scale)} };
    txPolygon (phone, 4);

    //shoes
    txLine (ROUND(x - 6 - dist *scale), ROUND(y + 128 *scale), ROUND(x +  6 - dist *scale), ROUND(y + 130 *scale));
    txLine (ROUND(x + 6 + dist *scale), ROUND(y + 128 *scale), ROUND(x + 18 + dist *scale), ROUND(y + 130 *scale));

    //body
        //hair
    txSetColor (RGB(139, 69, 19), 2 + width);
    txSetFillColor (RGB(139, 69, 19));
    txCircle (ROUND(x + 0.5 *scale), ROUND(y + 0.5 *scale), ROUND(24 *scale));

    POINT body[4] = { {ROUND(x - 22 *scale), ROUND(y -  7 *scale)}, {ROUND(x - 17 *scale), ROUND(y + 38 *scale)},
                      {ROUND(x - 28 *scale), ROUND(y + 38 *scale)}, {ROUND(x - 22 *scale), ROUND(y -  7 *scale)} };
    txPolygon (body, 4);

        //dress
    txSetColor (RGB(0, 0, 139), 2 + width);
    txSetFillColor (RGB(0, 0, 139));

    POINT body2[4] = { {ROUND(x +  3 *scale), ROUND(y + 23 *scale)}, {ROUND(x + 33 *scale), ROUND(y + 98 *scale)},
                       {ROUND(x - 33 *scale), ROUND(y + 98 *scale)}, {ROUND(x +  3 *scale), ROUND(y + 23 *scale)} };
    txPolygon (body2, 4);

        //head
    txSetColor (RGB(255, 228, 196), 2 + width);
    txSetFillColor (RGB(255, 228, 196));
    txCircle (ROUND(x + 3 *scale), ROUND(y + 2 *scale), ROUND(22 *scale));

        //fringe
    txSetColor (RGB(139, 69, 19), 2 + width);
    txSetFillColor (RGB(139, 69, 19));
    POINT body3[4] = { {ROUND(x + 17.5 *scale), ROUND(y - 18 *scale)}, {ROUND(x - 19 *scale),  ROUND(y +  5 *scale)},
                       {ROUND(x - 18.5 *scale), ROUND(y - 11 *scale)}, {ROUND(x -  1 *scale),  ROUND(y - 22 *scale)} };
    txPolygon (body3, 4);

        //legs
    txSetColor (TX_BLACK, 2 + width);
    txSetFillColor (RGB (255, 248, 220));
    txLine (ROUND(x - 3 *scale), ROUND(y + 98 *scale), ROUND(x - 3 - dist *scale), ROUND(y + 128 *scale));
    txLine (ROUND(x + 9 *scale), ROUND(y + 98 *scale), ROUND(x + 9 + dist *scale), ROUND(y + 128 *scale));

    //headphones
    txSetColor (TX_BLACK, 7 + width);
    txSetFillColor (RGB(0, 0, 0));
    txCircle (ROUND(x + 1 *scale), ROUND(y + 4 *scale), ROUND(10 *scale));
    txLine (ROUND(x + 1 *scale), ROUND(y - 6 *scale), ROUND(x - 1 *scale), ROUND(y - 24 *scale));

    //arm_handbag
    txSetColor (RGB(184, 134, 11), 2 + width);
    txCircle (ROUND(x + 3 *scale), ROUND(y + 56 *scale), ROUND(4 *scale));

    txSetFillColor (RGB(0, 0, 139));
    txSetColor (RGB(184, 134, 11), 2 + width);
    txRectangle (ROUND(x - 1 *scale), ROUND(y + 56 *scale), ROUND(x + 7 *scale), ROUND(y + 76 *scale));

    txSetFillColor (RGB(250, 235, 215));
    txRectangle (ROUND(x - 4 *scale), ROUND(y + 76 *scale), ROUND(x + 9 *scale), ROUND(y + 91 *scale));

    txSetColor (RGB(0, 0, 139), 2 + width);
    txLine (ROUND(x - 0.1 *scale), ROUND(y + 56 *scale), ROUND(x + 5 *scale), ROUND(y + 56 *scale));

    txSetColor (TX_BLACK, 2 + width);
    txLine (ROUND(x + 3 *scale), ROUND(y + 56 *scale), ROUND(x + 27 *scale), ROUND(y + 46 + height *scale));
    }

//-----------------------------------------------

//{-------------------------------------------------------
//!     Процедура рисования императрицы
//!
//!             параметры:
//! x, y     == координаты начальной точки
//! scale    == размер при масштабировании
//! width    == толщина линий
//! distance == расстояние между рук
//!
//}------------------------------------------------------

void Empress (int x, int y, double scale, double width, int distance)
    {
    txSetColor (RGB(0, 0, 0), 2 + width);
    txSetFillColor (RGB(255, 0, 0));

    //collar
    POINT collar[4] = { {ROUND(x + 0.1 *scale), ROUND(y - 60 *scale)}, {ROUND(x + 37 *scale), ROUND(y + 4 *scale)},
                        {ROUND(x + 0.1 *scale), ROUND(y + 62 *scale)}, {ROUND(x - 37 *scale), ROUND(y + 4 *scale)} };
    txPolygon (collar, 4);

    //dress
    POINT empress2[4] = { {ROUND(x + 0.1 *scale),  ROUND(y +  35 *scale)}, {ROUND(x + 46  *scale),  ROUND(y + 130 *scale)},
                          {ROUND(x - 46  *scale),  ROUND(y + 130 *scale)}, {ROUND(x + 0.1 *scale),  ROUND(y +  35 *scale)} };
    txPolygon (empress2, 4);

    //sleeves
    txSetColor (RGB(255, 0, 0), 2 + width);
    POINT empress3[4] = { {ROUND(x + 0.1 *scale), ROUND(y +  6 *scale)}, {ROUND(x + 26 *scale), ROUND(y + 44 *scale)},
                          {ROUND(x + 0.1 *scale), ROUND(y + 90 *scale)}, {ROUND(x - 26 *scale), ROUND(y + 44 *scale)} };
    txPolygon (empress3, 4);

    //braid
    txSetColor (RGB(0, 0, 0), 2 + width);
    txSetFillColor (RGB(0, 0, 0));
    POINT braid1[4] = { {ROUND(x - 11 *scale), ROUND(y + 15 *scale)}, {ROUND(x - 18 *scale), ROUND(y + 30 *scale)},
                        {ROUND(x -  4 *scale), ROUND(y + 30 *scale)}, {ROUND(x - 11 *scale), ROUND(y + 15 *scale)} };
    txPolygon (braid1, 4);

    POINT braid2[4] = { {ROUND(x - 11 *scale), ROUND(y + 23 *scale)}, {ROUND(x - 18 *scale), ROUND(y + 39 *scale)},
                        {ROUND(x -  4 *scale), ROUND(y + 39 *scale)}, {ROUND(x - 11 *scale), ROUND(y + 23 *scale)} };
    txPolygon (braid2, 4);

    POINT braid3[4] = { {ROUND(x - 11 *scale), ROUND(y + 30 *scale)}, {ROUND(x - 18 *scale), ROUND(y + 46 *scale)},
                        {ROUND(x -  4 *scale), ROUND(y + 46 *scale)}, {ROUND(x - 11 *scale), ROUND(y + 30 *scale)} };
    txPolygon (braid3, 4);

    //hair
    txCircle (ROUND(x + 0.1 *scale), ROUND(y - 2 *scale), ROUND(26 *scale));

    //neck
    txSetColor (RGB(255, 228, 196), 2 + width);
    txSetFillColor (RGB(255, 235, 205));
    POINT neck[4] = { {ROUND(x + 0.1 *scale), ROUND(y +  1 *scale)}, {ROUND(x + 8 *scale), ROUND(y + 19 *scale)},
                      {ROUND(x + 0.1 *scale), ROUND(y + 35 *scale)}, {ROUND(x - 8 *scale), ROUND(y + 19 *scale)} };
    txPolygon (neck, 4);

    //head
    txCircle (ROUND(x + 0.1 *scale), ROUND(y + 0.1 *scale), ROUND(21 *scale));

    //arms
    txLine (ROUND(x + 0.1 - distance *scale), ROUND(y + 75 *scale), ROUND(x - 9 *scale), ROUND(y + 60 *scale));
    txLine (ROUND(x + 0.1 + distance *scale), ROUND(y + 75 *scale), ROUND(x + 9 *scale), ROUND(y + 60 *scale));

    }

//-----------------------------------------------

//{-------------------------------------------------------
//!     Процедура рисования кота
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём хвоста
//!
//}------------------------------------------------------


void Cat (int x, int y, double scale, double width, int height)
    {
    txSetColor (RGB(0, 0, 0), 2 + width);
    txSetFillColor (RGB(0, 0, 0));

    //ears
    POINT earL[4] = { {ROUND(x - 8 *scale), ROUND(y - 15 *scale)}, {ROUND(x - 11 *scale), ROUND(y + 0.1 *scale)},
                      {ROUND(x - 5 *scale), ROUND(y - 13 *scale)}, {ROUND(x -  8 *scale), ROUND(y - 15  *scale) } };
    txPolygon (earL, 4);

    POINT earR[4] = { {ROUND(x +  8 *scale), ROUND(y - 15  *scale)}, {ROUND(x + 5 *scale), ROUND(y - 13 *scale)},
                      {ROUND(x + 11 *scale), ROUND(y + 0.1 *scale)}, {ROUND(x + 8 *scale), ROUND(y - 15 *scale)} };
    txPolygon (earR, 4);

    //tail
    POINT tail[4] = { {ROUND(x + 10 *scale), ROUND(y + 55 *scale)}, {ROUND(x + 15 + height *scale), ROUND(y + 26 *scale)},
                      {ROUND(x +  5 *scale), ROUND(y + 55 *scale)}, {ROUND(x + 10 *scale),         ROUND(y + 55 *scale)} };
    txPolygon (tail, 4);

    txSetColor (RGB (255, 228, 196), 2 + width);

    //head
    txSetFillColor (RGB (255, 228, 196));
    txCircle (ROUND(x + 0.1 *scale), ROUND(y + 0.1 *scale), ROUND(11 *scale));

    //body
    POINT body[4] = { {ROUND(x + 0.1 *scale), ROUND(y + 0.1 *scale)}, {ROUND(x + 10  *scale),  ROUND(y + 55  *scale)},
                      {ROUND(x - 10  *scale), ROUND(y + 55  *scale)}, {ROUND(x + 0.1 *scale),  ROUND(y + 0.1 *scale)} };
    txPolygon (body, 4);

    txSetColor (RGB(160, 82, 45));
    txSetFillColor (RGB(160, 82, 45));

    //marks
    txCircle (ROUND(x - 5 *scale), ROUND(y -  3 *scale), ROUND(5 *scale));
    txCircle (ROUND(x + 1 *scale), ROUND(y + 24 *scale), ROUND(2 *scale));
    txCircle (ROUND(x - 2 *scale), ROUND(y + 52 *scale), ROUND(3 *scale));

    txSetColor (RGB (0, 0, 0), 2 + width);
    txSetFillColor (RGB (0, 0, 0));

    //face
    txCircle (ROUND(x + 0.1 *scale), ROUND(y + 4.5 *scale), ROUND(5 *scale));

    //legs
    POINT legR[4] = { {ROUND(x + 5 *scale), ROUND(y + 35 *scale)}, {ROUND(x + 6 *scale), ROUND(y + 55 *scale)},
                      {ROUND(x + 4 *scale), ROUND(y + 55 *scale)}, {ROUND(x + 5 *scale), ROUND(y + 35 *scale)} };
    txPolygon (legR, 4);

    POINT legL[4] = { {ROUND(x - 3 *scale), ROUND(y + 35 *scale)}, {ROUND(x - 2 *scale), ROUND(y + 55 *scale)},
                      {ROUND(x - 4 *scale), ROUND(y + 55 *scale)}, {ROUND(x - 3 *scale), ROUND(y + 35 *scale)} };
    txPolygon (legL, 4);
    }
//-----------------------------------------------

//{-------------------------------------------------------
//!     Процедура рисования грузовика
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//!
//}------------------------------------------------------
void Truck (int x, int y, double scale)
    {
        //wheel_hidden
     txSetFillColor (RGB(0, 0, 0));
     txEllipse (ROUND(x +  85*scale), ROUND(y + 115*scale), ROUND(x + 117*scale), ROUND(y + 80*scale));

        //cabin
     txSetFillColor (RGB(47, 79, 79));
     POINT cabin_front[8] = {{ROUND(x + 0.1*scale), ROUND(y + 0.1*scale)}, {ROUND(x +  95*scale), ROUND(y - 15*scale)},
                             {ROUND(x + 95*scale ), ROUND(y + 40*scale )}, {ROUND(x + 120*scale), ROUND(y + 55*scale)},
                             {ROUND(x + 30*scale ), ROUND(y + 70*scale )}, {ROUND(x + 0.1*scale), ROUND(y + 55*scale)},
                             {ROUND(x + 95*scale ), ROUND(y + 40*scale )}, {ROUND(x + 0.1*scale), ROUND(y + 55*scale)}};
     txPolygon (cabin_front, 8);

     POINT _front[4] = {{ROUND(x + 120*scale), ROUND(y +  55*scale)}, {ROUND(x +  30*scale), ROUND(y +  70*scale)},
                        {ROUND(x +  30*scale), ROUND(y + 115*scale)}, {ROUND(x + 120*scale), ROUND(y + 100*scale)}};
     txPolygon (_front, 4);

     POINT cabin_side[6] = {{ROUND(x + 30 *scale), ROUND(y + 115*scale)}, {ROUND(x - 45*scale ), ROUND(y + 65*scale )},
                            {ROUND(x - 45 *scale), ROUND(y -  25*scale)}, {ROUND(x + 0.1*scale), ROUND(y + 0.1*scale)},
                            {ROUND(x + 0.1*scale), ROUND(y +  55*scale)}, {ROUND(x + 30*scale ), ROUND(y + 70*scale )}};
     txPolygon (cabin_side, 6);

     POINT cabin_up[4] = {{ROUND(x + 0.1*scale), ROUND(y + 0.1*scale)}, {ROUND(x + 95*scale), ROUND(y - 15*scale)},
                          {ROUND(x + 45 *scale), ROUND(y - 35 *scale)}, {ROUND(x - 45*scale), ROUND(y - 25*scale)}};
     txPolygon (cabin_up, 4);

        //pod
     txSetFillColor (RGB(192, 192, 192));
     POINT pod_side[4] = {{ROUND(x -  45*scale), ROUND(y +  65*scale)}, {ROUND(x - 180*scale), ROUND(y - 35*scale)},
                          {ROUND(x - 180*scale), ROUND(y - 125*scale)}, {ROUND(x -  45*scale), ROUND(y - 45*scale)}};
     txPolygon (pod_side, 4);

     POINT pod_fr[4] = {{ROUND(x + 45*scale), ROUND(y - 35*scale)}, {ROUND(x - 45*scale), ROUND(y - 25*scale)},
                        {ROUND(x - 45*scale), ROUND(y - 45*scale)}, {ROUND(x + 45*scale), ROUND(y - 55*scale)}};
     txPolygon (pod_fr, 4);

     POINT pod_up[4] = {{ROUND(x - 45*scale), ROUND(y -  45*scale)}, {ROUND(x +  45*scale), ROUND(y -  55*scale)},
                        {ROUND(x - 85*scale), ROUND(y - 130*scale)}, {ROUND(x - 180*scale), ROUND(y - 125*scale)}};
     txPolygon (pod_up, 4);

     //wheels
     txSetFillColor (RGB(0, 0, 0));
     txEllipse (ROUND(x + 0.1*scale), ROUND(y + 125*scale), ROUND(x +  30*scale), ROUND(y + 80*scale));
     txEllipse (ROUND(x - 83*scale ), ROUND(y +  75*scale), ROUND(x -  53*scale), ROUND(y + 30*scale));
     txEllipse (ROUND(x - 170*scale), ROUND(y -  35*scale), ROUND(x - 140*scale), ROUND(y + 10*scale));
    }

//===================MAIN CHARACTERS SECOND========

//{-------------------------------------------------------
//!     Процедура рисования Игоря
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём руки
//! dist    == расстояние между ногами
//!
//}------------------------------------------------------

void Igor (int x, int y, double scale, double width, int height, int dist)
    {
    //shoes
    txSetColor (RGB(0, 0, 0), 2 + width);
    txLine (ROUND(x - 6 - dist *scale), ROUND(y + 128 *scale), ROUND(x +  6 - dist *scale), ROUND(y + 130 *scale));
    txLine (ROUND(x + 6 + dist *scale), ROUND(y + 128 *scale), ROUND(x + 18 + dist *scale), ROUND(y + 130 *scale));

    //body
        //clothes
    txSetColor (RGB(65, 105, 225), 2 + width);
    txSetFillColor (RGB(65, 105, 225));
    txRectangle(ROUND(x - 20 *scale), ROUND(y +  23 *scale), ROUND(x + 20 *scale), ROUND(y +  98 *scale));

        //head
    txSetColor (RGB(255, 228, 196), 2 + width);
    txSetFillColor (RGB(255, 228, 196));
    txCircle (ROUND(x + 0.01 *scale), ROUND(y + 0.01 *scale), ROUND(22 *scale));

        //fringe
    txSetColor (RGB(160, 82, 45), 2 + width);
    txSetFillColor (RGB(160, 82, 45));
    POINT body3[4] = { {ROUND(x + 14.5  *scale), ROUND(y - 18 *scale)}, {ROUND(x - 22 *scale),  ROUND(y +  5 *scale)},
                       {ROUND(x - 22.25 *scale), ROUND(y - 11 *scale)}, {ROUND(x -  6 *scale),  ROUND(y - 22 *scale)} };
    txPolygon (body3, 4);

        //legs
    txSetColor (TX_BLACK, 2 + width);
    txSetFillColor (RGB (255, 248, 220));
    txLine (ROUND(x -  4 *scale), ROUND(y + 98 *scale), ROUND(x -  4 - dist *scale), ROUND(y + 128 *scale));
    txLine (ROUND(x + 10 *scale), ROUND(y + 98 *scale), ROUND(x + 10 + dist *scale), ROUND(y + 128 *scale));

       //arms
    txSetColor (TX_BLACK, 2 + width);
    txLine (ROUND(x + 4 *scale), ROUND(y + 50 *scale), ROUND(x + 37 *scale), ROUND(y + 40 + height *scale));
    txLine (ROUND(x + 7 *scale), ROUND(y + 56 *scale), ROUND(x + 37 *scale), ROUND(y + 46 + height *scale));

    //hat
    txSetColor (RGB(255, 165, 0), 2 + width);
    txSetFillColor (RGB (255, 165, 0));
    txRectangle(ROUND(x - 24*scale), ROUND(y - 12 *scale), ROUND(x + 25 *scale), ROUND(y - 24 *scale));
    txSetColor (RGB(0, 0, 0), 2 + width);
    txSetFillColor (RGB (0, 0, 0));
    txRectangle(ROUND(x + 15*scale), ROUND(y - 12 *scale), ROUND(x + 39 *scale), ROUND(y - 17 *scale));

    }
//-----------------------------------------------

//{-------------------------------------------------------
//!     Процедура рисования трамвая
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! type    == вид трамвая
//!
//}------------------------------------------------------
void Tram (int x, int y, double scale, int type)
    {
    int x1 = x;
    int x2 = x - 560;
    int y1 = y;
    int y2 = y + 93;
    txSetColor(TX_BLACK, 2);
    txSetFillColor(TX_BLACK);
    //wheels
    txCircle(ROUND(x1 + 266 *scale), ROUND(y1 + 160 *scale), ROUND(27 *scale));
    txCircle(ROUND(x1 + 600 *scale), ROUND(y1 + 106 *scale), ROUND(27 *scale));
                //-------------------
    txCircle(ROUND(x2 + 266 *scale), ROUND(y2 + 160 *scale), ROUND(27 *scale));
    txCircle(ROUND(x2 + 600 *scale), ROUND(y2 + 106 *scale), ROUND(27 *scale));

    //body
    txSetFillColor(TX_WHITE);
    POINT tram_face_f[4] = {{ROUND(x1 + 0.1  *scale), ROUND(y1 + 0.1 *scale)}, {ROUND(x1 +  20 *scale),  ROUND(y1 -  175 *scale)},
                            {ROUND(x1 + 130  *scale), ROUND(y1 - 75  *scale)}, {ROUND(x1 + 100 *scale),  ROUND(y1 +   85 *scale)}};
    txPolygon(tram_face_f, 4);
                //-------------------
    POINT tram_face_s[4] = {{ROUND(x2 + 0.1  *scale), ROUND(y2 + 0.1 *scale)}, {ROUND(x2 +  20 *scale),  ROUND(y2 -  175 *scale)},
                            {ROUND(x2 + 130  *scale), ROUND(y2 - 75  *scale)}, {ROUND(x2 + 100 *scale),  ROUND(y2 +   85 *scale)}};
    txPolygon(tram_face_s, 4);
    //-------------------
    POINT tram_face_down_f[4] = {{ROUND(x1 + 0.1 *scale), ROUND(y1 + 0.1 *scale)}, {ROUND(x1 +  20 *scale),  ROUND(y1 + 80 *scale)},
                                 {ROUND(x1 + 130 *scale), ROUND(y1 + 185 *scale)}, {ROUND(x1 + 100 *scale),  ROUND(y1 + 85 *scale)}};
    txPolygon(tram_face_down_f, 4);
                 //-------------------
    POINT tram_face_down_s[4] = {{ROUND(x2 + 0.1 *scale), ROUND(y2 + 0.1 *scale)}, {ROUND(x2 +  20 *scale),  ROUND(y2 + 80 *scale)},
                                 {ROUND(x2 + 130 *scale), ROUND(y2 + 185 *scale)}, {ROUND(x2 + 100 *scale),  ROUND(y2 + 85 *scale)}};
    txPolygon(tram_face_down_s, 4);
    //-------------------
    POINT tram_body_f[6] = {{ROUND(x1 + 130 *scale), ROUND(y1 + 185 *scale)}, {ROUND(x1 + 100 *scale), ROUND(y1 +  85 *scale)},
                            {ROUND(x1 + 130 *scale), ROUND(y1 -  75 *scale)}, {ROUND(x1 + 800 *scale), ROUND(y1 - 180 *scale)},
                            {ROUND(x1 + 820 *scale), ROUND(y1 -  20 *scale)}, {ROUND(x1 + 800 *scale), ROUND(y1 +  80 *scale)}};
    txPolygon(tram_body_f, 6);

    txSetColor(TX_BLACK, 4);
    txLine(ROUND(x + 40), ROUND(y + 60), ROUND(x - 30), ROUND(y + 90));
                //-------------------
    txSetColor(TX_BLACK, 2);
    POINT tram_body_s[6] = {{ROUND(x2 + 130 *scale), ROUND(y2 + 185 *scale)}, {ROUND(x2 + 100 *scale), ROUND(y2 +  85 *scale)},
                            {ROUND(x2 + 130 *scale), ROUND(y2 -  75 *scale)}, {ROUND(x2 + 800 *scale), ROUND(y2 - 180 *scale)},
                            {ROUND(x2 + 820 *scale), ROUND(y2 -  20 *scale)}, {ROUND(x2 + 800 *scale), ROUND(y2 +  80 *scale)}};
    txPolygon(tram_body_s, 6);

    //-------------------
    txSetFillColor (RGB (220, 20, 60));
    POINT tram_roof_f[4] = {{ROUND(x1 +  20 *scale), ROUND(y1 - 175 *scale)}, {ROUND(x1 + 130 *scale), ROUND(y1 -  75 *scale)},
                            {ROUND(x1 + 800 *scale), ROUND(y1 - 180 *scale)}, {ROUND(x1 + 690 *scale), ROUND(y1 - 280 *scale)}};
    txPolygon(tram_roof_f, 4);
                //-------------------
    POINT tram_roof_s[4] = {{ROUND(x2 +  20 *scale), ROUND(y2 - 175 *scale)}, {ROUND(x2 + 130 *scale), ROUND(y2 -  75 *scale)},
                            {ROUND(x2 + 800 *scale), ROUND(y2 - 180 *scale)}, {ROUND(x2 + 690 *scale), ROUND(y2 - 280 *scale)}};
    txPolygon(tram_roof_s, 4);

    //line
    POINT line_body_f[4] = {{ROUND(x1 + 100 *scale), ROUND(y1 +  85 *scale)}, {ROUND(x1 + 820 *scale), ROUND(y1 -   20 *scale)},
                            {ROUND(x1 + 810 *scale), ROUND(y1 +  30 *scale)}, {ROUND(x1 + 115 *scale), ROUND(y1 +  135 *scale)}};
    txPolygon(line_body_f, 4);
                //-------------------
    POINT line_body_s[4] = {{ROUND(x2 + 100 *scale), ROUND(y2 +  85 *scale)}, {ROUND(x2 + 820 *scale), ROUND(y2 -   20 *scale)},
                            {ROUND(x2 + 810 *scale), ROUND(y2 +  30 *scale)}, {ROUND(x2 + 115 *scale), ROUND(y2 +  135 *scale)}};
    txPolygon(line_body_s, 4);
    //-------------------
    POINT line_face_f[4] = {{ROUND(x1 + 115 *scale), ROUND(y1 + 135 *scale)}, {ROUND(x1 + 100 *scale), ROUND(y1 +  85 *scale)},
                            {ROUND(x1 + 0.1 *scale), ROUND(y1 + 0.1 *scale)}, {ROUND(x1 +  14 *scale), ROUND(y1 +  55 *scale)}};
    txPolygon(line_face_f, 4);
                //-------------------
    POINT line_face_s[4] = {{ROUND(x2 + 115 *scale), ROUND(y2 + 135 *scale)}, {ROUND(x2 + 100 *scale), ROUND(y2 +  85 *scale)},
                            {ROUND(x2 + 0.1 *scale), ROUND(y2 + 0.1 *scale)}, {ROUND(x2 +  14 *scale), ROUND(y2 +  55 *scale)}};
    txPolygon(line_face_s, 4);

    //window
    txSetFillColor (RGB (224, 255, 255));
    POINT window_body_f[4] = {{ROUND(x1 + 140 *scale), ROUND(y1 +  65 *scale)}, {ROUND(x1 + 790 *scale), ROUND(y1 -  28 *scale)},
                              {ROUND(x1 + 790 *scale), ROUND(y1 - 158 *scale)}, {ROUND(x1 + 140 *scale), ROUND(y1 -  60 *scale)}};
    txPolygon(window_body_f, 4);
                //-------------------
    POINT window_body_s[4] = {{ROUND(x2 + 140 *scale), ROUND(y2 +  65 *scale)}, {ROUND(x2 + 790 *scale), ROUND(y2 -  28 *scale)},
                              {ROUND(x2 + 790 *scale), ROUND(y2 - 158 *scale)}, {ROUND(x2 + 140 *scale), ROUND(y2 -  60 *scale)}};
    txPolygon(window_body_s, 4);
    //-------------------
    POINT window_face_f[4] = {{ROUND(x1 +  15  *scale), ROUND(y1 - 10 *scale)}, {ROUND(x1 + 30 *scale), ROUND(y1 -  135 *scale)},
                              {ROUND(x1 + 110  *scale), ROUND(y1 - 65 *scale)}, {ROUND(x1 + 85 *scale), ROUND(y1 +   50 *scale)}};
    txPolygon(window_face_f, 4);
                //-------------------
    POINT window_face_s[4] = {{ROUND(x2 +  15  *scale), ROUND(y2 - 10 *scale)}, {ROUND(x2 + 30 *scale), ROUND(y2 -  135 *scale)},
                              {ROUND(x2 + 110  *scale), ROUND(y2 - 65 *scale)}, {ROUND(x2 + 85 *scale), ROUND(y2 +   50 *scale)}};
    txPolygon(window_face_s, 4);

    //number
    if (type == 1)
        {txSetFillColor (RGB (255, 250, 250));
        POINT number_f[4] = {{ROUND(x1 + 25  *scale), ROUND(y1 + 0.1 *scale)}, {ROUND(x1 + 30 *scale), ROUND(y1 -  45 *scale)},
                             {ROUND(x1 + 70  *scale), ROUND(y1 - 15  *scale)}, {ROUND(x1 + 65 *scale), ROUND(y1 +  35 *scale)}};
        txPolygon(number_f, 4);
                    //-------------------
        POINT number_s[4] = {{ROUND(x2 + 25 *scale), ROUND(y2 + 0.1 *scale)}, {ROUND(x2 + 30 *scale), ROUND(y2 -  45 *scale)},
                             {ROUND(x2 + 70 *scale), ROUND(y2 - 15  *scale)}, {ROUND(x2 + 65 *scale), ROUND(y2 +  35 *scale)}};
        txPolygon(number_s, 4);
        }
    if (type == 2)
        {txSetFillColor (RGB (255, 250, 250));
        POINT number_f[4] = {{ROUND(x1 +  27  *scale), ROUND(y1 - 110 *scale)}, {ROUND(x1 +  30 *scale), ROUND(y1 -  140 *scale)},
                             {ROUND(x1 + 110  *scale), ROUND(y1 -  70 *scale)}, {ROUND(x1 + 105 *scale), ROUND(y1 -   40 *scale)}};
        txPolygon(number_f, 4);
                    //-------------------
        POINT number_s[4] = {{ROUND(x2 +  27  *scale), ROUND(y2 - 110 *scale)}, {ROUND(x2 +  30 *scale), ROUND(y2 -  140 *scale)},
                             {ROUND(x2 + 110  *scale), ROUND(y2 -  70 *scale)}, {ROUND(x2 + 105 *scale), ROUND(y2 -   40 *scale)}};
        txPolygon(number_s, 4);

        //lights
        txSetFillColor (RGB (255, 250, 205));
        txEllipse (ROUND(x1 + 18 *scale), ROUND(y1 + 35 *scale), ROUND(x1 + 45 *scale), ROUND(y1 + 60 *scale));
        txEllipse (ROUND(x1 + 58 *scale), ROUND(y1 + 65 *scale), ROUND(x1 + 85 *scale), ROUND(y1 + 90 *scale));
                    //-------------------
        txEllipse (ROUND(x2 + 18 *scale), ROUND(y2 + 35 *scale), ROUND(x2 + 45 *scale), ROUND(y2 + 60 *scale));
        txEllipse (ROUND(x2 + 58 *scale), ROUND(y2 + 65 *scale), ROUND(x2 + 85 *scale), ROUND(y2 + 90 *scale));
        }
    }

void Tram_Door_Left (int x, int y, double scale)
    {
    txSetFillColor (RGB(178, 34, 34));
    txSetColor (RGB(0, 0, 0), 2);
    POINT door_left[4] = {{ROUND(x + 150 *scale), ROUND(y -  45 *scale)}, {ROUND(x + 150 *scale), ROUND(y + 150 *scale)},
                          {ROUND(x + 200 *scale), ROUND(y + 143 *scale)}, {ROUND(x + 200 *scale), ROUND(y -  53 *scale)}};
    txPolygon(door_left, 4);
    }

void Tram_Door_Right (int x, int y, double scale)
    {
    txSetFillColor (RGB(178, 34, 34));
    txSetColor (RGB(0, 0, 0), 2);
    POINT door_right[4] = {{ROUND(x + 200  *scale), ROUND(y + 143 *scale)}, {ROUND(x + 200 *scale), ROUND(y -  53 *scale)},
                           {ROUND(x + 250  *scale), ROUND(y -  60 *scale)}, {ROUND(x + 250 *scale), ROUND(y + 134 *scale)}};
    txPolygon(door_right, 4);
    }

//===================MAIN CHARACTERS THIRD========
//{-------------------------------------------------------
//!     Процедура рисования Максима
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём руки
//! dist    == расстояние между ногами
//!
//}------------------------------------------------------
void Maxim (int x, int y, double scale, double width, int height, int dist)
    {
    //shoes
    txSetColor (RGB(0, 0, 0), 2 + width);
    txLine (ROUND(x + 10 - dist *scale), ROUND(y + 108 *scale), ROUND(x - 0.1 - dist *scale), ROUND(y + 110 *scale));
    txLine (ROUND(x - 6 + dist *scale), ROUND(y + 108 *scale), ROUND(x - 16 + dist *scale), ROUND(y + 110 *scale));

    //body
        //clothes
    txSetColor (RGB(30, 144, 255), 2 + width);
    txSetFillColor (RGB(30, 144, 255));
    txRectangle(ROUND(x + 20 *scale), ROUND(y +  23 *scale), ROUND(x - 20 *scale), ROUND(y +  88 *scale));

        //head
    txSetColor (RGB(255, 235, 205), 2 + width);
    txSetFillColor (RGB(255, 235, 205));
    txCircle (ROUND(x + 0.01 *scale), ROUND(y + 0.01 *scale), ROUND(24 *scale));

        //fringe
    txSetColor (RGB(250, 250, 210), 2 + width);
    txSetFillColor (RGB(250, 250, 210));
    POINT body3[4] = { {ROUND(x - 20.5  *scale), ROUND(y - 13 *scale)}, {ROUND(x + 20 *scale),  ROUND(y +  5 *scale)},
                       {ROUND(x + 22.25 *scale), ROUND(y - 17 *scale)}, {ROUND(x +  2 *scale),  ROUND(y - 22 *scale)} };
    txPolygon (body3, 4);

        //legs
    txSetColor (TX_BLACK, 2 + width);
    txSetFillColor (RGB (255, 248, 220));
    txLine (ROUND(x +  6 *scale), ROUND(y + 88 *scale), ROUND(x + 6 - dist *scale), ROUND(y + 108 *scale));
    txLine (ROUND(x - 10 *scale), ROUND(y + 88 *scale), ROUND(x - 10 + dist *scale), ROUND(y + 108 *scale));

       //arms
    txSetColor (TX_BLACK, 2 + width);
    txLine (ROUND(x -  4 *scale), ROUND(y + 48 *scale), ROUND(x - 37 *scale), ROUND(y + 37 + height *scale));
    txLine (ROUND(x - 20 *scale), ROUND(y + 37 *scale), ROUND(x - 37 *scale), ROUND(y + 31 + height *scale));

    //hat
    txSetColor (RGB(25, 25, 112), 2 + width);
    txSetFillColor (RGB (25, 25, 112));
    POINT hat[4] = { {ROUND(x + 31 *scale), ROUND(y -  2 *scale)}, {ROUND(x + 36 *scale),  ROUND(y - 13 *scale)},
                     {ROUND(x - 10 *scale), ROUND(y - 32 *scale)}, {ROUND(x - 15 *scale),  ROUND(y - 20 *scale)} };
    txPolygon (hat, 4);

    txSetColor (RGB(30, 144, 255), 2 + width);
    txSetFillColor (RGB (30, 144, 255));
    POINT visor[4] = { {ROUND(x + 43 *scale), ROUND(y -  1 *scale)}, {ROUND(x + 46 *scale),  ROUND(y - 7 *scale)},
                       {ROUND(x + 27 *scale), ROUND(y - 13 *scale)}, {ROUND(x + 24 *scale),  ROUND(y - 8 *scale)} };
    txPolygon (visor, 4);
    }

//{-------------------------------------------------------
//!     Процедура рисования самоката
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! type    == вид самоката
//!
//}------------------------------------------------------
void Scooter (int x, int y, double scale, int type)
    {


    }
