#include "general.h"
int settings(int *flag)
{

    // 显示注册快递员界面
    mouse_off(&mouse);
    delay(100);
    draw_settings();
    mouse_on(mouse);
    
    while(1)
    {
        mouse_show(&mouse);
        
        // 返回主菜单
        if(mouse_press(180, 700, 220, 735)==1)
        {
            *flag = 2;
            return 0;
        }
        
//         // 账号
//         else if(mouse_press(312,320,712,355)==1)
//         {
//             mouse_off(&mouse);
//             bar1(320, 325, 712, 357,0xffff);
//             mouse_on(mouse);
//             input(name, 12,2,0x0000,0xffff,320, 325);

//             // 检查用户名
//             nc = namecheck_reg(name);
//             bar1(620, 340, 700, 357,0xffff);
//             switch(nc)
//             {
//                 case 0:
//                     puthz(620,340,"用户名未注册",16,16,0x001f);   
//                     break;
//                 case 1:
//                     puthz(620,340,"用户名为空",16,16,0x001f);
//                     break;
//                 case 2:                    
//                     puthz(620,340,"用户名过短",16,16,0x001f);                    
//                     break;       
//                 case 3:
//                     puthz(620,340,"通过",16,16,0x0f00);
//                     break;
//                 case 4:
//                     puthz(620,340,"用户名非法",16,16,0x001f);
//                     break;                                                                                                                     
//             }   
                delay(15);
        }
        return 0;
}
//         // 检查密码
//         else if (mouse_press(312, 380, 712, 415)==1)
//         {
//             mouse_off(&mouse);
//             bar1(320, 385,712, 417,0xffff);
//             mouse_on(mouse);
            
//             if (eye==0)
//             {
//                 input_encrypted(code, 12,2,0x0000,0xffff ,320, 385);
//             }
//             else
//             {
//                 input(code, 12,2,0x0000,0xffff,320, 385);
//             }

//             // 检查密码
//             cc = codecheck_reg(code);
//             bar1(620, 400, 700, 417,0xffff);
            
//             switch(cc)
//             {
//                 // case 0:
//                 //     puthz(620,400,"密码未注册",16,16,0x001f);   
//                 //     break;
//                 case 1:
//                     puthz(620,400,"密码为空",16,16,0x001f);
//                     break;
//                 case 2:                     
//                     puthz(620,400,"密码过短",16,16,0x001f);                                                     
//                     break;                    
//                 case 3:                    
//                     puthz(620,400,"密码非法",16,16,0x001f);                                                     
//                     break;
//                 default:
//                     if(replace_code(name,code) == 1)
//                     {
//                         puthz(620,400,"密码已被注册",16,16,0x001f);
//                         cc = 4;
//                     }
//                     else
//                     {
//                         puthz(620,400,"通过",16,16,0x0f00);
//                         cc = 0;
//                     }
//             }                                                                                                                    
//         }   
        
//         //鼠标点击确认密码
//         else if(mouse_press(312,440,712,475)==1)
//         {
//             mouse_off(&mouse);
//             bar1(320, 445, 720, 477,0xffff);
//             mouse_on(mouse);
            
//             if (eye_confirm==0)
//             {
//                 input_encrypted(code_confirm, 12,2,0x0000,0xffff ,320, 445);
//             }
//             else
//             {
//                 input(code_confirm, 12,2,0x0000,0xffff,320, 445);
//             }
            
//             if (strcmp(code,code_confirm) != 0)
//             {
//                 bar1(560, 460, 720, 477,0xffff);
//                 puthz(560,460,"两次输入的密码不一致",16,16,0xf800);
//             }
//             else
//             {
//                 bar1(560, 460, 720, 477,0xffff);
//                 puthz(668,460,"通过",16,16,0x0f00);
//             }
            
//         }


//             // 等待鼠标释放，防止连续触发
//             while (mouse_press(312, 500, 336, 524) == 1) 
//             {
//                 delay(1); // 避免CPU忙等待
//             }
//         }

//         //鼠标点击确定
//         else if (mouse_press(400, 550, 624, 630)==1)
//         {
            
//             //用户名和密码检查通过，数据写入文件
//             if ( cc==0 && nc==3 && press==1 && strcmp(code,code_confirm) == 0)
//             {
//                 replace_code(name, code);
//                 puthz(668,505,"密码修改成功",16,16,0x0f00);
//                 *flag = 0;
//                 return 0;
//             }
            
//             else
//             {
//                 bar1(668, 505, 780, 536,0xffff);
//                 puthz(668,505,"请同意用户协议",16,16,0xf800);
//             }
            
//         }
// }

void draw_settings() 
{
    bar1(0, 0, 1024, 690, 0xffe0);
    FillRoundedRectangle(160, 170, 704, 90, 20, 0xffff);
    FillRoundedRectangle(160, 270, 704, 90, 20, 0xffff);
    FillRoundedRectangle(160, 370, 704, 90, 20, 0xffff);
    FillRoundedRectangle(160, 470, 704, 90, 20, 0xffff);

    //提示文字
    puthz(400,110, "个人主页", 48, 48,0x0821);
    puthz(200,210,"个人信息",32,32,0x001f);
    // puthz(200,210,"用户名",32,32,0x0821);
    // puthz(200,270,"是否注册成为快递员",32,32,0x0821);
    // puthz(680,655,"电话号码",24,24,0x001f);
    // puthz(680,715,"收货地址",24,24,0x001f);

    puthz(200,310,"消息通知",32,32,0x001f);

    puthz(200,410,"支付设置",32,32,0x001f);
    // puthz(200,625,"查看个人余额",32,32,0x0821);

    puthz(200,510,"帮助中心",32,32,0x001f);


    Circlefill(198,718,12,0xffff);
    Circlefill(798,718,12,0x00ff);
}
