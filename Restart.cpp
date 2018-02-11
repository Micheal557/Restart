
#include "TXLib.h"
#include <iostream>
using namespace std;

struct Ball {int x, y, vx, vy, radius;};

void Balls_Movement (Ball balls [], int dt, int nAfricans);
void Draw_Ball (int x, int y, int radius);
void Physics (Ball* ball, int dt);
void Physics_Manager (Ball balls [], int nAfricans, int dt);
void DrawBall_Manager (Ball balls [], int nAfricans);
void Control (Ball* ball);
void Distance (Ball ball1, Ball ball2);
double Collision_Detection (Ball ball1, Ball ball2);
void Bump (Ball balls [], int nAfricans);

int main ()
    {
    txCreateWindow (800, 600);

    Ball balls [4] = {{100, 100, 5, 6, 30},
                      {200, 200, 8, 9, 40},
                      {300, 300, 3, 4, 50},
                      {400, 400, 1, 2, 60}};

    int nAfricans = 4;
    int dt = 1;

    Balls_Movement (balls, dt, nAfricans);

    return 0;
    }

//=============================================================================

void Balls_Movement (Ball balls [], int dt, int nAfricans)  //добить, разобраться с указателем
    {
                                                                       //8(916)-504-09-45
    while (!GetAsyncKeyState (VK_ESCAPE))
        {
        txSetFillColor (TX_BLACK);
        txClear ();


        DrawBall_Manager (balls, nAfricans);

        Physics_Manager (balls, nAfricans, dt);

        Control (balls);

        Distance (balls [0], balls [1]);

        Bump (balls, nAfricans);

        txSleep (100);
        }
    }


//=============================================================================

void DrawBall_Manager (Ball balls [], int nAfricans)
    {
    for (int j = 0; j < nAfricans; j++)
        {
        Draw_Ball (balls [j].x, balls [j].y, balls [j].radius);
        }
    }

//=============================================================================разобраться с синтаксисом массива полностью!!!!!,

void Physics_Manager (Ball balls [], int nAfricans, int dt)
    {

    for (int i = 0; i < nAfricans; i++)
        {
        Physics (&balls [i], dt);
        }
    }

//=============================================================================

void Physics (Ball* ball, int dt)
    {

    ball -> x = ball -> x + ball -> vx * dt;
    ball -> y = ball -> y + ball -> vy * dt;

    if (ball->x > 800)
        {
        ball->vx = -(ball->vx);
        ball->x = 800;
        }

    if (ball->y > 600)
        {
        ball->vy = -(ball->vy);
        ball->y = 600;
        }

    if (ball->x < 0)
        {
        ball->vx = -(ball->vx);
        ball->x = 0;
        }

    if (ball->y < 0)
        {
        ball->vy = -(ball->vy);
        ball->y = 0;
        }
    }

//=============================================================================

void Draw_Ball (int x, int y, int radius)
    {
    txSetFillColor (TX_RED);
    txSetColor (TX_CYAN);
    txCircle (x, y, radius);
    }

//=============================================================================

void Control (Ball* ball)
    {
    if (GetAsyncKeyState (VK_RIGHT))  ball->vx += 3;
    if (GetAsyncKeyState (VK_LEFT))   ball->vx -= 3;
    if (GetAsyncKeyState (VK_UP))     ball->vy -= 3;
    if (GetAsyncKeyState (VK_DOWN))   ball->vy += 3;
    }

//=============================================================================

double Collision_Detection (Ball ball1, Ball ball2)
    {
    double S = sqrt ((ball1.x - ball2.x)*(ball1.x - ball2.x) + (ball1.y - ball2.y)*(ball1.y - ball2.y));
    return S;
    }

//=============================================================================

void Distance (Ball ball1, Ball ball2)
    {
    if (Collision_Detection (ball1, ball2) <= ball1.radius + ball2.radius) txMessageBox ("СТОП");
    }

//=============================================================================

void Bump (Ball balls [], int nAfricans)
    {

    for (int i = 0; i < nAfricans; i++)
        {

        for (int j = i + 1; j < nAfricans; j++)
            {
            if (Collision_Detection (balls [i], balls [j]) <= balls [i].radius + balls [j].radius)
                                     swap (balls [i].vx, balls [j].vx), swap (balls [i].vy, balls [j].vy);
            }
        }
    }






















