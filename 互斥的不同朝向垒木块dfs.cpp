#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
//dfs只能满足三分之一的数据 可寻矩阵快速幂 满足100%的数据
long long n,ans=0,st[6][6]={};
void dfs(int num,int i)
{
    if(num!=n)
    {
        for(int j=1;j<=6;j++)
        {
            if(st[i][j]!=1)
                dfs(num+1,j);
            else continue;
        }
    }
    else
    {
        ans++;
        return ;
    }
}
int main()
{
    int m,a,b;
    scanf("%lld%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        st[a][b]=1;
        st[b][a]=1;
    }
    for(int j=1;j<=6;j++)
        dfs(1,j);
    printf("%lld",((int)pow(4,n)*ans)%(1000000007));
}
