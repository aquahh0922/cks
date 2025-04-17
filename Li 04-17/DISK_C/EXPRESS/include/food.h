#ifndef _FOOD_H_
#define _FOOD_H_
#include "general.h"
#define MAX_STORE_NUM 20			//����������

int food(int *flag, user* users, order* ord);
void draw_food(Store* food_stores , int food_stores_count);
// void print_food_stores(Store* food_stores);
int read_merchants(Mer* merchants, int max_merchants);
int find_food_stores(Store* food_stores , int max_stores);  
void show_menu(const Store* store, ShoppingCart* cart);
void tip_empty(const char* name);
int choose_number(const COM* product);
void draw_exit_confirm(void);
void draw_checkout(ShoppingCart* cart);
int update_user_balance(user* u , float amount);
void draw_payment(ShoppingCart* cart, user* u, const char* selected_address);
void show_payment_result(int result);
int update_inventory(ShoppingCart* cart);
int check_balance(float balance, float total_price);
unsigned short draw_address(void);
int init_order(const ShoppingCart* cart, const user* u, unsigned short payment_addr, unsigned short delivery_addr, StoreCategory type, order* odr);
void generate_order_num(char* buffer, size_t size);
// void test_order(order* ord);
#endif
