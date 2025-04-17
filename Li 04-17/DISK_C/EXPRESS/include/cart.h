#ifndef _CART_H
#define _CART_H
#include "general.h"

/* 功能：初始化购物车 */
void cart_init(ShoppingCart* cart);

/*
功能：添加商品到购物车
input：购物车指针、商品指针、购买数量
output：成功返回0，失败返回-1
*/
int cart_add(ShoppingCart* cart, const COM* item, unsigned short quantity);

/*
功能：从购物车移除商品
input：购物车指针、商品名称
output：成功移除的数量（0表示未找到）
*/
unsigned cart_remove(ShoppingCart* cart, const char* item_name);

/*
功能：计算购物车总价
input：购物车指针
output：当前总价
*/
float cart_calculate_total(ShoppingCart* cart);

/*
功能：打印购物车
input：购物车指针
output：void
*/
// void cart_print(ShoppingCart* cart);

/*
功能：清空购物车
input：购物车指针
output：void
*/
void cart_clear(ShoppingCart* cart);

/*
功能：获取购物车商品数量
input：购物车指针
output：商品数量
*/
unsigned char cart_count(ShoppingCart* cart);

#endif // CART_H