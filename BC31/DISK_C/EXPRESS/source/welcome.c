#include "general.h"

//��ӭ����
//����������ֵָ��
int welcome(int *flag,user * users)
{
    //����ͳ�ʼ���û�������������
    char name[20]="\0";
    char code[20]="\0";
    //�����û��ṹ��
    user usr;
    //�����������������ֵ
    int press=0;

    //�����۾������������ֵ
    int eye=0;

    //����ӭ����
    mouse_off(&mouse);
    delay(100);
    draw_wel();
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);

        //�������¼
       if (mouse_press(400, 550, 624, 630)==1)
       {
           /*if (namecheck_wel(name, &usr)==1)
           {
               if (strcmp(usr.code, code)==0)
               {
                    
                    if (press==1)
                    {
                        //��¼�ɹ�
                        *flag=2;
                        return 0;
                    }
                    else
                    {
                        bar1(520, 360, 774, 392,0x8410);
                        puthz(520, 360, "��ͬ���û�Э��", 32, 32,0xf800);
                    }
                    
               }
               else
               {
                    bar1(520, 360, 774, 392,0x8410);
                    puthz(520, 360, "�������", 32, 32,0xf800);
               }
               
           }
           else
           {
                bar1(520, 360, 774, 392,0x8410);
                puthz(520, 360, "�û�������", 32, 32,0xf800);
           }*/
           if (press==1)
           {
                if (namecheck_wel(name, &usr)==1)
                {
                    if (strcmp(usr.code, code)==0)
                    {
                        //��¼�ɹ�
                        *flag=2;
                        *users=usr;
                        return 0;
                    }
                    else
                    {
                        bar1(520, 360, 774, 392,0x8410);
                        puthz(520, 360, "�������", 32, 32,0xf800);
                    }
                }
                else
                {
                    bar1(520, 360, 774, 392,0x8410);
                    puthz(520, 360, "�û�������", 32, 32,0xf800);
                }
           }
           else
            {
                bar1(520, 360, 774, 392,0x8410);
                puthz(520, 360, "��ͬ���û�Э��", 32, 32,0xf800);
            }
           
       }

       //������û��������
       else if (mouse_press(272, 250, 752, 330)==1)
       {
            mouse_off(&mouse);
            bar1(292, 270, 732, 318,0xffff);
            mouse_on(mouse);
            input_wel(name, 14,3,0x0000,0xffff,292, 270);
            if (strlen(name)==0)
            {   
                mouse_off(&mouse);
                puthz(292, 270, "�������û���", 48, 48,0x8410);
                mouse_on(mouse);
            }
            
            

       }

       //��������������
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
                    puthz(292, 420, "����������", 48, 48,0x8410);
                    mouse_on(mouse);
                }
                
            }
            else
            {   
                
                inputcode_wel(code, 14,3,0x0000,0xffff,292, 420);
                if (strlen(code)==0)
                {
                    mouse_off(&mouse);
                    puthz(292, 420, "����������", 48, 48,0x8410);
                    mouse_on(mouse);
                }
                
            }
            
       }

         //�����ע��
        else if (mouse_press(650,680,938,712)==1)
        {
            *flag=1;
            return 0;
        }

        //������û�Э��Բť
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

            // �ȴ�����ͷţ���ֹ��������
            while (mouse_press(352, 500, 372, 520)==1) 
            {
                delay(1); // ����CPUæ�ȴ�
            }
        }

        //������۾�
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

        //�������������
        else if (mouse_press(650,640,800,670)==1)
        {
           *flag=3;
            return 1;
        } 
        
        
        delay(15);
    }
    
}

//����ӭ����
void draw_wel()
{
    //����ɫ
    bar1(0, 0, 1024, 768, 0x8410);
    //�û����߿�
    FillRoundedRectangle(272, 250, 480, 80, 20, 0xffff);
    //����߿�
    FillRoundedRectangle(272, 400, 480, 80, 20, 0xffff);
    //��¼��ť
    FillRoundedRectangle(400, 550, 224, 80, 20, 0x001f);
    puthz(435, 570, "��¼", 48, 96,0xffff);
    puthz(292, 270, "�������û���", 48, 48,0x8410);
    puthz(292, 420, "����������", 48, 48,0x8410);
    puthz(650,640,"�������룿",32,32,0x001f);
    puthz(650,680,"û���˺ţ����ע��",32,32,0x001f);
    Circle(362, 510, 10, 0x0000);
    puthz(380,500,"�����Ķ���ͬ��",24,24,0xffff);
    puthz(548,500,"�û�Э��",24,24,0x001f);

    //���۾�
    DrawEye(800, 445, 16);

    //��ݵ���ͨ��
   /*  bar1(0,0,50,50,0xffff); */
}



// ����û����Ƿ����,1��ʾ���ڣ�0��ʾ������
// �������û������û��ṹ��ָ��
int namecheck_wel(char *name, user *usr)
{
    FILE *fp;
    int found = 0;

    // ���û����ݿ��ļ�
    if ((fp = fopen("data\\user.dat", "rb")) == NULL)
    {
        CloseSVGA();
        printf("file open fail: %s\n", "..\\data\\user.dat");
        exit(1);
    }

    // �����ȡ�û����ݲ�����û����Ƿ����
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








