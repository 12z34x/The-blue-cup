#include <iostream>
#include<math.h>
#include<stdio.h>
#define N 310
using namespace std;
int main() {
    long long dp[N][N]={},n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;//将1分最多i份有一种
        dp[i][1]=1;//将i分最多1份也有一种
    }
    for(int i=1;i<=n;i++)//将i分最多j份有dp[i][j]种
        for(int j=1;j<=k;j++)
        {
            if(j>i) dp[i][j]=dp[i][i];//和将i分成i份数量一样
            else if(i==j) dp[i][j]=dp[i][j-1]+1;//第j份不分或者均分
            else dp[i][j]=dp[i][j-1]+dp[i-j][j];//第j份不分或者均分后（据鸽巢原理）将余下i-j份分最多j份
        }
    printf("%lld\n",dp[n][k]);
    return 0;
}
