#ifndef _REGISTER_H_
#define _REGISTER_H_
#include "general.h"

int reg(int *flag);
void draw_reg();
int namecheck_reg(char *name);
int name_repeat_check(char *name);
int name_legal_check(char *name);
int codecheck_reg(char *code);
int code_legal_check(char *code);
void draw_success();


#endif