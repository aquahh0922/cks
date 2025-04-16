#include "general.h"
#include <ctype.h>
int food(int *flag, user* users)
{
    int food_store_count = 0;
    Store food_stores[MAX_FOOD_STORES];
    Store* current_store = NULL;
    int current_screen = 0; // 0�������� 1����Էʳ�� 2����ѩ���� 3�������� 4������ѡ����� 5:ȷ���˳����� 6:���ﳵ���� 7:֧��ҳ�� 8:ѡ���ַҳ��
    int selected_store = -1; // ��ǰ����ĵ���������0,  1, 2��
    int selected_product = -1; // ��ǰѡ�����Ʒ����(0, 1, 2)
    int j ; // ����
    int quantity;
    int confirm_exit = 0; // ȷ���˳�״̬
    unsigned short delivery_address; // ѡ��ĵ�ַ
    ShoppingCart cart; 
    CartNode* curr = NULL;

    cart_init(&cart); 
    memset(food_stores, 0, sizeof(Store) * MAX_FOOD_STORES); 
    //��ʼ��������
    mouse_off(&mouse);
    delay(1000);
    food_store_count = find_food_stores(food_stores, MAX_FOOD_STORES);
    draw_food(food_stores , food_store_count);
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);
        delay(15);
        
        // --------------�������߼���current_screen == 0 )------------  //
        if(current_screen == 0)
        {   // �������˵�
            if(mouse_press(895, 725, 1024, 768) == 1) 
            {
                *flag = 2;
                return 0;
            }
            // ������Էʳ��
            if(mouse_press(375, 160, 585, 265) == 1)
            {
                show_menu(&food_stores[0],&cart);
                current_screen = 1;
                selected_store = 0;
            }
            // ������ѩ����
            if(mouse_press(375, 360, 585, 465) == 1) 
            {
                show_menu(&food_stores[1],&cart);
                current_screen = 2; 
                selected_store = 1;
            }
            // ���뺺����
            if(mouse_press(375, 560, 585, 665) == 1) 
            {
                show_menu(&food_stores[2],&cart);
                current_screen = 3;
                selected_store = 2;
            }
        }
        // --------------���̽����߼���current_screen == 1, 2, 3��-------------- //
        else if (current_screen >=1 && current_screen <=3)
        {
            //���������水ť
            if(mouse_press(900 , 730 , 1024, 768) == 1) 
            {
                confirm_exit = 1;
                current_screen = 5;
            }
            //���빺�ﳵҳ��
            if(mouse_press(800, 730, 875, 755) == 1) 
            {
                current_screen = 6; 
            }

            current_store = &food_stores[selected_store];
            for( j = 0 ; j < current_store->com_count ; j++)
            {
                if(mouse_press(760, 270 + j*75, 910, 310 + j*75) == 1) // ѡ����Ʒ
                {
                    selected_product = j;
                    current_screen = 4; // ��������ѡ�����
                    break;
                }
            }
        }

        // --------------����ѡ������߼���current_screen == 4��-------------- //
        else if (current_screen == 4)
        {
            quantity = choose_number(&current_store->products[selected_product]);
            if (quantity > 0)
            {
                // ��ֱ���޸Ŀ�棬������Ʒ��ӵ����ﳵ
                cart_add(&cart, &current_store->products[selected_product], quantity);
            }

            // ����ԭ���̽��沢�ػ�
            current_screen = selected_store + 1; // 1: ��Էʳ��, 2: ��ѩ����, 3: ������
            switch (selected_store) 
            {
                case 0: show_menu(&food_stores[0], &cart); break;
                case 1: show_menu(&food_stores[1], &cart); break;
                case 2: show_menu(&food_stores[2], &cart); break;
            }

            selected_product = -1; // ������Ʒ����
        }
        // ----------------�˳�ȷ�Ͻ���(current_screen == 5)-----------------//
        else if (current_screen == 5)
        {
            static int exit_screen_drawn = 0; // ��־λ��ȷ��ֻ����һ��
            if (!exit_screen_drawn) {
                draw_exit_confirm();
                exit_screen_drawn = 1; // ���ñ�־λΪ�ѻ���
            }
            //ȷ���˳�
            if(mouse_press(386, 427, 500, 480) == 1) 
            {
                cart_clear(&cart); 
                current_screen = 0;
                confirm_exit = 0;
                exit_screen_drawn = 0; // ���ñ�־λ
                mouse_off(&mouse);
                delay(1000);
                draw_food(food_stores, food_store_count);
                mouse_on(mouse);
                continue;
            }
            // ȡ���˳�
            else if(mouse_press(527, 432, 640, 479) == 1) 
            {
                confirm_exit = 0;
                current_screen = selected_store + 1; 
                exit_screen_drawn = 0; // ���ñ�־λ
                show_menu(&food_stores[selected_store],&cart);
                continue;
            }
        }
        // ----------------���ﳵ����(current_screen == 6)-----------------//
        else if (current_screen == 6)
        {
            static int checkout_drawn = 0;
            if (!checkout_drawn) 
            {
                draw_checkout(&cart);
                checkout_drawn = 1;
            }
            
            //ȷ��֧��
            if (mouse_press(345, 650, 450, 700) == 1) 
            {
                current_screen = 7; // ����֧��ҳ��
                checkout_drawn = 0; // ���û��Ʊ�־

            }

            // ��չ��ﳵ
            if(mouse_press(455, 650, 605, 700) == 1)
            {
                cart_clear(&cart); // ��չ��ﳵ
                current_screen = selected_store + 1; // ���ص�ǰ����ҳ��
                checkout_drawn = 0; // ���û��Ʊ�־
                show_menu(&food_stores[selected_store], &cart); // �ػ����ҳ��
            }
        
            // ����ԭ����
            if (mouse_press(617, 652, 725, 700) == 1)
            {
                current_screen = selected_store + 1; 
                checkout_drawn = 0;
                show_menu(&food_stores[selected_store], &cart);
            }
        }
        //----------------------֧��ҳ���߼�(current_screen == 7)-----------------//
        else if(current_screen == 7)
        {
            static int payment_drawn = 0;
            if (!payment_drawn) 
            {
                // ��֧��ҳ��
                draw_payment(&cart, users);
                payment_drawn = 1; 
            }
            
            // ȷ��֧��
            if (mouse_press(383, 647, 518, 693) == 1)
            {
                if(check_balance(users->balance, cart.total_price))
                {
                    if(update_user_balance(users, cart.total_price) == 0)
                    {
                        if(update_inventory(&cart) == 0)
                        {
                            show_payment_result(1);
                            cart_clear(&cart); // ��չ��ﳵ
                            current_screen = 0; 
                            draw_food(food_stores, food_store_count); 
                            payment_drawn = 0; // ���ñ�־λ
                        }
                    }
                }
            }

            // ��ʾ����
            if(mouse_press(558, 650, 685, 690) == 1)
            {
                show_payment_result(0);
                current_screen = 6; // ���ع��ﳵ����
                payment_drawn = 0; // ���ñ�־λ
            }

            // ����ѡ���ַҳ��
            if(mouse_press(392, 517, 621, 558) == 1)
            {
                current_screen = 8; // ����ѡ���ַҳ��
                payment_drawn = 0; // ���ñ�־λ
            }

            // ���ض���
            if (mouse_press(620, 650, 740, 700) == 1) 
            {
                current_screen = 6; // ���ع��ﳵ�嵥����
                payment_drawn = 0;  // ���ñ�־λ
            }
        }
        // --------------------------ѡ���ַ����(current_screen == 8)-------------------------//
        else if(current_screen == 8)
        {
            static int address_drawn = 0; // ��־λ��ȷ��ֻ����һ��
            if (!address_drawn) 
            {
                delivery_address = draw_address(); // ��ѡ���ַҳ��
                address_drawn = 1; // ���ñ�־λΪ�ѻ���
            }

            if(delivery_address != 0)
            {
                current_screen = 7;
                address_drawn = 0;
            }
            // ����֧��ҳ��(����˷��ذ�ť)
            else
            {
                current_screen = 7;
                address_drawn = 0;  
            }
        }
    }
}

