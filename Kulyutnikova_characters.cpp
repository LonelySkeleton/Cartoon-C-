#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <sstream>

using namespace std ;

void HueColor     (int orig, int col);

void Road     (int x, int y);
void Polosa   (int x, int y);
void Pavement (int x, int y);
void Houses   (int x, int y);

void Girl         (int x,    int y, double scale, double width, int height,   int dist);
void Empress      (int x,    int y, double scale, double width, int distance          );
void Cat          (int x,    int y, double scale, double width, int height            );

void GirlWalking   (int x,    int y, double scale, double width);
void CatTail       (int x,    int y, double scale, double width);
void EmpressWalking(int x,    int y, double scale, double width);

void massovka_fem (int x, int y, double scale, double dist);
void massovka_male(int x, int y, double scale, double dist);

void Background();
void AllMoving();

int main()
    {
    txCreateWindow(1200, 800);

    Background();

    //GirlWalking   (792, 439, 1, 1);
    //CatTail       (342, 400, 2, 1);
    //EmpressWalking(345, 219, 1, 1);
    AllMoving();

    return 0;
    }

//-------------------------
void Background()
        {
        txClear();

        txSetFillColor(RGB(220, 220, 220));
        txRectangle(0, 0, 1200, 800);
        Road(114, -45);

        Polosa(820, 390);
        Polosa(870, 355);
        Polosa(920, 320);
        Polosa(970, 285);

        Pavement(700, 400);

        Houses(15, 45);
        }

//-------------------------
void GirlWalking (int x, int y, double scale, double width)
        {
         for (int i=0; i<=30;i++)
             {
              x += 10;
              y -= 10;
              if (i % 2 == 0)
                {
                Girl (792+x, 439+y, scale, width, 2, -4);
                }
              else
                {
                Girl (792+x, 439+y, scale, width, -2, 4);
                }

              txSleep(250);

              if (i!=30)
                {
                   Background();
                }
             }
        }

void CatTail (int x, int y, double scale, double width)
        {
         for (int i = 0; i <= 30; i++)
             {
              if (i % 3 == 0)
                  {
                   Cat(x, y, scale, width, 3);
                  }
              else
                  {
                   Cat(x, y, scale, width, 1);
                  }
              txSleep(300);

              if (i!=30)
                {
                Background();
                }
             }
        }
void EmpressWalking (int x, int y, double scale, double width)
        {
         for (int i=0; i<=60;i++)
             {
              x += 1;
              y += 5;
              if (i % 2 == 0)
                {
                Empress (x, y, scale, width, 1);
                }
              else
                {
                Empress (x, y, scale, width, -1);
                }

              txSleep(140);

              if (i!=60)
                {
                Background();
                }
             }
        }

void AllMoving()
        {
          for (int i=0; i<=30;i++)
             {
              int x, y = 0 ;
              x += 5;
              y -= 5;
              if (i % 2 == 0)
                    {
                    Girl        (792 + x, 439 + y, 1, 1, 2, -4);

                    massovka_fem( 725 + x, 419 + y, 0.5, 1.5);
                    massovka_fem( 700 + x, 400 + y, 1  , 1.5);
                    massovka_fem( 845 + x, 450 + y, 0.5, 1.5);
                    massovka_fem( 870 + x, 490 + y, 1  , 1.5);
                    massovka_fem(1055 + x, 150 + y, 0.5, 1.5);

                    massovka_male (1130 + x, 170 + y, 1  , 1.5);
                    massovka_male ( 650 + x, 460 + y, 0.5, 1.5);
                    massovka_male ( 750 + x, 560 + y, 1  , 1.5);
                    }
              else if (i % 3 == 0)
                    {
                    Empress (345 + x, 219 + y, 1, 1, 1    );
                    }
              else if (i % 4 == 0)
                    {
                    Cat(342 + x, 400 + y, 2, 1, 3);
                    }
              else
                    {
                    Cat     (342 + x, 400 + y, 2, 1, 1    );
                    Girl    (792 + x, 439 + y, 1, 1, -2, 4);
                    Empress (345 + x, 219 + y, 1, 1, -1   );

                    massovka_fem( 725 + x, 419 + y, 0.5, 0.5);
                    massovka_fem( 700 + x, 400 + y, 1  , 0.5);
                    massovka_fem( 845 + x, 450 + y, 0.5, 0.5);
                    massovka_fem( 870 + x, 490 + y, 1  , 0.5);
                    massovka_fem(1055 + x, 150 + y, 0.5, 0.5);

                    massovka_male (1130 + x, 170 + y, 1  , 0.5);
                    massovka_male ( 650 + x, 460 + y, 0.5, 0.5);
                    massovka_male ( 750 + x, 560 + y, 1  , 0.5);
                    }
              txSleep(250);
              if (i!=30)
                {
                   Background();
                }
             }
        }

