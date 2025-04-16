#include "general.h"
// volatile unsigned long timerTicks = 0;
// volatile int redrawFlag = 0;
// void interrupt (*oldTimerISR)(...);

int main()
{
    //特征值flag
    int flag = 0;
    user *users=(user*)malloc(sizeof(user));
    BriefPoint/*  *path2=NULL,*path1=NULL, */*temp=NULL;
    int start=201,end=107/* ,shortime=0,path_len1=0,path_len2=0 */;
    // PointWithTime *path = NULL;
    // int pathSize = 0;
    // time_t initime=0,currentime=0;
    RealTimeOrder *rto=NULL,*rtotemp=NULL;
    unsigned char rtosize=1;
    unsigned char OrderNum=0;
    // char state=0;
    PointWithTime *pwttemp=NULL;

    if (users==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
    // if ((path=(PointWithTime*)malloc(sizeof(PointWithTime)*NODE_NUM))==NULL)
    // {
    //     CloseSVGA();
    //     printf("memery error in main\n");
    //     exit(1);
    // }
    // if ((path1=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    // {
    //     CloseSVGA();
    //     printf("memery error in main\n");
    //     exit(1);
    // }
    // if ((path2=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    // {
    //     CloseSVGA();
    //     printf("memery error in main\n");
    //     exit(1);
    // }
    if ((rto=(RealTimeOrder*)malloc(sizeof(RealTimeOrder)*rtosize))==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
    if ((rto->path1=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
    if ((rto->path2=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
    if ((rto->path=(PointWithTime*)malloc(sizeof(PointWithTime)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("memery error in main\n");
        exit(1);
    }
   
    
    
    
   
    
    
    NewOrder(start,end,rto,&OrderNum);
    
    // printf("%ld",rto->initime);    
    // exit(1);
    // for ( i = 0; i < rto->pathSize; i++)
    // {
    //     printf("%d(%d,%d)\n",rto->path[i].time,rto->path[i].point.x,rto->path[i].point.y);
    // }
    
    // for ( i = 0; i < path_len2; i++)
    // {
    //     printf("\n%d(%d,%d) ",path2[i].location,path2[i].point.x,path2[i].point.y);
    // }
    // for ( i = 0; i < path_len1; i++)
    // {
    //     printf("\n%d(%d,%d) ",path1[i].location,path1[i].point.x,path1[i].point.y);
    // }
    // exit(1);
    // if ((temp=(BriefPoint*)realloc(path1,sizeof(BriefPoint)*path_len1))==NULL)
    // {
    //     CloseSVGA();
    //     free(path1);
    //     printf("memery error in main\n");
    //     exit(1);
    // }
    // path1=temp;
    // temp=NULL;
    // if ((temp=(BriefPoint*)realloc(path2,sizeof(BriefPoint)*path_len2))==NULL)
    // {
    //     CloseSVGA();
    //     free(path2);
    //     printf("memery error in main\n");
    //     exit(1);
    // }
    // path2=temp;
    // temp=NULL;
    // for ( i = 0; i < path_len1; i++)
    // {
    //     printf("%d(%d,%d)\n ",np1[i].location,np1[i].point.x,np1[i].point.y);
    // }
    // exit(1);
    if ((temp=(BriefPoint*)realloc(rto->path1,sizeof(BriefPoint)*rto->path_len1))==NULL)
    {
        CloseSVGA();
        free(rto->path1);
        printf("memery error in main\n");
        exit(1);
    }
    rto->path1=temp;
    temp=NULL;
    if ((temp=(BriefPoint*)realloc(rto->path2,sizeof(BriefPoint)*rto->path_len2))==NULL)
    {
        CloseSVGA();
        free(rto->path2);
        printf("memery error in main\n");
        exit(1);
    }
    rto->path2=temp;
    temp=NULL;
    if ((pwttemp=(PointWithTime*)realloc(rto->path,sizeof(PointWithTime)*rto->pathSize))==NULL)
    {
        CloseSVGA();
        free(rto->path);
        printf("memery error in main\n");
        exit(1);
    }
    rto->path=pwttemp;
    pwttemp=NULL;
    SetSVGA64k();
    mouse_init();
    while (1)
    {
        switch (flag)
        {
        case 0://欢迎界面
        
            welcome(&flag,users);
            break;
        
        case 1://注册界面
            reg(&flag);
            break;

        case 2://主菜单
            mainmenu(&flag);
            break;

        case 3://订单详情界面
            DetailedOrder(&flag,rto);
            break;

        case 13://忘记密码界面
            forget(&flag);
            break;    
        
        case 21://店铺界面
            food(&flag, users);
            break;    

        case 24://设置界面
            settings(&flag);
            break;
            
        default:
            break;
        }
    delay(15);
    }
    free(users);
    CloseSVGA();
    return 0;
}