#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <cmath>
#include <sstream>
//#include "Galyarov.h"

using namespace std ;

double d;
double pi = 22/7;

//void povorot(double x, double y, int d);
void KolobokS (long x, long y, int radStandart, double size, int type);

int main ()
    {

    txCreateWindow (1200, 800);
    txSetColor(RGB(255, 255, 255));
    txRectangle(0, 0, 1200, 800);
    //KolobokS(200, 200, 10, 1, 1);
   // KolobokS(600, 200, 10, 1, 2);
   // KolobokS(200, 600, 10, 1, 3);
   // KolobokS(600, 600, 10, 1, 4);

    //povorot(200, 200, 90);

    int x = 200;
    int i = 0;
    while ( x <= 1200)
        {
        txClear();

        x += i*16;
        i += 1;

        KolobokS(x, 200, 10, 1, (i % 4));

        txSleep (750);
        }
    return 0;
    }

void KolobokS (long x, long y, int radStandart, double size, int type)
    {
    if (type == 0)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_YELLOW);
        txCircle       (x, y, 100*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BROWN);
        POINT nos [4]  {{ROUND(x)          , ROUND(y)          }, {ROUND(x - 20*size), ROUND(y + 20*size)},
                        {ROUND(x + 20*size), ROUND(y + 20*size)}, {ROUND(x)          , ROUND(y)           }};
        txPolygon      (nos, 4);


        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x - 25*size, y - 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x + 25*size, y - 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txEllipse      (x - 40*size, y + 60*size,
                        x + 50*size, y + 75*size);

        txSetColor     (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        txEllipse      (x - 40*size, y + 55*size,
                        x + 50*size, y + 65*size);
        }

    if (type == 1)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_YELLOW);
        txCircle       (x, y, 100*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BROWN);
        POINT nos [4]  {{ROUND(x + 20  - 20*size), ROUND(y + 20 - 20*size)}, {ROUND(x - 0.1 - 20*size), ROUND(y + 0.1 - 20*size)},
                        {ROUND(x - 0.1 - 20*size), ROUND(y + 40 - 20*size)}, {ROUND(x + 20  - 20*size), ROUND(y + 20  - 20*size)}};
        txPolygon      (nos, 4);


        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x + 25*size, y - 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x + 25*size, y + 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txEllipse      (x - 60*size, y - 40*size,
                        x - 75*size, y + 50 *size);

        txSetColor     (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        txEllipse      (x - 55*size, y - 40*size,
                        x - 65*size, y + 50*size);
        }

    if (type == 2)
        {
               txSetColor     (TX_BLACK);
        txSetFillColor (TX_YELLOW);
        txCircle       (x, y, 100*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BROWN);
        POINT nos [4]  {{ROUND(x)           ,  ROUND(y + 10*size)           },   {ROUND(x - 20*size), ROUND(y - 10*size)},
                        {ROUND(x + 20*size), ROUND(y - 10*size)},  {ROUND(x)           ,  ROUND(y + 10*size)           }};
        txPolygon      (nos, 4);


        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x - 25*size, y + 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x + 25*size, y + 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txEllipse      (x - 40*size, y - 60*size,
                        x + 50*size, y - 75*size);

        txSetColor     (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        txEllipse      (x - 40*size, y - 55*size,
                        x + 50*size, y - 65*size);
        }

    if (type == 3)
        {
        txSetColor     (TX_BLACK);
        txSetFillColor (TX_YELLOW);
        txCircle       (x, y, 100*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BROWN);
        POINT nos [4]  {{ROUND(x - 20  + 20*size), ROUND(y + 20 - 20*size)}, {ROUND(x - 0.1 + 20*size), ROUND(y + 0.1 - 20*size)},
                        {ROUND(x - 0.1 + 20*size), ROUND(y + 40 - 20*size)}, {ROUND(x - 20  + 20*size), ROUND(y + 20  - 20*size)}};
        txPolygon      (nos, 4);


        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x - 25*size, y - 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txCircle       (x - 25*size, y + 25*size, radStandart*size);

        txSetColor     (TX_BLACK);
        txSetFillColor (TX_BLACK);
        txEllipse      (x + 60*size, y - 40*size,
                        x + 75*size, y + 50 *size);

        txSetColor     (TX_YELLOW);
        txSetFillColor (TX_YELLOW);
        txEllipse      (x + 55*size, y - 40*size,
                        x + 65*size, y + 50*size);
        }
    }