/* �������̽��� (current_screen = 0) */
void draw_food(Store* food_stores , int food_stores_count)

{
    int i, j;
    int x, y;
    int base_x , base_y;
    Store* store = NULL;
    // ������
    bar1(0, 0, 1024, 768, 0x8410);
    Cirbar(140,60,860,110,0xffff);
    
    FillRoundedRectangle(100,150,824,160,20,0xf7bb);
    FillRoundedRectangle(100,350,824,160,20,0xf7bb);
    FillRoundedRectangle(100,550,824,180,20,0xf7bb);
    bar1(150, 160, 360, 280 , 0xffff);
    bar1(150, 360, 360, 480 , 0xffff);
    bar1(150, 560, 360, 680 , 0xffff);

    bar1(80, 180, 130, 275, 0x99f);
    bar1(80, 380, 130, 475, 0x99f);
    bar1(80, 580, 130, 675, 0x99f);
    bar1(900, 160, 950, 280 , 0x99f);
    bar1(900, 360, 950, 480 , 0x99f);
    bar1(900, 560, 950, 680 , 0x99f);

    FillRoundedRectangle(375, 160, 210, 103, 30,  0xffff);
    FillRoundedRectangle(375, 360, 210, 103, 30,  0xffff);
    FillRoundedRectangle(375, 560, 210, 103, 30,  0xffff);

    puthz(430 , 70 , "��" , 32 , 32 , 0x0000);
    puthz(560 , 70 , "��" , 32 , 32 , 0x0000);
    puthz(160 , 275 , "�Ͼƴ�ʳ�ã��е���ʹ���" , 24 , 24 , 0x0000);
    puthz(160 , 475 , "ѩ����������һ�ģ�" , 24 , 24 , 0x0000);
    puthz(160 , 685 , "��������棬ҧ���������ƣ�" , 24 , 24 , 0x0000);
    puthz(900 , 730 , "������ҳ��" , 24 , 24 , 0x001f);

    for(i = 0  ; i < food_stores_count ; i++)
    {
        store = &food_stores[i];
        base_y = 160 + i * 200;
        puthz(160 , base_y , store->name , 32 , 32 , 0x001f);
        
        puthz(160 , base_y + 40 , "��ַ��" , 16 , 16 , 0x0000);
        prt_hz16_asc16_size(160 + 2*25 , base_y + 40 , 1.5 , 1.5 , store->address , 0x0000 , "HZK\\HZK16K");

        puthz(160 , base_y + 65 , "���֣�" , 16 , 16 , 0x0000);
        put_asc16_number_size(160 + 2*25 , base_y + 65 , 1.5 , 1.5 , store->score , 0x0000);
        puthz(160 , base_y + 90 , "�˾����ѣ�" , 16 , 16 , 0x0000);
        RMB(160 + 4*16 + 10, base_y + 90 , 1.5 , 1.5 ,0x0000);
        put_asc16_number_size(160 + 4*16 + 25 , base_y + 90 , 1.5 , 1.5 , store->AveragePrice , 0x0000);
        puthz(430 , 210 + i*200 , "�������" , 24 , 24 , 0x001f);
    }
}
/*
���ܣ���ȡmerchant.dat�ļ����̼���Ŀ
input��Mer* �� int max_merchants
output���̼���Ŀ
*/
int read_merchants(Mer *merchants, int max_merchants) {
    int count;
    FILE *fp;

    if ((fp = fopen("data\\merchant.dat", "rb")) == NULL)
    {
        CloseSVGA();
        printf("file open fail in read_merchants: %s\n", "..\\data\\merchant.dat"); 
        exit(1);
    }

    for(count = 0 ; count < max_merchants ; count++)
    {
        memset(&merchants[count], 0, sizeof(Mer)); // ����̼ҽṹ��
        fread(&merchants[count], sizeof(Mer), 1, fp); // ��ȡ�̼�����
        if (feof(fp)) break; // ��������ļ�ĩβ���˳�ѭ��
    }   
    fclose(fp);
    return count;
}

