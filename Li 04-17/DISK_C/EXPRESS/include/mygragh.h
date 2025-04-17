#ifndef _MYGRAGH_H_
#define _MYGRAGH_H_
#include "general.h"
void DrawRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color);

void DrawCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color);

void FillRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color);

void FillCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color);

void HorizontalLine(int xStart, int xEnd, int y, unsigned int color) ;

void FillEllipse(int xc, int yc, int a, int b, unsigned int color);

void DrawEye(int x, int y,float r);

void ThickLine(int x1, int y1, int x2, int y2, unsigned int color, int thickness);
#endif