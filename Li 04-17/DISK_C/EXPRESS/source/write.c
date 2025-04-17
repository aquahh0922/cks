#include"write.h"

void nodewrite()
{
    FILE *fp;
  
    node *p;

    if ((fp=fopen("data\\node.dat","wb"))==NULL)//打开文件
    {
        CloseSVGA();
        printf("Cannot open node\n");
        exit(1);
    }
    if((p=(node*)malloc(sizeof(node)*NODE_NUM))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc node\n");
        exit(1);
    }
    p[0].num=1; 
    p[0].point.x=668;
    p[0].point.y=6;
    strcpy(p[0].name,"\0");
    p[0].type=0;
    p[1].num=2;
    p[1].point.x=711;
    p[1].point.y=11;
    strcpy(p[1].name,"\0");
    p[1].type=0;
    p[2].num=3;
    p[2].point.x=718;
    p[2].point.y=20;
    strcpy(p[2].name,"\0");
    p[2].type=1;
    p[3].num=4;
    p[3].point.x=718;
    p[3].point.y=33;
    strcpy(p[3].name,"\0");
    p[3].type=1;
    p[4].num=5;
    p[4].point.x=718;
    p[4].point.y=42;
    strcpy(p[4].name,"\0");
    p[4].type=1;
    p[5].num=6;
    p[5].point.x=724;
    p[5].point.y=66;
    strcpy(p[5].name,"\0");
    p[5].type=2;
    p[6].num=7;
    p[6].point.x=661;
    p[6].point.y=55;
    strcpy(p[6].name,"\0");
    p[6].type=1;
    p[7].num=8;
    p[7].point.x=648;
    p[7].point.y=59;
    strcpy(p[7].name,"\0");
    p[7].type=0;

    p[8].num=9;
    p[8].point.x=643;
    p[8].point.y=76;
    strcpy(p[8].name,"\0");
    p[8].type=1;

    p[9].num=10;
    p[9].point.x=736;
    p[9].point.y=87;
    strcpy(p[9].name,"\0");
    p[9].type=1;

    p[10].num=11;
    p[10].point.x=683;
    p[10].point.y=83;
    strcpy(p[10].name,"\0");
    p[10].type=1;

    p[11].num=12;
    p[11].point.x=678;
    p[11].point.y=103;
    strcpy(p[11].name,"\0");
    p[11].type=0;

    p[12].num=13;
    p[12].point.x=641;
    p[12].point.y=101;
    strcpy(p[12].name,"\0");
    p[12].type=1;

    p[13].num=14;
    p[13].point.x=758;
    p[13].point.y=117;
    strcpy(p[13].name,"\0");
    p[13].type=2;

    p[14].num=15;
    p[14].point.x=639;
    p[14].point.y=124;
    strcpy(p[14].name,"\0");
    p[14].type=1;

    p[15].num=16;
    p[15].point.x=759;
    p[15].point.y=139;
    strcpy(p[15].name,"\0");
    p[15].type=2;

    p[16].num=17;
    p[16].point.x=803;
    p[16].point.y=138;
    strcpy(p[16].name,"\0");
    p[16].type=1;

    p[17].num=18;
    p[17].point.x=822;
    p[17].point.y=147;
    strcpy(p[17].name,"\0");
    p[17].type=1;

    p[18].num=19;
    p[18].point.x=843;
    p[18].point.y=149;
    strcpy(p[18].name,"\0");
    p[18].type=0;

    p[19].num=20;
    p[19].point.x=840;
    p[19].point.y=176;
    strcpy(p[19].name,"\0");
    p[19].type=2;

    p[20].num=21;
    p[20].point.x=816;
    p[20].point.y=174;
    strcpy(p[20].name,"\0");
    p[20].type=1;

    p[21].num=22;
    p[21].point.x=757;
    p[21].point.y=166;
    strcpy(p[21].name,"\0");
    p[21].type=2;

    p[22].num=23;
    p[22].point.x=837;
    p[22].point.y=199;
    strcpy(p[22].name,"\0");
    p[22].type=1;

    p[23].num=24;
    p[23].point.x=831;
    p[23].point.y=198;
    strcpy(p[23].name,"\0");
    p[23].type=1;

    p[24].num=25;
    p[24].point.x=814;
    p[24].point.y=196;
    strcpy(p[24].name,"\0");
    p[24].type=1;

    p[25].num=26;
    p[25].point.x=754;
    p[25].point.y=191;
    strcpy(p[25].name,"\0");
    p[25].type=2;

    p[26].num=27;
    p[26].point.x=638;
    p[26].point.y=180;
    strcpy(p[26].name,"\0");
    p[26].type=3;

    p[27].num=28;
    p[27].point.x=628;
    p[27].point.y=293;
    strcpy(p[27].name,"\0");
    p[27].type=1;

    p[28].num=29;
    p[28].point.x=689;
    p[28].point.y=297;
    strcpy(p[28].name,"\0");
    p[28].type=1;

    p[29].num=30;
    p[29].point.x=744;
    p[29].point.y=302;
    strcpy(p[29].name,"\0");
    p[29].type=1;

    p[30].num=31;
    p[30].point.x=772;
    p[30].point.y=306;
    strcpy(p[30].name,"\0");
    p[30].type=1;

    p[31].num=32;
    p[31].point.x=834;
    p[31].point.y=312;
    strcpy(p[31].name,"\0");
    p[31].type=1;

    p[32].num=33;
    p[32].point.x=876;
    p[32].point.y=316;
    strcpy(p[32].name,"\0");
    p[32].type=1;

    p[33].num=34;
    p[33].point.x=619;
    p[33].point.y=379;
    strcpy(p[33].name,"\0");
    p[33].type=1;

    p[34].num=35;
    p[34].point.x=760;
    p[34].point.y=393;
    strcpy(p[34].name,"\0");
    p[34].type=1;

    p[35].num=36;
    p[35].point.x=614;
    p[35].point.y=417;
    strcpy(p[35].name,"\0");
    p[35].type=1;

    p[36].num=37;
    p[36].point.x=760;
    p[36].point.y=434;
    strcpy(p[36].name,"\0");
    p[36].type=1;

    p[37].num=38;
    p[37].point.x=669;
    p[37].point.y=424;
    strcpy(p[37].name,"\0");
    p[37].type=1;

    p[38].num=39;
    p[38].point.x=709;
    p[38].point.y=432;
    strcpy(p[38].name,"\0");
    p[38].type=1;

    p[39].num=40;
    p[39].point.x=612;
    p[39].point.y=451;
    strcpy(p[39].name,"\0");
    p[39].type=1;

    p[40].num=41;
    p[40].point.x=666;
    p[40].point.y=457;
    strcpy(p[40].name,"\0");
    p[40].type=2;

    p[41].num=42;
    p[41].point.x=705;
    p[41].point.y=461;
    strcpy(p[41].name,"\0");
    p[41].type=1;

    p[42].num=43;
    p[42].point.x=608;
    p[42].point.y=486;
    strcpy(p[42].name,"\0");
    p[42].type=1;

    p[43].num=44;
    p[43].point.x=604;
    p[43].point.y=519;
    strcpy(p[43].name,"\0");
    p[43].type=1;

    p[44].num=45;
    p[44].point.x=580;
    p[44].point.y=760;
    strcpy(p[44].name,"\0");
    p[44].type=4;

    p[45].num=46;
    p[45].point.x=665;
    p[45].point.y=771;
    strcpy(p[45].name,"\0");
    p[45].type=4;

    p[46].num=47;
    p[46].point.x=465;
    p[46].point.y=508;
    strcpy(p[46].name,"\0");
    p[46].type=4;

    p[47].num=48;
    p[47].point.x=462;
    p[47].point.y=162;
    strcpy(p[47].name,"\0");
    p[47].type=3;
    
    p[48].num=49;
    p[48].point.x=632;
    p[48].point.y=182;
    strcpy(p[48].name,"\0");
    p[48].type=1;

    p[49].num=50;
    p[49].point.x=905;
    p[49].point.y=208;
    strcpy(p[49].name,"\0");
    p[49].type=0;

    p[50].num=51;
    p[50].point.x=751;
    p[50].point.y=466;
    strcpy(p[50].name,"\0");
    p[50].type=0;

    p[51].num=52;
    p[51].point.x=758;
    p[51].point.y=459;
    strcpy(p[51].name,"\0");
    p[51].type=0;

    p[52].num=53;
    p[52].point.x=900;
    p[52].point.y=290;
    strcpy(p[52].name,"\0");
    p[52].type=0;

    p[53].num=54;
    p[53].point.x=884;
    p[53].point.y=316;
    strcpy(p[53].name,"\0");
    p[53].type=0;

    p[54].num=55;
    p[54].point.x=662;
    p[54].point.y=423;
    strcpy(p[54].name,"\0");
    p[54].type=0;

    p[55].num=56;
    p[55].point.x=686;
    p[55].point.y=622;
    strcpy(p[55].name,"\0");
    p[55].type=0;

    p[56].num=57;
    p[56].point.x=662;
    p[56].point.y=489;
    strcpy(p[56].name,"\0");
    p[56].type=1;

    p[57].num=58;
    p[57].point.x=705;
    p[57].point.y=484;
    strcpy(p[57].name,"\0");
    p[57].type=1;

    p[58].num=59;
    p[58].point.x=681;
    p[58].point.y=490;
    strcpy(p[58].name,"\0");
    p[58].type=1;

    p[59].num=101;
    p[59].point.x=729;
    p[59].point.y=44;
    strcpy(p[59].name,"韵苑学生公寓25栋");
    p[59].type=5;

    p[60].num=102;
    p[60].point.x=317;
    p[60].point.y=131;
    strcpy(p[60].name,"东九教学楼");
    p[60].type=5;

    p[61].num=103;
    p[61].point.x=665;
    p[61].point.y=296;
    strcpy(p[61].name,"东十二教学楼");
    p[61].type=5;

    p[62].num=104;
    p[62].point.x=704;
    p[62].point.y=31;
    strcpy(p[62].name,"韵苑学生公寓26栋");
    p[62].type=5;

    p[63].num=105;
    p[63].point.x=878;
    p[63].point.y=179;
    strcpy(p[63].name,"韵苑学生公寓19栋");
    p[63].type=5;

    p[64].num=106;
    p[64].point.x=645;
    p[64].point.y=179;
    strcpy(p[64].name,"韵苑学生公寓5栋");
    p[64].type=5;

    p[65].num=107;
    p[65].point.x=651;
    p[65].point.y=68;
    strcpy(p[65].name,"韵苑学生公寓10栋");
    p[65].type=5;

    p[66].num=201;
    p[66].point.x=624;
    p[66].point.y=333;
    strcpy(p[66].name,"学生二食堂");
    p[66].type=4;

    p[67].num=202;
    p[67].point.x=619;
    p[67].point.y=372;
    strcpy(p[67].name,"学生一食堂");
    p[67].type=4;

    p[68].num=203;
    p[68].point.x=612;
    p[68].point.y=433;
    strcpy(p[68].name,"东校区CBD");
    p[68].type=4;

    p[69].num=204;
    p[69].point.x=621;
    p[69].point.y=360;
    strcpy(p[69].name,"韵苑学生公寓1栋");
    p[69].type=4;

    p[70].num=205;
    p[70].point.x=623;
    p[70].point.y=337;
    strcpy(p[70].name,"韵苑学生公寓2栋");
    p[70].type=4;

    p[71].num=206;
    p[71].point.x=626;
    p[71].point.y=307;
    strcpy(p[71].name,"韵苑学生公寓3栋");
    p[71].type=4;

    p[72].num=207;
    p[72].point.x=586;
    p[72].point.y=686;
    strcpy(p[72].name,"东教工食堂");
    p[72].type=4;

    p[73].num=208;
    p[73].point.x=624;
    p[73].point.y=179;
    strcpy(p[73].name,"韵苑食堂");
    p[73].type=4;

    p[74].num=209;
    p[74].point.x=836;
    p[74].point.y=213;
    strcpy(p[74].name,"东园食堂");
    p[74].type=4;

    fwrite(p,sizeof(node),NODE_NUM,fp);//写入文件
    fclose(fp);//关闭文件
    free(p);//释放内存
    
}

