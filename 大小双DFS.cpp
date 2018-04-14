#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
int ans=0,a[3][4]={},number=0, b[3][4]={},flag=0;
void chan(int x,int y)//判断是否有五连通区域
{
    number++;
    b[x][y]=1;
    if(number==5) {flag=1;return;}
    if(x>0&&a[x-1][y]==1&&b[x-1][y]==0)
        chan(x-1,y);
    if(x<2&&a[x+1][y]==1&&b[x+1][y]==0)
        chan(x+1,y);
    if(y>0&&a[x][y-1]==1&&b[x][y-1]==0)
        chan(x,y-1);
    if(y<3&&a[x][y+1]==1&&b[x][y+1]==0)
        chan(x,y+1);
    if(number==5) {flag=1;return;}
    return;
}
void dfs(int x,int y,int is,int num)//回溯时置a[x][y]
{
    flag=0;
    if(is)
        a[x][y]=1;
    if(num==5)
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<4;j++)
            {
                if(a[i][j]==0)continue;
                for(int k=0;k<3;k++)
                    for(int l=0;l<4;l++)
                        b[k][l]=0;
                number=0;
                chan(i,j);
            }
        }
        if(flag) ans++;
        a[x][y]=0;
        return;
    }
    else
    {
        if(x>=2)
        {
            if(y>=3)
            {
                a[x][y]=0;
                return;
            }
            else
            {
                dfs(x,y+1,1,num+1);
                dfs(x,y+1,0,num);
            }
        }
        else
        {
            if(y>=3)
            {
                dfs(x+1,0,1,num+1);
                dfs(x+1,0,0,num);
            }
            else
            {
                dfs(x,y+1,1,num+1);
                dfs(x,y+1,0,num);
            }
        }
    }
    a[x][y]=0;
    return ;
}
int main()
{
    dfs(0,0,1,1);
    dfs(0,0,0,0);
    printf("%d\n",ans);
    return 0;
}
