#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#define M 1000
using namespace std;
int dp[M][M];
int main()
{

    int T,N,W,v[M]={},c[M]={};//

    scanf("%d",&T);

    while(T--)
    {
        memset(dp,0,sizeof(dp));
        scanf("%d%d",&N,&W);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&c[i]);
        }
        for(int i=1;i<=N;i++)
            for(int j=1;j<=W;j++)
            {
                if(j-c[i]>=0) dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
                else dp[i][j]=dp[i-1][j];
            }
    printf("%d\n",dp[N][W]);
    }
    return 0;
}
