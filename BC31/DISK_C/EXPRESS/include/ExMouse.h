#ifndef _EXMOUSE_H_
#define _EXMOUSE_H_
#include "general.h"
#define MAX_DELTA 100
void HandleMouseDrag(int *deltax, int *deltay, MOUSE *mouse, unsigned char sensitivity); 

typedef struct {
    int isDragging;    // �Ƿ������϶���1=�ǣ�0=��
    int startX;        // �϶���ʼ����X
    int startY;        // �϶���ʼ����Y
} DragState;
#endif