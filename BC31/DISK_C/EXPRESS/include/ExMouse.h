#ifndef _EXMOUSE_H_
#define _EXMOUSE_H_
#include "general.h"
#define MAX_DELTA 100
void HandleMouseDrag(int *deltax, int *deltay, MOUSE *mouse, unsigned char sensitivity); 

typedef struct {
    int isDragging;    // 是否正在拖动（1=是，0=否）
    int startX;        // 拖动起始坐标X
    int startY;        // 拖动起始坐标Y
} DragState;
#endif