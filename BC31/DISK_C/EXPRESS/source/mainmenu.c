#include "general.h"


int mainmenu(int *flag)
{
    char hzsearch[50]={0};
    mouse_off(&mouse);
    delay(100);
    draw_mainmenu();
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);
        if (mouse_press(140,60,860,110)==1)
        {
            inputhz(hzsearch,49,2,0,0xffff,140,60);
            
        }
        
        
        delay(15);
    }
    return 0;
}


//�����˵�����
void draw_mainmenu()
{
    //����ɫ
    bar1(0, 0, 1024, 768, 0x8410);
   
    Cirbar(140,60,860,110,0xffff);

    FillRoundedRectangle(100,150,824,200,20,0xffff);
    Circle(312,205,45,0x0000);
    Circle(512,205,45,0x0000);
    Circle(712,205,45,0x0000);
    Circle(512,205,45,0x0000);
    Circle(512,205,45,0x0000);
    
    bar1(0,688,1024,768,0xffff);
    Circle(198,718,16,0x0000);
    Circlefill(198,718,12,0x00ff);
    Circle(398,718,16,0x0000);
    Circle(608,718,16,0x0000);
    Circle(798,718,16,0x0000);
    puthz(180,748,"��ҳ",16,20,0x8410);
    puthz(380,748,"����",16,20,0x8410);
    puthz(580,748,"����Ա",16,20,0x8410);
    puthz(780,748,"�ҵ�",16,20,0x8410);
}