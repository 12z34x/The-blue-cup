#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define M 10000
using namespace std;
int p[M]={},q[M]={};
struct Tree
{
    int father;
}T[M];
int sea(int x,int y)
{
    int i=0,j=0,a,b;
    p[i]=x;
    q[j]=y;
    while(T[x].father!=0)
    {
        i++;
        x=T[x].father;
        p[i]=x;
    }
    while(T[y].father!=0)
    {
        j++;
        y=T[y].father;
        q[j]=y;
    }
    for( a=i,b=j;p[a]==q[b];)
    {
        if(a!=0&&b!=0)
        {
            a--;
            b--;
        }
        else return a>=b?q[b]:p[a];
    }
    return T[p[a]].father;
}
int main()
{
    int a,b,num=0,t,c[M]={};
    scanf("%d",&t);
    while(t--)
    {
        int n=0;
        scanf("%d",&n);
        memset(T,0,sizeof(Tree)*n);
        memset(q,0,sizeof(int)*n);
        memset(p,0,sizeof(int)*n);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            T[b].father=a;
        }
        scanf("%d%d",&a,&b);
        printf("%d\n",sea(a,b));
    }
    return 0;
}
