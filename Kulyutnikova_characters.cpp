#include "TXLib.h"
#include "stdlib.h"
#include <string>
#include <sstream>

using namespace std ;

void HueColor(int orig, int col);
void Road    (double x, double y);
void Polosa  (double x, double y);
void Pavement(double x, double y);
void Girl    (double x, double y, double scale, double width, double height,   int colour);
void Empress (double x, double y, double scale, double width, double distance, int colour);
void Cat     (double x, double y, double scale, double width, double height,   int colour);

int main()
    {
    txCreateWindow(1200, 800);

    txSetFillColor(RGB(220, 220, 220));
    txRectangle(0, 0, 1200, 800);

    Road(114, -45);

    Polosa(820, 390);
    Polosa(870, 355);
    Polosa(920, 320);
    Polosa(970, 285);

    Pavement(700, 400);

    Girl(792, 439, 1, 2, 1, 0);
    Girl(592, 439, 2, 3, 0, 12347);
    Girl(462, 562, 0.5, 1, 17, 3);

    Empress(345, 219, 1, 1, 0, 0);
    Empress(100, 219, 0.5, 2, 1, 64);
    Empress(965, 134, 2, 3, 5, 168356);

    Cat(342, 400, 0.5, 1, 0, 0);
    Cat(876, 400, 1, 0.5, 2, 64);
    Cat(234, 134, 2, 1, 0, 123);


    return 0;
    }

//-------------------------
void HueColor(int orig, int col)
    {
    int redRGB[] =    { 205,240,250,233,255,220,255,178,139,
                        255,255,255,255,199,219,
                        255,255,255,255,255,255,
                        255,255,255,255,250,255,255,238,240,189,
                        230,216,221,238,218,255,255,186,147,138,148,153,139,128,75,106,72,
                        255,255,255,255,245,222,210,188,244,218,184,205,210,139,160,165,128,
                        173,127,124,  0, 50,152,144,  0,  0, 60, 46, 34,  0,  0,154,205,107,128, 85,102,143,32,0,0,
                          0,  0,224,175,127, 64, 72,  0, 95, 70,176,176,173,135,135,  0, 30,100,123, 65,   0,0,0,0,25,
                        255,255,240,245,240,240,248,245,255,245,253,255,255,250,250,255,255,
                        220,211,211,192,169,169,128,128,105,105,119,119,112,112, 47, 47,  0};

    int blueRGB[] = { 92,128,128,150,160, 20,  0, 34,  0,
                     192,182,105, 20, 21,112,
                     160,127, 99, 69,140,165,
                     215,255,255,250,250,239,218,232,230,183,
                     230,191,160,130,112,  0,  0, 85,112, 43,  0, 50,  0,  0,  0, 90, 61,
                     248,235,228,222,222,184,180,143,164,165,134,133,105, 69, 82, 42,  0,
                     255,255,252,255,205,251,238,250,255,179,139,139,128,100,205,142,128,107,205,188,178,139,128,
                     255,255,255,238,255,224,209,206,158,130,196,224,216,206,206,191,144,149,104,105,  0,  0,  0,0,25,
                     255,250,255,255,255,248,248,245,245,245,245,250,225,235,240,240,228,
                     220,211,211,192,169,169,128,128,105,105,136,136,128,128, 79, 79,  0};

    int greenRGB[] = {  92,128,114,122,122, 60,  0, 34,  0,
                       203,193,180,147,133,147,
                       122, 80, 71,  0,  0,  0,
                         0,  0,224,205,210,213,181,185,170,140,107,
                       250,216,221,238,214,255,255,211,219,226,211,204,139,128,130,205,139,
                       220,205,196,173,179,135,140,143, 96, 32, 11, 63, 30, 19, 45, 42, 0,
                        47,  0,  0,  0, 50,152,144,154,127,113, 87, 34,  0,  0, 50, 35,  0, 47,170,143,170,139,128,
                       255,255,255,238,212,208,204,209,160,180,222,230,230,235,250,255,255,237,238,225,255,205,139,128,112,
                       255,250,240,250,255,255,255,245,238,220,230,240,240,215,230,245,225,
                       220,211,211,192,169,169,128,128,105,105,153,153,144,144, 79, 79,  0};

    int newColor = orig + col;
    while (newColor >= 148)
        {
        newColor = newColor - 148;
        }

    int red = redRGB[newColor];
    int blue = blueRGB[newColor];
    int green = greenRGB[newColor];
    cout << red<<"," << blue<<"," << green;
    }

