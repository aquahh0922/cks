#ifndef _DTLORDER_H_
#define _DTLORDER_H_
#include"general.h"

#define NODE_NUM 75
#define ROAD_NUM 93
int DetailedOrder(int *flag,struct RealTimeOrder *rto,struct order *ord);
void drawDetailedOrder();
void drawMap(char mode,int cx,int cy);
int BinarySearch(struct node *p,int num);
int random_range(int min, int max); 
int NewOrder(struct RealTimeOrder *rto,unsigned char *OrderNum,struct order *ord);

typedef enum CentralPoint
{
    CenterX=512,
    CenterY=384,
    MapminWidth=978,
    MapminHeight=603,
    MapmidWidth=652,
    MapmidHeight=402,
    BottomLow=550
}CentralPoint;

typedef struct coordinate
{
    int x;
    int y;
}coordinate;

typedef struct FloatCoordinate
{
    float x;
    float y;
}FloatCoordinate;

typedef struct node
{
    unsigned char num;
    char name[30];
    char type;//0:弯道转弯点，1：普通路口，2：十字路口，3：红绿灯，4：起点，5：终点
    coordinate point;
}node;

typedef struct road
{
    int node1;
    int node2;  
    int distance;//时间长度，单位秒
}road;

typedef struct RandomPoint
{
    int location;
    int shortest;
}RandomPoint;

typedef struct BriefPoint
{
    int location;
    coordinate point;
}BriefPoint;

typedef struct PointWithTime
{
    
    coordinate point;
    int time;       //到下一个节点的时间
}PointWithTime;


typedef struct RealTimeOrder
{
    time_t currentime;
    time_t initime;
    int shorttime;
    int pathSize;
    int path_len1;
    int path_len2;
    PointWithTime *path;
    BriefPoint *path1;
    BriefPoint *path2;
    char state;
}RealTimeOrder;
#endif // _DTLORDER_H_