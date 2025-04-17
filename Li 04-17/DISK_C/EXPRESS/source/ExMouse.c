#include "ExMouse.h"


void HandleMouseDrag(int *deltax, int *deltay, MOUSE *mouse, unsigned char sensitivity) 
{
    static DragState state = {0, 0, 0}; // 静态变量保持拖动状态

    // 获取当前鼠标状态
    MouseGet(mouse);

    if (mouse->key & 1) { // 左键按下
        if (!state.isDragging) 
        { // 拖动开始
            state.isDragging = 1;
            state.startX = mouse->x;
            state.startY = mouse->y;
        } else 
        { // 拖动中
            // 计算基于初始位置的增量（考虑灵敏度）
            // 限制增量范围
            *deltax = (*deltax > MAX_DELTA) ? MAX_DELTA : (*deltax < -MAX_DELTA) ? -MAX_DELTA :(mouse->x - state.startX) * sensitivity;
            *deltay = (*deltay > MAX_DELTA) ? MAX_DELTA : (*deltay < -MAX_DELTA) ? -MAX_DELTA : (mouse->y - state.startY) * sensitivity;
            // 更新起始点以实现"连续拖动"（根据需求选择）
            state.startX = mouse->x;
            state.startY = mouse->y;
        }
    } 
    else 
    { // 左键释放
        if (state.isDragging) 
        { // 拖动结束
            state.isDragging = 0;
            *deltax = 0;
            *deltay = 0;
        }
    }
}