#include<cstring>
#include<stdio.h>
#include<iostream>
#define M 1010
using namespace std;
int f[M];
int main()
{
    int T,N,V,v[M]={},w[M]={};
    scanf("%d",&T);
    while(T--)
    {
        memset(f,0,sizeof(f));
        scanf("%d%d",&N,&V);
        for(int i=0;i<N;i++)
            scanf("%d",&v[i]);
        for(int j=0;j<N;j++)
            scanf("%d",&w[j]);
        for(int i=0;i<N;i++)
            for(int j=w[i];j<=V;j++)//01和完全，起始点均为w[i]
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
            }
        printf("%d",f[V]);
    }
    return 0;
}