/*
���ܣ���ô���ȡ������ΪFOOD��������Ŀ
input��Mer* �� int max_merchants
output���ɹ�����������Ŀ��ʧ�ܷ���-1
*/
int find_food_stores(Store *food_stores, int max_stores) {
    // ��ȡ�����̼�����
    Mer merchants[MAX_MERCHANTS];
    Mer* mer = NULL;
    Store* store = NULL;
    int merchant_count = 0;
    int food_store_count = 0;
    int m, s;

    merchant_count = read_merchants(merchants, MAX_MERCHANTS);
    if (merchant_count <= 0) return -1;


    //���������̼�
    for (m = 0; m < merchant_count; m++) 
    {
        mer = &merchants[m];
        
        // �����̼ҵ����е���
        for (s = 0; s < mer->store_count; s++) 
        {
            store = &mer->stores[s];
            if (store->type == CATEGORY_FOOD)
            {
                food_stores[food_store_count] = *store;
                food_store_count++;
            }
        }
    }
    return food_store_count;
}


/*
���ܣ���ʾ����ҳ��
input��Store
output��void
*/
void show_menu(const Store* store , ShoppingCart* cart)
{
    int i;
    char buffer[100];
    mouse_off(&mouse);
    delay(150);
    bar1(0, 0, 1024, 768, 0x8410);
    FillRoundedRectangle(62, 50, 900, 668 ,30, 0xffff);
    Line1(80, 160, 940, 160, 0xcd91);
    Line1(80, 200, 940, 200, 0xcd91);
    Line1(80, 250, 940, 250, 0xcd91);
    puthz(800, 730, "���ﳵ", 24, 24, 0x001f);
    puthz(900, 730, "�������˵�", 24, 24, 0x001f);

    //������
    puthz(100, 75, store->name, 24, 24, 0x0000);
    prt_hz16_asc16_size(120 , 170 , 1.5 , 1.5 , store->address , 0x0000 , "HZK\\HZK16K");
    put_asc16_number_size(120 , 135 , 1.5 , 1.5 , store->score , 0x0000);
    
    //����Ʒ
    for( i = 0; i < store->com_count ; i++)
    {
        FillRoundedRectangle(80 , 260 + i*75 , 860 , 60 , 30 , 0xf7bb);
        puthz(100, 270 + i*75, store->products[i].name, 24, 24, 0x0000);
        bar1(760, 270 + i*75, 910, 310 + i*75 , 0x001f);
        puthz(770, 275 + i*75, "����", 24, 24, 0xffff);
    }
    mouse_on(mouse);
}