void roadwrite()
{
    FILE *fp;
  
    road *p;
    
    if ((fp=fopen("data\\road.dat","wb"))==NULL)//打开文件
    {
        CloseSVGA();
        printf("Cannot open road\n");
        exit(1);
    }
    if((p=(road*)malloc(sizeof(road)*ROAD_NUM))==NULL)
    {
        CloseSVGA();
        printf("Cannot malloc road\n");
        exit(1);
    }
    p[0].node1=1;
    p[0].node2=2;
    p[0].distance=14;

    p[1].node1=1;
    p[1].node2=7;
    p[1].distance=15;

    p[2].node1=2;
    p[2].node2=3;
    p[2].distance=3;

    p[3].node1=3;
    p[3].node2=4;
    p[3].distance=5;

    p[4].node1=4;
    p[4].node2=5;
    p[4].distance=4;

    p[89].node1=4;
    p[89].node2=104;
    p[89].distance=3;

    p[5].node1=5;
    p[5].node2=6;
    p[5].distance=8;

    p[83].node1=5;
    p[83].node2=101;
    p[83].distance=3;

    p[6].node1=6;
    p[6].node2=7;
    p[6].distance=20;

    p[7].node1=6;
    p[7].node2=10;
    p[7].distance=6;

    p[8].node1=7;
    p[8].node2=8;
    p[8].distance=4;

    p[9].node1=8;
    p[9].node2=9;
    p[9].distance=5;

    p[10].node1=9;
    p[10].node2=11;
    p[10].distance=12;

    p[11].node1=9;
    p[11].node2=13;
    p[11].distance=8;

    p[92].node1=9;
    p[92].node2=107;
    p[92].distance=3;

    p[12].node1=10;
    p[12].node2=11;
    p[12].distance=18;

    p[13].node1=10;
    p[13].node2=14;
    p[13].distance=10;

    p[14].node1=11;
    p[14].node2=12;
    p[14].distance=8;

    p[15].node1=12;
    p[15].node2=13;
    p[15].distance=11;

    p[16].node1=13;
    p[16].node2=15;
    p[16].distance=6;

    p[84].node1=14;
    p[84].node2=16;
    p[84].distance=5;

    p[17].node1=14;
    p[17].node2=17;
    p[17].distance=12;

    p[18].node1=15;
    p[18].node2=16;
    p[18].distance=28;

    p[19].node1=15;
    p[19].node2=49;
    p[19].distance=16;

    p[20].node1=16;
    p[20].node2=17;
    p[20].distance=15;

    p[21].node1=16;
    p[21].node2=22;
    p[21].distance=6;

    p[22].node1=17;
    p[22].node2=18;
    p[22].distance=4;

    p[23].node1=18;
    p[23].node2=19;
    p[23].distance=4;

    p[24].node1=18;
    p[24].node2=21;
    p[24].distance=7;

    p[25].node1=19;
    p[25].node2=20;
    p[25].distance=7;

    p[26].node1=20;
    p[26].node2=21;
    p[26].distance=5;

    p[27].node1=20;
    p[27].node2=23;
    p[27].distance=6;

    p[90].node1=20;
    p[90].node2=105;
    p[90].distance=6;

    p[28].node1=21;
    p[28].node2=22;
    p[28].distance=17;

    p[29].node1=21;
    p[29].node2=25;
    p[29].distance=5;

    p[30].node1=22;
    p[30].node2=26;
    p[30].distance=6;

    p[31].node1=23;
    p[31].node2=24;
    p[31].distance=2;

    p[32].node1=23;
    p[32].node2=50;
    p[32].distance=20;

    p[85].node1=23;
    p[85].node2=209;
    p[85].distance=2;

    p[33].node1=24;
    p[33].node2=25;
    p[33].distance=4;

    p[34].node1=24;
    p[34].node2=32;
    p[34].distance=30;

    p[35].node1=25;
    p[35].node2=26;
    p[35].distance=16;

    p[36].node1=26;
    p[36].node2=27;
    p[36].distance=30;

    p[37].node1=26;
    p[37].node2=30;
    p[37].distance=30;

    p[38].node1=27;
    p[38].node2=28;
    p[38].distance=32;

    p[39].node1=27;
    p[39].node2=49;
    p[39].distance=3;

    p[40].node1=28;
    p[40].node2=103;
    p[40].distance=8;

    p[41].node1=28;
    p[41].node2=206;
    p[41].distance=3;

    p[42].node1=29;
    p[42].node2=30;
    p[42].distance=12;

    p[43].node1=29;
    p[43].node2=103;
    p[43].distance=6;

    p[44].node1=30;
    p[44].node2=31;
    p[44].distance=6;

    p[45].node1=31;
    p[45].node2=32;
    p[45].distance=12;

    p[46].node1=31;
    p[46].node2=35;
    p[46].distance=24;

    p[47].node1=32;
    p[47].node2=33;
    p[47].distance=8;

    p[48].node1=33;
    p[48].node2=54;
    p[48].distance=3;

    p[49].node1=34;
    p[49].node2=35;
    p[49].distance=38;

    p[50].node1=34;
    p[50].node2=202;
    p[50].distance=3;

    p[51].node1=34;
    p[51].node2=36;
    p[51].distance=10;

    p[52].node1=35;
    p[52].node2=37;
    p[52].distance=10;

    p[53].node1=36;
    p[53].node2=55;
    p[53].distance=8;

    p[54].node1=36;
    p[54].node2=203;
    p[54].distance=2;

    p[55].node1=37;
    p[55].node2=39;
    p[55].distance=13;

    p[56].node1=37;
    p[56].node2=52;
    p[56].distance=5;

    p[57].node1=38;
    p[57].node2=39;
    p[57].distance=10;

    p[58].node1=38;
    p[58].node2=41;
    p[58].distance=8;

    p[59].node1=38;
    p[59].node2=55;
    p[59].distance=3;

    p[60].node1=39;
    p[60].node2=42;
    p[60].distance=8;

    p[61].node1=40;
    p[61].node2=41;
    p[61].distance=13;

    p[62].node1=40;
    p[62].node2=43;
    p[62].distance=8;

    p[63].node1=40;
    p[63].node2=203;
    p[63].distance=7;

    p[64].node1=41;
    p[64].node2=42;
    p[64].distance=10;

    p[65].node1=41;
    p[65].node2=57;
    p[65].distance=8;

    p[66].node1=42;
    p[66].node2=58;
    p[66].distance=6;
    
    p[67].node1=43;
    p[67].node2=44;
    p[67].distance=8;

    p[68].node1=43;
    p[68].node2=57;
    p[68].distance=13;

    p[69].node1=44;
    p[69].node2=47;
    p[69].distance=30;

    p[70].node1=44;
    p[70].node2=207;
    p[70].distance=60;

    p[71].node1=45;
    p[71].node2=207;
    p[71].distance=25;

    p[72].node1=46;
    p[72].node2=56;
    p[72].distance=50;

    p[73].node1=48;
    p[73].node2=102;
    p[73].distance=30;

    p[74].node1=48;
    p[74].node2=208;
    p[74].distance=60;

    p[91].node1=49;
    p[91].node2=106;
    p[91].distance=3;

    p[75].node1=49;
    p[75].node2=208;
    p[75].distance=2;

    p[85].node1=50;
    p[85].node2=53;
    p[85].distance=16;

    p[76].node1=51;
    p[76].node2=52;
    p[76].distance=2;

    p[77].node1=51;
    p[77].node2=58;
    p[77].distance=10;

    p[78].node1=53;
    p[78].node2=54;
    p[78].distance=8;

    p[86].node1=56;
    p[86].node2=59;
    p[86].distance=30;

    p[87].node1=57;
    p[87].node2=59;
    p[87].distance=4;

    p[88].node1=58;
    p[88].node2=59;
    p[88].distance=6;

    p[79].node1=201;
    p[79].node2=205;
    p[79].distance=3;

    p[80].node1=201;
    p[80].node2=206;
    p[80].distance=4;

    p[81].node1=202;
    p[81].node2=204;
    p[81].distance=2;

    p[82].node1=204;
    p[82].node2=205;
    p[82].distance=4;

    

    // for ( ; i < ROAD_NUM; i++)
    // {
    //     // fwrite(&p[i],sizeof(road),1,fp);//写入文件
    //     fwrite(&p[i].node1, sizeof(int), 1, fp);
    //     fwrite(&p[i].node2, sizeof(int), 1, fp);
    //     fwrite(&p[i].distance, sizeof(int), 1, fp);
    // }
    fwrite(p, sizeof(road), ROAD_NUM, fp);//写入文件
    fclose(fp);//关闭文件
    free(p);//释放内存
}
    
