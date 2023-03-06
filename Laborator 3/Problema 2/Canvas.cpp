#include "Canvas.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
Canvas::Canvas(int width,int height) :width(width), height(height)
{
    for (int i = 0;i < height;i++)
        for (int j = 0;j < width;j++)
            this->a[i][j] = ' ';
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch) {

    int dx = abs(x2 - x1);
    int sx = x1 < x2 ? 1 : -1;

    int dy = -abs(y2 - y1);
    int sy = y1 < y2 ? 1 : -1;

    int err = dx + dy;
    while (true) {
        this->SetPoint(y1, x1, ch);

        if (x1 == x2 && y1 == y2)  
            break;
        if (2 * err >= dy)  
            err += dy, x1 += sx;
        if (2 * err <= dx)  
            err += dx, y1 += sy;
    }
}
void Canvas::SetPoint(int x, int y, char ch)
{
    this->a[x][y] = ch;
}
void Canvas::Print() {
    for (int i = 0;i < this->height;i++)
    {
        for (int j = 0;j < this->width;j++)
            cout << this->a[i][j];
        cout << endl;
    }
}
void Canvas::Clear() {
    for (int i = 0;i < this->height;i++)
        for (int j = 0;j < this->width;j++)
            this->a[i][j] = ' ';
}
void Canvas::DrawRect(int left,int top,int right,int bottom,char ch) {
    this->DrawLine(left,top,right,top,ch);
    this->DrawLine(right,top,right,bottom,ch);
    this->DrawLine(right,bottom,left,bottom,ch);
    this->DrawLine(left,bottom,left,top,ch);
}   
void Canvas::FillRect(int left, int top, int right, int bottom, char ch) {
    int aux = bottom - 1;
    while (top != aux)
    {
        this->DrawLine(left, top, right, top, ch);
            top += 1;
    }
}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
    for (int i = 0; i < this->height; i++)
        for (int j = 0; j < this->width; j++)
        {
            int newX = i-x;
            int newY = j-y;
            if (newX * newX + newY * newY >= ray * (ray-1) && newX * newX + newY * newY <= ray * (ray+1))
                this->a[i][j] = ch;
        }
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
    for (int i = 1; i <= this->height; i++)
        for (int j = 1; j <= this->width; j++)
        {
            int newX = x - i;
            int newY = y - j;
            if (newX * newX + newY * newY <= ray * ray)
                this->a[i][j] = ch;
        }
}

