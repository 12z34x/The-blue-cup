#include<stdio.h>
#include<iostream>
#define N 12
using namespace std;
long long dp[N][2<<N]={};//防止爆int
int n,m;
void dfs(int c,int from,int to,int j)
{
    if(c>m)//超列
        return;
    else if(c==m)
        dp[j][from]+=dp[j-1][to];//据上行给予下一行的状态
    else
    {
        dfs(c+1,(from<<1)+1,to<<1,j);//不放
        dfs(c+1,from<<1,(to<<1)+1,j);//竖放
        dfs(c+2,(from<<2)+3,(to<<2)+3,j);//横放
    }
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    if((n*m)%2)//奇数不符合题意
    {
        printf("0\n");
        return 0;
    }
    dp[0][(1<<m)-1]=1;//第0行封顶
    for(int i=1;i<=n;i++)
        dfs(0,0,0,i);//每一行据上一行状态
    printf("%lld",dp[n][(1<<m)-1]);//最后一行只有全为1
    return 0;
}

