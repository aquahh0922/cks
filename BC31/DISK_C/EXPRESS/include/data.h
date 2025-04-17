#ifndef _DATA_H
#define _DATA_H
#define MAX_SHOPS 3  // 每个商家最大店铺数量
#define MAX_COM 6 // 每个店铺的最大商品数量
#define MAX_FOOD_STORES 3 // 每个页面的最大店铺数量
#define MAX_MERCHANTS 10
#define MAX_ORDERS 10
#define MAX_ORDER_ITEMS 10 // 每个订单的最大商品项数量
#include "general.h"


typedef enum 
{
    USER_NORMAL = 1,
    USER_DELIVERY = 2
} UserType;

typedef enum
{
    STATE_ONSALE = 1,
    STATE_SOLDOUT = 0
} CommodityState;

typedef enum
{
	CATEGORY_FOOD = 1,
	CATEGORY_SUPERMARKET = 2,
	CATEGORY_EXPRESS = 3
} StoreCategory;

typedef enum
{
    Finished = 2,
	Delivering = 1,
	SearchDeliver = 0
} OrderState;


// 用户结构体
typedef struct user
{
    char name[20];        // 用户名
    char code[20];        // 密码          
    UserType type;        // 身份标识
    float balance;        // 余额
    char phone[12];       // 电话号码（预留+86）
    char address[30];     // 详细地址
}user;

// 快递员结构体
typedef struct DeliveryMan
{
	char name[20];						//用户名
	unsigned int OrderNum;				//完成订单数
}DeliveryMan;



// 商品结构体
typedef struct Commodity
{
	char name[24];			//商品中文名
	unsigned char store_id;       //商品所属的商铺编号
	float price;		    //价格
	CommodityState state;   //'S'在售 'O'告罄
	unsigned short stock;	//库存
}COM;


typedef struct Store
{
	char name[24];					//店铺中文名
	unsigned char id;				//店铺编号
	char address[24];			    //地址
	float score;					//评分
	StoreCategory type;				    //类别（1 餐饮 2 超市 3 快递）
	float AveragePrice;		//人均消费
	COM products[MAX_COM];            //商品数组
	unsigned char com_count;                 //当前商品数量
}Store;

// 商家结构体
typedef struct Merchant
{
	char name[20];			        //用户名
	char password[20];              //密码
	unsigned char store_count;      //当前店铺数量
	Store stores[MAX_SHOPS];        //店铺数组
}Mer;

// 代取快递结构体
typedef struct package
{	
	char name[20];                  // 用户名
	char state;                     // 状态
	char location[30];              // 取件地址
	char id[12];                   // 快递单号
	time_t time;                  // 取件时间
}package;

// 购物车节点结构体
typedef struct CartNode
{
    const COM* item;                      // 商品信息
    unsigned short quantity;       // 购买数量
    struct CartNode *next;       // 链表下一节点指针
}CartNode;

// 购物车结构体
typedef struct ShoppingCart
{
    CartNode *head;               // 链表头指针
    float total_price;            // 购物车实时总价
}ShoppingCart;

// 订单项结构体（记录单个商品购买信息）
typedef struct {
    char name[24];          // 商品名称
    unsigned char store_id; // 所属店铺ID
    float price;            // 商品单价
    unsigned short quantity;// 购买数量
} OrderItem;

// 改进后的订单结构体
typedef struct order {
    char name[20];                  // 用户名
    StoreCategory type;             // 订单类型（餐饮/超市/快递）
    char state;               // 订单状态（等待配送，配送中，已完成）
    char order_num[20];             // 订单号（唯一标识）
    float money;                    // 订单总金额
    time_t time;                    // 下单时间
    unsigned char delivery_address;      // 收货地址（用户输入的配送地址）
    unsigned char payment_address;               // 下单地址（商家地址）
    OrderItem items[MAX_ORDER_ITEMS]; // 购买的商品项列表
    unsigned char item_count;       // 实际购买的商品项数量
} order;

#endif


