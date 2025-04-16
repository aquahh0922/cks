#include "general.h"
#include <ctype.h>
int food(int *flag, user* users)
{
    int food_store_count = 0;
    Store food_stores[MAX_FOOD_STORES];
    Store* current_store = NULL;
    int current_screen = 0; // 0：主界面 1：韵苑食堂 2：蜜雪冰城 3：汉堡王 4：数量选择界面 5:确认退出界面 6:购物车界面 7:支付页面 8:选择地址页面
    int selected_store = -1; // 当前进入的店铺索引（0,  1, 2）
    int selected_product = -1; // 当前选择的商品索引(0, 1, 2)
    int j ; // 遍历
    int quantity;
    int confirm_exit = 0; // 确认退出状态
    unsigned short delivery_address; // 选择的地址
    ShoppingCart cart; 
    CartNode* curr = NULL;

    cart_init(&cart); 
    memset(food_stores, 0, sizeof(Store) * MAX_FOOD_STORES); 
    //初始化主界面
    mouse_off(&mouse);
    delay(1000);
    food_store_count = find_food_stores(food_stores, MAX_FOOD_STORES);
    draw_food(food_stores , food_store_count);
    mouse_on(mouse);

    while (1)
    {
        mouse_show(&mouse);
        delay(15);
        
        // --------------主界面逻辑（current_screen == 0 )------------  //
        if(current_screen == 0)
        {   // 返回主菜单
            if(mouse_press(895, 725, 1024, 768) == 1) 
            {
                *flag = 2;
                return 0;
            }
            // 进入韵苑食堂
            if(mouse_press(375, 160, 585, 265) == 1)
            {
                show_menu(&food_stores[0],&cart);
                current_screen = 1;
                selected_store = 0;
            }
            // 进入蜜雪冰城
            if(mouse_press(375, 360, 585, 465) == 1) 
            {
                show_menu(&food_stores[1],&cart);
                current_screen = 2; 
                selected_store = 1;
            }
            // 进入汉堡王
            if(mouse_press(375, 560, 585, 665) == 1) 
            {
                show_menu(&food_stores[2],&cart);
                current_screen = 3;
                selected_store = 2;
            }
        }
        // --------------店铺界面逻辑（current_screen == 1, 2, 3）-------------- //
        else if (current_screen >=1 && current_screen <=3)
        {
            //返回主界面按钮
            if(mouse_press(900 , 730 , 1024, 768) == 1) 
            {
                confirm_exit = 1;
                current_screen = 5;
            }
            //进入购物车页面
            if(mouse_press(800, 730, 875, 755) == 1) 
            {
                current_screen = 6; 
            }

            current_store = &food_stores[selected_store];
            for( j = 0 ; j < current_store->com_count ; j++)
            {
                if(mouse_press(760, 270 + j*75, 910, 310 + j*75) == 1) // 选择商品
                {
                    selected_product = j;
                    current_screen = 4; // 进入数量选择界面
                    break;
                }
            }
        }

        // --------------数量选择界面逻辑（current_screen == 4）-------------- //
        else if (current_screen == 4)
        {
            quantity = choose_number(&current_store->products[selected_product]);
            if (quantity > 0)
            {
                // 不直接修改库存，仅将商品添加到购物车
                cart_add(&cart, &current_store->products[selected_product], quantity);
            }

            // 返回原店铺界面并重绘
            current_screen = selected_store + 1; // 1: 韵苑食堂, 2: 蜜雪冰城, 3: 汉堡王
            switch (selected_store) 
            {
                case 0: show_menu(&food_stores[0], &cart); break;
                case 1: show_menu(&food_stores[1], &cart); break;
                case 2: show_menu(&food_stores[2], &cart); break;
            }

            selected_product = -1; // 重置商品索引
        }
        // ----------------退出确认界面(current_screen == 5)-----------------//
        else if (current_screen == 5)
        {
            static int exit_screen_drawn = 0; // 标志位，确保只绘制一次
            if (!exit_screen_drawn) {
                draw_exit_confirm();
                exit_screen_drawn = 1; // 设置标志位为已绘制
            }
            //确认退出
            if(mouse_press(386, 427, 500, 480) == 1) 
            {
                cart_clear(&cart); 
                current_screen = 0;
                confirm_exit = 0;
                exit_screen_drawn = 0; // 重置标志位
                mouse_off(&mouse);
                delay(1000);
                draw_food(food_stores, food_store_count);
                mouse_on(mouse);
                continue;
            }
            // 取消退出
            else if(mouse_press(527, 432, 640, 479) == 1) 
            {
                confirm_exit = 0;
                current_screen = selected_store + 1; 
                exit_screen_drawn = 0; // 重置标志位
                show_menu(&food_stores[selected_store],&cart);
                continue;
            }
        }
        // ----------------购物车界面(current_screen == 6)-----------------//
        else if (current_screen == 6)
        {
            static int checkout_drawn = 0;
            if (!checkout_drawn) 
            {
                draw_checkout(&cart);
                checkout_drawn = 1;
            }
            
            //确认支付
            if (mouse_press(345, 650, 450, 700) == 1) 
            {
                current_screen = 7; // 进入支付页面
                checkout_drawn = 0; // 重置绘制标志

            }

            // 清空购物车
            if(mouse_press(455, 650, 605, 700) == 1)
            {
                cart_clear(&cart); // 清空购物车
                current_screen = selected_store + 1; // 返回当前店铺页面
                checkout_drawn = 0; // 重置绘制标志
                show_menu(&food_stores[selected_store], &cart); // 重绘店铺页面
            }
        
            // 返回原店铺
            if (mouse_press(617, 652, 725, 700) == 1)
            {
                current_screen = selected_store + 1; 
                checkout_drawn = 0;
                show_menu(&food_stores[selected_store], &cart);
            }
        }
        //----------------------支付页面逻辑(current_screen == 7)-----------------//
        else if(current_screen == 7)
        {
            static int payment_drawn = 0;
            if (!payment_drawn) 
            {
                // 画支付页面
                draw_payment(&cart, users);
                payment_drawn = 1; 
            }
            
            // 确认支付
            if (mouse_press(383, 647, 518, 693) == 1)
            {
                if(check_balance(users->balance, cart.total_price))
                {
                    if(update_user_balance(users, cart.total_price) == 0)
                    {
                        if(update_inventory(&cart) == 0)
                        {
                            show_payment_result(1);
                            cart_clear(&cart); // 清空购物车
                            current_screen = 0; 
                            draw_food(food_stores, food_store_count); 
                            payment_drawn = 0; // 重置标志位
                        }
                    }
                }
            }

            // 显示余额不足
            if(mouse_press(558, 650, 685, 690) == 1)
            {
                show_payment_result(0);
                current_screen = 6; // 返回购物车界面
                payment_drawn = 0; // 重置标志位
            }

            // 进入选择地址页面
            if(mouse_press(392, 517, 621, 558) == 1)
            {
                current_screen = 8; // 进入选择地址页面
                payment_drawn = 0; // 重置标志位
            }

            // 返回订单
            if (mouse_press(620, 650, 740, 700) == 1) 
            {
                current_screen = 6; // 返回购物车清单界面
                payment_drawn = 0;  // 重置标志位
            }
        }
        // --------------------------选择地址界面(current_screen == 8)-------------------------//
        else if(current_screen == 8)
        {
            static int address_drawn = 0; // 标志位，确保只绘制一次
            if (!address_drawn) 
            {
                delivery_address = draw_address(); // 画选择地址页面
                address_drawn = 1; // 设置标志位为已绘制
            }

            if(delivery_address != 0)
            {
                current_screen = 7;
                address_drawn = 0;
            }
            // 返回支付页面(点击了返回按钮)
            else
            {
                current_screen = 7;
                address_drawn = 0;  
            }
        }
    }
}

