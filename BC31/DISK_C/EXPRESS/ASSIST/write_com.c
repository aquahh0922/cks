#include <general.h>
#include <stddef.h> 
#define MAX_SHOPS 3
#define MAX_COM 6
/*
功能：初始化店铺
input：店铺结构体，店铺编号，店铺中文名，店铺地址，店铺评分，店铺类型，人均消费，商品数组，商品数量
*/
void initialize_store(Store *store, unsigned char id, const char *name, 
                     const char *address, float score , StoreCategory type,
                     float AveragePrice , const COM *products, size_t product_count) {
    int i;
    // 店铺基本信息
    strncpy(store->name, name, sizeof(store->name)-1);
    store->id = id;
    strncpy(store->address, address, sizeof(store->address)-1);
    store->score = score;
    store->type = type;
    store->AveragePrice = AveragePrice;

    // 商品初始化
    store->com_count = product_count > MAX_COM ? MAX_COM : product_count;
    for(i=0; i<store->com_count; i++) {
        store->products[i] = products[i];
    }
}

int main() {
    FILE* fp;

    // ================== 初始化数据 ==================
    // 初始化商品数据（食堂）
    COM canteen_products[MAX_COM] = {
        {"卤肉饭", 1, 12.0f, STATE_ONSALE, 150},
        {"早餐馄饨", 1, 4.0f, STATE_ONSALE, 200},
        {"热干面", 1, 5.0f, STATE_ONSALE, 200}
    };
    
    // 初始化店铺（食堂）
    Store canteen;

    // 初始化商品数据 （蜜雪冰城）、
    COM drink_products[MAX_COM] = {
        {"冰鲜柠檬水", 3, 4.0f, STATE_ONSALE, 200},
        {"蜜桃四季春", 3, 7.0f, STATE_ONSALE, 100},
        {"雪王大圣代", 3, 6.0f, STATE_ONSALE, 50},
        {"珍珠奶茶", 3, 6.0f, STATE_ONSALE, 100},
        {"棒打鲜橙", 3, 6.0f, STATE_SOLDOUT, 0},
        {"美式咖啡", 3, 5.0f, STATE_ONSALE, 80},
    };
    
    Store drink_shop;

    // 初始化商品数据 （汉堡王）
    COM burger_products[MAX_COM] = {
        {"汉堡", 15.8f, STATE_ONSALE, 20},
        {"薯条", 9.9f, STATE_ONSALE, 200},
        {"可乐", 6.0f, STATE_ONSALE, 300},
    };
    
    Store burger_shop;

    // 初始化商品数据（超市）
    COM supermarket_products[MAX_COM] = {
        {"矿泉水", 4, 2.0f, STATE_ONSALE, 500},
        {"方便面", 4, 5.0f, STATE_ONSALE, 80},
        {"纸巾", 4, 3.5f, STATE_ONSALE, 150}
    };

    // 初始化店铺（超市）
    Store supermarket;


    // 初始化商家
    Mer merchant_hust;
    Mer merchant_mi;
    Mer merchant_ham;
    
    strncpy(merchant_hust.name, "hust123", sizeof(merchant_hust.name) - 1);
    strncpy(merchant_hust.password, "hust123", sizeof(merchant_hust.password) - 1);
    merchant_hust.store_count = 2;


    strncpy(merchant_mi.name, "mixue123", sizeof(merchant_mi.name) - 1);
    strncpy(merchant_mi.password, "mixue123", sizeof(merchant_mi.password) - 1);
    merchant_mi.store_count = 1;
    

    strncpy(merchant_ham.name, "hambur123", sizeof(merchant_ham.name) - 1);
    strncpy(merchant_ham.password, "hambur123", sizeof(merchant_ham.password) - 1);
    merchant_ham.store_count = 1;

    // 初始化店铺数据
    initialize_store(&supermarket, 2, "韵苑学生超市",
                     "韵苑学生生活区", 4.5f, CATEGORY_SUPERMARKET,
                     0.0f , supermarket_products, 3);

    initialize_store(&canteen, 1, "韵苑食堂", 
                     "韵苑学生生活区", 3.5f, CATEGORY_FOOD,
                     12.0f ,canteen_products, 3);

    initialize_store(&drink_shop, 3, "蜜雪冰城", 
                     "韵苑学生服务区22号", 4.8f , CATEGORY_FOOD,
                     6.0f , drink_products, 6);

    initialize_store(&burger_shop, 4, "汉堡王",
                    "韵苑学生服务区23号", 4.1f , CATEGORY_FOOD,
                    20.0f , burger_products, 3);

    merchant_hust.stores[0] = canteen;
    merchant_hust.stores[1] = supermarket;

    merchant_mi.stores[0] = drink_shop;
    merchant_ham.stores[0] = burger_shop;

    // ================== 写入文件 ==================
    if((fp = fopen("data\\merchant.dat" , "wb")) == NULL)
    {
        printf("无法打开商家文件");
        exit(1);
    }

    if( (fwrite(&merchant_hust, sizeof(Mer), 1,fp)!= 1) ||
        (fwrite(&merchant_mi, sizeof(Mer), 1,fp)!= 1) ||
        (fwrite(&merchant_ham, sizeof(Mer), 1,fp)!= 1) )
    {
        printf("写入商家数据失败");
        fclose(fp);
        exit(1);
    }
    fclose(fp);

    printf("商家数据已成功保存至 %s\n", "data\\merchant.dat");
    printf("Size of Mer: %lu\n", sizeof(Mer));
    return 0;
}
