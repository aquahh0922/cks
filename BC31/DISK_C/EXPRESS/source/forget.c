#include"general.h"
// 忘记密码函数
int forget(int *flag)
{
    char name[20]="\0"; 
    char code[20]="\0"; // 新密码
    char code_confirm[20] = "\0"; // 确认新密码

    int nc=-1; // 用户名检查结果
    int cc=-1; // 密码检查结果
    int press=0;
    int eye=0; 
    int eye_confirm=0;

    // 显示忘记密码界面
    mouse_off(&mouse);
    delay(100);
    draw_forget();
    mouse_on(mouse);
    
    while(1)
    {
        mouse_show(&mouse);
        
        // 返回登录
        if(mouse_press(670, 650, 780, 680)==1)
        {
            *flag = 0;
            return 0;
        }
        
        // 账号
        else if(mouse_press(312,320,712,355)==1)
        {
            mouse_off(&mouse);
            bar1(320, 325, 712, 357,0xffff);
            mouse_on(mouse);
            input(name, 12,2,0x0000,0xffff,320, 325);

            // 检查用户名
            nc = namecheck_reg(name);
            bar1(620, 340, 700, 357,0xffff);
            switch(nc)
            {
                case 0:
                    puthz(620,340,"用户名未注册",16,16,0x001f);   
                    break;
                case 1:
                    puthz(620,340,"用户名为空",16,16,0x001f);
                    break;
                case 2:                    
                    puthz(620,340,"用户名过短",16,16,0x001f);                    
                    break;       
                case 3:
                    puthz(620,340,"通过",16,16,0x0f00);
                    break;
                case 4:
                    puthz(620,340,"用户名非法",16,16,0x001f);
                    break;                                                                                                                     
            }   

        }
        // 检查密码
        else if (mouse_press(312, 380, 712, 415)==1)
        {
            mouse_off(&mouse);
            bar1(320, 385,712, 417,0xffff);
            mouse_on(mouse);
            
            if (eye==0)
            {
                input_encrypted(code, 12,2,0x0000,0xffff ,320, 385);
            }
            else
            {
                input(code, 12,2,0x0000,0xffff,320, 385);
            }

            // 检查密码
            cc = codecheck_reg(code);
            bar1(620, 400, 700, 417,0xffff);
            
            switch(cc)
            {
                // case 0:
                //     puthz(620,400,"密码未注册",16,16,0x001f);   
                //     break;
                case 1:
                    puthz(620,400,"密码为空",16,16,0x001f);
                    break;
                case 2:                     
                    puthz(620,400,"密码过短",16,16,0x001f);                                                     
                    break;                    
                case 3:                    
                    puthz(620,400,"密码非法",16,16,0x001f);                                                     
                    break;
                default:
                    if(replace_code(name,code) == 1)
                    {
                        puthz(620,400,"密码已被注册",16,16,0x001f);
                        cc = 4;
                    }
                    else
                    {
                        puthz(620,400,"通过",16,16,0x0f00);
                        cc = 0;
                    }
            }                                                                                                                    
        }   
        
        //鼠标点击确认密码
        else if(mouse_press(312,440,712,475)==1)
        {
            mouse_off(&mouse);
            bar1(320, 445, 720, 477,0xffff);
            mouse_on(mouse);
            
            if (eye_confirm==0)
            {
                input_encrypted(code_confirm, 12,2,0x0000,0xffff ,320, 445);
            }
            else
            {
                input(code_confirm, 12,2,0x0000,0xffff,320, 445);
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

        //鼠标点击确定
        else if (mouse_press(400, 550, 624, 630)==1)
        {
            
            //用户名和密码检查通过，数据写入文件
            if ( cc==0 && nc==3 && press==1 && strcmp(code,code_confirm) == 0)
            {
                replace_code(name, code);
                puthz(668,505,"密码修改成功",16,16,0x0f00);
                *flag = 0;
                return 0;
            }
            
            else
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

//画重置密码界面
void draw_forget()
{   
    //背景色
    bar1(0, 0, 1024, 768, 0x8410);
    //边框
    FillRoundedRectangle(252, 250, 520, 450, 20, 0x8400);

    //注册界面白色圆角矩形
    FillRoundedRectangle(200, 200, 624, 497, 15, 0xffff);

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
    puthz(435, 570, "确定", 48, 96,0xffff);

    //提示文字
    puthz(410,230, "重置密码", 48, 48,0x0821);
    puthz(320,325,"账号",32,32,0x8410);
    puthz(320,385,"请输入新密码",32,32,0x8410);
    puthz(320,445,"确认新密码",32,32,0x8410);
    puthz(680,655,"返回登录",24,24,0x001f);

    //画眼睛
    DrawEye(740, 395, 12);
    DrawEye(740, 455, 12);
}

//功能：用户名相同时替换密码
//参数：name为用户名，new_code为新密码
int replace_code(char *name, char *new_code)
{
    FILE *fp;
    user current_user;
    int found = 0;
    long offset = -1;

    if ((fp = fopen("data\\user.dat", "rb+")) == NULL) 
    {
        CloseSVGA();
        printf("file open fail in replace_code: %s\n", "..\\data\\user.dat");
        exit(1);
    }

    // 遍历文件查找用户
    while (fread(&current_user, sizeof(user), 1, fp) == 1) 
    {
        if (strcmp(current_user.name, name) == 0) 
        {
            // 检查新旧密码是否相同
            if (strcmp(current_user.code, new_code) == 0)
            {
                fclose(fp);
                return 1; // 密码相同返回1
            }
            
            // 记录找到的位置
            offset = ftell(fp) - sizeof(user);
            found = 1;
            break;
        }
    }

    if (found) 
    {
        // 定位回用户记录起始位置
        fseek(fp, offset, SEEK_SET);
        
        // 更新密码
        strcpy(current_user.code, new_code);
        
        // 写入更新后的数据
        if (fwrite(&current_user, sizeof(user), 1, fp) != 1) 
        {
            CloseSVGA();
            printf("code update fail in replace_code\n");
            fclose(fp);
            exit(1);
        }
        fclose(fp);
        return 0; // 修改成功返回0
    }

    fclose(fp);
    CloseSVGA();
    printf("user not found in replace_code: %s\n", name);
    exit(1);
    return -1; // 用户名未找到返回-1
}