//-------------------------
void Road(int x, int y)
    {
    txSetColor(TX_BLACK, 4);
    txSetFillColor(TX_WHITE);
    POINT road[4] = { {x,        y      }, {x + 126,  y - 105},
                      {x + 1236, y + 450}, {x + 1086, y + 735} };
    txPolygon(road, 4);
    txLine(x + 481, y + 195, x +  571, y + 245);
    txLine(x + 331, y +  95, x +  421, y + 145);
    txLine(x + 631, y + 295, x +  721, y + 345);
    txLine(x + 931, y + 495, x + 1021, y + 545);
    }

//-----------------------------------------------
void Polosa(int x, int y)
    {
    txSetColor(TX_BLACK, 2);
    txSetFillColor(TX_BLACK);
    POINT polosa[4] = { {x,       y      }, {x +  20, y - 10},
                        {x + 155, y + 70 }, {x + 135, y + 80} };
    txPolygon(polosa, 4);
    }

//-----------------------------------------------
void Pavement(int x, int y)
    {
    txSetFillColor(TX_GRAY);
    POINT pavement1[6] = { {x,       y      }, {x +  34, y + 145},
                           {x - 580, y + 400}, {x - 700, y + 400},
                           {x - 700, y + 200}, {x,       y      } };
    txPolygon(pavement1, 6);
    POINT pavement2[6] = { {x - 694, y - 445}, {x - 586, y - 445},
                           {x + 500, y + 290}, {x + 500, y + 400},
                           {x + 350, y + 400}, {x - 694, y - 445} };
    txPolygon(pavement2, 6);
    POINT pavement3[5] = { {x - 460, y - 550}, {x - 400, y - 550},
                           {x + 600, y - 110}, {x + 650, y +  50},
                           {x - 460, y - 550}  };
    txPolygon(pavement3, 5);
    }