/*
���ܣ�ѡ������Ʒ����ҳ��
input��COM�ṹ��ָ��
output��ѡ����Ʒ����Ŀ
*/
int choose_number(const COM* product)
{
    int quantity = 1;
    // �Ի�������ͳߴ�
    int x = 312, y = 284;       
    int width = 400, height = 200;
    // ��ť������
    int btn_minus_x1 = x + 150, btn_minus_y1 = y + 100;
    int btn_minus_x2 = btn_minus_x1 + 50, btn_minus_y2 = btn_minus_y1 + 50;
    int btn_plus_x1 = x + 250, btn_plus_y1 = y + 100;
    int btn_plus_x2 = btn_plus_x1 + 50, btn_plus_y2 = btn_plus_y1 + 50;
    int btn_confirm_x1 = x + 100, btn_confirm_y1 = y + 150;
    int btn_confirm_x2 = btn_confirm_x1 + 100, btn_confirm_y2 = btn_confirm_y1 + 40;
    int btn_cancel_x1 = x + 250, btn_cancel_y1 = y + 150;
    int btn_cancel_x2 = btn_cancel_x1 + 100, btn_cancel_y2 = btn_cancel_y1 + 40;

    // ��������Ϊ0ʱ������ʾ
    if(product->stock <= 0) 
    {
        tip_empty(product->name);
        return 0; 
    }

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    // ����Ϳ����Ϣ
    puthz(x + 150, y + 30, "ѡ��������", 24, 24, 0x0000);
    puthz(x + 50, y + 70, "���", 16, 16, 0x0000);
    put_asc16_number_size(x + 100, y + 70, 1.5, 1.5, product->stock, 0x0000);
    // ����������ť
    Circlefill(btn_minus_x1 + 25, btn_minus_y1 + 25, 20, 0xf800); // ���ٰ�ť
    Circlefill(btn_plus_x1 + 30, btn_plus_y1 + 25, 20, 0xf800); // ���Ӱ�ť

    // ������ʾ����
    FillRoundedRectangle(x + 200, y + 100, 60, 40, 10, 0xffff);
    put_asc16_number_size(x + 215, y + 110, 2.0, 2.0, quantity, 0x0000);
    // ȷ�Ϻ�ȡ����ť
    FillRoundedRectangle(btn_confirm_x1, btn_confirm_y1, 100, 40, 10, 0x99f);
    puthz(btn_confirm_x1 + 20, btn_confirm_y1 + 10, "ȷ��", 24, 24, 0xffff);
    FillRoundedRectangle(btn_cancel_x1, btn_cancel_y1, 100, 40, 10, 0x99f);
    puthz(btn_cancel_x1 + 20, btn_cancel_y1 + 10, "ȡ��", 24, 24, 0xffff);

    mouse_on(mouse);

    while (1) 
    {
        mouse_show(&mouse);
        // �������ť
        if (mouse_press(btn_minus_x1, btn_minus_y1, btn_minus_x2, btn_minus_y2) == 1) {
            
            if (quantity == 1) 
            {
                continue;
            }
            else
                quantity--;
            
            FillRoundedRectangle(x + 200, y + 100, 60, 40, 10, 0xffff);
            put_asc16_number_size(x + 215, y + 110, 2.0, 2.0, quantity, 0x0000);

            delay(200); 
        }
        // ����Ӱ�ť
        if (mouse_press(btn_plus_x1, btn_plus_y1, btn_plus_x2, btn_plus_y2) == 1)
        {
            if(quantity >= product->stock) 
            {
                continue;
            }
            else
                quantity++;
            
            FillRoundedRectangle(x + 200, y + 100, 60, 40, 10, 0xffff);
            put_asc16_number_size(x + 215, y + 110, 2.0, 2.0, quantity, 0x0000);
            
            delay(200);
        }
        
        // ȷ�Ϲ���
        if (mouse_press(btn_confirm_x1, btn_confirm_y1, btn_confirm_x2, btn_confirm_y2) == 1)
        {
            mouse_off(&mouse);
            return quantity;
        }
        
        // ȡ������
        if (mouse_press(btn_cancel_x1, btn_cancel_y1, btn_cancel_x2, btn_cancel_y2) == 1)
        {
            mouse_off(&mouse);
            return 0;
        }
        delay(15);
    }
}

