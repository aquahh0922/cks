#include "general.h"
int settings(int *flag)
{

    // ��ʾע����Ա����
    mouse_off(&mouse);
    delay(100);
    draw_settings();
    mouse_on(mouse);
    
    while(1)
    {
        mouse_show(&mouse);
        
        // �������˵�
        if(mouse_press(180, 700, 220, 735)==1)
        {
            *flag = 2;
            return 0;
        }
        
//         // �˺�
//         else if(mouse_press(312,320,712,355)==1)
//         {
//             mouse_off(&mouse);
//             bar1(320, 325, 712, 357,0xffff);
//             mouse_on(mouse);
//             input(name, 12,2,0x0000,0xffff,320, 325);

//             // ����û���
//             nc = namecheck_reg(name);
//             bar1(620, 340, 700, 357,0xffff);
//             switch(nc)
//             {
//                 case 0:
//                     puthz(620,340,"�û���δע��",16,16,0x001f);   
//                     break;
//                 case 1:
//                     puthz(620,340,"�û���Ϊ��",16,16,0x001f);
//                     break;
//                 case 2:                    
//                     puthz(620,340,"�û�������",16,16,0x001f);                    
//                     break;       
//                 case 3:
//                     puthz(620,340,"ͨ��",16,16,0x0f00);
//                     break;
//                 case 4:
//                     puthz(620,340,"�û����Ƿ�",16,16,0x001f);
//                     break;                                                                                                                     
//             }   
                delay(15);
        }
        return 0;
}
//         // �������
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

//             // �������
//             cc = codecheck_reg(code);
//             bar1(620, 400, 700, 417,0xffff);
            
//             switch(cc)
//             {
//                 // case 0:
//                 //     puthz(620,400,"����δע��",16,16,0x001f);   
//                 //     break;
//                 case 1:
//                     puthz(620,400,"����Ϊ��",16,16,0x001f);
//                     break;
//                 case 2:                     
//                     puthz(620,400,"�������",16,16,0x001f);                                                     
//                     break;                    
//                 case 3:                    
//                     puthz(620,400,"����Ƿ�",16,16,0x001f);                                                     
//                     break;
//                 default:
//                     if(replace_code(name,code) == 1)
//                     {
//                         puthz(620,400,"�����ѱ�ע��",16,16,0x001f);
//                         cc = 4;
//                     }
//                     else
//                     {
//                         puthz(620,400,"ͨ��",16,16,0x0f00);
//                         cc = 0;
//                     }
//             }                                                                                                                    
//         }   
        
//         //�����ȷ������
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
//                 puthz(560,460,"������������벻һ��",16,16,0xf800);
//             }
//             else
//             {
//                 bar1(560, 460, 720, 477,0xffff);
//                 puthz(668,460,"ͨ��",16,16,0x0f00);
//             }
            
//         }


//             // �ȴ�����ͷţ���ֹ��������
//             while (mouse_press(312, 500, 336, 524) == 1) 
//             {
//                 delay(1); // ����CPUæ�ȴ�
//             }
//         }

//         //�����ȷ��
//         else if (mouse_press(400, 550, 624, 630)==1)
//         {
            
//             //�û�����������ͨ��������д���ļ�
//             if ( cc==0 && nc==3 && press==1 && strcmp(code,code_confirm) == 0)
//             {
//                 replace_code(name, code);
//                 puthz(668,505,"�����޸ĳɹ�",16,16,0x0f00);
//                 *flag = 0;
//                 return 0;
//             }
            
//             else
//             {
//                 bar1(668, 505, 780, 536,0xffff);
//                 puthz(668,505,"��ͬ���û�Э��",16,16,0xf800);
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

    //��ʾ����
    puthz(400,110, "������ҳ", 48, 48,0x0821);
    puthz(200,210,"������Ϣ",32,32,0x001f);
    // puthz(200,210,"�û���",32,32,0x0821);
    // puthz(200,270,"�Ƿ�ע���Ϊ���Ա",32,32,0x0821);
    // puthz(680,655,"�绰����",24,24,0x001f);
    // puthz(680,715,"�ջ���ַ",24,24,0x001f);

    puthz(200,310,"��Ϣ֪ͨ",32,32,0x001f);

    puthz(200,410,"֧������",32,32,0x001f);
    // puthz(200,625,"�鿴�������",32,32,0x0821);

    puthz(200,510,"��������",32,32,0x001f);


    Circlefill(198,718,12,0xffff);
    Circlefill(798,718,12,0x00ff);
}
