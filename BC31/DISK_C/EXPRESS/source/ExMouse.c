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


unsigned int mouse_background[H][W];           //存放被鼠标覆盖的区域


//鼠标初始化
void ExtMouseInit()
{
    MouseInit();                  //鼠标复位，检测是否安装鼠标
    MouseRange(0,0,1012,752);         //鼠标范围设置
    MouseGet(&mouse);                  //得到鼠标状态
    MouseSpeed(6,4);
                     
}

//画鼠标
//参数：鼠标变量，鼠标形态（0箭头，1输入）
void ExtMouseDraw(MOUSE mouse,uint8_t shape)
{
    int i, j;
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            
            mouse_background[i][j] = Getpixel64k(j + mouse.x, i + mouse.y);  //存储鼠标覆盖区

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

//隐藏鼠标
//参数：鼠标变量
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
            
            Putpixel64k(x + j, y + i, mouse_background[i][j]);   //画出原鼠标覆盖区
        }
    }
}

//更新并显示鼠标
//参数：鼠标变量，鼠标形态（0箭头，1手，2线）
void ExtMouseShow(MOUSE *mouse,uint8_t shape)
{  
    int i,j;       //循环变量
    int x,y;
    x=mouse->x;             //鼠标原位置坐标
    y=mouse->y;         
    MouseGet(mouse);    //得到新鼠标状态
    if(mouse->x!=x||mouse->y!=y)         //鼠标移动就重新画鼠标
    {
        for (i = 0; i < H; i++)            
        {
            for (j = 0; j < W; j++)
            {
                Putpixel64k(x + j, y + i, mouse_background[i][j]);   //画出原鼠标覆盖区
            }
        }
        ExtMouseDraw(*mouse,shape);                            //在新位置显示鼠标
    }
}