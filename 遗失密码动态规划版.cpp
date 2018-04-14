#include<stdio.h>
#include<iostream>
#define N 1024*1024*4096
using namespace std;
int main()
{
    long long n,m,ans,dp[110]={};
    scanf("%lld%lld",&n,&m);
    if(m==1)
    {
        printf("1\n");
        return 0;
    }
    if(n==1)
    {
        printf("%lld\n",m);
    }
    dp[1]=m;
    dp[2]=m*(m-1);
    ans=(dp[1]+dp[2])%N;
    for(int i=3;i<=n;i++)
    {
        if(i%2)
        {
            dp[i]=dp[i-1]*m;
        }
        else
        {
            dp[i]=dp[i-1]*m-dp[i/2];
        }
        ans=(ans+dp[i])%N;
    }
    printf("%lld\n",ans%N);
    return 0;
}
