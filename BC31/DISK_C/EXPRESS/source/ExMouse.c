#include "ExMouse.h"


void HandleMouseDrag(int *deltax, int *deltay, MOUSE *mouse, unsigned char sensitivity) 
{
    static DragState state = {0, 0, 0}; // ��̬���������϶�״̬

    // ��ȡ��ǰ���״̬
    MouseGet(mouse);

    if (mouse->key & 1) { // �������
        if (!state.isDragging) 
        { // �϶���ʼ
            state.isDragging = 1;
            state.startX = mouse->x;
            state.startY = mouse->y;
        } else 
        { // �϶���
            // ������ڳ�ʼλ�õ����������������ȣ�
            // ����������Χ
            *deltax = (*deltax > MAX_DELTA) ? MAX_DELTA : (*deltax < -MAX_DELTA) ? -MAX_DELTA :(mouse->x - state.startX) * sensitivity;
            *deltay = (*deltay > MAX_DELTA) ? MAX_DELTA : (*deltay < -MAX_DELTA) ? -MAX_DELTA : (mouse->y - state.startY) * sensitivity;
            // ������ʼ����ʵ��"�����϶�"����������ѡ��
            state.startX = mouse->x;
            state.startY = mouse->y;
        }
    } 
    else 
    { // ����ͷ�
        if (state.isDragging) 
        { // �϶�����
            state.isDragging = 0;
            *deltax = 0;
            *deltay = 0;
        }
    }
}