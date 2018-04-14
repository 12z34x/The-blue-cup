#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;//利用前缀和预处理一下。
long long x[50005]={},y[50005]={},w[50005]={},flag[2005][2005]={},dp[2005][2005]={};
long x11[50005]={},y11[50005]={},x22[50005]={},y22[50005]={},n;
long long counter(int a,int b,int c,int d)
{
    if(a==0&&b==0)return dp[c][d];
    else if(b==0) return dp[c][d]-dp[a-1][d];
    else if(a==0) return dp[c][d]-dp[c][b-1];
    return dp[c][d]-dp[c][b-1]-dp[a-1][d]+dp[a-1][b-1];
}
int  main()
{
    long q;
    long long sum[50005]={};//数组略大些
    scanf("%ld",&n);
    for(long i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&x[i],&y[i],&w[i]);
            flag[x[i]][y[i]]+=w[i];//亮度叠加
    }
    for(int i=0;i<=2005;i++)
        for(int j=0;j<=2005;j++)
        {
            if(i==0&&j==0)dp[i][j]=flag[i][j];
            else if(j==0) dp[i][j]=flag[i][j]+dp[i-1][j];
            else if(i==0) dp[i][j]=dp[i][j-1]+flag[i][j];
            else dp[i][j]=dp[i-1][j]+dp[i][j-1]+flag[i][j]-dp[i-1][j-1];

        }

    scanf("%ld",&q);
    for(long i=0;i<q;i++)//可以将下标都从1开始，省略越界判断。
    {
        scanf("%ld%ld%ld%ld",&x11[i],&y11[i],&x22[i],&y22[i]);
        printf("%lld\n",counter(x11[i],y11[i],x22[i],y22[i]));
    }
    return 0;
}