//-------------------------
void Road(double x, double y)
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
void Polosa(double x, double y)
    {
    txSetColor(TX_BLACK, 2);
    txSetFillColor(TX_BLACK);
    POINT polosa[4] = { {x,       y      }, {x +  20, y - 10},
                        {x + 155, y + 70 }, {x + 135, y + 80} };
    txPolygon(polosa, 4);
    }

//-----------------------------------------------
void Pavement(double x, double y)
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


//{-------------------------------------------------------
//!     Процедура рисования девочки
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height   == подъём руки
//! colour  == цвет фигур
//!
//}------------------------------------------------------

void Girl(double x, double y, double scale, double width, double height, int colour)
    {
    //phone
    txSetFillColor(RGB(0, 255, 255));
    POINT phone[4] = { {x + 27 * scale, y + 29 + height * scale}, {x + 27 * scale, y + 54 + height * scale},
                       {x + 18 * scale, y + 56 + height * scale}, {x + 18 * scale, y + 27 + height * scale} };
    txPolygon(phone, 4);

    //shoes
    txLine(x - 6 * scale, y + 128 * scale, x +  6 * scale, y + 130 * scale);
    txLine(x + 6 * scale, y + 128 * scale, x + 18 * scale, y + 130 * scale);

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
    txLine(x - 3 * scale, y + 98 * scale, x - 3 * scale, y + 128 * scale);
    txLine(x + 9 * scale, y + 98 * scale, x + 9 * scale, y + 128 * scale);

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

void Empress(double x, double y, double scale, double width, double distance, int colour)
    {
    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(255, 0, 0));
    POINT empress1[4] = { {x + 0.1 * scale, y - 60 * scale}, {x + 37 * scale, y + 4 * scale},
                          {x + 0.1 * scale, y + 62 * scale}, {x - 37 * scale, y + 4 * scale} };
    txPolygon(empress1, 4);

    POINT empress2[4] = { {x + 0.1 * scale,  y +  35 * scale}, {x + 46  * scale,  y + 130 * scale},
                          {x - 46  * scale,  y + 130 * scale}, {x + 0.1 * scale,  y +  35 * scale} };
    txPolygon(empress2, 4);

    txSetColor(RGB(255, 0, 0), 2 + width);
    POINT empress3[4] = { {x + 0.1 * scale, y +  6 * scale}, {x + 26 * scale, y + 44 * scale},
                          {x + 0.1 * scale, y + 90 * scale}, {x - 26 * scale, y + 44 * scale} };
    txPolygon(empress3, 4);

    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(0, 0, 0));
    POINT dress1[4] = { {x - 11 * scale, y + 15 * scale}, {x - 18 * scale, y + 30 * scale},
                        {x -  4 * scale, y + 30 * scale}, {x - 11 * scale, y + 15 * scale} };
    txPolygon(dress1, 4);
    POINT dress2[4] = { {x - 11 * scale, y + 23 * scale}, {x - 18 * scale, y + 39 * scale},
                        {x -  4 * scale, y + 39 * scale}, {x - 11 * scale, y + 23 * scale} };
    txPolygon(dress2, 4);
    POINT dress3[4] = { {x - 11 * scale, y + 30 * scale}, {x - 18 * scale, y + 46 * scale},
                        {x -  4 * scale, y + 46 * scale}, {x - 11 * scale, y + 30 * scale} };
    txPolygon(dress3, 4);

    txCircle(x + 0.1 * scale, y - 2 * scale, 26 * scale);

    txSetColor(RGB(255, 228, 196), 2 + width);
    txSetFillColor(RGB(255, 235, 205));
    POINT dress4[4] = { {x + 0.1 * scale, y +  1 * scale}, {x + 8 * scale, y + 19 * scale},
                        {x + 0.1 * scale, y + 35 * scale}, {x - 8 * scale, y + 19 * scale} };
    txPolygon(dress4, 4);

    txCircle(x + 0.1 * scale, y + 0.1 * scale, 21 * scale);

    txLine(x + 0.1 - distance * scale, y + 75 * scale, x - 9 * scale, y + 60 * scale);
    txLine(x + 0.1 + distance * scale, y + 75 * scale, x + 9 * scale, y + 60 * scale);

    }

