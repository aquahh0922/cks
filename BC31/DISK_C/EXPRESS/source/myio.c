#include "general.h"

//输入函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        
        
        
        
    }
    return i;
}

//加密输入函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_encrypted(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
        x+=16*(size-1);
        i++;
    } 
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        delay(15);
    }
    
    return i;
}

//输出函数
//参数：输出数组，字体大小，字体颜色，背景颜色，起始坐标
int output(char *outputarray,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
    int i=0;
    char ch;
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    } 
    return i;
}

//加密输出函数
//参数：输出数组，字体大小，字体颜色，背景颜色，起始坐标
int output_encrypted(char *outputarray,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
    int i=0;
    char ch;
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
        x+=16*(size-1);
        i++;
    } 
    return i;
}

//欢迎输入函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,250)==1||mouse_press(0,330,1024,768)==1||mouse_press(0,250,272,330)==1||mouse_press(752,250,1024,330)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//欢迎加密输入函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_encrypted_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
        x+=16*(size-1);
        i++;
    } 
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        delay(15);

        if (mouse_press(0,0,1024,400)==1||mouse_press(0,480,1024,768)==1||mouse_press(0,400,272,480)==1||mouse_press(752,400,1024,480)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
    }
    
    return i;
}

//欢迎输入密码函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int inputcode_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,400)==1||mouse_press(0,480,1024,768)==1||mouse_press(0,400,272,480)==1||mouse_press(752,400,1024,480)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//注册输入用户名函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,328)==1||mouse_press(0,360,1024,768)==1||mouse_press(0,328,312,360)==1||mouse_press(712,328,1024,360)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//注册加密输入密码函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_encrypted_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,388)==1||mouse_press(0,420,1024,768)==1||mouse_press(0,388,312,420)==1||mouse_press(712,388,1024,420)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//注册加密确认密码函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int input_encrypted2_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Circlefill(x+8*(size-1),y+8*size,6*(size-1),color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,448)==1||mouse_press(0,480,1024,768)==1||mouse_press(0,448,312,480)==1||mouse_press(712,448,1024,480)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//注册输入密码函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int inputcode_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,388)==1||mouse_press(0,420,1024,768)==1||mouse_press(0,388,312,420)==1||mouse_press(712,388,1024,420)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//注册确认密码函数
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int inputcode2_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
   
    int i=0;
    char ch;
    mouse_off(&mouse);
    bar1(x,y,x+16*(size-1)*strlen(outputarray),y+16*size,backcolor);
    
    Line1(x+16*(size-1)*strlen(outputarray),y,x+16*(size-1)*strlen(outputarray),y+16*size,color);
    while (outputarray[i]!='\0')
    {
        ch=outputarray[i];
        Put_Asc16_Size(x,y,size,size,ch,color);
        x+=16*(size-1);
        i++;
    }
    mouse_on(mouse);
    while(1)
    {
        mouse_show(&mouse);
        
        if (kbhit())//非阻塞输入
        {
            ch=getch();
            if(ch==13)
            {   
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                outputarray[i]='\0';
                break;
            }
            else if(ch==8)
            {
                if(i>0)
                {
                    i--;
                    outputarray[i]='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                }
            }
            else
            {
                if(i<length)
                {
                    outputarray[i]=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=16*(size-1);
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    i++;
                }
            }
        }
        
        
        
        delay(15);
        
        if (mouse_press(0,0,1024,448)==1||mouse_press(0,480,1024,768)==1||mouse_press(0,448,312,480)==1||mouse_press(712,448,1024,480)==1)
        {
            mouse_off(&mouse);
            Line1(x,y,x,y+16*size,backcolor);
            mouse_on(mouse);
            outputarray[i]='\0';
            break;
        }
        
        
        
    }
    return i;
}

