#include "general.h"

//ע�ắ��
//����������ֵָ��
int reg(int *flag)
{
    //����ͳ�ʼ���û�������������
    char name[20]="\0";
    char code[20]="\0";
    char code_confirm[20]="\0";

    //����ͳ�ʼ���������ֵ��0��ʾͨ��
    int nc=-1;
    int cc=-1;
    int press=0;
    int eye=0;
    int eye_confirm=0;


    //��ע�����
    mouse_off(&mouse);
    delay(100);
    draw_reg();
    mouse_on(mouse);


    while (1)
    {
        
        mouse_show(&mouse);

        //���������
        if (mouse_press(520,655,750,685)==1)
        {
            *flag=0;
            return 0;
        }

        //����������û���
        else if(mouse_press(312,320,712,355)==1)
        {
            mouse_off(&mouse);
            bar1(320, 325, 712, 357,0xffff);
            mouse_on(mouse);
            input_reg(name, 12,2,0x0000,0xffff,320, 325);

            //����û���
            nc=namecheck_reg(name);

            
        }
        
        //�������������
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
            
            

            //�������
            cc=codecheck_reg(code);

        }
        
        //�����ȷ������
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

        //�����ע��
        else if (mouse_press(400, 550, 624, 630)==1)
        {
            
            //�û�����������ͨ��������д���ļ�
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


//��ע�����
void draw_reg()
{   
    //����ɫ
    bar1(0, 0, 1024, 768, 0x8410);
    //�߿�
    FillRoundedRectangle(252, 250, 520, 450, 20, 0x8400);

    //ע������ɫԲ�Ǿ���
    FillRoundedRectangle(200, 200, 624, 497, 15, 0xffff);
    puthz(340, 230, "ע���Ϊ���û�", 48, 48,0x0821);

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
    puthz(435, 570, "ע��", 48, 96,0xffff);

    //��ʾ����
    puthz(320,325,"�������û���",32,32,0x8410);
    puthz(320,385,"����������",32,32,0x8410);
    puthz(320,445,"���ٴ���������",32,32,0x8410);
    puthz(600,655,"�����˺ţ������¼",24,24,0x001f);

    //���۾�
    DrawEye(740, 395, 12);
    DrawEye(740, 455, 12);
}

//�û�����麯��
//�������û���
int namecheck_reg(char *name)
{
    //�û���Ϊ��
    if (strlen(name)==0)
    {
        puthz(320, 325, "�������û���", 32, 32,0x8410);
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"�û���Ϊ��",16,16,0xf800);
        return 1;
    }

    //�û�������
    else if (strlen(name)<3)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"�û�������",16,16,0xf800);
        return 2;
    }
    
    //�û����Ѵ���
    else if (name_repeat_check(name)==1)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"�û��Ѵ���",16,16,0xf800);
        return 3;
    }

    //�û����Ƿ�
    else if (name_legal_check(name)==1)
    {
        bar1(620, 340, 700, 357,0xffff);
        puthz(620,340,"�û����Ƿ�",16,16,0xf800);
        return 4;
    }

    //�û������ͨ��
    bar1(668, 340, 700, 357,0xffff);
    puthz(668,340,"ͨ��",16,16,0x0f00);
    return 0;
}

//�û����ظ���麯��
//�������û���
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

//�û����Ϸ���麯��,ֻ�ܰ������֡���ĸ���»���
//�������û���
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

//�����麯��������5Ϊ��ͬʱ�������ֺ���ĸ
//����������
int codecheck_reg(char *code)
{

    //����Ϊ��
    if (strlen(code)==0)
    {
        puthz(320, 385, "����������", 32, 32,0x8410);
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"����Ϊ��",16,16,0xf800);
        return 1;
    }

    //�������
    else if (strlen(code)<5)
    {
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"�������",16,16,0xf800);
        return 2;
    }

    //����Ƿ�
    else if (code_legal_check(code)==1)
    {
        //bar1(620, 490, 700, 510,0xffff);
        puthz(620,400,"����Ƿ�",16,16,0xf800);
        return 3;
    }

    //������ͨ��
    //bar1(620, 490, 700, 510,0xffff);
    puthz(668,400,"ͨ��",16,16,0x0f00);
    return 0;
}

//����Ϸ���麯�������ٰ���һ�����ֺ�һ����ĸ
//����������
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

//ע��ɹ�����
void draw_success()
{
    FillRoundedRectangle(252, 230, 520, 430, 20, 0x8400);
    FillRoundedRectangle(257, 235, 510, 420, 15, 0xffff);
    puthz(410, 450, "ע��ɹ�", 48, 48,0x0821);
    delay(500);
}
