#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n=0,dp[51]={};
    scanf("%d",&n);
    dp[0]=0;
    dp[2]=2;
    dp[1]=1;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2];//从dp[n-1]走一步或者从dp[n-2]走两步。为此两种方法之和
    printf("%d\n",dp[n]);
    return 0;
}