/* ��Ʒ���Ϊ0ʱ������ҳ��*/
void tip_empty(const char* name)
{
    int x = 312, y = 284;       // �Ի�������
    int width = 400, height = 200; // �Ի���ߴ�

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    puthz(x + 50, y + 70, "��ѡ�����Ʒ��", 24, 24, 0x0000);
    puthz(x + 200, y + 70, name , 24 , 24 , 0x001f);
    puthz(x + 50, y + 100, "��治��", 24, 24, 0x0000);
    puthz(x + 50, y + 130, "���������Ĳ��㣬", 24, 24, 0x0000);
    puthz(x + 235, y + 130, "�����½�", 24, 24, 0x0000);

    delay(1000); // ��ʾ2����
}

/*
���ܣ����Ƿ�ȷ���˳��Ľ���(current_screen == 5)
*/
void draw_exit_confirm(void)
{
    int x = 312, y = 234;       // �Ի�������
    int width = 400, height = 300; // �Ի���ߴ�

    mouse_off(&mouse);
    delay(100);

    // ���ƾ��η��򱳾�
    bar1(x, y, x + width, y + height, 0xffff);
    Line1(x, y, x + width, y, 0x0000); // �ϱ߿�
    Line1(x, y, x, y + height, 0x0000); // ��߿�
    Line1(x + width, y, x + width, y + height, 0x0000); // �ұ߿�
    Line1(x, y + height, x + width, y + height, 0x0000); // �±߿�

    // ��ʾ��ʾ����
    puthz(400, 350, "�Ƿ�ȷ���˳���", 32, 32, 0x001f);

    // ����ȷ�ϰ�ť
    FillRoundedRectangle(x + 80, y + 200, 100, 40, 10, 0x99f);
    puthz(x + 100, y + 210, "ȷ��", 24, 24, 0xffff);

    // ����ȡ����ť
    FillRoundedRectangle(x + 220, y + 200, 100, 40, 10, 0x99f);
    puthz(x + 240, y + 210, "ȡ��", 24, 24, 0xffff);

    mouse_on(mouse);
    delay(1000); // ��ʾ1����
}

