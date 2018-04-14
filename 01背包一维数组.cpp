#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<cstdio>
#include<cstring>
#define M 1010
using namespace std;
int f[M];
int main()
{
    int T,N,V,w[M]={},v[M]={};
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&V);
        memset(f,0,sizeof(f));//一定要初始化！
        for(int i=1;i<=N;i++)
            scanf("%d",&v[i]);
        for(int i=1;i<=N;i++)
            scanf("%d",&w[i]);
        for(int i=1;i<=N;i++)
            for(int j=V;j>=w[i];j--)
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
            }
        printf("%d",f[V]);
    }
    return 0;
}