/* 画主店铺界面 (current_screen = 0) */
void draw_food(Store* food_stores , int food_stores_count)

{
    int i, j;
    int x, y;
    int base_x , base_y;
    Store* store = NULL;
    // 画背景
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

    puthz(430 , 70 , "店" , 32 , 32 , 0x0000);
    puthz(560 , 70 , "铺" , 32 , 32 , 0x0000);
    puthz(160 , 275 , "韵酒大食堂，有胆你就闯！" , 24 , 24 , 0x0000);
    puthz(160 , 475 , "雪王出马，清凉一夏！" , 24 , 24 , 0x0000);
    puthz(160 , 685 , "肉饼夹宇宙，咬出快乐星云！" , 24 , 24 , 0x0000);
    puthz(900 , 730 , "返回主页面" , 24 , 24 , 0x001f);

    for(i = 0  ; i < food_stores_count ; i++)
    {
        store = &food_stores[i];
        base_y = 160 + i * 200;
        puthz(160 , base_y , store->name , 32 , 32 , 0x001f);
        
        puthz(160 , base_y + 40 , "地址：" , 16 , 16 , 0x0000);
        prt_hz16_asc16_size(160 + 2*25 , base_y + 40 , 1.5 , 1.5 , store->address , 0x0000 , "HZK\\HZK16K");

        puthz(160 , base_y + 65 , "评分：" , 16 , 16 , 0x0000);
        put_asc16_number_size(160 + 2*25 , base_y + 65 , 1.5 , 1.5 , store->score , 0x0000);
        puthz(160 , base_y + 90 , "人均消费：" , 16 , 16 , 0x0000);
        RMB(160 + 4*16 + 10, base_y + 90 , 1.5 , 1.5 ,0x0000);
        put_asc16_number_size(160 + 4*16 + 25 , base_y + 90 , 1.5 , 1.5 , store->AveragePrice , 0x0000);
        puthz(430 , 210 + i*200 , "进入店铺" , 24 , 24 , 0x001f);
    }
}
/*
功能：读取merchant.dat文件中商家数目
input：Mer* ， int max_merchants
output：商家数目
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
        memset(&merchants[count], 0, sizeof(Mer)); // 清空商家结构体
        fread(&merchants[count], sizeof(Mer), 1, fp); // 读取商家数据
        if (feof(fp)) break; // 如果到达文件末尾，退出循环
    }   
    fclose(fp);
    return count;
}

/*
功能：获得待读取的类型为FOOD的商铺数目
input：Mer* ， int max_merchants
output：成功返回商铺数目，失败返回-1
*/
int find_food_stores(Store *food_stores, int max_stores) {
    // 读取所有商家数据
    Mer merchants[MAX_MERCHANTS];
    Mer* mer = NULL;
    Store* store = NULL;
    int merchant_count = 0;
    int food_store_count = 0;
    int m, s;

    merchant_count = read_merchants(merchants, MAX_MERCHANTS);
    if (merchant_count <= 0) return -1;


    //遍历所有商家
    for (m = 0; m < merchant_count; m++) 
    {
        mer = &merchants[m];
        
        // 遍历商家的所有店铺
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
功能：显示店铺页面
input：Store
output：void
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
    puthz(800, 730, "购物车", 24, 24, 0x001f);
    puthz(900, 730, "返回主菜单", 24, 24, 0x001f);

    //画店铺
    puthz(100, 75, store->name, 24, 24, 0x0000);
    prt_hz16_asc16_size(120 , 170 , 1.5 , 1.5 , store->address , 0x0000 , "HZK\\HZK16K");
    put_asc16_number_size(120 , 135 , 1.5 , 1.5 , store->score , 0x0000);
    
    //画商品
    for( i = 0; i < store->com_count ; i++)
    {
        FillRoundedRectangle(80 , 260 + i*75 , 860 , 60 , 30 , 0xf7bb);
        puthz(100, 270 + i*75, store->products[i].name, 24, 24, 0x0000);
        bar1(760, 270 + i*75, 910, 310 + i*75 , 0x001f);
        puthz(770, 275 + i*75, "购买", 24, 24, 0xffff);
    }
    mouse_on(mouse);
}

/*
功能：选择购买商品数量页面
input：COM结构体指针
output：选择商品的数目
*/
int choose_number(const COM* product)
{
    int quantity = 1;
    // 对话框坐标和尺寸
    int x = 312, y = 284;       
    int width = 400, height = 200;
    // 按钮区域定义
    int btn_minus_x1 = x + 150, btn_minus_y1 = y + 100;
    int btn_minus_x2 = btn_minus_x1 + 50, btn_minus_y2 = btn_minus_y1 + 50;
    int btn_plus_x1 = x + 250, btn_plus_y1 = y + 100;
    int btn_plus_x2 = btn_plus_x1 + 50, btn_plus_y2 = btn_plus_y1 + 50;
    int btn_confirm_x1 = x + 100, btn_confirm_y1 = y + 150;
    int btn_confirm_x2 = btn_confirm_x1 + 100, btn_confirm_y2 = btn_confirm_y1 + 40;
    int btn_cancel_x1 = x + 250, btn_cancel_y1 = y + 150;
    int btn_cancel_x2 = btn_cancel_x1 + 100, btn_cancel_y2 = btn_cancel_y1 + 40;

    // 货架数量为0时给出提示
    if(product->stock <= 0) 
    {
        tip_empty(product->name);
        return 0; 
    }

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    // 标题和库存信息
    puthz(x + 150, y + 30, "选择购买数量", 24, 24, 0x0000);
    puthz(x + 50, y + 70, "库存", 16, 16, 0x0000);
    put_asc16_number_size(x + 100, y + 70, 1.5, 1.5, product->stock, 0x0000);
    // 数量调整按钮
    Circlefill(btn_minus_x1 + 25, btn_minus_y1 + 25, 20, 0xf800); // 减少按钮
    Circlefill(btn_plus_x1 + 30, btn_plus_y1 + 25, 20, 0xf800); // 增加按钮

    // 数量显示区域
    FillRoundedRectangle(x + 200, y + 100, 60, 40, 10, 0xffff);
    put_asc16_number_size(x + 215, y + 110, 2.0, 2.0, quantity, 0x0000);
    // 确认和取消按钮
    FillRoundedRectangle(btn_confirm_x1, btn_confirm_y1, 100, 40, 10, 0x99f);
    puthz(btn_confirm_x1 + 20, btn_confirm_y1 + 10, "确认", 24, 24, 0xffff);
    FillRoundedRectangle(btn_cancel_x1, btn_cancel_y1, 100, 40, 10, 0x99f);
    puthz(btn_cancel_x1 + 20, btn_cancel_y1 + 10, "取消", 24, 24, 0xffff);

    mouse_on(mouse);

    while (1) 
    {
        mouse_show(&mouse);
        // 处理减按钮
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
        // 处理加按钮
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
        
        // 确认购买
        if (mouse_press(btn_confirm_x1, btn_confirm_y1, btn_confirm_x2, btn_confirm_y2) == 1)
        {
            mouse_off(&mouse);
            return quantity;
        }
        
        // 取消购买
        if (mouse_press(btn_cancel_x1, btn_cancel_y1, btn_cancel_x2, btn_cancel_y2) == 1)
        {
            mouse_off(&mouse);
            return 0;
        }
        delay(15);
    }
}

/* 商品库存为0时弹出该页面*/
void tip_empty(const char* name)
{
    int x = 312, y = 284;       // 对话框坐标
    int width = 400, height = 200; // 对话框尺寸

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    puthz(x + 50, y + 70, "你选择的商品：", 24, 24, 0x0000);
    puthz(x + 200, y + 70, name , 24 , 24 , 0x001f);
    puthz(x + 50, y + 100, "库存不足", 24, 24, 0x0000);
    puthz(x + 50, y + 130, "给您带来的不便，", 24, 24, 0x0000);
    puthz(x + 235, y + 130, "敬请谅解", 24, 24, 0x0000);

    delay(1000); // 显示2秒钟
}

/*
功能：画是否确认退出的界面(current_screen == 5)
*/
void draw_exit_confirm(void)
{
    int x = 312, y = 234;       // 对话框坐标
    int width = 400, height = 300; // 对话框尺寸

    mouse_off(&mouse);
    delay(100);

    // 绘制矩形方框背景
    bar1(x, y, x + width, y + height, 0xffff);
    Line1(x, y, x + width, y, 0x0000); // 上边框
    Line1(x, y, x, y + height, 0x0000); // 左边框
    Line1(x + width, y, x + width, y + height, 0x0000); // 右边框
    Line1(x, y + height, x + width, y + height, 0x0000); // 下边框

    // 显示提示文字
    puthz(400, 350, "是否确认退出？", 32, 32, 0x001f);

    // 绘制确认按钮
    FillRoundedRectangle(x + 80, y + 200, 100, 40, 10, 0x99f);
    puthz(x + 100, y + 210, "确认", 24, 24, 0xffff);

    // 绘制取消按钮
    FillRoundedRectangle(x + 220, y + 200, 100, 40, 10, 0x99f);
    puthz(x + 240, y + 210, "取消", 24, 24, 0xffff);

    mouse_on(mouse);
    delay(1000); // 显示1秒钟
}

/*
功能：画结算页面(current_screen == 6)
input：ShoppingCart* cart
*/
void draw_checkout(ShoppingCart* cart)
{
    int x = 310, y = 260;          // 对话框坐标
    int width = 420, height = 440; // 对话框尺寸
    int item_x = x + 20, item_y = y + 100; // 商品列表起始坐标
    int line_height = 40;          // 每行高度
    int i = 0;
    CartNode* curr = cart->head;

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    Line1(x + 140, 325, x + 140, 600, 0xcd91);
    Line1(x + 210, 325, x + 210, 600, 0xcd91);
    Line1(x + 280, 325, x + 280, 600, 0xcd91);
    puthz(x + 140, y + 10, "结算页面", 32, 32, 0x001f);

    // 显示购物车商品列表
    puthz(item_x + 20, item_y - 30, "商品", 24, 24, 0x0000); 
    puthz(item_x + 125, item_y - 30, "数量", 24, 24, 0x0000); 
    puthz(item_x + 195, item_y - 30, "单价", 24, 24, 0x0000); 
    puthz(item_x + 310, item_y - 30, "总价", 24, 24, 0x0000); 

    while (curr != NULL && i < 4) // 最多显示4个商品
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

    // 绘制确认按钮
    FillRoundedRectangle(x + 40, y + height - 50, 100, 40, 10, 0x99f);
    puthz(x + 60, y + height - 40, "确认", 24, 24, 0xffff);

    // 绘制清空购物车按钮
    FillRoundedRectangle(x + 150, y + height - 50, 140, 40, 10, 0x99f);
    puthz(x + 160, y + height - 40, "清空购物车", 24, 24, 0xffff);

    // 绘制返回按钮
    FillRoundedRectangle(x + 310, y + height - 50, 100, 40, 10, 0x99f);
    puthz(x + 330, y + height - 40, "返回", 24, 24, 0xffff);

    mouse_on(mouse);
}

/*
功能：更新用户余额
input：用户结构体，金额
output：0表示成功，-1表示失败
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
            
            // 更新传入的结构体
            *u = tmp;
            break;
        }
        pos = ftell(fp);
    }

    fclose(fp);
    return found ? 0 : -1;
}

/*
功能：更新库存
input：购物车链表
output：0表示成功，-1无效参数，-2文件操作失败，-3库存不足，-4商品不存在
*/
int update_inventory(ShoppingCart *cart) 
{
    FILE *fp;
    Mer merchants[MAX_MERCHANTS];
    int merchant_count, need_update = 0;
    int found = 0;
    int m, s, p;
    CartNode *current = cart->head;

    // 参数校验
    if (!cart || !cart->head) return -1;

    // 1. 全量读取数据
    if ((fp = fopen("DATA\\merchant.dat", "rb")) == NULL) return -2;
    merchant_count = read_merchants(merchants, MAX_MERCHANTS);
    
    if (merchant_count <= 0)
    {
        fclose(fp);
        return -1; 
    }

    fclose(fp);

    // 2. 校验库存（内存操作）
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
                            return -3; // 库存不足
                        }
                        found = 1;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }

        if (!found) return -4; // 商品不存在
        current = current->next;
    }

    // 3. 批量扣减库存
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

    // 4. 全量写回
    if (need_update) {
        if ((fp = fopen("DATA\\merchant.dat", "wb")) == NULL) return -2;
        fwrite(merchants, sizeof(Mer), merchant_count, fp);
        fclose(fp);
    }
    return 0;
}

