#include<stdio.h>
#include<iostream>
#define N 6
#define L 1000000007
using namespace std;
void Multi(long long X[N][N],long long Y[N][N])//矩阵乘法
{
    long long Z[N][N]={};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
            {
                Z[i][j]+=X[i][k]*Y[k][j];
                Z[i][j]%=L;
            }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            X[i][j]=Z[i][j];
}
long long fast(long long p,int q,long long sum)//快速幂
{
    while(q)
    {
        if(q&1)
        {
            sum*=p;
            sum%=L;
        }
            p*=p;
            p%=L;
            q>>=1;
    }
    return sum;
}
void M_fast(long long M[N][N],int e)//矩阵快速幂
{
    long long RET[N][N]={};
    for(int i=0;i<N;i++)
            RET[i][i]=1;
    while(e)
    {
        if(e&1)
        {
            Multi(RET,M);
        }
	Multi(M,M);
        e>>=1;
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            M[i][j]=RET[i][j];
}
int main()
{
    long long Z[N][N],ans=0,c=4;
    int n,m;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            Z[i][j]=1;
        }
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        Z[(a-1)%N][(b+2)%N]=0;
        Z[(b-1)%N][(a+2)%N]=0;

    }
    M_fast(Z,n-1);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
        {
            ans+=Z[i][j];

            ans%=L;
        }
    ans=fast(c,n,ans);
    printf("%lld",ans);
    return 0;
}
