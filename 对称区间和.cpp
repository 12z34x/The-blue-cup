#include<stdio.h>
#include<iostream>
#define N 100001
using namespace std;
long long a[N]={},sum[N]={},dp[N]={};
bool chan(int x,int y)
{
    bool flag=true;
    for(int i=0;2*i<y-x;i++)
    {
        if(a[x+i]!=a[y-i])
        {
            flag=false;
            break;
        }
    }
    return flag;
}
int main()
{
    int n,m,ans,x,y;
    dp[0]=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        dp[i]+=dp[i-1]+a[i];
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        sum[i]+=dp[y]-dp[x-1];
        for(int j=x;j<=y;j++)
            for(int k=1;k<=y-j;k++)
            {
                if(chan(j,k+j)) sum[i]+=dp[j+k]-dp[j-1];
            }
    }
    for(int i=0;i<m;i++)
        printf("%lld\n",sum[i]);
    return 0;
}