/*功能：画支付页面 (current_screen == 7)*/
void draw_payment(ShoppingCart* cart, user* u)
{
    int x = 310, y = 260;       // 对话框坐标
    int width = 420, height = 440; // 对话框尺寸
    int total_quantity = 0;
    CartNode* curr = cart->head;

    while (curr != NULL) 
    {
        total_quantity += curr->quantity;
        curr = curr->next;
    }

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    bar1(800, 730, 875, 760, 0x8410);
    bar1(350, 345, 700, 625, 0xf7bb);
    Line1(370, 445, 660, 445, 0xcd91);
    Line1(370, 490, 660, 490, 0xcd91);
    Line1(370, 550, 660, 550, 0xcd91);
    puthz(x + 160, y + 20, "支付页面", 32, 32, 0x0000);
    RMB(600, 415, 1.5, 1.5, 0x0000);
    put_asc16_number_size(620, 410, 2.0, 2.0, cart->total_price , 0x001f);
    RMB(600 , 460 ,1.5 ,1.5 ,0x0000);
    put_asc16_number_size(620 , 450 ,2.0 ,2.0 ,u->balance ,0x001f);
    puthz(370, 415, "商品总额", 24, 24, 0x0000);
    puthz(465, 425, "（共", 16, 16, 0x8410);
    put_asc16_number_size(500, 430, 1.0, 1.0, total_quantity, 0x001f);
    puthz(520, 425, "件）", 16, 16, 0x8410);
    
    puthz(370, 460, "账户余额：", 24, 24, 0x0000);
    puthz(400, 525, "请选择您的收货地址", 24, 24, 0x8410);
    // 确认支付按钮
    FillRoundedRectangle(x + 80, y + height - 50, 120, 40, 10, 0x99f);
    puthz(x + 95, y + height - 40, "确认支付", 24, 24, 0xffff);

    // 返回按钮
    FillRoundedRectangle(x + width -170 , y + height -50 ,120 ,40 ,10 ,0x99f);
    puthz(x + width -155 , y + height -40 ,"返回订单" ,24 ,24 ,0xffff);


    mouse_on(mouse);
}

