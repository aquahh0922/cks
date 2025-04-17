#include "general.h"
void cart_init(ShoppingCart* cart)
{
    cart->head = NULL;
    cart->total_price = 0.0f;
}

int cart_add(ShoppingCart* cart, const COM* item, unsigned short quantity)
{
    CartNode** curr = &cart->head;
    CartNode* new_node = malloc(sizeof(CartNode));
    if(item == NULL || quantity == 0 || item->state != STATE_ONSALE) return -1;

    
    while(*curr)
    {
        if((*curr)->item == item)
        {
            (*curr)->quantity += quantity;
            goto update_total;
        }
        curr = &(*curr)->next;
    }
    
    // 新建节点
        if(!new_node) return -1;
        
        new_node->item = item;
        new_node->quantity = quantity;
        new_node->next = cart->head;
        cart ->head = new_node;

update_total:
    cart->total_price += item->price * quantity;
    return 0;
}


unsigned cart_remove(ShoppingCart* cart, const char* item_name) {
    unsigned removed = 0;
    CartNode** curr = &cart->head;
    
    while (*curr) {
        if (strcmp((*curr)->item->name, item_name) == 0) {
            CartNode* temp = *curr;
            removed = temp->quantity;
            
            // 更新统计信息
            cart->total_price -= temp->item->price * removed;
            
            // 移除节点
            *curr = temp->next;
            free(temp);
            break;
        }
        curr = &(*curr)->next;
    }
    return removed;
}

float cart_calculate_total(ShoppingCart* cart) {
    float total = 0.0f;
    CartNode* curr = cart->head;
    while (curr) {
        total += curr->item->price * curr->quantity;
        curr = curr->next;
    }
    cart->total_price = total;
    return total;
}


// void cart_print(ShoppingCart* cart) {
//     int index = 1;
//     CartNode* curr = cart->head;
//     printf("=== 购物车 ===\n");
//     while (curr) {
//         printf("%d. %-20s * %d ￥%.2f\n", index , curr->item->name , curr->quantity, curr->item->price * curr->quantity);
//         curr = curr->next;
//     }
//     printf("总价: %.2f\n", cart->total_price);
// }

void cart_clear(ShoppingCart* cart) {
    CartNode* curr = cart->head;
    while (curr) {
        CartNode* next = curr->next;
        free(curr);
        curr = next;
    }
    cart_init(cart); // 重置统计信息
}

unsigned char cart_count(ShoppingCart* cart)
{
    unsigned char count = 0;
    CartNode* curr = cart->head;
    while (curr) {
        count++;
        curr = curr->next;
    }
        return count;
}
