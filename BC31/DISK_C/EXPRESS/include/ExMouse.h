#ifndef _EXMOUSE_H_
#define _EXMOUSE_H_
#include "general.h"

void ExtMouseInit();
void ExtMouseDraw(MOUSE mouse,uint8_t shape);
void ExtMouseHide(MOUSE *mouse);
void ExtMouseShow(MOUSE *mouse,uint8_t shape);

#endif