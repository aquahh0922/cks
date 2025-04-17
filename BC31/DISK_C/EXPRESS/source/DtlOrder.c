#include "DtlOrder.h"

int DetailedOrder(int *flag,struct RealTimeOrder *rto,struct order *ord)
{
    char ch;
    char mapsize=1;
    int deltax=0,deltay=0,cx=CenterX,cy=CenterY;
    unsigned char i,CurrentPoint,SearchTime;
    unsigned int deltat,t=0;
    FloatCoordinate UnitVector;
    int maxy;
    char timeflag=0,roadflag=0;
    char DeliverAd[20];
    node n;
    FILE *fp;
    if ((fp=fopen("data\\node.dat","r"))==NULL)
    {
        CloseSVGA();
        printf("Cannot open node.txt\n");
        exit(1);
    }
    
    
    i=BinarySearch(&n,ord->delivery_address);
    fseek(fp,i*sizeof(n),SEEK_SET);
    fread(&n,sizeof(n),1,fp);
    strcpy(DeliverAd,n.name);
    fclose(fp);
    
    
    if (ord->state=SearchDeliver)
    {
        SearchTime=random_range(1,20);
    }
    
    
    mouse_off(&mouse);
    delay(100);
    
    drawMap(mapsize,cx,cy);
    // FillRoundedRectangle(50,BottomLow+10,924,80,5,0xffff);
    // puthz(55,BottomLow+10,"订单信息",32,32,0x0000);
    if (ord->state==Delivering)
    {
        for ( i = 0; i < rto->path_len2-1; i++)
        {
            ThickLine(cx+rto->path2[i].point.x-MapmidWidth,cy+rto->path2[i].point.y-MapmidHeight,cx+rto->path2[i+1].point.x-MapmidWidth,cy+rto->path2[i+1].point.y-MapmidHeight,26620,3);
        }

        for ( i = 0; i < rto->path_len1-1; i++)
        {
            ThickLine(cx+rto->path1[i].point.x-MapmidWidth,cy+rto->path1[i].point.y-MapmidHeight,cx+rto->path1[i+1].point.x-MapmidWidth,cy+rto->path1[i+1].point.y-MapmidHeight,3569,3);
        }
        roadflag=1;
    }
    else if (ord->state==Finished)
    {
        for ( i = 0; i < rto->pathSize-1; i++)
        {
            ThickLine(cx+rto->path[i].point.x-MapmidWidth,cy+rto->path[i].point.y-MapmidHeight,cx+rto->path[i+1].point.x-MapmidWidth,cy+rto->path[i+1].point.y-MapmidHeight,64704,3);
        }
        
    }
   
    
    
    

    mouse_on(mouse);
    // CloseSVGA();
    // for ( i = 0; i < rto->pathSize; i++)
    // {
    //     printf("%d(%d,%d)\n ",rto->path[i].time,rto->path[i].point.x,rto->path[i].point.y);
    // }
    // exit(1);
    while (1)
    {
        mouse_show(&mouse);
        mouse_off(&mouse);
        HandleMouseDrag(&deltax,&deltay,&mouse,10);
        mouse_on(mouse);

        if(kbhit())
        {
            ch=getch();
            if (ch=='='&&mapsize>=0)
            {
                mapsize--;
                if (cx > MapminWidth) 
                cx = MapminWidth;
                else if (cx < 1024 - MapminWidth)
                cx = 1024 - MapminWidth;

                if (cy > MapminHeight)
                cy = MapminHeight;
                else if (cy < 768 - MapminHeight)
                cy = 768 - MapminHeight;
                drawMap(mapsize,cx,cy);
            }
            else if (ch=='-'&&mapsize<=1)
            {
                mapsize++;
                if (cx > MapmidWidth) 
                cx = MapmidWidth;
                else if (cx < 1024 - MapmidWidth)
                cx = 1024 - MapmidWidth;

                if (cy > MapmidHeight)
                cy = MapmidHeight;
                else if (cy < 768 - MapmidHeight)
                cy = 768 - MapmidHeight;
                drawMap(mapsize,cx,cy);
            }
            else if (ch==27)//ESC键退出
            {
                break;
            }
            
            
            
        }
        if (ord->state=SearchDeliver)
        {
            time(&(rto->currentime));
            if (rto->currentime-rto->initime>SearchTime&&timeflag==0)
            {
                ord->state=Delivering;
                rto->initime=rto->currentime;
                timeflag=1;
            }
            
            
        }
        
        if (ord->state=Delivering)
        {
            time(&(rto->currentime));
            // CloseSVGA();
            // printf("%ld",rto->currentime);
            // exit(1);
            deltat=(int)(rto->currentime-rto->initime);
           
            
            CurrentPoint=0;
            t=0;
            while (CurrentPoint<rto->pathSize)
            {
                t+=rto->path[CurrentPoint].time;
                if (t>deltat)
                {
                
                    break;
                }
                CurrentPoint++;
            
            }
            if (CurrentPoint<rto->pathSize-1)
            {
                UnitVector.x=1.0*(rto->path[CurrentPoint+1].point.x-rto->path[CurrentPoint].point.x)/rto->path[CurrentPoint].time;
                UnitVector.y=1.0*(rto->path[CurrentPoint+1].point.y-rto->path[CurrentPoint].point.y)/rto->path[CurrentPoint].time;
            }
            else
            {
               ord->state=Finished;
            }
        }
        
        
        if(mapsize==0)
        {
            if (deltax!=0||deltay!=0)
            {
                cx+=deltax;
                cy+=deltay;
                 // 分别检查并限制x和y的边界
                if (cx > MapminWidth) 
                cx = MapminWidth;
                else if (cx < 1024 - MapminWidth)
                cx = 1024 - MapminWidth;

                if (cy > MapminHeight)
                cy = MapminHeight;
                else if (cy < BottomLow - MapminHeight)
                cy = BottomLow - MapminHeight;

                // 绘制图像
                mouse_off(&mouse);
                drawMap(mapsize,cx,cy);
               
                mouse_on(mouse);
                deltax = 0;
                deltay = 0;
            }
        }
        else if (mapsize==1)
        {
            if (deltax!=0||deltay!=0)
            {
                cx+=deltax;
                cy+=deltay;
                 // 分别检查并限制x和y的边界
                if (cx > MapmidWidth) 
                cx = MapmidWidth;
                else if (cx < 1024 - MapmidWidth)
                cx = 1024 - MapmidWidth;

                if (cy > MapmidHeight)
                cy = MapmidHeight;
                else if (cy < BottomLow - MapmidHeight)
                cy = BottomLow - MapmidHeight;

                // 绘制图像
                mouse_off(&mouse);
                
                
                // CloseSVGA();
                // printf("%d\n ",path_len2);
                // for ( i = 0; i < path_len2; i++)
                // {
                //     printf("%d(%d,%d)\n ",newpath2[i].location,newpath2[i].point.x,newpath2[i].point.y);
                // }
                // exit(1);
                drawMap(mapsize,cx,cy);
                if (ord->state==Delivering)
                {
                    for ( i = 0; i < rto->path_len2-1; i++)
                    {
                        ThickLine(cx+rto->path2[i].point.x-MapmidWidth,cy+rto->path2[i].point.y-MapmidHeight,cx+rto->path2[i+1].point.x-MapmidWidth,cy+rto->path2[i+1].point.y-MapmidHeight,26620,3);
                    }

                    for ( i = 0; i < rto->path_len1-1; i++)
                    {
                        ThickLine(cx+rto->path1[i].point.x-MapmidWidth,cy+rto->path1[i].point.y-MapmidHeight,cx+rto->path1[i+1].point.x-MapmidWidth,cy+rto->path1[i+1].point.y-MapmidHeight,3569,3);
                    }
                }
                
                
                
                // if (*OrderState==0)
                // {
                //     for ( i = 0; i < CurrentPoint; i++)
                //     {
                //         ThickLine(cx+pwt[i].point.x-MapmidWidth,cy+pwt[i].point.y-MapmidHeight,cx+pwt[i+1].point.x-MapmidWidth,cy+pwt[i+1].point.y-MapmidHeight,64704,3);
                //     }
                //     ThickLine(cx+pwt[CurrentPoint].point.x-MapmidWidth,cy+pwt[CurrentPoint].point.y-MapmidHeight,cx+pwt[CurrentPoint].point.x+UnitVector.x*(t-deltat)-MapmidWidth,cy+pwt[CurrentPoint].point.y+UnitVector.y*(t-deltat)-MapmidHeight,64704,3);
                // }
                if (ord->state==Finished)
                {
                    for ( i = 0; i < rto->pathSize-1; i++)
                    {
                        ThickLine(cx+rto->path[i].point.x-MapmidWidth,cy+rto->path[i].point.y-MapmidHeight,cx+rto->path[i+1].point.x-MapmidWidth,cy+rto->path[i+1].point.y-MapmidHeight,64704,3);
                    }
                    
                }
                bar1(0, BottomLow, 1024, 768, 54938);
              
                mouse_on(mouse);
                // CloseSVGA();
                // for ( i = 0; i < path_len; i++)
                // {
                //     printf("(%d,%d)\n ",pc[i].x,pc[i].y);
                // }
                // exit(1);
                deltax = 0;
                deltay = 0;
            }
            mouse_off(&mouse);
            if (ord->state==Delivering&&roadflag==0)
            {
                for ( i = 0; i < rto->path_len2-1; i++)
                {
                    ThickLine(cx+rto->path2[i].point.x-MapmidWidth,cy+rto->path2[i].point.y-MapmidHeight,cx+rto->path2[i+1].point.x-MapmidWidth,cy+rto->path2[i+1].point.y-MapmidHeight,26620,3);
                }

                for ( i = 0; i < rto->path_len1-1; i++)
                {
                    ThickLine(cx+rto->path1[i].point.x-MapmidWidth,cy+rto->path1[i].point.y-MapmidHeight,cx+rto->path1[i+1].point.x-MapmidWidth,cy+rto->path1[i+1].point.y-MapmidHeight,3569,3);
                }
        
            }
            if (ord->state==Delivering)
            {   
                maxy=cy+rto->path[0].point.y-MapmidHeight;
                for ( i = 0; i < CurrentPoint; i++)
                {   
                    
                    ThickLine(cx+rto->path[i].point.x-MapmidWidth,cy+rto->path[i].point.y-MapmidHeight,cx+rto->path[i+1].point.x-MapmidWidth,cy+rto->path[i+1].point.y-MapmidHeight,64704,3);
                    if (cy+rto->path[i+1].point.y-MapmidHeight>maxy)
                    {
                        maxy=cy+rto->path[i+1].point.y-MapmidHeight;
                    }
                    
                }
                
                if ((int)(cy+rto->path[CurrentPoint].point.y+UnitVector.y*(deltat-t+rto->path[CurrentPoint].time)+0.5)-MapmidHeight>maxy)
                {
                    maxy=(int)(cy+rto->path[CurrentPoint].point.y+UnitVector.y*(deltat-t+rto->path[CurrentPoint].time)+0.5)-MapmidHeight;
                }
                
                ThickLine(cx+rto->path[CurrentPoint].point.x-MapmidWidth,cy+rto->path[CurrentPoint].point.y-MapmidHeight,(int)(cx+rto->path[CurrentPoint].point.x+UnitVector.x*(deltat-t+rto->path[CurrentPoint].time)+0.5)-MapmidWidth,(int)(cy+rto->path[CurrentPoint].point.y+UnitVector.y*(deltat-t+rto->path[CurrentPoint].time)+0.5)-MapmidHeight,64704,3);
            }
            // CloseSVGA();
            // printf("%d\n ",maxy);
            // exit(1);
            if (maxy>BottomLow)
            {
                bar1(0, BottomLow, 1024, 768, 54938);
    
            }
            
            mouse_on(mouse);
        }
        
        
        
        
        delay(15);
    }
    // free(newpath2);
    // free(newpath);
    *flag=2;
    return 0;
}


