#include "general.h"
//��������Բ�Ǿ���
//�������������Ͻ����꣬���ο�ȣ����θ߶ȣ�Բ�ǰ뾶����ɫ
void DrawRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color)
{
    // ������ֱ��
    Line1(x + radius, y, x + width - radius, y, color); // �ϱ�
    Line1(x + radius, y + height, x + width - radius, y + height, color); // �±�
    Line1(x, y + radius, x, y + height - radius, color); // ���
    Line1(x + width, y + radius, x + width, y + height - radius, color); // �ұ�

    // ���ĸ�Բ��
    DrawCircleQuarter(x + radius, y + radius, radius, 1, color); // ���Ͻ�
    DrawCircleQuarter(x + width - radius, y + radius, radius, 2, color); // ���Ͻ�
    DrawCircleQuarter(x + radius, y + height - radius, radius, 3, color); // ���½�
    DrawCircleQuarter(x + width - radius, y + height - radius, radius, 4, color); // ���½�
}

// ���������ķ�֮һԲ
// ������Բ�����꣬�뾶����λ��1Ϊ���Ͻǣ�2Ϊ���Ͻǣ�3Ϊ���½ǣ�4Ϊ���½ǣ�����ɫ
void DrawCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color)
{
    int x = 0, y = r;
    int d = 3 - 2 * r;

    while (x <= y)
    {
        if (quarter == 1) // ���Ͻ�
        {
            Putpixel64k(xc - x, yc - y, color);
            Putpixel64k(xc - y, yc - x, color);
        }
        else if (quarter == 2) // ���Ͻ�
        {
            Putpixel64k(xc + x, yc - y, color);
            Putpixel64k(xc + y, yc - x, color);
        }
        else if (quarter == 3) // ���½�
        {
            Putpixel64k(xc - x, yc + y, color);
            Putpixel64k(xc - y, yc + x, color);
        }
        else if (quarter == 4) // ���½�
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

// �������Բ�Ǿ���
//�������������Ͻ����꣬���ο�ȣ����θ߶ȣ�Բ�ǰ뾶����ɫ
void FillRoundedRectangle(int x, int y, int width, int height, int radius, unsigned int color)
{
    int i, j;

    // �����ε��м䲿��
    for (i = y + radius; i <= y + height - radius; i++)
    {
        for (j = x; j <= x + width; j++)
        {
            Putpixel64k(j, i, color);
        }
    }

    // �����ε��ϱߺ��±�
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

    // ����ĸ�Բ��
    FillCircleQuarter(x + radius, y + radius, radius, 1, color); // ���Ͻ�
    FillCircleQuarter(x + width - radius, y + radius, radius, 2, color); // ���Ͻ�
    FillCircleQuarter(x + radius, y + height - radius, radius, 3, color); // ���½�
    FillCircleQuarter(x + width - radius, y + height - radius, radius, 4, color); // ���½�
}

// ����ķ�֮һԲ�ĺ���
// ������Բ�����꣬�뾶����λ��1Ϊ���Ͻǣ�2Ϊ���Ͻǣ�3Ϊ���½ǣ�4Ϊ���½ǣ�����ɫ
void FillCircleQuarter(int xc, int yc, int r, int quarter, unsigned int color) 
{
    int x = r;
    int y = 0;
    int err = 0;

    while (x >= y) {
        // ����ˮƽ������ķ�֮һԲ
        switch (quarter) {
            case 1: // ���Ͻ�
                HorizontalLine(xc - x, xc, yc - y, color);
                HorizontalLine(xc - y, xc, yc - x, color);
                break;
            case 2: // ���Ͻ�
                HorizontalLine(xc, xc + x, yc - y, color);
                HorizontalLine(xc, xc + y, yc - x, color);
                break;
            case 3: // ���½�
                HorizontalLine(xc - x, xc, yc + y, color);
                HorizontalLine(xc - y, xc, yc + x, color);
                break;
            case 4: // ���½�
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

// ��������������ˮƽ��
// ������x��ʼ���꣬x��ֹ���꣬y���꣬��ɫ
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

// ������Բ������߿�
// ��������Բ�������꣬��Բ����뾶����Բ����뾶����ɫ
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

//�����۾�ͼ��
//�������۾��������꣬�۾��뾶
void DrawEye(int x, int y,float r)
{
    Circlefill(x, y, r, 0x0000);

    FillEllipse(x, y, r, r / 2, 0xffff);

    Circlefill(x, y, r / 3, 0x0000);

}