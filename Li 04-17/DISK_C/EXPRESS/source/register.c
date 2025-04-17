#include "general.h"

//注册函数
//参数：特征值指针
int reg(int *flag)
{
    //定义和初始化用户名和密码数组
    char name[20]="\0";
    char code[20]="\0";
    char code_confirm[20]="\0";

    //定义和初始化检查特征值，0表示通过
    int nc=-1;
    int cc=-1;
    int press=0;
    int eye=0;
    int eye_confirm=0;


    //画注册界面
    mouse_off(&mouse);
    delay(100);
    draw_reg();
    mouse_on(mouse);


    while (1)
    {
        
        mouse_show(&mouse);

        //鼠标点击返回
        if (mouse_press(520,655,750,685)==1)
        {
            *flag=0;
            return 0;
        }

        //鼠标点击输入用户名
        else if(mouse_press(312,320,712,355)==1)
        {
            mouse_off(&mouse);
            bar1(320, 325, 712, 357,0xffff);
            mouse_on(mouse);
            input_reg(name, 12,2,0x0000,0xffff,320, 325);

            //检查用户名
            nc=namecheck_reg(name);

            
        }
        
        //鼠标点击输入密码
        else if (mouse_press(312, 380, 712, 415)==1)
        {
            mouse_off(&mouse);
            bar1(320, 385, 712, 417,0xffff);
            mouse_on(mouse);
            if (eye==0)
            {
                input_encrypted_reg(code, 12,2,0x0000,0xffff ,320, 385);
            }
            else
            {
                inputcode_reg(code, 12,2,0x0000,0xffff,320, 385);
            }
            
            

            //检查密码
            cc=codecheck_reg(code);

        }
        
        //鼠标点击确认密码
        else if(mouse_press(312,440,712,475)==1)
        {
            mouse_off(&mouse);
            bar1(320, 445, 720, 477,0xffff);
            mouse_on(mouse);
            
            if (eye_confirm==0)
            {
                input_encrypted2_reg(code_confirm, 12,2,0x0000,0xffff ,320, 445);
            }
            else
            {
                inputcode2_reg(code_confirm, 12,2,0x0000,0xffff,320, 445);
            }
            
            if (strcmp(code,code_confirm) != 0)
            {
                bar1(560, 460, 720, 477,0xffff);
                puthz(560,460,"两次输入的密码不一致",16,16,0xf800);
            }
            else
            {
                bar1(560, 460, 720, 477,0xffff);
                puthz(668,460,"通过",16,16,0x0f00);
            }
            
        }

        //鼠标点击用户协议圆框
        else if (mouse_press(312, 500, 336, 524)==1)
        {
            mouse_off(&mouse);
            if (press==0)
            {
                Circlefill(324, 518, 8, 0x001f);
                press=1;
            }
            else
            {
                Circlefill(324, 518, 9, 0xffff);
                press=0;
            }
            mouse_on(mouse);

            // 等待鼠标释放，防止连续触发
            while (mouse_press(312, 500, 336, 524) == 1) 
            {
                delay(1); // 避免CPU忙等待
            }
        }

        //鼠标点击注册
        else if (mouse_press(400, 550, 624, 630)==1)
        {
            
            //用户名和密码检查通过，数据写入文件
            if ( cc==0 && nc==0 && press==1 && strcmp(code,code_confirm) == 0)
            {
                FILE *fp;
                user *newuser=(user*)malloc(sizeof(user));
                if (newuser==NULL)
                {
                    CloseSVGA();
                    printf("memory fail\n");
                    exit(1);
                }
                if ((fp=fopen("data\\user.dat","ab"))==NULL)
                {
                    CloseSVGA();
                    printf("file open fail: %s\n", "..\\data\\user.dat");
                    exit(1);
                }
                strcpy(newuser->name,name);
                strcpy(newuser->code,code);
                newuser->type=USER_NORMAL;
                newuser->balance=200.0f;
                fwrite(newuser,sizeof(user),1,fp);
                fclose(fp);
                free(newuser);
                draw_success();
                delay(2000);
                *flag=0;
                return 0;
            }
            if ( press==0 && cc== 0 && nc==0 && strcmp(code,code_confirm) == 0)
            {
                bar1(668, 505, 780, 536,0xffff);
                puthz(668,505,"请同意用户协议",16,16,0xf800);
            }
            
        }

        //用户点击眼睛1 -- 密码
        else if (mouse_press(728,388,752,412)==1)
        {
            mouse_off(&mouse);
            if (eye==0)
            {
                eye=1;
                output(code,2,0x0000,0xffff ,320, 385);
            }
            else
            {
                eye=0;
                output_encrypted(code,2,0x0000,0xffff ,320, 385);
            }
            mouse_on(mouse);
            // 等待鼠标释放，防止连续触发
            while (mouse_press(728,388,752,412)==1)
            {
                delay(1);
            }
        }
        
        //用户点击眼睛2 -- 确认密码
        else if (mouse_press(728,448,752,472)==1)
        {
            mouse_off(&mouse);
            if (eye_confirm==0)
            {
                
                eye_confirm=1;
                output(code_confirm,2,0x0000,0xffff ,320, 445);
            }
            else
            {
                eye_confirm=0;
                output_encrypted(code_confirm,2,0x0000,0xffff ,320, 445);
            }
            mouse_on(mouse);
            // 等待鼠标释放，防止连续触发
            while (mouse_press(728,448,752,472)==1)
            {
                delay(1);
            }
        }
        delay(15);     
    }
    
}


