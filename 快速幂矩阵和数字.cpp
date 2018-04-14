#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 3
using namespace std;
int n,m,a,b,k,st[N][N]={};
void Multi(int X[N][N],int Y[N][N])
{
    int Z[N][N]={};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int l=0;l<N;l++)
            {
                Z[i][j]+=X[i][l]*Y[l][j];
            }
    memcpy(X,Z,sizeof(Z));
}
void M_fast(int x)
{
    int Z[N][N]={};
    for(int i=0;i<N;i++)
        Z[i][i]=1;
    while(x)
    {
        if(x&1)
        {
            Multi(Z,st);
        }

        Multi(st,st);
        x>>=1;
    }
    memcpy(st,Z,sizeof(st));
}
int fast(int p,int q)
{
    int sum=1;
    while(q)
    {
        if(q&1)
        {
            sum*=p;
        }
        p*=p;
        q>>=1;
    }
    return sum;
}
int main()
{
    scanf("%d%",&a);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++ )
            scanf("%d",&st[i][j]);
    M_fast(a);
    scanf("%d%d",&k,&b);
    k=fast(k,b);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++ )
            cout<<st[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
