#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;//画好魔方展开图
int rx[3][4]={{0,1,2,3},{4,21,14,19},{7,20,13,18}};//代表每种旋转方式所能变动的点
int ry[3][4]={{4,5,6,7},{1,17,11,21},{2,18,8,22}};
int rz[3][4]={{16,17,18,19},{0,12,8,4},{1,13,9,5}};
char rgb[6]={'g','r','b','o','w','y'};//分别对应0-5
void chan(char t,int m[24])
{
    int tm[24];
    for(int i=0;i<24;i++)
        tm[i]=m[i];
        //每次在上次变化之后再操作。
    if(t=='x')
    {
        for(int i=0;i<3;i++)
        {
            tm[rx[i][0]]=m[rx[i][3]];
            tm[rx[i][1]]=m[rx[i][0]];
            tm[rx[i][2]]=m[rx[i][1]];
            tm[rx[i][3]]=m[rx[i][2]];
        }
    }
    else if(t=='y')
    {
        for(int i=0;i<3;i++)
        {
            tm[ry[i][0]]=m[ry[i][3]];
            tm[ry[i][1]]=m[ry[i][0]];
            tm[ry[i][2]]=m[ry[i][1]];
            tm[ry[i][3]]=m[ry[i][2]];
        }
    }
    else if(t=='z')
    {
        for(int i=0;i<3;i++)
        {
            tm[rz[i][0]]=m[rz[i][3]];
            tm[rz[i][1]]=m[rz[i][0]];
            tm[rz[i][2]]=m[rz[i][1]];
            tm[rz[i][3]]=m[rz[i][2]];
        }
    }
    memcpy(m,tm,24*sizeof(int));//24个整形元素
    return ;
}
int main()
{
    char str[100];
    int T=0;
    scanf("%d",&T);
    while(T--)
    {
        memset(str,0,sizeof(str));
        int m[24]={0,0,0,0,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5};//代表六个面的上不同点的颜色
        scanf("%s",&str);
        for(int i=0;i<strlen(str);i++)
        {
            chan(str[i],m);
        }
        printf("%c%c%c\n",rgb[m[1]],rgb[m[4]],rgb[m[18]]);
    }
    return 0;
}
