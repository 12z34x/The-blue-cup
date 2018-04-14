#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define M 100
using namespace std;
int main()
{
    int n,dp[M][M];
    scanf("%d",&n);
    int N=n*(n+1)/4;//集合和的一半
    if(n*(n+1)%4!=0)
    {
        printf("0");
        return 0;
    }
    dp[1][1]=1;//dp[i][j]表示1~i中和为j的情况数
    for(int i=2;i<=n;i++)
        for(int j=1;j<=N;j++)
        {
            if(j<i)dp[i][j]=dp[i-1][j];//大于j的i用不到
            else if(j==i) dp[i][j]=dp[i-1][j]+1;//多了一种只选i的情况
            else dp[i][j]=dp[i-1][j]+dp[i-1][j-i];/*由和为j及和为j-i情况数加和。因为剩下的j-i与新加入的i构成新的情况*/
        }
    printf("%d",dp[n][N]/2);//去除对称情况
    return 0;
}