//中文输入法
//参数：输出数组，输入长度限制，字体大小，字体颜色，背景颜色，起始坐标
int inputhz(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y)
{
    unsigned char i=0,j=0,k=0,page=0;
    char ch;
    char hanzi[3];
    hz inp={0};
    char ip[20]="pinyin\\";
    FILE *fp;
    unsigned int* inputbar;
    char inputbarflag=0;
    int x0=x;
    inputbar=(unsigned int*)malloc(230*40*sizeof(unsigned int));
    if (inputbar==NULL)
    {

        printf("memery failed in inputhz\n");
        CloseSVGA();
        exit(1);
    }
    
    // 存储像素
    for (i = 0; i < 40; i++)
    {
        for (j = 0; j < 230; j++)
        {
            inputbar[i*230+j] = Getpixel64k(x+j, y+60+i);  // 使用相同的偏移 y+90
        }
    }
    i=0;
    j=0;
    
    
    mouse_off(&mouse);
    bar1(x,y,x+8*size*strlen(outputarray),y+16*size,backcolor);
    Line1(x+8*size*strlen(outputarray),y,x+8*size*strlen(outputarray),y+16*size,color);
    while (*outputarray!='\0')
    {
        if (ishz(outputarray)==1)
        {
            strncpy(hanzi,outputarray,2);
            hanzi[2]='\0';
            puthz(x,y,hanzi,16*size,8*size,color);
            outputarray+=2;
            i+=2;
            x+=16*size;
        }
        else
        {
            ch=*outputarray;
            Put_Asc16_Size(x,y,size,size,ch,color);
            outputarray++;
            i++;
            x+=8*size;
        }
        
    }
    
    mouse_on(mouse);
    while (1)
    {
        mouse_show(&mouse);
        if (kbhit())
        {
            ch=getch();
            if (ch==13)
            {
                if (inp.pinyin[0]!=0)
                {
                    for ( k = 0; k < 10; k++)
                    {
                        if (inp.pinyin[k]==0)
                        {
                            break;
                        }
                        inp.pinyin[k]=0;
                        
                        
                    }
                    
                    
                    for ( k = 0; k < 5; k++)
                    {
                        strcpy(inp.hanzi[k],"0");
                    }
                    mouse_off(&mouse);
                    for (k = 0; k < 40; k++)
                    {
                        for (j = 0; j < 230; j++)
                        {
                            Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                        }
                    }
                    mouse_on(mouse);
                    j=0;
                    inputbarflag=0;
                    
                }
                else
                {
                    mouse_off(&mouse);
                    if (inp.pinyin[0]!=0)
                    {
                        
                        for (k = 0; k < 40; k++)
                        {
                            for (j = 0; j < 230; j++)
                            {
                                Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                            }
                        }
                       
                    }
                    Line1(x,y,x,y+16*size,backcolor);
                    mouse_on(mouse);
                    *outputarray='\0';
                    break;
                }
                           
            }
            else if (ch==27)//esc
            {
                mouse_off(&mouse);
                if (inp.pinyin[0]!=0)
                {
                    for (k = 0; k < 40; k++)
                    {
                        for (j = 0; j < 230; j++)
                        {
                            Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                        }
                    }
                }
                
                Line1(x,y,x,y+16*size,backcolor);
                mouse_on(mouse);
                *outputarray='\0';
                break;
            }
            
            else if (ch==8)
            {
                
                if (inp.pinyin[0]!=0)
                {
                    j--;
                    inp.pinyin[j]='\0';
                    outputarray--;
                    i--;
                    *outputarray='\0';
                    x-=16*(size-1);
                    mouse_off(&mouse);
                    bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                    Line1(x,y,x,y+16*size,color);
                    
                    strcat(ip,inp.pinyin);
                    strcat(ip,".txt");
                    //bar1(x0,y+60,x0+228,y+100,backcolor);
                    FillRoundedRectangle(x0,y+60,228,38,2,52863);
                    put_asc16_size(x0,y+60,1,1,inp.pinyin,0);
                    if ((fp=fopen(ip,"r"))!=NULL)
                    {
                        for (k=0;k<5;k++)
                        {
                            if (fread(inp.hanzi[k],2,1,fp)!=1)
                            {
                                break;
                            }
                        
                            put_asc16_number_size(x0+k*48,y+60+18,1,1,k+1,0);
                            puthz(x0+k*48+16,y+60+16,inp.hanzi[k],16,16,color);
                        
                        }
                        fclose(fp);
                    }
                    else
                    {
                        for ( k = 0; k < 5; k++)
                        {
                            if (inp.hanzi[k][0]!=0)
                            {
                                break;
                            }
                            strcpy(inp.hanzi[k],"\0");
                        }
                    }
                    strcpy(ip,"pinyin\\");
                    if (j==0)
                    {
                        
                        for (k = 0; k < 40; k++)
                        {
                            for (j = 0; j < 230; j++)
                            {
                            Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                            }
                        }
                        j=0;
                        inputbarflag=0;
                    }
                    mouse_on(mouse);
                    
                    
                }
                else
                {
                    
                    
                    
                    if (i>1)
                    {
                        if (ishz(outputarray-2)==1)
                        {
                            outputarray-=2;
                            i-=2;
                            *outputarray='\0';
                            *(outputarray+1)='\0';
                            x-=16*(size-1)*2;
                            mouse_off(&mouse);
                            bar1(x,y,x+16*(size-1)*2,y+16*size,backcolor);
                            Line1(x+16*(size-1)*2,y,x+16*(size-1)*2,y+16*size,backcolor);
                            Line1(x,y,x,y+16*size,color);
                            mouse_on(mouse);
                        }
                        else
                        {
                            outputarray--;
                            i--;
                            *outputarray='\0';
                            x-=16*(size-1);
                            mouse_off(&mouse);
                            bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                            Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                            Line1(x,y,x,y+16*size,color);
                            mouse_on(mouse);
                        }
                        
                    }
                    else if (i>0)
                    {
                        outputarray--;
                        i--;
                        *outputarray='\0';
                        x-=16*(size-1);
                        mouse_off(&mouse);
                        bar1(x,y,x+16*(size-1),y+16*size,backcolor);
                        Line1(x+16*(size-1),y,x+16*(size-1),y+16*size,backcolor);
                        Line1(x,y,x,y+16*size,color);
                        mouse_on(mouse);
                    }
                    
                    
                }
                
                
            }
            else if(ch==49&&inp.hanzi[0][0]!=0||ch==' '&&inp.hanzi[0][0]!=0)
            {
                outputarray-=j;
                i-=j;
                strcpy(outputarray,inp.hanzi[0]);
                outputarray+=2;
                i+=2;
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                x-=8*size*j;
                bar1(x,y,x+8*size*j,y+16*size,backcolor);
                puthz(x,y,inp.hanzi[0],size*16,size*16,color);
                x+=16*size;
                Line1(x,y,x,y+16*size,color);
                mouse_on(mouse);
                for ( k = 0; k < 5; k++)
                {
                    strcpy(inp.hanzi[k],"\0");
                }
                for ( k = 0; k < 10; k++)
                {
                    if (inp.pinyin[k]==0)
                    {
                        break;
                    }
                    inp.pinyin[k]=0;
                }
                inputbarflag=0;
                mouse_off(&mouse);
                for (k = 0; k < 40; k++)
                {
                    for (j = 0; j < 230; j++)
                    {
                        Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                    }
                }
                
                mouse_on(mouse);
                j=0;
            }
            else if(ch==50&&inp.hanzi[1][0]!=0)
            {
                outputarray-=j;
                i-=j;
                strcpy(outputarray,inp.hanzi[1]);
                outputarray+=2;
                i+=2;
                mouse_off(&mouse);
                x-=8*size*j;
                bar1(x,y,x+8*size*j,y+16*size,backcolor);
                puthz(x,y,inp.hanzi[1],size*16,size*16,color);
                x+=16*size;
                Line1(x,y,x,y+16*size,color);
                mouse_on(mouse);
                for ( k = 0; k < 5; k++)
                {
                    strcpy(inp.hanzi[k],"\0");
                }
                for ( k = 0; k < 10; k++)
                {
                    if (inp.pinyin[k]==0)
                    {
                        break;
                    }
                    inp.pinyin[k]=0;
                }
                inputbarflag=0;
                mouse_off(&mouse);
                for (k = 0; k < 40; k++)
                {
                    for (j = 0; j < 230; j++)
                    {
                        Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                    }
                }
                mouse_on(mouse);
                j=0;
            }
            else if (ch==51&&inp.hanzi[2][0]!=0)
            {
                outputarray-=j;
                i-=j;
                strcpy(outputarray,inp.hanzi[2]);
                outputarray+=2;
                i+=2;
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                x-=8*size*j;
                bar1(x,y,x+8*size*j,y+16*size,backcolor);
                puthz(x,y,inp.hanzi[2],size*16,size*16,color);
                x+=16*size;
                Line1(x,y,x,y+16*size,color);
                mouse_on(mouse);
                for ( k = 0; k < 5; k++)
                {
                    strcpy(inp.hanzi[k],"\0");
                }
                for ( k = 0; k < 10; k++)
                {
                    if (inp.pinyin[k]==0)
                    {
                        break;
                    }
                    inp.pinyin[k]=0;
                }
                inputbarflag=0;
                mouse_off(&mouse);
                for (k = 0; k < 40; k++)
                {
                    for (j = 0; j < 230; j++)
                    {
                        Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                    }
                }
                mouse_on(mouse);
                j=0;
            }
            else if (ch==52&&inp.hanzi[3][0]!=0)
            {
                outputarray-=j;
                i-=j;
                strcpy(outputarray,inp.hanzi[3]);
                outputarray+=2;
                i+=2;
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                x-=8*size*j;
                bar1(x,y,x+8*size*j,y+16*size,backcolor);
                puthz(x,y,inp.hanzi[3],size*16,size*16,color);
                x+=16*size;
                Line1(x,y,x,y+16*size,color);
                mouse_on(mouse);
                for ( k = 0; k < 5; k++)
                {
                    strcpy(inp.hanzi[k],"\0");
                }
                for ( k = 0; k < 10; k++)
                {
                    if (inp.pinyin[k]==0)
                    {
                        break;
                    }
                    inp.pinyin[k]=0;
                }
                inputbarflag=0;
                mouse_off(&mouse);
                for (k = 0; k < 40; k++)
                {
                    for (j = 0; j < 230; j++)
                    {
                        Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                    }
                }
                mouse_on(mouse);
                j=0;
            }
            else if (ch==53&&inp.hanzi[4][0]!=0)
            {
                outputarray-=j;
                i-=j;
                strcpy(outputarray,inp.hanzi[4]);
                outputarray+=2;
                i+=2;
                mouse_off(&mouse);
                Line1(x,y,x,y+16*size,backcolor);
                x-=8*size*j;
                bar1(x,y,x+8*size*j,y+16*size,backcolor);
                puthz(x,y,inp.hanzi[4],size*16,size*16,color);
                x+=16*size;
                Line1(x,y,x,y+16*size,color);
                mouse_on(mouse);
                for ( k = 0; k < 5; k++)
                {
                    strcpy(inp.hanzi[k],"\0");
                }
                for ( k = 0; k < 10; k++)
                {
                    if (inp.pinyin[k]==0)
                    {
                        break;
                    }
                    inp.pinyin[k]=0;
                }
                inputbarflag=0;
                mouse_off(&mouse);
                for (k = 0; k < 40; k++)
                {
                    for (j = 0; j < 230; j++)
                    {
                        Putpixel64k(x0+j, y+60+k, inputbar[k*230+j]);
                    }
                }
                mouse_on(mouse);
                j=0;
            }
            else if (ch=='='&&inp.hanzi[4][0]!=0)
            {
                page++;
                //bar1(x0,y+60,x0+228,y+100,0xffff);
                mouse_off(&mouse);
                FillRoundedRectangle(x0,y+60,228,38,2,52863);
                put_asc16_size(x0,y+60,1,1,inp.pinyin,0);
                strcat(ip,inp.pinyin);
                strcat(ip,".txt");
                if ((fp=fopen(ip,"r"))!=NULL)
                {
                    fseek(fp,page*5*2,SEEK_SET);
                    mouse_off(&mouse);
                    for (k=0;k<5;k++)
                    {
                        if (fread(inp.hanzi[k],2,1,fp)!=1)
                        {
                            break;
                        }
                        
                        put_asc16_number_size(x0+k*48,y+60+18,1,1,k+1,0);
                        puthz(x0+k*48+16,y+60+16,inp.hanzi[k],16,16,color);
                        
                    }
                    mouse_on(mouse);
                    fclose(fp);
                }
                strcpy(ip,"pinyin\\");
                mouse_on(mouse);
            }
            else if (ch=='-'&&page>0)
            {
                page--;
                //bar1(x0,y+60,x0+228,y+100,0xffff);
                mouse_off(&mouse);
                FillRoundedRectangle(x0,y+60,228,38,2,52863);
                put_asc16_size(x0,y+60,1,1,inp.pinyin,0);
                strcat(ip,inp.pinyin);
                strcat(ip,".txt");
                if ((fp=fopen(ip,"r"))!=NULL)
                {
                    fseek(fp,page*5*2,SEEK_SET);
                    mouse_off(&mouse);
                    for (k=0;k<5;k++)
                    {
                        fread(inp.hanzi[k],2,1,fp);
                        put_asc16_number_size(x0+k*48,y+60+18,1,1,k+1,0);
                        puthz(x0+k*48+16,y+60+16,inp.hanzi[k],16,16,color);
                    }
                    mouse_on(mouse);
                    fclose(fp);
                }
                strcpy(ip,"pinyin\\");
                mouse_on(mouse);
            }
            
            else
            {
                if (i<length-1)
                {
                    *outputarray=ch;
                    mouse_off(&mouse);
                    Put_Asc16_Size(x,y,size,size,ch,color);
                    Line1(x,y,x,y+16*size,backcolor);
                    x+=8*size;
                    Line1(x,y,x,y+16*size,color);
                    mouse_on(mouse);
                    if (j<9)
                    {
                        *(inp.pinyin+j)=ch;
                        j++;
                        
                        strcat(ip,inp.pinyin);
                        strcat(ip,".txt");
                        mouse_off(&mouse);
                        if (inputbarflag==0)
                        {
                            
                            //bar1(x0,y+60,x0+228,y+100,0xffff);
                            FillRoundedRectangle(x0,y+60,228,38,2,52863);
                            
                            
                            inputbarflag=1;
                        }
                        put_asc16_size(x0,y+60,1,1,inp.pinyin,0);
                        mouse_on(mouse);
                        
                        if ((fp=fopen(ip,"r"))!=NULL)
                        {
                            mouse_off(&mouse);
                            for (k=0;k<5;k++)
                            {
                                if (fread(inp.hanzi[k],2,1,fp)!=1)
                                {
                                    break;
                                }
                                put_asc16_number_size(x0+k*48,y+60+18,1,1,k+1,0);
                                puthz(x0+k*48+16,y+60+16,inp.hanzi[k],16,16,color);
                            }
                            mouse_on(mouse);
                            inputbarflag=0;
                            page=0;
                            fclose(fp);
                            
                        }
                        
                        else
                        {
                            for (k=0;k<5;k++)
                            {
                                if (inp.hanzi[k][0]==0)
                                {
                                    break;
                                }
                                
                                strcpy(inp.hanzi[k],"\0");
                                
                            }
                           
                        }
                        
                        
                    }
                    outputarray++;
                    i++;
                    strcpy(ip,"pinyin\\");//清空ip
                   
                    
                }
            }
        }
        
        delay(15);
    }
    free(inputbar);
    
    return i;
    
    
}

//判断前一个字是否是否中文
//参数：字符指针
int ishz(char* hz)
{
    
    if ((unsigned char)hz[0] >= 0xA1 && (unsigned char)hz[0] <= 0xF7 &&
    (unsigned char)hz[1] >= 0xA1 && (unsigned char)hz[1] <= 0xFE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
}