// 功能：支付结果页面
void show_payment_result(int result)
{
    int x = 360, y = 390;       // 对话框坐标
    int width = 310, height = 160; // 对话框尺寸

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    bar1(x, y, x + width, y + height, 0xffff);
    bar1(x, y, x + width, y + 65, 0x001f);

    if(result)
    {
        puthz(x + 90, y + 100, "支付成功！", 24, 24, 0x07e0);
        delay(1500);
    }
    else
    {
        puthz(x + 90, y + 100, "余额不足！", 24, 24, 0xf800);
        delay(1500);
    }
    mouse_on(mouse);
}

/*
功能：比较用户余额和商品总价
input：用户余额，商品总价
output：1表示余额足够，0表示余额不足
*/
int check_balance(float balance, float total_price)
{
    if(balance < total_price) return 0; 
    return 1; 
}


/*
功能：选择收货地址页面(current_screen == 8)
input：void
output：101-107：店铺地址 
        0：返回支付页面
*/
unsigned short draw_address(void)
{
    int x = 310, y = 260;       // 对话框坐标
    int width = 420, height = 440; // 对话框尺寸
    int i;

    mouse_off(&mouse);
    delay(100);

    // 绘制对话框背景
    FillRoundedRectangle(x, y, width, height, 20, 0xffff);
    bar1(325, 278, 720, 345, 0x001f);

    Line1(x + 50, y + 130, x + 370, y + 130, 0xcd91); 
    Line1(x + 50, y + 180, x + 370, y + 180, 0xcd91); 
    Line1(x + 50, y + 230, x + 370, y + 230, 0xcd91); 
    Line1(x + 50, y + 280, x + 370, y + 280, 0xcd91); 
    Line1(x + 50, y + 330, x + 370, y + 330, 0xcd91); 
    Line1(x + 50, y + 380, x + 370, y + 380, 0xcd91); 
    Line1(x + 50, y + 430, x + 370, y + 430, 0xcd91);

    puthz(435, 300, "选择收货地址", 32, 32, 0xffff);
    puthz(610, 675, "返回支付页面", 16, 16, 0x001f);
    prt_hz16_asc16_size(450, 365, 1.5, 1.5, "韵苑25栋学生宿舍", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 415, 1.5, 1.5, "东九教学楼", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 465, 1.5, 1.5, "东十二教学楼", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 515, 1.5, 1.5, "韵苑26栋学生宿舍", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 565, 1.5, 1.5, "韵苑19栋学生宿舍", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 615, 1.5, 1.5, "韵苑5栋学生宿舍", 0x8410, "HZK\\HZK16K");
    prt_hz16_asc16_size(450, 665, 1.5, 1.5, "韵苑10栋学生宿舍", 0x8410, "HZK\\HZK16K");

    mouse_on(mouse);
    while (1)
    {
        mouse_show(&mouse);
        // 点击不同地址返回对应值
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
        // 返回支付页面
        if (mouse_press(606, 672, 710, 700) == 1) return 0;
    }
}