void drawDetailedOrder()
{
    
    bar1(0, 0, 1024, 768, 54938);
    
}


void drawMap(char mode,int cx,int cy)
{
    if (mode==0)//大地图
    {
        Readbmp64k(cx-MapminWidth, cy-MapminHeight, "img\\mapmin1.bmp");
        Readbmp64k(cx, cy-MapminHeight, "img\\mapmin2.bmp");
        Readbmp64k(cx-MapminWidth, cy, "img\\mapmin3.bmp");
        Readbmp64k(cx, cy, "img\\mapmin4.bmp");
        bar1(0, BottomLow, 1024, 768, 54938);
    }
    else if (mode==1)//大地图缩小1.5倍
    {
        Readbmp64k(cx-MapmidWidth, cy-MapmidHeight, "img\\mapmid1.bmp");
        Readbmp64k(cx, cy-MapmidHeight, "img\\mapmid2.bmp");
        Readbmp64k(cx-MapmidWidth, cy, "img\\mapmid3.bmp");
        Readbmp64k(cx, cy, "img\\mapmid4.bmp");
        bar1(0, BottomLow, 1024, 768, 54938);
    }
   
    
}

int BinarySearch(struct node *p,int num)
{
    int low=0,high=NODE_NUM-1,mid;
    while (low<=high)
    {
        mid=(low+high)/2;
        if (p[mid].num==num)
        {
            return mid;
        }
        else if (p[mid].num<num)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}

int random_range(int min, int max) 
{
    int temp,range,limit,random_num;
    // 确保max >= min
    if(max < min) {
        temp = max;
        max = min;
        min = temp;
    }
    
    // 计算范围大小
    range = max - min + 1;
    
    // 限制随机数在[0, RAND_MAX]范围内，且能被range整除
    limit = RAND_MAX - (RAND_MAX % range);
    
    // 生成随机数，直到它在[0, limit]范围内
    do {
        random_num = rand();
    } while(random_num > limit); // 丢弃超出limit的值以保证均匀分布
    
    return min + (random_num % range);
}

int NewOrder(struct RealTimeOrder *rto,unsigned char *OrderNum,struct order *ord)
{
    FILE *fp;
    node *pn;
    road *pr;
    Graph *graph;
    RandomPoint *rp;
    BriefPoint *path,*path2,temp,*newpath,*newpath2;
    int *prev;
    int shortest,shortest2,current,index;
    unsigned char path_len,i,path_len2;
    if ((fp=fopen("data\\road.dat","rb"))==NULL)//打开文件
    {
        CloseSVGA();
        printf("Cannot open raod\n");
        exit(1);
    }
    if((pr=(road*)malloc(sizeof(road)))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc road\n");
        exit(1);
    }
    if ((graph=(Graph*)malloc(sizeof(Graph)))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc graph\n");
        exit(1);
    }
    if ((prev=(int*)malloc(sizeof(int)*MAX_V))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc prev\n");
        exit(1);
    }
    
    if ((rp=(RandomPoint*)malloc(sizeof(RandomPoint)*6))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc RandomPoint\n");
        exit(1);
    }
    
    
   
    
   
    
    
    
    initGraph(graph, MAX_V);
    
    
    while (fread(pr,sizeof(road),1,fp)==1)//读取文件
    {
        addEdge(graph,pr->node1,pr->node2,pr->distance);
       
    }
    
    srand(time(NULL));
    for ( i = 0; i < 6; i++)
    {
        rp[i].location=random_range(1,59);
        rp[i].shortest=dijkstra(graph,rp[i].location,ord->payment_address,prev);
    }
    // CloseSVGA();
    //     for ( i = 0; i < 6; i++)
    //     {
    //         printf("%d\n ",rp[i].location);
    //     }
    //     exit(1);
    shortest2=rp[0].shortest;
    index=rp[0].location;
    for ( i = 1; i < 6; i++)
    {
        
        if (rp[i].shortest<shortest2)
        {
            shortest2=rp[i].shortest;
            index=rp[i].location;
            
        }
        
    }
    free(rp);
    for ( i = 0; i < MAX_V; i++)
    {
        prev[i]=-1;
    }
    if ((path2=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc path2\n");
        exit(1);
    }
    shortest2=dijkstra(graph,index,ord->payment_address,prev);
    

    if (shortest2!=INT_MAX)
    {
        current=ord->payment_address;    
        path_len2=0;
        while (current!=-1)
        {
            path2[path_len2++].location=current;
            current=prev[current];
        }
        
        for ( i = 0; i < path_len2/2; i++)
        {
            temp=path2[i];
            path2[i]=path2[path_len2-i-1];
            path2[path_len2-i-1]=temp;
        }
        
    }
    
    if ((newpath2=(BriefPoint*)realloc(path2,sizeof(BriefPoint)*path_len2))==NULL)
    {
        CloseSVGA();
        free(path2);
        printf("Cannot realloc path2\n");
        exit(1);
    }
  
    
    for ( i = 0; i < MAX_V; i++)
    {
        prev[i]=-1;
    }

    shortest=dijkstra(graph,ord->payment_address,ord->delivery_address,prev);

    if ((path=(BriefPoint*)malloc(sizeof(BriefPoint)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc path\n");
        exit(1);
    }
   
    
    if (shortest!=INT_MAX)
    {
        current=ord->delivery_address;    
        path_len=0;
        while (current!=-1)
        {
            path[path_len++].location=current;
            current=prev[current];
        }
        
        // CloseSVGA();
        // for ( i = 0; i < path_len; i++)
        // {
        //     printf("%d\n ",path[i]);
        // }
        // exit(1);
        for ( i = 0; i < path_len/2; i++)
        {
            temp=path[i];
            path[i]=path[path_len-i-1];
            path[path_len-i-1]=temp;
        }
        // CloseSVGA();
        // for ( i = 0; i < path_len; i++)
        // {
        //     printf("%d\n ",path[i]);
        // }
        // exit(1);
    }
    if ((newpath=(BriefPoint*)realloc(path,sizeof(BriefPoint)*path_len))==NULL)
    {
        CloseSVGA();
        free(path);
        printf("Cannot realloc path\n");
        exit(1);
    }
   
    
    free(graph);
    free(prev);
    fclose(fp);
    fp=NULL;
    if ((pn=(node*)malloc(sizeof(node)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc node\n");
        exit(1);
    }
    if ((fp=fopen("data\\node.dat","rb"))==NULL)//打开文件
    {
        CloseSVGA();
        printf("Cannot open node\n");
        exit(1);
    }
   
    // for ( i = 0; i < MAX_V; i++)
    // {
    //     fread(&pn[i],sizeof(node),1,fp);//读取文件
       
    // }
    i=0;
    while (i<NODE_NUM&&fread(&pn[i],sizeof(node),1,fp)==1)//读取文件
    {
        i++;
        
    }
    
    
    fclose(fp);//关闭文件
    fp=NULL;
    // CloseSVGA();
    //     for ( i = 0; i < NODE_NUM; i++)
    //     {
    //         printf("%d_(%d,%d)\n ",pn[i].num,pn[i].point.x,pn[i].point.y);
    //     }
    //     exit(1);
    for ( i = 0; i < path_len; i++)
    {
        index=BinarySearch(pn,newpath[i].location);
        if (index==-1)
        {
            CloseSVGA();
            printf("Cannot find node %d\n",path[i]);
            exit(1);
        }
    
        newpath[i].point=pn[index].point;
        
        
    }

    for ( i = 0; i < path_len2; i++)
    {
        index=BinarySearch(pn,newpath2[i].location);
        if (index==-1)
        {
            CloseSVGA();
            printf("Cannot find node %d\n",path[i]);
            exit(1);
        }
    
        newpath2[i].point=pn[index].point;
        
        
    }
    
    // CloseSVGA();
    // for ( i = 0; i < path_len; i++)
    // {
    //     printf("%d(%d,%d)\n ",newpath[i].location,newpath[i].point.x,newpath[i].point.y);
    // }
    // exit(1);
    free(pn);
    rto->path_len1=path_len;
    rto->path_len2=path_len2;
    rto->pathSize=path_len+path_len2-1;
    rto->shorttime=shortest+shortest2;
    
    if ((fp=fopen("data\\road.dat","rb"))==NULL)//打开文件
    {
        CloseSVGA();
        printf("Cannot open raod\n");
        exit(1);
    }
    for ( i = 0; i < path_len2-1; i++)
    {
        rto->path[i].point=newpath2[i].point;
        rewind(fp);//将文件指针移到文件开头
        while (fread(pr,sizeof(road),1,fp)==1)//读取文件
        {
            if ((pr->node1==newpath2[i].location&&pr->node2==newpath2[i+1].location)||(pr->node2==newpath2[i].location&&pr->node1==newpath2[i+1].location))
            {
                rto->path[i].time=pr->distance;
                break;
            }
            
        }
        
    }
    for ( i = path_len2-1; i < rto->pathSize-1; i++)
    {
        rto->path[i].point=newpath[i-path_len2+1].point;
        rewind(fp);//将文件指针移到文件开头
        while (fread(pr,sizeof(road),1,fp)==1)//读取文件
        {
            if ((pr->node1==newpath[i-path_len2+1].location&&pr->node2==newpath[i-path_len2+2].location)||(pr->node2==newpath[i-path_len2+1].location&&pr->node1==newpath[i-path_len2+2].location))
            {
                rto->path[i].time=pr->distance;
                break;
            }
            
        }
        
        
    }
    rto->path[rto->pathSize-1].point=newpath[path_len-1].point;
    for ( i = 0; i < path_len; i++)
    {
        rto->path1[i]=newpath[i];
    }
    for ( i = 0; i < path_len2; i++)
    {
        rto->path2[i]=newpath2[i];
    }
    
    free(newpath2);
    free(newpath);
    fclose(fp);//关闭文件
    free(pr);
    time(&(rto->initime));
    ord->state=SearchDeliver;
}

// void interrupt newTimerISR(...) {
//     timerTicks++;
//     // 约 55ms 触发一次 (18.2 Hz)
//     if (timerTicks % 18 == 0) { // 约 1 秒更新一次
//         if (path != NULL && currentNode < pathSize - 1) {
//             totalTime += 1.0;
//             // 计算是否移动到下一节点
//             if (totalTime >= path[currentNode].time) {
//                 totalTime = 0;
//                 currentNode++;
//             }
//             redrawFlag = 1; // 触发重绘
//         }
//     }
//     oldTimerISR(); // 调用原始中断
// }