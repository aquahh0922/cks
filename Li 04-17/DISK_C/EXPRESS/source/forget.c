#include"general.h"
// �������뺯��
int forget(int *flag)
{
    char name[20]="\0"; 
    char code[20]="\0"; // ������
    char code_confirm[20] = "\0"; // ȷ��������

    int nc=-1; // �û��������
    int cc=-1; // ��������
    int press=0;
    int eye=0; 
    int eye_confirm=0;

    // ��ʾ�����������
    mouse_off(&mouse);
    delay(100);
    draw_forget();
    mouse_on(mouse);
    
    while(1)
    {
        mouse_show(&mouse);
        
        // ���ص�¼
        if(mouse_press(670, 650, 780, 680)==1)
        {
            *flag = 0;
            return 0;
        }
        
        // �˺�
        else if(mouse_press(312,320,712,355)==1)
        {
            mouse_off(&mouse);
            bar1(320, 325, 712, 357,0xffff);
            mouse_on(mouse);
            input(name, 12,2,0x0000,0xffff,320, 325);

            // ����û���
            nc = namecheck_reg(name);
            bar1(620, 340, 700, 357,0xffff);
            switch(nc)
            {
                case 0:
                    puthz(620,340,"�û���δע��",16,16,0x001f);   
                    break;
                case 1:
                    puthz(620,340,"�û���Ϊ��",16,16,0x001f);
                    break;
                case 2:                    
                    puthz(620,340,"�û�������",16,16,0x001f);                    
                    break;       
                case 3:
                    puthz(620,340,"ͨ��",16,16,0x0f00);
                    break;
                case 4:
                    puthz(620,340,"�û����Ƿ�",16,16,0x001f);
                    break;                                                                                                                     
            }   

        }
        // �������
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

            // �������
            cc = codecheck_reg(code);
            bar1(620, 400, 700, 417,0xffff);
            
            switch(cc)
            {
                // case 0:
                //     puthz(620,400,"����δע��",16,16,0x001f);   
                //     break;
                case 1:
                    puthz(620,400,"����Ϊ��",16,16,0x001f);
                    break;
                case 2:                     
                    puthz(620,400,"�������",16,16,0x001f);                                                     
                    break;                    
                case 3:                    
                    puthz(620,400,"����Ƿ�",16,16,0x001f);                                                     
                    break;
                default:
                    if(replace_code(name,code) == 1)
                    {
                        puthz(620,400,"�����ѱ�ע��",16,16,0x001f);
                        cc = 4;
                    }
                    else
                    {
                        puthz(620,400,"ͨ��",16,16,0x0f00);
                        cc = 0;
                    }
            }                                                                                                                    
        }   
        
        //�����ȷ������
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
                puthz(560,460,"������������벻һ��",16,16,0xf800);
            }
            else
            {
                bar1(560, 460, 720, 477,0xffff);
                puthz(668,460,"ͨ��",16,16,0x0f00);
            }
            
        }

         //������û�Э��Բ��
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

            // �ȴ�����ͷţ���ֹ��������
            while (mouse_press(312, 500, 336, 524) == 1) 
            {
                delay(1); // ����CPUæ�ȴ�
            }
        }

        //�����ȷ��
        else if (mouse_press(400, 550, 624, 630)==1)
        {
            
            //�û�����������ͨ��������д���ļ�
            if ( cc==0 && nc==3 && press==1 && strcmp(code,code_confirm) == 0)
            {
                replace_code(name, code);
                puthz(668,505,"�����޸ĳɹ�",16,16,0x0f00);
                *flag = 0;
                return 0;
            }
            
            else
            {
                bar1(668, 505, 780, 536,0xffff);
                puthz(668,505,"��ͬ���û�Э��",16,16,0xf800);
            }
            
        }

        //�û�����۾�1 -- ����
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
            // �ȴ�����ͷţ���ֹ��������
            while (mouse_press(728,388,752,412)==1)
            {
                delay(1);
            }
        }
        
        //�û�����۾�2 -- ȷ������
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
            // �ȴ�����ͷţ���ֹ��������
            while (mouse_press(728,448,752,472)==1)
            {
                delay(1);
            }
        }
        delay(15);     
    }
    
}

//�������������
void draw_forget()
{   
    //����ɫ
    bar1(0, 0, 1024, 768, 0x8410);
    //�߿�
    FillRoundedRectangle(252, 250, 520, 450, 20, 0x8400);

    //ע������ɫԲ�Ǿ���
    FillRoundedRectangle(200, 200, 624, 497, 15, 0xffff);

    //�û��������������
    Line3(312, 360, 712, 400,2, 0x8400);
    Line3(312, 420, 712, 480,2, 0x8400);
    Line3(312, 480, 712, 540,2, 0x8400);

    //�û�Э��UI
    Circle(324, 518, 12, 0x0000);
    puthz(342, 505, "�����Ķ���ͬ��",24,24, 0x8400);
    puthz(520, 505, "�û�Э��",24,24, 0x001f);

    //ע�ᰴť
    FillRoundedRectangle(400, 550, 224, 80, 20, 0x001f);
    puthz(435, 570, "ȷ��", 48, 96,0xffff);

    //��ʾ����
    puthz(410,230, "��������", 48, 48,0x0821);
    puthz(320,325,"�˺�",32,32,0x8410);
    puthz(320,385,"������������",32,32,0x8410);
    puthz(320,445,"ȷ��������",32,32,0x8410);
    puthz(680,655,"���ص�¼",24,24,0x001f);

    //���۾�
    DrawEye(740, 395, 12);
    DrawEye(740, 455, 12);
}

//���ܣ��û�����ͬʱ�滻����
//������nameΪ�û�����new_codeΪ������
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

    // �����ļ������û�
    while (fread(&current_user, sizeof(user), 1, fp) == 1) 
    {
        if (strcmp(current_user.name, name) == 0) 
        {
            // ����¾������Ƿ���ͬ
            if (strcmp(current_user.code, new_code) == 0)
            {
                fclose(fp);
                return 1; // ������ͬ����1
            }
            
            // ��¼�ҵ���λ��
            offset = ftell(fp) - sizeof(user);
            found = 1;
            break;
        }
    }

    if (found) 
    {
        // ��λ���û���¼��ʼλ��
        fseek(fp, offset, SEEK_SET);
        
        // ��������
        strcpy(current_user.code, new_code);
        
        // д����º������
        if (fwrite(&current_user, sizeof(user), 1, fp) != 1) 
        {
            CloseSVGA();
            printf("code update fail in replace_code\n");
            fclose(fp);
            exit(1);
        }
        fclose(fp);
        return 0; // �޸ĳɹ�����0
    }

    fclose(fp);
    CloseSVGA();
    printf("user not found in replace_code: %s\n", name);
    exit(1);
    return -1; // �û���δ�ҵ�����-1
}


