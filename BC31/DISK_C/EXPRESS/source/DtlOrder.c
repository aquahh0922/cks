#include "DtlOrder.h"

int DetailedOrder(int *flag)
{
    int deltax=0,deltay=0,cx=CenterX,cy=CenterY;
    mouse_off(&mouse);
    delay(100);
    
    drawDetailedOrder();
    mouse_on(mouse);
    while (1)
    {
        mouse_show(&mouse);
        mouse_off(&mouse);
        HandleMouseDrag(&deltax,&deltay,&mouse,10);
        mouse_on(mouse);
        // if (deltax!=0||deltay!=0)
        // {
            
        //     cx+=deltax;
        //     cy+=deltay;
        //     mouse_off(&mouse);
        //     if (cx<MapminWidth&&cx>1024-MapminWidth&&cy<MapminHeight&&cy>768-MapminHeight)
        //     {
        //         Readbmp64k(cx-MapminWidth,cy-MapminHeight,"img\\mapmin1.bmp");
        //         Readbmp64k(cx,cy-MapminHeight,"img\\mapmin2.bmp");
        //         Readbmp64k(cx-MapminWidth,cy,"img\\mapmin3.bmp");
        //         Readbmp64k(cx,cy,"img\\mapmin4.bmp");
               
        //         deltax=0;
        //         deltay=0;
        //     }
        //     else
        //     {
        //         cx=(abs(cx-MapminWidth)<abs(cx-1024+MapminWidth))?MapminWidth:1024-MapminWidth;
        //         cy=(abs(cy-MapminHeight)<abs(cy-768+MapminHeight))?MapminHeight:768-MapminHeight;
        //         Readbmp64k(cx-MapminWidth,cy-MapminHeight,"img\\mapmin1.bmp");
        //         Readbmp64k(cx,cy-MapminHeight,"img\\mapmin2.bmp");
        //         Readbmp64k(cx-MapminWidth,cy,"img\\mapmin3.bmp");
        //         Readbmp64k(cx,cy,"img\\mapmin4.bmp");
        //         deltax=0;
        //         deltay=0;
        //     }
        //     mouse_on(mouse);

        // }
        if (deltax!=0||deltay!=0)
        {
            cx+=deltax;
            cy+=deltay;
             // 分别检查并限制x和y的边界
            if (cx > MapminWidth) 
            cx = MapminWidth;
            else if (cx < 1024 - MapminWidth)
            cx = 1024 - MapminWidth;

            if (cy > MapminHeight)
            cy = MapminHeight;
            else if (cy < 768 - MapminHeight)
            cy = 768 - MapminHeight;

            // 绘制图像
            mouse_off(&mouse);
            Readbmp64k(cx-MapminWidth, cy-MapminHeight, "img\\mapmin1.bmp");
            Readbmp64k(cx, cy-MapminHeight, "img\\mapmin2.bmp");
            Readbmp64k(cx-MapminWidth, cy, "img\\mapmin3.bmp");
            Readbmp64k(cx, cy, "img\\mapmin4.bmp");
            mouse_on(mouse);
            deltax = 0;
            deltay = 0;
        }
        
        
        delay(15);
    }
    
}


void drawDetailedOrder()
{
    
    bar1(0, 0, 1024, 768, 54938);
    Readbmp64k(-466,-219,"img\\mapmin1.bmp");
    Readbmp64k(512,-219,"img\\mapmin2.bmp");
    Readbmp64k(-466,384,"img\\mapmin3.bmp");
    Readbmp64k(512,384,"img\\mapmin4.bmp");
}