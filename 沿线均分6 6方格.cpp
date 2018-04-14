#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int ans=0,num=0,a[7][7]={};
void dfs(int x,int y,int t)
{
    if(t==1)x-=1;
    else if(t==2)x+=1;
    else if(t==3) y-=1;
    else y+=1;
    a[x][y]=1;
    a[6-x][6-y]=1;
    if(y==0||x==0||y==6||x==6)
    {
        a[x][y]=0;
        a[6-x][6-y]=0;
        ans++;
        return;
    }

    else
    {

        if(a[x-1][y]!=1)
        {
            dfs(x,y,1);
        }
        if(a[x+1][y]!=1)
        {
            dfs(x,y,2);
        }
        if(a[x][y-1]!=1)
        {
            dfs(x,y,3);
        }
        if(a[x][y+1]!=1)
        {
            dfs(x,y,4);
        }
    }
    a[x][y]=0;//ÖØÔÚ»ØËİ
    a[6-x][6-y]=0;
}
int main()
{
    a[3][3]=1;
    dfs(3,3,1);
    printf("%d",ans);
    return 0;
}