//画注册界面
void draw_reg()
{   
    //背景色
    bar1(0, 0, 1024, 768, 0x8410);
    //边框
    FillRoundedRectangle(252, 250, 520, 450, 20, 0x8400);

    //注册界面白色圆角矩形
    FillRoundedRectangle(200, 200, 624, 497, 15, 0xffff);
    puthz(340, 230, "注册成为新用户", 48, 48,0x0821);

    //用户名和密码输入框
    Line3(312, 360, 712, 400,2, 0x8400);
    Line3(312, 420, 712, 480,2, 0x8400);
    Line3(312, 480, 712, 540,2, 0x8400);

    //用户协议UI
    Circle(324, 518, 12, 0x0000);
    puthz(342, 505, "我已阅读并同意",24,24, 0x8400);
    puthz(520, 505, "用户协议",24,24, 0x001f);

    //注册按钮
    FillRoundedRectangle(400, 550, 224, 80, 20, 0x001f);
    puthz(435, 570, "注册", 48, 96,0xffff);

    //提示文字
    puthz(320,325,"请输入用户名",32,32,0x8410);
    puthz(320,385,"请输入密码",32,32,0x8410);
    puthz(320,445,"请再次输入密码",32,32,0x8410);
    puthz(600,655,"已有账号？点击登录",24,24,0x001f);

    //画眼睛
    DrawEye(740, 395, 12);
    DrawEye(740, 455, 12);
}

//用户名检查函数
//参数：用户名
int namecheck_reg(char *name)
{
    //用户名为空
    if (strlen(name)==0)
    {
        puthz(320, 325, "请输入用户名", 32, 32,0x8410);
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"用户名为空",16,16,0xf800);
        return 1;
    }

    //用户名过短
    else if (strlen(name)<3)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"用户名过短",16,16,0xf800);
        return 2;
    }
    
    //用户名已存在
    else if (name_repeat_check(name)==1)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"用户已存在",16,16,0xf800);
        return 3;
    }

    //用户名非法
    else if (name_legal_check(name)==1)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"用户名非法",16,16,0xf800);
        return 4;
    }

    //用户名检查通过
    bar1(668, 340, 700, 357,0xffff);
    puthz(668,340,"通过",16,16,0x0f00);
    return 0;
}

//用户名重复检查函数
//参数：用户名
int name_repeat_check(char *name)
{
    FILE *fp;
    user *newuser=(user*)malloc(sizeof(user));
    if (newuser==NULL)
    {
        CloseSVGA();
        printf("memory fail\n");
        exit(1);
    }
    if ((fp=fopen("data\\user.dat","rb"))==NULL)
    {
        CloseSVGA();
        printf("file open fail in name_repeat_check: %s\n", "..\\data\\user.dat");
        exit(1);
    }
    while (fread(newuser,sizeof(user),1,fp)==1)
    {
        if (strcmp(newuser->name,name)==0)
        {
            fclose(fp);
            free(newuser);
            return 1;
        }
    }
    fclose(fp);
    free(newuser);
    return 0;
}

//用户名合法检查函数,只能包含数字、字母和下划线
//参数：用户名
int name_legal_check(char *name)
{
    int i;
    for (i=0; i<strlen(name); i++)
    {
        if (name[i]>='0'&&name[i]<='9')
        {
            continue;
        }
        else if (name[i]>='a'&&name[i]<='z')
        {
            continue;
        }
        else if (name[i]>='A'&&name[i]<='Z')
        {
            continue;
        }
        else if (name[i]=='_')
        {
            continue;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

//密码检查函数，至少5为，同时包含数字和字母
//参数：密码
int codecheck_reg(char *code)
{

    //密码为空
    if (strlen(code)==0)
    {
        puthz(320, 385, "请输入密码", 32, 32,0x8410);
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"密码为空",16,16,0xf800);
        return 1;
    }

    //密码过短
    else if (strlen(code)<5)
    {
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"密码过短",16,16,0xf800);
        return 2;
    }

    //密码非法
    else if (code_legal_check(code)==1)
    {
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"密码非法",16,16,0xf800);
        return 3;
    }

    //密码检查通过
    //bar1(620, 490, 700, 510,0xffff);
    puthz(668,400,"通过",16,16,0x0f00);
    return 0;
}

//密码合法检查函数，至少包含一个数字和一个字母
//参数：密码
int code_legal_check(char *code)
{
    int i,ch=0,num=0;
    for (i=0; i<strlen(code); i++)
    {
        if (code[i]>='0'&&code[i]<='9')
        {
            num++;
        }
        else if (code[i]>='a'&&code[i]<='z')
        {
            ch++;
        }
        else if (code[i]>='A'&&code[i]<='Z')
        {
            ch++;
        }
    }
    if (ch==0||num==0)
    {
        return 1;
    }
    return 0;
}

//注册成功界面
void draw_success()
{
    FillRoundedRectangle(252, 230, 520, 430, 20, 0x8400);
    FillRoundedRectangle(257, 235, 510, 420, 15, 0xffff);
    puthz(410, 450, "注册成功", 48, 48,0x0821);
    delay(500);
}
