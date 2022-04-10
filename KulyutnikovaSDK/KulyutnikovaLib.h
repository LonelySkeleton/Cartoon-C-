#include "TXLib.h"


void Girl (int x, int y, double scale,
           double width,
           int height,
           int dist);

//-----------------------
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
