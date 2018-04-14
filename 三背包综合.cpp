#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#define N 100
using namespace std;
int main()
{
    int n,W,c[N]={},v[N]={},dp[N][N]={},f[N]={},p[N]={};
    scanf("%d%d",&n,&W);
    for(int i=1;i<=n;i++)
        scanf("%d",&v[i]);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=W;j++)
        {
            if(j-c[i]>=0)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-c[i]]+v[i]);
            else dp[i][j]=dp[i-1][j];
        }
    for(int i=1;i<=n;i++)
        for(int j=W;j>=c[i];j--)
            f[j]=max(f[j],f[j-c[i]]+v[i]);
    for(int i=1;i<=n;i++)
        for(int j=c[i];j<=W;j++)
            p[j]=max(p[j],p[j-c[i]]+v[i]);
    cout<<dp[n][W]<<" "<<f[W]<<" "<<p[W]<<endl;
    return 0;
}
/*
2 2
5 4
1 1

3 5
3 4 5
4 2 2

5 10
2 3 3 4 6
1 2 5 9 4
*/