//-----------------------------------------------
void Houses(int x, int y)
    {
        //house1
    txSetFillColor(TX_GRAY);
    txRectangle (x, y, x + 180, y + 305);
        //window1
    txSetFillColor(TX_YELLOW);
    txRectangle (x + 15,  y +  30,  x +  60, y +  80);
    txRectangle (x + 75,  y +  30,  x + 115, y +  80);
    txRectangle (x + 129, y +  30,  x + 165, y +  80);
    txRectangle (x +  15, y + 125,  x +  60, y + 185);
    txRectangle (x +  75, y + 125,  x + 115, y + 185);
    txRectangle (x + 129, y + 125,  x + 165, y + 185);
        //house2
    txSetFillColor(TX_GRAY);
    txRectangle (x + 134, y + 15, x + 180 + 134, y + 305 + 15);
        //window2
    txSetFillColor(TX_YELLOW);
    txRectangle (x +  41 + 104, y +  30 + 15, x +  96 + 104,  y +  75 + 15);
    txRectangle (x + 116 + 104, y +  30 + 15, x + 200 + 104,  y +  75 + 15);
    txRectangle (x +  38 + 104, y +  90 + 15, x +  65 + 104,  y + 141 + 15);
    txRectangle (x +  86 + 104, y +  90 + 15, x + 136 + 104,  y + 147 + 15);
    txRectangle (x + 176 + 104, y +  90 + 15, x + 211 + 104,  y + 147 + 15);
    txRectangle (x +  41 + 104, y + 165 + 15, x + 100 + 104,  y + 219 + 15);
    txRectangle (x + 131 + 104, y + 165 + 15, x + 211 + 104,  y + 255 + 15);
        //house3
    txSetFillColor(TX_GRAY);
    txRectangle (x + 120, y + 135, x + 165 + 120, y + 225 + 135);
        //window3
    txSetFillColor(TX_YELLOW);
    txRectangle (x + 15 + 120, y +  30 + 135, x +  60 + 120, y +  45 + 135);
    txRectangle (x + 75 + 120, y +  27 + 135, x + 120 + 120, y +  72 + 135);
    txRectangle (x + 12 + 120, y + 102 + 135, x +  72 + 120, y + 138 + 135);
    txRectangle (x + 90 + 120, y + 102 + 135, x + 135 + 120, y + 138 + 135);
    txRectangle (x + 75 + 120, y + 153 + 135, x + 111 + 120, y + 210 + 135);
    txRectangle (x + 30 + 120, y + 165 + 135, x +  60 + 120, y + 221 + 135);
        //house4
    txSetFillColor(TX_GRAY);
    txRectangle (x + 1000, y - 195, x + 180 + 1000, y + 305 - 195);
        //window4
    txSetFillColor(TX_YELLOW);
    txRectangle (x - 150 + 1175, y + 150 - 195,  x - 130 + 1175, y + 240 - 195);
    txRectangle (x - 100 + 1175, y + 133 - 195,  x -  50 + 1175, y + 185 - 195);
    }
void massovka_fem(int x, int y, double scale, double dist)
    {
    txSetFillColor(TX_BLACK);
    txCircle(x + 0.5 * scale, y + 0.5 * scale, 23 * scale);
    POINT body[4] = { {x           , y + 23*scale}, {x + 27*scale, y + 95*scale},
                      {x - 27*scale, y + 95*scale}, {x           , y + 23*scale} };
    txPolygon(body, 4);
    txLine(x - 5, y + 95*scale, x - 5, y - dist + 115*scale);
    txLine(x + 5, y + 95*scale, x + 5, y + dist + 115*scale);
    }

