#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <cmath>
#include <sstream>

using namespace std ;

void Road         (int x, int y);
void Rails        (int x, int y);
void Layout       (int x, int y);
void Polosa       (int x, int y);
void Pavement     (int x, int y, int choice);
void Houses       (int x, int y, double size, int choice);
void TrafficLight (int x, int y, int first, int second, int third);

void Girl         (int x, int y, double scale, double width, int height, int dist);
void Empress      (int x, int y, double scale, double width, int distance);
void Cat          (int x, int y, double scale, double width, int height);
void Truck        (int x, int y, double scale);

void Boy         (int x, int y, double scale, double width, int height, int dist);

void people_woman (int x, int y, double scale, double dist);
void people_men   (int x, int y, double scale, double dist);

void Background_Scene_First  ();
void Background_Scene_Second ();
void SceneFirst ();

void GirlAndTruck (int xG, int yG, double scaleG, double width, int xT, int yT, double scaleT, int xP, int yP, double scaleP);

int main ()
    {
    txCreateWindow (1200, 800);


    //SceneFirst ();

    Background_Scene_Second ();
    //Boy (800, 500, 1, 1, 1, 1);
    return 0;
    }

//-------------------------
void SceneFirst ()
    {

    Background_Scene_First ();
    GirlAndTruck (792, 439, 0.9, 1, 230, -100, 0.4, 725, 419, 1);
    txSleep (760);
    }

void GirlAndTruck (int xG, int yG, double scaleG, double width, int xT, int yT, double scaleT, int xP, int yP, double scaleP)
    {
    int i = 0;
    int w = 1;
    txPlaySound ("Сцена1.wav");
    while ( pow( (pow(xG - xT, 2) + pow(yG - yT, 2) ), 0.5) >= 100 )
        {
        Background_Scene_First ();
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
        txTextOut (300, 200, "Отвлекись от телефона,");
        txTextOut (275, 265, "сделай музыку в наушниках тише.");
        txTextOut (230, 430, "Следи за тем, что происходит на дороге!");
        }

    }
//-------------------------
void Background_Scene_First ()
    {
    txClear ();

    txSetFillColor (RGB(220, 220, 220));
    txRectangle (0, 0, 1200, 800);
    Road (114, -45);
    Layout(114, -45);

    Polosa (820, 390);
    Polosa (870, 355);
    Polosa (920, 320);
    Polosa (970, 285);

    Pavement (700, 400, 1);

    Houses (15, 45, 1, 1);
    }

//-------------------------
void Background_Scene_Second ()
    {
    txClear ();

    txSetFillColor (RGB(220, 220, 220));
    txRectangle (0, 0, 1200, 800);
    Road (114, -45);

    Pavement (700, 400, 2);

    Houses (5, 45, 1.5, 2);
    }

//-------------------------
void Road (int x, int y)
    {
    txSetColor (TX_BLACK, 4);
    txSetFillColor (TX_WHITE);
    POINT road[4] = { {x,        y      }, {x + 126,  y - 105},
                      {x + 1236, y + 450}, {x + 1086, y + 735} };
    txPolygon (road, 4);

    }