//-----------------------------------------------

//{-------------------------------------------------------
//!     Процедура рисования императрицы
//!
//!             параметры:
//! x, y    == координаты начальной точки
//! scale   == размер при масштабировании
//! width   == толщина линий
//! height  == подъём хвоста
//! colour  == цвет фигур
//!
//}------------------------------------------------------


void Cat(double x, double y, double scale, double width, double height, int colour)
    {
    txSetColor(RGB(0, 0, 0), 2 + width);
    txSetFillColor(RGB(0, 0, 0));
    POINT cat1[4] = { {x - 8 * scale, y - 15 * scale}, {x - 11 * scale, y + 0.1 * scale},
                      {x - 5 * scale, y - 13 * scale}, {x -  8 * scale, y - 15  * scale } };
    txPolygon(cat1, 4);
    POINT cat2[4] = { {x +  8 * scale, y - 15  * scale}, {x + 5 * scale, y - 13 * scale},
                      {x + 11 * scale, y + 0.1 * scale}, {x + 8 * scale, y - 15 * scale} };
    txPolygon(cat2, 4);
    POINT cat3[4] = { {x + 10 * scale, y + 55 * scale}, {x + 15 + height * scale, y + 26 * scale},
                      {x +  5 * scale, y + 55 * scale}, {x + 10 * scale,         y + 55 * scale} };
    txPolygon(cat3, 4);

    txSetColor(RGB (255, 228, 196), 2 + width);
    txSetFillColor(RGB (255, 228, 196));
    txCircle(x + 0.1 * scale, y + 0.1 * scale, 11 * scale);

    POINT cat4[4] = { {x + 0.1 * scale, y + 0.1 * scale}, {x + 10  * scale,  y + 55  * scale},
                      {x - 10  * scale, y + 55  * scale}, {x + 0.1 * scale,  y + 0.1 * scale} };
    txPolygon(cat4, 4);

    txSetColor(RGB(160, 82, 45));
    txSetFillColor(RGB(160, 82, 45));
    txCircle(x - 5 * scale, y -  3 * scale, 5 * scale);
    txCircle(x + 1 * scale, y + 24 * scale, 2 * scale);
    txCircle(x - 2 * scale, y + 52 * scale, 3 * scale);

    txSetColor(RGB (0, 0, 0), 2 + width);
    txSetFillColor(RGB (0, 0, 0));
    txCircle(x + 0.1 * scale, y + 4.5 * scale, 5 * scale);

    POINT cat5[4] = { {x + 5 * scale, y + 35 * scale}, {x + 6 * scale, y + 55 * scale},
                      {x + 4 * scale, y + 55 * scale}, {x + 5 * scale, y + 35 * scale} };
    txPolygon(cat5, 4);

    POINT cat6[4] = { {x - 3 * scale, y + 35 * scale}, {x - 2 * scale, y + 55 * scale},
                      {x - 4 * scale, y + 55 * scale}, {x - 3 * scale, y + 35 * scale} };
    txPolygon(cat6, 4);

    }