/*
���ܣ�������ҳ��(current_screen == 6)
input��ShoppingCart* cart
*/
void draw_checkout(ShoppingCart* cart)
{
    int x = 310, y = 260;          // �Ի�������
    int width = 420, height = 440; // �Ի���ߴ�
    int item_x = x + 20, item_y = y + 100; // ��Ʒ�б���ʼ����
    int line_height = 40;          // ÿ�и߶�
    int i = 0;
    CartNode* curr = cart->head;

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    Line1(x + 140, 325, x + 140, 600, 0xcd91);
    Line1(x + 210, 325, x + 210, 600, 0xcd91);
    Line1(x + 280, 325, x + 280, 600, 0xcd91);
    puthz(x + 140, y + 10, "����ҳ��", 32, 32, 0x001f);

    // ��ʾ���ﳵ��Ʒ�б�
    puthz(item_x + 20, item_y - 30, "��Ʒ", 24, 24, 0x0000); 
    puthz(item_x + 125, item_y - 30, "����", 24, 24, 0x0000); 
    puthz(item_x + 195, item_y - 30, "����", 24, 24, 0x0000); 
    puthz(item_x + 310, item_y - 30, "�ܼ�", 24, 24, 0x0000); 

    while (curr != NULL && i < 4) // �����ʾ4����Ʒ
    {
        puthz(item_x, item_y + i * line_height, curr->item->name, 24, 24, 0x0000);
        put_asc16_number_size(item_x + 150, item_y + i * line_height, 1.5, 1.5, curr->quantity, 0x0000);
        RMB(item_x + 195, item_y + i * line_height, 1.5, 1.5, 0x0000);
        put_asc16_number_size(item_x + 210, item_y + i * line_height, 1.5, 1.5, curr->item->price, 0x0000);
        RMB(item_x + 295, item_y + i * line_height, 1.5, 1.5, 0x0000);
        put_asc16_number_size(item_x + 310, item_y + i * line_height, 1.5, 1.5, curr->quantity * curr->item->price, 0x0000);
        curr = curr->next;
        i++;
    }

    RMB(x + 330, y + height - 80, 1.5, 1.5, 0x0000);
    put_asc16_number_size(x + 355, y + height - 80, 1.5, 1.5, cart->total_price, 0x001f);

    // ����ȷ�ϰ�ť
    FillRoundedRectangle(x + 40, y + height - 50, 100, 40, 10, 0x99f);
    puthz(x + 60, y + height - 40, "ȷ��", 24, 24, 0xffff);

    // ������չ��ﳵ��ť
    FillRoundedRectangle(x + 150, y + height - 50, 140, 40, 10, 0x99f);
    puthz(x + 160, y + height - 40, "��չ��ﳵ", 24, 24, 0xffff);

    // ���Ʒ��ذ�ť
    FillRoundedRectangle(x + 310, y + height - 50, 100, 40, 10, 0x99f);
    puthz(x + 330, y + height - 40, "����", 24, 24, 0xffff);

    mouse_on(mouse);
}

/*
���ܣ������û����
input���û��ṹ�壬���
output��0��ʾ�ɹ���-1��ʾʧ��
*/
int update_user_balance(user* u, float amount)
{
    FILE *fp;
    user tmp;
    long pos = 0;
    int found = 0;

    if(!u || amount <= 0) return -1;

    if ((fp = fopen("DATA\\user.dat","rb+")) == NULL)
    {
        CloseSVGA();
        printf("File open failed in update_user_balance: %s\n", "DATA\\users.dat");
        exit(1);
    } 

    while (fread(&tmp, sizeof(user), 1, fp) == 1)
    {
        if (strcmp(tmp.name, u->name) == 0) 
        {
            found = 1;
            if(tmp.balance < amount)
            {
                fclose(fp);
                return -1;
            }
            else
            {
                tmp.balance -= amount;  
            }
            
            fseek(fp, pos, SEEK_SET);
            
            if (fwrite(&tmp, sizeof(user), 1, fp) != 1) 
            {
                fclose(fp);
                return -1;
            }
            
            // ���´���Ľṹ��
            *u = tmp;
            break;
        }
        pos = ftell(fp);
    }

    fclose(fp);
    return found ? 0 : -1;
}

