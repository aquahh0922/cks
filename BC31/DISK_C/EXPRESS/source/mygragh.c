#include "general.h"
//画不填充的圆角矩形
//参数：矩形左上角坐标，矩形宽度，矩形高度，圆角半径，颜色
void DrawRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color)
{
    // 画四条直线
    Line1(x + radius, y, x + width - radius, y, color); // 上边
    Line1(x + radius, y + height, x + width - radius, y + height, color); // 下边
    Line1(x, y + radius, x, y + height - radius, color); // 左边
    Line1(x + width, y + radius, x + width, y + height - radius, color); // 右边

    // 画四个圆角
    DrawCircleQuarter(x + radius, y + radius, radius, 1, color); // 左上角
    DrawCircleQuarter(x + width - radius, y + radius, radius, 2, color); // 右上角
    DrawCircleQuarter(x + radius, y + height - radius, radius, 3, color); // 左下角
    DrawCircleQuarter(x + width - radius, y + height - radius, radius, 4, color); // 右下角
}

// 画不填充的四分之一圆
// 参数：圆心坐标，半径，方位（1为左上角，2为右上角，3为左下角，4为右下角），颜色
void DrawCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        if (quarter == 1) // 左上角
        {
            Putpixel64k(xc - x, yc - y, color);
            Putpixel64k(xc - y, yc - x, color);
        }
        else if (quarter == 2) // 右上角
        {
            Putpixel64k(xc + x, yc - y, color);
            Putpixel64k(xc + y, yc - x, color);
        }
        else if (quarter == 3) // 左下角
        {
            Putpixel64k(xc - x, yc + y, color);
            Putpixel64k(xc - y, yc + x, color);
        }
        else if (quarter == 4) // 右下角
        {
            Putpixel64k(xc + x, yc + y, color);
            Putpixel64k(xc + y, yc + x, color);
        }

        if (d < 0)
        {
            d = d + 4 * x + 6;
        }
        else
        {
            d = d + 4 * (x - y) + 10;
            y--;
        }
        x++;
    }
}

// 绘制填充圆角矩形
//参数：矩形左上角坐标，矩形宽度，矩形高度，圆角半径，颜色
void FillRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color)
{
    int i, j;

    // 填充矩形的中间部分
    for (i = y + radius; i <= y + height - radius; i++)
    {
        for (j = x; j <= x + width; j++)
        {
            Putpixel64k(j, i, color);
        }
    }

    // 填充矩形的上边和下边
    for (i = y; i <= y + radius; i++)
    {
        for (j = x + radius; j <= x + width - radius; j++)
        {
            Putpixel64k(j, i, color);
        }
    }
    for (i = y + height - radius; i <= y + height; i++)
    {
        for (j = x + radius; j <= x + width - radius; j++)
        {
            Putpixel64k(j, i, color);
        }
    }

    // 填充四个圆角
    FillCircleQuarter(x + radius, y + radius, radius, 1, color); // 左上角
    FillCircleQuarter(x + width - radius, y + radius, radius, 2, color); // 右上角
    FillCircleQuarter(x + radius, y + height - radius, radius, 3, color); // 左下角
    FillCircleQuarter(x + width - radius, y + height - radius, radius, 4, color); // 右下角
}

// 填充四分之一圆的函数
// 参数：圆心坐标，半径，方位（1为左上角，2为右上角，3为左下角，4为右下角），颜色
void FillCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color) 
{
    int x = r;
    int y = 0;
    int err = 0;

    while (x >= y) {
        // 绘制水平线填充四分之一圆
        switch (quarter) {
            case 1: // 左上角
                HorizontalLine(xc - x, xc, yc - y, color);
                HorizontalLine(xc - y, xc, yc - x, color);
                break;
            case 2: // 右上角
                HorizontalLine(xc, xc + x, yc - y, color);
                HorizontalLine(xc, xc + y, yc - x, color);
                break;
            case 3: // 左下角
                HorizontalLine(xc - x, xc, yc + y, color);
                HorizontalLine(xc - y, xc, yc + x, color);
                break;
            case 4: // 右下角
                HorizontalLine(xc, xc + x, yc + y, color);
                HorizontalLine(xc, xc + y, yc + x, color);
                break;
        }

        y += 1;
        err += 1 + 2*y;
        if (2*(err - x) + 1 > 0) {
            x -= 1;
            err += 1 - 2*x;
        }
    }
}

// 辅助函数：绘制水平线
// 参数：x起始坐标，x终止坐标，y坐标，颜色
void HorizontalLine(int xStart, int xEnd, int y, unsigned int color) 
{
	int x;
    if (xStart > xEnd) 
	{
        int temp = xStart;
        xStart = xEnd;
        xEnd = temp;
    }
    for ( x = xStart; x <= xEnd; x++)
	{
        Putpixel64k(x, y, color);
    }
}

// 绘制椭圆（填充或边框）
// 参数：椭圆中心坐标，椭圆长轴半径，椭圆短轴半径，颜色
void FillEllipse(int xc, int yc, int a, int b, unsigned int color)
{
    int x = 0, y = b;
    long a2 = a * a, b2 = b * b;
    long fa2 = 4 * a2, fb2 = 4 * b2;
    long sigma = 2 * b2 + a2 * (1 - 2 * b);

    while (b2 * x <= a2 * y)
    {
        Line1(xc - x, yc - y, xc + x, yc - y, color);
        Line1(xc - x, yc + y, xc + x, yc + y, color);
        if (sigma >= 0)
        {
            sigma += fa2 * (1 - y);
            y--;
        }
        sigma += b2 * ((4 * x) + 6);
        x++;
    }

    x = a;
    y = 0;
    sigma = 2 * a2 + b2 * (1 - 2 * a);

    while (a2 * y <= b2 * x)
    {
        Line1(xc - x, yc - y, xc + x, yc - y, color);
        Line1(xc - x, yc + y, xc + x, yc + y, color);
        if (sigma >= 0)
        {
            sigma += fb2 * (1 - x);
            x--;
        }
        sigma += a2 * ((4 * y) + 6);
        y++;
    }
}

//绘制眼睛图标
//参数：眼睛中心坐标，眼睛半径
void DrawEye(int x, int y,float r)
{
    Circlefill(x, y, r, 0x0000);

    FillEllipse(x, y, r, r / 2, 0xffff);

    Circlefill(x, y, r / 3, 0x0000);

}