void massovka_male(int x, int y, double scale, double dist)
    {
    txSetFillColor(TX_BLACK);
    txCircle(x + 0.5 * scale, y + 0.5 * scale, 23 * scale);
    txRectangle(x + 15, y + 95*scale, x - 23, y + 24*scale);
    txLine(x - 5, y + 95*scale, x - 5, y - dist+ 115*scale);
    txLine(x + 5, y + 95*scale, x + 5, y + dist+ 115*scale);
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

void Girl(int x, int y, double scale, double width, int height, int dist)
    {
    //phone
    txSetFillColor(RGB(0, 255, 255));
    POINT phone[4] = { {x + 27 * scale, y + 27 + height * scale}, {x + 27 * scale, y + 56 + height * scale},
                       {x + 18 * scale, y + 54 + height * scale}, {x + 18 * scale, y + 29 + height * scale} };
    txPolygon(phone, 4);

    //shoes
    txLine(x - 6 - dist * scale, y + 128 * scale, x +  6 - dist * scale, y + 130 * scale);
    txLine(x + 6 + dist * scale, y + 128 * scale, x + 18 + dist * scale, y + 130 * scale);

    //body
        //hair
    txSetColor(RGB(139, 69, 19), 2 + width);
    txSetFillColor(RGB(139, 69, 19));
    txCircle(x + 0.5 * scale, y + 0.5 * scale, 24 * scale);

    POINT body[4] = { {x - 22 * scale, y -  7 * scale}, {x - 17 * scale, y + 38 * scale},
                      {x - 28 * scale, y + 38 * scale}, {x - 22 * scale, y -  7 * scale} };
    txPolygon(body, 4);

        //dress
    txSetColor(RGB(0, 0, 139), 2 + width);
    txSetFillColor(RGB(0, 0, 139));

    POINT body2[4] = { {x +  3 * scale, y + 23 * scale}, {x + 33 * scale, y + 98 * scale},
                       {x - 33 * scale, y + 98 * scale}, {x +  3 * scale, y + 23 * scale} };
    txPolygon(body2, 4);

        //head
    txSetColor(RGB(255, 228, 196), 2 + width);
    txSetFillColor(RGB(255, 228, 196));
    txCircle(x + 3 * scale, y + 2 * scale, 22 * scale);

        //fringe
    txSetColor(RGB(139, 69, 19), 2 + width);
    txSetFillColor(RGB(139, 69, 19));
    POINT body3[4] = { {x + 17.5 * scale, y - 18 * scale}, {x - 19 * scale,  y +  5 * scale},
                       {x - 18.5 * scale, y - 11 * scale}, {x -  1 * scale,  y - 22 * scale} };
    txPolygon(body3, 4);

        //legs
    txSetColor(TX_BLACK, 2 + width);
    txSetFillColor(RGB (255, 248, 220));
    txLine(x - 3 * scale, y + 98 * scale, x - 3 - dist * scale, y + 128 * scale);
    txLine(x + 9 * scale, y + 98 * scale, x + 9 + dist * scale, y + 128 * scale);

    //headphones
    txSetColor(TX_BLACK, 7 + width);
    txSetFillColor(RGB(0, 0, 0));
    txCircle(x + 1 * scale, y + 4 * scale, 10 * scale);
    txLine(x + 1 * scale, y - 6 * scale, x - 1 * scale, y - 24 * scale);

    //arm_handbag
    txSetColor(RGB(184, 134, 11), 2 + width);
    txCircle(x + 3 * scale, y + 56 * scale, 4 * scale);

    txSetFillColor(RGB(0, 0, 139));
    txSetColor(RGB(184, 134, 11), 2 + width);
    txRectangle(x - 1 * scale, y + 56 * scale, x + 7 * scale, y + 76 * scale);

    txSetFillColor(RGB(250, 235, 215));
    txRectangle(x - 4 * scale, y + 76 * scale, x + 9 * scale, y + 91 * scale);

    txSetColor(RGB(0, 0, 139), 2 + width);
    txLine(x - 0.1 * scale, y + 56 * scale, x + 5 * scale, y + 56 * scale);

    txSetColor(TX_BLACK, 2 + width);
    txLine(x + 3 * scale, y + 56 * scale, x + 27 * scale, y + 46 + height * scale);
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

void Empress(int x, int y, double scale, double width, int distance)
    {
    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(255, 0, 0));

    //collar
    POINT collar[4] = { {x + 0.1 * scale, y - 60 * scale}, {x + 37 * scale, y + 4 * scale},
                        {x + 0.1 * scale, y + 62 * scale}, {x - 37 * scale, y + 4 * scale} };
    txPolygon(collar, 4);

    //dress
    POINT empress2[4] = { {x + 0.1 * scale,  y +  35 * scale}, {x + 46  * scale,  y + 130 * scale},
                          {x - 46  * scale,  y + 130 * scale}, {x + 0.1 * scale,  y +  35 * scale} };
    txPolygon(empress2, 4);

    //sleeves
    txSetColor(RGB(255, 0, 0), 2 + width);
    POINT empress3[4] = { {x + 0.1 * scale, y +  6 * scale}, {x + 26 * scale, y + 44 * scale},
                          {x + 0.1 * scale, y + 90 * scale}, {x - 26 * scale, y + 44 * scale} };
    txPolygon(empress3, 4);

    //braid
    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(0, 0, 0));
    POINT braid1[4] = { {x - 11 * scale, y + 15 * scale}, {x - 18 * scale, y + 30 * scale},
                        {x -  4 * scale, y + 30 * scale}, {x - 11 * scale, y + 15 * scale} };
    txPolygon(braid1, 4);
    POINT braid2[4] = { {x - 11 * scale, y + 23 * scale}, {x - 18 * scale, y + 39 * scale},
                        {x -  4 * scale, y + 39 * scale}, {x - 11 * scale, y + 23 * scale} };
    txPolygon(braid2, 4);
    POINT braid3[4] = { {x - 11 * scale, y + 30 * scale}, {x - 18 * scale, y + 46 * scale},
                        {x -  4 * scale, y + 46 * scale}, {x - 11 * scale, y + 30 * scale} };
    txPolygon(braid3, 4);

    //hair
    txCircle(x + 0.1 * scale, y - 2 * scale, 26 * scale);

    //neck
    txSetColor(RGB(255, 228, 196), 2 + width);
    txSetFillColor(RGB(255, 235, 205));
    POINT neck[4] = { {x + 0.1 * scale, y +  1 * scale}, {x + 8 * scale, y + 19 * scale},
                      {x + 0.1 * scale, y + 35 * scale}, {x - 8 * scale, y + 19 * scale} };
    txPolygon(neck, 4);

    //head
    txCircle(x + 0.1 * scale, y + 0.1 * scale, 21 * scale);

    //arms
    txLine(x + 0.1 - distance * scale, y + 75 * scale, x - 9 * scale, y + 60 * scale);
    txLine(x + 0.1 + distance * scale, y + 75 * scale, x + 9 * scale, y + 60 * scale);

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


void Cat(int x, int y, double scale, double width, int height)
    {
    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(0, 0, 0));

    //ears
    POINT earL[4] = { {x - 8 * scale, y - 15 * scale}, {x - 11 * scale, y + 0.1 * scale},
                      {x - 5 * scale, y - 13 * scale}, {x -  8 * scale, y - 15  * scale } };
    txPolygon(earL, 4);

    POINT earR[4] = { {x +  8 * scale, y - 15  * scale}, {x + 5 * scale, y - 13 * scale},
                      {x + 11 * scale, y + 0.1 * scale}, {x + 8 * scale, y - 15 * scale} };
    txPolygon(earR, 4);

    //tail
    POINT tail[4] = { {x + 10 * scale, y + 55 * scale}, {x + 15 + height * scale, y + 26 * scale},
                      {x +  5 * scale, y + 55 * scale}, {x + 10 * scale,         y + 55 * scale} };
    txPolygon(tail, 4);

    txSetColor(RGB (255, 228, 196), 2 + width);

    //head
    txSetFillColor(RGB (255, 228, 196));
    txCircle(x + 0.1 * scale, y + 0.1 * scale, 11 * scale);

    //body
    POINT body[4] = { {x + 0.1 * scale, y + 0.1 * scale}, {x + 10  * scale,  y + 55  * scale},
                      {x - 10  * scale, y + 55  * scale}, {x + 0.1 * scale,  y + 0.1 * scale} };
    txPolygon(body, 4);

    txSetColor(RGB(160, 82, 45));
    txSetFillColor(RGB(160, 82, 45));

    //marks
    txCircle(x - 5 * scale, y -  3 * scale, 5 * scale);
    txCircle(x + 1 * scale, y + 24 * scale, 2 * scale);
    txCircle(x - 2 * scale, y + 52 * scale, 3 * scale);

    txSetColor(RGB (0, 0, 0), 2 + width);
    txSetFillColor(RGB (0, 0, 0));

    //face
    txCircle(x + 0.1 * scale, y + 4.5 * scale, 5 * scale);

    //legs
    POINT legR[4] = { {x + 5 * scale, y + 35 * scale}, {x + 6 * scale, y + 55 * scale},
                      {x + 4 * scale, y + 55 * scale}, {x + 5 * scale, y + 35 * scale} };
    txPolygon(legR, 4);

    POINT legL[4] = { {x - 3 * scale, y + 35 * scale}, {x - 2 * scale, y + 55 * scale},
                      {x - 4 * scale, y + 55 * scale}, {x - 3 * scale, y + 35 * scale} };
    txPolygon(legL, 4);

    }