/*
���ܣ����¿��
input�����ﳵ����
output��0��ʾ�ɹ���-1��Ч������-2�ļ�����ʧ�ܣ�-3��治�㣬-4��Ʒ������
*/
int update_inventory(ShoppingCart *cart) 
{
    FILE *fp;
    Mer merchants[MAX_MERCHANTS];
    int merchant_count, need_update = 0;
    int found = 0;
    int m, s, p;
    CartNode *current = cart->head;

    // ����У��
    if (!cart || !cart->head) return -1;

    // 1. ȫ����ȡ����
    if ((fp = fopen("DATA\\merchant.dat", "rb")) == NULL) return -2;
    merchant_count = read_merchants(merchants, MAX_MERCHANTS);
    
    if (merchant_count <= 0)
    {
        fclose(fp);
        return -1; 
    }

    fclose(fp);

    // 2. У���棨�ڴ������
    current = cart->head;
    while (current) 
    {
        for (m = 0; m < merchant_count; m++) {
            for (s = 0; s < merchants[m].store_count; s++) 
            {
                if (merchants[m].stores[s].id != current->item->store_id) 
                continue;
                
                for (p = 0; p < merchants[m].stores[s].com_count; p++) 
                {
                    if (strcmp(merchants[m].stores[s].products[p].name, 
                              current->item->name) == 0) 
                    {
                        if (merchants[m].stores[s].products[p].stock < current->quantity) 
                        {
                            return -3; // ��治��
                        }
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        if (!found) return -4; // ��Ʒ������
        current = current->next;
    }

    // 3. �����ۼ����
    current = cart->head;
    while (current) 
    {
        for (m = 0; m < merchant_count; m++) 
        {
            for (s = 0; s < merchants[m].store_count; s++) 
            {
                if (merchants[m].stores[s].id != current->item->store_id) continue;
                
                for (p = 0; p < merchants[m].stores[s].com_count; p++) 
                {
                    if (strcmp(merchants[m].stores[s].products[p].name, 
                              current->item->name) == 0) 
                    {
                        merchants[m].stores[s].products[p].stock -= current->quantity;
                        need_update = 1;
                        break;
                    }
                }
                break;
            }
        }
        current = current->next;
    }

    // 4. ȫ��д��
    if (need_update) {
        if ((fp = fopen("DATA\\merchant.dat", "wb")) == NULL) return -2;
        fwrite(merchants, sizeof(Mer), merchant_count, fp);
        fclose(fp);
    }
    return 0;
}

/*���ܣ���֧��ҳ�� (current_screen == 7)*/
void draw_payment(ShoppingCart* cart, user* u)
{
    int x = 310, y = 260;       // �Ի�������
    int width = 420, height = 440; // �Ի���ߴ�
    int total_quantity = 0;
    CartNode* curr = cart->head;

    while (curr != NULL) 
    {
        total_quantity += curr->quantity;
        curr = curr->next;
    }

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    bar1(800, 730, 875, 760, 0x8410);
    bar1(350, 345, 700, 625, 0xf7bb);
    Line1(370, 445, 660, 445, 0xcd91);
    Line1(370, 490, 660, 490, 0xcd91);
    Line1(370, 550, 660, 550, 0xcd91);
    puthz(x + 160, y + 20, "֧��ҳ��", 32, 32, 0x0000);
    RMB(600, 415, 1.5, 1.5, 0x0000);
    put_asc16_number_size(620, 410, 2.0, 2.0, cart->total_price , 0x001f);
    RMB(600 , 460 ,1.5 ,1.5 ,0x0000);
    put_asc16_number_size(620 , 450 ,2.0 ,2.0 ,u->balance ,0x001f);
    puthz(370, 415, "��Ʒ�ܶ�", 24, 24, 0x0000);
    puthz(465, 425, "����", 16, 16, 0x8410);
    put_asc16_number_size(500, 430, 1.0, 1.0, total_quantity, 0x001f);
    puthz(520, 425, "����", 16, 16, 0x8410);
    
    puthz(370, 460, "�˻���", 24, 24, 0x0000);
    puthz(400, 525, "��ѡ�������ջ���ַ", 24, 24, 0x8410);
    // ȷ��֧����ť
    FillRoundedRectangle(x + 80, y + height - 50, 120, 40, 10, 0x99f);
    puthz(x + 95, y + height - 40, "ȷ��֧��", 24, 24, 0xffff);

    // ���ذ�ť
    FillRoundedRectangle(x + width -170 , y + height -50 ,120 ,40 ,10 ,0x99f);
    puthz(x + width -155 , y + height -40 ,"���ض���" ,24 ,24 ,0xffff);


    mouse_on(mouse);
}

// ���ܣ�֧�����ҳ��
void show_payment_result(int result)
{
    int x = 360, y = 390;       // �Ի�������
    int width = 310, height = 160; // �Ի���ߴ�

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    bar1(x, y, x + width, y + height, 0xffff);
    bar1(x, y, x + width, y + 65, 0x001f);

    if(result)
    {
        puthz(x + 90, y + 100, "֧���ɹ���", 24, 24, 0x07e0);
        delay(1500);
    }
    else
    {
        puthz(x + 90, y + 100, "���㣡", 24, 24, 0xf800);
        delay(1500);
    }
    mouse_on(mouse);
}

/*
���ܣ��Ƚ��û�������Ʒ�ܼ�
input���û�����Ʒ�ܼ�
output��1��ʾ����㹻��0��ʾ����
*/
int check_balance(float balance, float total_price)
{
    if(balance < total_price) return 0; 
    return 1; 
}


/*
���ܣ�ѡ���ջ���ַҳ��(current_screen == 8)
input��void
output��101-107�����̵�ַ 
        0������֧��ҳ��
*/
unsigned short draw_address(void)
{
    int x = 310, y = 260;       // �Ի�������
    int width = 420, height = 440; // �Ի���ߴ�
    int i;

    mouse_off(&mouse);
    delay(100);

    // ���ƶԻ��򱳾�
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    bar1(325, 278, 720, 345, 0x001f);

    Line1(x + 50, y + 130, x + 370, y + 130, 0xcd91); 
    Line1(x + 50, y + 180, x + 370, y + 180, 0xcd91); 
    Line1(x + 50, y + 230, x + 370, y + 230, 0xcd91); 
    Line1(x + 50, y + 280, x + 370, y + 280, 0xcd91); 
    Line1(x + 50, y + 330, x + 370, y + 330, 0xcd91); 
    Line1(x + 50, y + 380, x + 370, y + 380, 0xcd91); 
    Line1(x + 50, y + 430, x + 370, y + 430, 0xcd91);

    puthz(435, 300, "ѡ���ջ���ַ", 32, 32, 0xffff);
    puthz(610, 675, "����֧��ҳ��", 16, 16, 0x001f);
    prt_hz16_asc16_size(450, 365, 1.5, 1.5, "��Է25��ѧ������", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 415, 1.5, 1.5, "���Ž�ѧ¥", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 465, 1.5, 1.5, "��ʮ����ѧ¥", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 515, 1.5, 1.5, "��Է26��ѧ������", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 565, 1.5, 1.5, "��Է19��ѧ������", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 615, 1.5, 1.5, "��Է5��ѧ������", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 665, 1.5, 1.5, "��Է10��ѧ������", 0x8410, "HZK\\HZK16K");

    mouse_on(mouse);
    while (1)
    {
        mouse_show(&mouse);
        // �����ͬ��ַ���ض�Ӧֵ
        if (mouse_press(445, 365, 580, 380) == 1) 
        {
            bar1(445, 365, 580, 380, 0xffe0);
            return 101; 
        }
        
        if (mouse_press(445, 415, 580, 430) == 1) 
        {
            bar1(445, 415, 580, 430, 0xffe0);
            return 102; 
        }

        if (mouse_press(445, 465, 580, 480) == 1) 
        {
            bar1(445, 465, 580, 480, 0xffe0);
            return 103; 
        }

        if (mouse_press(445, 515, 580, 530) == 1) 
        {
            bar1(445, 515, 580, 530, 0xffe0);
            return 104; 
        }

        if (mouse_press(445, 565, 580, 580) == 1) 
        {
            bar1(445, 565, 580, 580, 0xffe0);
            return 105; 
        }

        if (mouse_press(445, 615, 580, 630) == 1) 
        {
            bar1(445, 615, 580, 630, 0xffe0);
            return 106; 
        }

        if (mouse_press(445, 665, 580, 680) == 1) 
        {
            bar1(445, 665, 580, 680, 0xffe0);
            return 107; 
        }
        // ����֧��ҳ��
        if (mouse_press(606, 672, 710, 700) == 1) return 0;
    }
}