#include "general.h"

//欢迎函数
//参数：特征值指针
int welcome(int *flag,user * users)
{
    //定义和初始化用户名和密码数组
    char name[20]="\0";
    char code[20]="\0";
    //定义用户结构体
    user usr;
    //定义鼠标点击次数特征值
    int press=0;

    //定义眼睛点击次数特征值
    int eye=0;

    //画欢迎界面
    mouse_off(&mouse);
    delay(100);
    draw_wel();
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);

        //鼠标点击登录
       if (mouse_press(400, 550, 624, 630)==1)
       {
           /*if (namecheck_wel(name, &usr)==1)
           {
               if (strcmp(usr.code, code)==0)
               {
                    
                    if (press==1)
                    {
                        //登录成功
                        *flag=2;
                        return 0;
                    }
                    else
                    {
                        bar1(520, 360, 774, 392,0x8410);
                        puthz(520, 360, "请同意用户协议", 32, 32,0xf800);
                    }
                    
               }
               else
               {
                    bar1(520, 360, 774, 392,0x8410);
                    puthz(520, 360, "密码错误", 32, 32,0xf800);
               }
               
           }
           else
           {
                bar1(520, 360, 774, 392,0x8410);
                puthz(520, 360, "用户不存在", 32, 32,0xf800);
           }*/
           if (press==1)
           {
                if (namecheck_wel(name, &usr)==1)
                {
                    if (strcmp(usr.code, code)==0)
                    {
                        //登录成功
                        *flag=2;
                        *users=usr;
                        return 0;
                    }
                    else
                    {
                        bar1(520, 360, 774, 392,0x8410);
                        puthz(520, 360, "密码错误", 32, 32,0xf800);
                    }
                }
                else
                {
                    bar1(520, 360, 774, 392,0x8410);
                    puthz(520, 360, "用户不存在", 32, 32,0xf800);
                }
           }
           else
            {
                bar1(520, 360, 774, 392,0x8410);
                puthz(520, 360, "请同意用户协议", 32, 32,0xf800);
            }
           
       }

       //鼠标点击用户名输入框
       else if (mouse_press(272, 250, 752, 330)==1)
       {
            mouse_off(&mouse);
            bar1(292, 270, 732, 318,0xffff);
            mouse_on(mouse);
            input_wel(name, 14,3,0x0000,0xffff,292, 270);
            if (strlen(name)==0)
            {   
                mouse_off(&mouse);
                puthz(292, 270, "请输入用户名", 48, 48,0x8410);
                mouse_on(mouse);
            }
            
            

       }

       //鼠标点击密码输入框
       else if (mouse_press(272, 400, 752, 480)==1)
       {
            mouse_off(&mouse);
            bar1(292, 420, 732, 468,0xffff);
            mouse_on(mouse);
            if (eye==0)
            {   
                
                input_encrypted_wel(code, 14,3,0x0000,0xffff ,292, 420);
                if (strlen(code)==0)
                {
                    mouse_off(&mouse);
                    puthz(292, 420, "请输入密码", 48, 48,0x8410);
                    mouse_on(mouse);
                }
                
            }
            else
            {   
                
                inputcode_wel(code, 14,3,0x0000,0xffff,292, 420);
                if (strlen(code)==0)
                {
                    mouse_off(&mouse);
                    puthz(292, 420, "请输入密码", 48, 48,0x8410);
                    mouse_on(mouse);
                }
                
            }
            
       }

         //鼠标点击注册
        else if (mouse_press(650,680,938,712)==1)
        {
            *flag=1;
            return 0;
        }

        //鼠标点击用户协议圆钮
        else if (mouse_press(352, 500, 372, 520)==1)
        {
            mouse_off(&mouse);
            if (press==0)
            {
                Circlefill(362, 510, 6, 0x001f);

                press=1;
            }
            else
            {
                Circlefill(362, 510, 8, 0x8410);
                press=0;
            }
            mouse_on(mouse);

            // 等待鼠标释放，防止连续触发
            while (mouse_press(352, 500, 372, 520)==1) 
            {
                delay(1); // 避免CPU忙等待
            }
        }

        //鼠标点击眼睛
        else if (mouse_press(784,429,816,461)==1)
        {
            mouse_off(&mouse);
            if (eye==0)
            {
                output(code,3,0x0000,0xffff,292, 420);
                eye=1;
            }
            else
            {
                output_encrypted(code,3,0x0000,0xffff ,292, 420);
                eye=0;
            }
            mouse_on(mouse);
            while (mouse_press(784,429,816,461)==1)
            {
                delay(1);
            }
            
        }

        //鼠标点击忘记密码
        else if (mouse_press(650,640,800,670)==1)
        {
           *flag=3;
            return 1;
        } 
        
        
        delay(15);
    }
    
}

//画欢迎界面
void draw_wel()
{
    //背景色
    bar1(0, 0, 1024, 768, 0x8410);
    //用户名边框
    FillRoundedRectangle(272, 250, 480, 80, 20, 0xffff);
    //密码边框
    FillRoundedRectangle(272, 400, 480, 80, 20, 0xffff);
    //登录按钮
    FillRoundedRectangle(400, 550, 224, 80, 20, 0x001f);
    puthz(435, 570, "登录", 48, 96,0xffff);
    puthz(292, 270, "请输入用户名", 48, 48,0x8410);
    puthz(292, 420, "请输入密码", 48, 48,0x8410);
    puthz(650,640,"忘记密码？",32,32,0x001f);
    puthz(650,680,"没有账号？点击注册",32,32,0x001f);
    Circle(362, 510, 10, 0x0000);
    puthz(380,500,"我已阅读并同意",24,24,0xffff);
    puthz(548,500,"用户协议",24,24,0x001f);

    //画眼睛
    DrawEye(800, 445, 16);

    //快捷调试通道
   /*  bar1(0,0,50,50,0xffff); */
}



// 检查用户名是否存在,1表示存在，0表示不存在
// 参数：用户名，用户结构体指针
int namecheck_wel(char *name, user *usr)
{
    FILE *fp;
    int found = 0;

    // 打开用户数据库文件
    if ((fp = fopen("data\\user.dat", "rb")) == NULL)
    {
        CloseSVGA();
        printf("file open fail: %s\n", "..\\data\\user.dat");
        exit(1);
    }

    // 逐个读取用户数据并检查用户名是否存在
    while (fread(usr, sizeof(user), 1, fp) == 1)
    {
        if (strcmp(usr->name, name) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(fp);
    return found;
}








