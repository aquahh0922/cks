#ifndef _CART_H
#define _CART_H
#include "general.h"

/* ���ܣ���ʼ�����ﳵ */
void cart_init(ShoppingCart* cart);

/*
���ܣ������Ʒ�����ﳵ
input�����ﳵָ�롢��Ʒָ�롢��������
output���ɹ�����0��ʧ�ܷ���-1
*/
int cart_add(ShoppingCart* cart, const COM* item, unsigned short quantity);

/*
���ܣ��ӹ��ﳵ�Ƴ���Ʒ
input�����ﳵָ�롢��Ʒ����
output���ɹ��Ƴ���������0��ʾδ�ҵ���
*/
unsigned cart_remove(ShoppingCart* cart, const char* item_name);

/*
���ܣ����㹺�ﳵ�ܼ�
input�����ﳵָ��
output����ǰ�ܼ�
*/
float cart_calculate_total(ShoppingCart* cart);

/*
���ܣ���ӡ���ﳵ
input�����ﳵָ��
output��void
*/
// void cart_print(ShoppingCart* cart);

/*
���ܣ���չ��ﳵ
input�����ﳵָ��
output��void
*/
void cart_clear(ShoppingCart* cart);

/*
���ܣ���ȡ���ﳵ��Ʒ����
input�����ﳵָ��
output����Ʒ����
*/
unsigned char cart_count(ShoppingCart* cart);

#endif // CART_H