//-----------------------------------------------
void Layout (int x, int y)
    {
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

//-------------------------
void Rails (int x, int y)
{

}
//-----------------------------------------------
void Pavement (int x, int y, int choice)
    {
    txSetFillColor (TX_GRAY);
    txSetColor (TX_BLACK, 1.5);

    if (choice == 1)
        {
        POINT pavement1[6] = { {x,       y      }, {x +  34, y + 145},
                               {x - 580, y + 400}, {x - 700, y + 400},
                               {x - 700, y + 200}, {x,       y      } };
        txPolygon (pavement1, 6);
        }

    if (choice == 2)
        {
        POINT pavement1[6] = { {x + 150      , y + 200      }, {x +  34 + 290, y + 145 + 100},
                               {x - 580 + 200, y + 400 + 100}, {x - 700 + 390, y + 400 + 200},
                               {x - 700 + 150, y + 200 + 200}, {x + 150      , y + 200      } };
        txPolygon (pavement1, 6);
        }

    POINT pavement2[6] = { {x - 694, y - 445}, {x - 586, y - 445},
                           {x + 500, y + 290}, {x + 500, y + 400},
                           {x + 350, y + 400}, {x - 694, y - 445} };
    txPolygon (pavement2, 6);
    POINT pavement3[5] = { {x - 460, y - 550}, {x - 400, y - 550},
                           {x + 600, y - 110}, {x + 650, y +  50},
                           {x - 460, y - 550}  };
    txPolygon (pavement3, 5);


    }

//-----------------------------------------------
void Houses (int x, int y, double size, int choice)
    {
        //house1
    txSetFillColor (TX_GRAY);
    txRectangle (ROUND(x + 0.1 *size), ROUND(y + 0.1 *size), ROUND(x  + 180 *size), ROUND(y + 305  *size));
        //window1
    txSetFillColor (TX_YELLOW);
    txRectangle (ROUND(x  +  15*size), ROUND(y +  30*size),  ROUND(x +  60*size), ROUND(y +  80*size));
    txRectangle (ROUND(x  +  75*size), ROUND(y +  30*size),  ROUND(x + 115*size), ROUND(y +  80*size));
    txRectangle (ROUND(x  + 129*size), ROUND(y +  30*size),  ROUND(x + 165*size), ROUND(y +  80*size));
    txRectangle (ROUND(x  +  15*size), ROUND(y + 125*size),  ROUND(x +  60*size), ROUND(y + 185*size));
    txRectangle (ROUND(x  +  75*size), ROUND(y + 125*size),  ROUND(x + 115*size), ROUND(y + 185*size));
    txRectangle (ROUND(x  + 129*size), ROUND(y + 125*size),  ROUND(x + 165*size), ROUND(y + 185*size));
        //house2
    txSetFillColor (TX_GRAY);
    txRectangle (ROUND(x  + (134 + 50)*size), ROUND(y + (15 + 50)*size), ROUND(x  + (180 + 134 + 50)*size), ROUND(y + (305 + 15 + 50)*size));
        //window2
    txSetFillColor (TX_YELLOW);
    txRectangle (ROUND(x  + ( 41 + 104 + 50)*size), ROUND(y  + ( 30 + 15 + 50)*size), ROUND(x  + ( 96 + 104 + 50)*size),  ROUND(y + ( 75 + 15 + 50)*size));
    txRectangle (ROUND(x  + (116 + 104 + 50)*size), ROUND(y  + ( 30 + 15 + 50)*size), ROUND(x  + (200 + 104 + 50)*size),  ROUND(y + ( 75 + 15 + 50)*size));
    txRectangle (ROUND(x  + ( 38 + 104 + 50)*size), ROUND(y  + ( 90 + 15 + 50)*size), ROUND(x  + ( 65 + 104 + 50)*size),  ROUND(y + (141 + 15 + 50)*size));
    txRectangle (ROUND(x  + ( 86 + 104 + 50)*size), ROUND(y  + ( 90 + 15 + 50)*size), ROUND(x  + (136 + 104 + 50)*size),  ROUND(y + (147 + 15 + 50)*size));
    txRectangle (ROUND(x  + (176 + 104 + 50)*size), ROUND(y  + ( 90 + 15 + 50)*size), ROUND(x  + (211 + 104 + 50)*size),  ROUND(y + (147 + 15 + 50)*size));
    txRectangle (ROUND(x  + ( 41 + 104 + 50)*size), ROUND(y  + (165 + 15 + 50)*size), ROUND(x  + (100 + 104 + 50)*size),  ROUND(y + (219 + 15 + 50)*size));
    txRectangle (ROUND(x  + (131 + 104 + 50)*size), ROUND(y  + (165 + 15 + 50)*size), ROUND(x  + (211 + 104 + 50)*size),  ROUND(y + (255 + 15 + 50)*size));

    if (choice == 1)
        {
        //house3
        txSetFillColor (TX_GRAY);
        txRectangle (ROUND(x  + 120 *size), ROUND(y  + 135 *size), ROUND(x  + (165 + 120)*size), ROUND(y  + (225 + 145)*size));
            //window3
        txSetFillColor (TX_YELLOW);
        txRectangle (ROUND(x  + (15 + 120)*size), ROUND(y  + ( 30 + 135)*size), ROUND(x  + ( 60 + 120)*size), ROUND(y  + ( 45 + 135)*size));
        txRectangle (ROUND(x  + (75 + 120)*size), ROUND(y  + ( 27 + 135)*size), ROUND(x  + (120 + 120)*size), ROUND(y  + ( 72 + 135)*size));
        txRectangle (ROUND(x  + (12 + 120)*size), ROUND(y  + (102 + 135)*size), ROUND(x  + ( 72 + 120)*size), ROUND(y  + (138 + 135)*size));
        txRectangle (ROUND(x  + (90 + 120)*size), ROUND(y  + (102 + 135)*size), ROUND(x  + (135 + 120)*size), ROUND(y  + (138 + 135)*size));
        txRectangle (ROUND(x  + (75 + 120)*size), ROUND(y  + (153 + 135)*size), ROUND(x  + (111 + 120)*size), ROUND(y  + (210 + 135)*size));
        txRectangle (ROUND(x  + (30 + 120)*size), ROUND(y  + (165 + 135)*size), ROUND(x  + ( 60 + 120)*size), ROUND(y  + (221 + 135)*size));
            //house4
        txSetFillColor (TX_GRAY);
        txRectangle (ROUND(x  + 1000 *size), ROUND(y  - 195 *size), ROUND(x  + (180 + 1000)*size), ROUND(y  + (305 - 195)*size));
            //window4
        txSetFillColor (TX_YELLOW);
        txRectangle (ROUND(x  - (150 + 1175)*size), ROUND(y  + (150 - 195)*size),  ROUND(x  - (130 + 1175)*size), ROUND(y  + (240 - 195)*size));
        txRectangle (ROUND(x  - (100 + 1175)*size), ROUND(y  + (133 - 195)*size),  ROUND(x  - ( 50 + 1175)*size), ROUND(y  + (185 - 195)*size));
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

//{-------------------------------------------------------
//!     Процедура рисования девочки
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём руки
//! dist    == расстояние между ногами
//! colour  == цвет фигур
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
//! colour   == цвет фигур
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
//! colour  == цвет фигур
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

//{-------------------------------------------------------
//!     Процедура рисования мальчика
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём руки
//! dist    == расстояние между ногами
//! colour  == цвет фигур
//!
//}------------------------------------------------------

void Boy (int x, int y, double scale, double width, int height, int dist)
    {
    //shoes
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
    txCircle (ROUND(x *scale), ROUND(y *scale), ROUND(22 *scale));

        //fringe
    txSetColor (RGB(160, 82, 45), 2 + width);
    txSetFillColor (RGB(160, 82, 45));
    POINT body3[4] = { {ROUND(x + 14.5 *scale), ROUND(y - 18 *scale)}, {ROUND(x - 22 *scale),  ROUND(y +  5 *scale)},
                       {ROUND(x - 22.5 *scale), ROUND(y - 11 *scale)}, {ROUND(x -  6 *scale),  ROUND(y - 22 *scale)} };
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


