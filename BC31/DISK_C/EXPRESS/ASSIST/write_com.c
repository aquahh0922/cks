#include <general.h>
#include <stddef.h> 
#define MAX_SHOPS 3
#define MAX_COM 6
/*
���ܣ���ʼ������
input�����̽ṹ�壬���̱�ţ����������������̵�ַ���������֣��������ͣ��˾����ѣ���Ʒ���飬��Ʒ����
*/
void initialize_store(Store *store, unsigned char id, const char *name, 
                     const char *address, float score , StoreCategory type,
                     float AveragePrice , const COM *products, size_t product_count) {
    int i;
    // ���̻�����Ϣ
    strncpy(store->name, name, sizeof(store->name)-1);
    store->id = id;
    strncpy(store->address, address, sizeof(store->address)-1);
    store->score = score;
    store->type = type;
    store->AveragePrice = AveragePrice;

    // ��Ʒ��ʼ��
    store->com_count = product_count > MAX_COM ? MAX_COM : product_count;
    for(i=0; i<store->com_count; i++) {
        store->products[i] = products[i];
    }
}

int main() {
    FILE* fp;

    // ================== ��ʼ������ ==================
    // ��ʼ����Ʒ���ݣ�ʳ�ã�
    COM canteen_products[MAX_COM] = {
        {"±�ⷹ", 1, 12.0f, STATE_ONSALE, 150},
        {"������", 1, 4.0f, STATE_ONSALE, 200},
        {"�ȸ���", 1, 5.0f, STATE_ONSALE, 200}
    };
    
    // ��ʼ�����̣�ʳ�ã�
    Store canteen;

    // ��ʼ����Ʒ���� ����ѩ���ǣ���
    COM drink_products[MAX_COM] = {
        {"��������ˮ", 3, 4.0f, STATE_ONSALE, 200},
        {"�����ļ���", 3, 7.0f, STATE_ONSALE, 100},
        {"ѩ����ʥ��", 3, 6.0f, STATE_ONSALE, 50},
        {"�����̲�", 3, 6.0f, STATE_ONSALE, 100},
        {"�����ʳ�", 3, 6.0f, STATE_SOLDOUT, 0},
        {"��ʽ����", 3, 5.0f, STATE_ONSALE, 80},
    };
    
    Store drink_shop;

    // ��ʼ����Ʒ���� ����������
    COM burger_products[MAX_COM] = {
        {"����", 15.8f, STATE_ONSALE, 20},
        {"����", 9.9f, STATE_ONSALE, 200},
        {"����", 6.0f, STATE_ONSALE, 300},
    };
    
    Store burger_shop;

    // ��ʼ����Ʒ���ݣ����У�
    COM supermarket_products[MAX_COM] = {
        {"��Ȫˮ", 4, 2.0f, STATE_ONSALE, 500},
        {"������", 4, 5.0f, STATE_ONSALE, 80},
        {"ֽ��", 4, 3.5f, STATE_ONSALE, 150}
    };

    // ��ʼ�����̣����У�
    Store supermarket;


    // ��ʼ���̼�
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

    // ��ʼ����������
    initialize_store(&supermarket, 2, "��Էѧ������",
                     "��Էѧ��������", 4.5f, CATEGORY_SUPERMARKET,
                     0.0f , supermarket_products, 3);

    initialize_store(&canteen, 1, "��Էʳ��", 
                     "��Էѧ��������", 3.5f, CATEGORY_FOOD,
                     12.0f ,canteen_products, 3);

    initialize_store(&drink_shop, 3, "��ѩ����", 
                     "��Էѧ��������22��", 4.8f , CATEGORY_FOOD,
                     6.0f , drink_products, 6);

    initialize_store(&burger_shop, 4, "������",
                    "��Էѧ��������23��", 4.1f , CATEGORY_FOOD,
                    20.0f , burger_products, 3);

    merchant_hust.stores[0] = canteen;
    merchant_hust.stores[1] = supermarket;

    merchant_mi.stores[0] = drink_shop;
    merchant_ham.stores[0] = burger_shop;

    // ================== д���ļ� ==================
    if((fp = fopen("data\\merchant.dat" , "wb")) == NULL)
    {
        printf("�޷����̼��ļ�");
        exit(1);
    }

    if( (fwrite(&merchant_hust, sizeof(Mer), 1,fp)!= 1) ||
        (fwrite(&merchant_mi, sizeof(Mer), 1,fp)!= 1) ||
        (fwrite(&merchant_ham, sizeof(Mer), 1,fp)!= 1) )
    {
        printf("д���̼�����ʧ��");
        fclose(fp);
        exit(1);
    }
    fclose(fp);

    printf("�̼������ѳɹ������� %s\n", "data\\merchant.dat");
    printf("Size of Mer: %lu\n", sizeof(Mer));
    return 0;
}
