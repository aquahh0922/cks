#include "ExMouse.h"

#define H 15
#define W 12

uint8_t arrow_shape[H][W] = {
    {1,1,0,0,0,0,0,0,0,0,0,0},
	{1,2,1,0,0,0,0,0,0,0,0,0},
	{1,2,2,1,0,0,0,0,0,0,0,0},
	{1,2,2,2,1,0,0,0,0,0,0,0},
	{1,2,2,2,2,1,0,0,0,0,0,0},
	{1,2,2,2,2,2,1,0,0,0,0,0},
	{1,2,2,2,2,2,2,1,0,0,0,0},
	{1,2,2,2,2,2,2,2,1,0,0,0},
	{1,2,2,2,2,2,2,2,2,1,0,0},
	{1,2,2,2,2,2,2,2,2,2,1,0},
	{1,2,2,2,2,2,2,1,1,1,1,1},
	{1,2,2,1,2,2,2,1,0,0,0,0},
	{1,2,1,0,1,2,2,2,1,0,0,0},	
	{1,1,0,0,0,1,2,2,2,1,0,0},	
	{1,0,0,0,0,0,1,1,1,1,0,0}
};



uint8_t line_shape[H][W] = {
    {0,1,1,1,1,1,1,1,1,1,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,0,0,0,0,1,0,0,0,0,0,0},
    {0,1,1,1,1,1,1,1,1,1,0,0}
};


unsigned int mouse_background[H][W];           //��ű���긲�ǵ�����


//����ʼ��
void ExtMouseInit()
{
    MouseInit();                  //��긴λ������Ƿ�װ���
    MouseRange(0,0,1012,752);         //��귶Χ����
    MouseGet(&mouse);                  //�õ����״̬
    MouseSpeed(6,4);
                     
}

//�����
//�������������������̬��0��ͷ��1���룩
void ExtMouseDraw(MOUSE mouse,uint8_t shape)
{
    int i, j;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            
            mouse_background[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  //�洢��긲����

            if (shape==0)
            {
                if (arrow_shape[i][j] == 1)
                    Putpixel64k(mouse.x + j, mouse.y + i, 0);
                else if (arrow_shape[i][j] == 2)
                    Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
               
                
            }
            else
            {
               if (line_shape[i][j] == 1)
                    Putpixel64k(mouse.x + j, mouse.y + i, 0);
                else if (line_shape[i][j] == 2)
                    Putpixel64k(mouse.x + j, mouse.y + i, 0xffff);
               
               
            }
            
            
            
        }
    }

}

//�������
//������������
void ExtMouseHide(MOUSE *mouse)
{
    int i,j;
    int x,y;
    x=mouse->x;
    y=mouse->y;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            
            Putpixel64k(x + j, y + i, mouse_background[i][j]);   //����ԭ��긲����
        }
    }
}

//���²���ʾ���
//�������������������̬��0��ͷ��1�֣�2�ߣ�
void ExtMouseShow(MOUSE *mouse,uint8_t shape)
{  
    int i,j;       //ѭ������
    int x,y;
    x=mouse->x;             //���ԭλ������
    y=mouse->y;         
    MouseGet(mouse);    //�õ������״̬
    if(mouse->x!=x||mouse->y!=y)         //����ƶ������»����
    {
        for (i = 0; i < H; i++)            
        {
            for (j = 0; j < W; j++)
            {
                Putpixel64k(x + j, y + i, mouse_background[i][j]);   //����ԭ��긲����
            }
        }
        ExtMouseDraw(*mouse,shape);                            //����λ����ʾ���
    }
}