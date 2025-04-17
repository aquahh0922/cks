#ifndef _DATA_H
#define _DATA_H
#define MAX_SHOPS 3  // ÿ���̼�����������
#define MAX_COM 6 // ÿ�����̵������Ʒ����
#define MAX_FOOD_STORES 3 // ÿ��ҳ�������������
#define MAX_MERCHANTS 10
#define MAX_ORDERS 10
#define MAX_ORDER_ITEMS 10 // ÿ�������������Ʒ������
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


// �û��ṹ��
typedef struct user
{
    char name[20];        // �û���
    char code[20];        // ����          
    UserType type;        // ��ݱ�ʶ
    float balance;        // ���
    char phone[12];       // �绰���루Ԥ��+86��
    char address[30];     // ��ϸ��ַ
}user;

// ���Ա�ṹ��
typedef struct DeliveryMan
{
	char name[20];						//�û���
	unsigned int OrderNum;				//��ɶ�����
}DeliveryMan;



// ��Ʒ�ṹ��
typedef struct Commodity
{
	char name[24];			//��Ʒ������
	unsigned char store_id;       //��Ʒ���������̱��
	float price;		    //�۸�
	CommodityState state;   //'S'���� 'O'����
	unsigned short stock;	//���
}COM;


typedef struct Store
{
	char name[24];					//����������
	unsigned char id;				//���̱��
	char address[24];			    //��ַ
	float score;					//����
	StoreCategory type;				    //���1 ���� 2 ���� 3 ��ݣ�
	float AveragePrice;		//�˾�����
	COM products[MAX_COM];            //��Ʒ����
	unsigned char com_count;                 //��ǰ��Ʒ����
}Store;

// �̼ҽṹ��
typedef struct Merchant
{
	char name[20];			        //�û���
	char password[20];              //����
	unsigned char store_count;      //��ǰ��������
	Store stores[MAX_SHOPS];        //��������
}Mer;

// ��ȡ��ݽṹ��
typedef struct package
{	
	char name[20];                  // �û���
	char state;                     // ״̬
	char location[30];              // ȡ����ַ
	char id[12];                   // ��ݵ���
	time_t time;                  // ȡ��ʱ��
}package;

// ���ﳵ�ڵ�ṹ��
typedef struct CartNode
{
    const COM* item;                      // ��Ʒ��Ϣ
    unsigned short quantity;       // ��������
    struct CartNode *next;       // ������һ�ڵ�ָ��
}CartNode;

// ���ﳵ�ṹ��
typedef struct ShoppingCart
{
    CartNode *head;               // ����ͷָ��
    float total_price;            // ���ﳵʵʱ�ܼ�
}ShoppingCart;

// ������ṹ�壨��¼������Ʒ������Ϣ��
typedef struct {
    char name[24];          // ��Ʒ����
    unsigned char store_id; // ��������ID
    float price;            // ��Ʒ����
    unsigned short quantity;// ��������
} OrderItem;

// �Ľ���Ķ����ṹ��
typedef struct order {
    char name[20];                  // �û���
    StoreCategory type;             // �������ͣ�����/����/��ݣ�
    char state;               // ����״̬���ȴ����ͣ������У�����ɣ�
    char order_num[20];             // �����ţ�Ψһ��ʶ��
    float money;                    // �����ܽ��
    time_t time;                    // �µ�ʱ��
    unsigned char delivery_address;      // �ջ���ַ���û���������͵�ַ��
    unsigned char payment_address;               // �µ���ַ���̼ҵ�ַ��
    OrderItem items[MAX_ORDER_ITEMS]; // �������Ʒ���б�
    unsigned char item_count;       // ʵ�ʹ������Ʒ������
} order;

#endif


