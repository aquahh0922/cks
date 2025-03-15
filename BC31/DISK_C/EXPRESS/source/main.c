#include "general.h"

int main()
{
    //特征值flag
    int flag = 0;
    user *users=(user*)malloc(sizeof(user));
    if (users==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
    
    SetSVGA64k();
    mouse_init();
    while (1)
    {
        switch (flag)
        {
        case 0://欢迎界面
        
            welcome(&flag,users);
            break;
        
        case 1://注册界面
            reg(&flag);
            break;

        case 2://主菜单
            mainmenu(&flag);
            break;


        default:
            break;
        }
    delay(15);
    }
    free(users);
    CloseSVGA();
    return 0;
}