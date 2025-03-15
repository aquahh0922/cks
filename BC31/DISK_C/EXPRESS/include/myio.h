#ifndef _MYIO_H_
#define _MYIO_H_
#include "general.h"
int input(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int input_encrypted(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int output(char *outputarray,int size,unsigned int color,unsigned int backcolor,int x,int y);
int output_encrypted(char *outputarray,int size,unsigned int color,unsigned int backcolor,int x,int y);

int input_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int input_encrypted_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int inputcode_wel(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int input_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int input_encrypted_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int input_encrypted2_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int inputcode_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int inputcode2_reg(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);

int inputhz(char *outputarray,int length,int size,unsigned int color,unsigned int backcolor,int x,int y);
int ishz(char* hz);
typedef struct hz
{
    char pinyin[10];
    char hanzi[5][4];
}hz;

#endif