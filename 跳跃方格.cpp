#include<stdio.h>
#include<string.h>
#include<iostream>
#define N 100
using namespace std;
int main()
{
    int n,a[N],dp[N]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<=a[i]+i;j++)
            if(dp[j]==0||dp[i]+1<dp[j]) dp[j]=dp[i]+1;
    printf("%d\n",dp[n-1]);
    return 0;
}

