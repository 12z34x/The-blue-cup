#include<stdio.h>
#include<iostream>
using namespace std;
char a[10][11]={};
int ans=0;
void check(int x,int y)
{
    int vis[10][10]={};//初始化
    while(1)
    {
        if(x>9||x<0||y<0||y>9){ans++;return ;}
        if(vis[x][y]==1)return;
        vis[x][y]=1;//防止原地打转
    switch(a[x][y])
    {
    case 'U':x-=1;break;
    case 'R':y+=1;break;
    case 'L':y-=1;break;
    case 'D':x+=1;break;
        default:break;
    }
    }
}
int main()
{
    char c;
    for(int i=0;i<10;i++)
        for(int j=0;j<=10;j++)
        {
            c=getchar();
            if(c>='A'&&c<='Z')
            {
                a[i][j]=c;
            }

        }
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
        {
           check(i,j);//对于每点进行暴力枚举
        }
    cout<<ans;
}
/*
UDDLUULRUL
UURLLLRRRU
RRUURLDLRD
RUDDDDUUUU
URUDLLRRUU
DURLRLDLRL
ULLURLLRDU
RDLULLRDDD
UUDDUDUDLL
ULRDLUURRR
*/