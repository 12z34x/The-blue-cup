#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int st[1000][1000]={},n,m;
void chan(int x,int y)
{
    if(x==y||st[x][y]) return;
    st[x][y]=1;
    st[y][x]=1;
    for(int i=1;i<=m;i++)
    {
        if(i==y) continue;
        if(st[x][i])
        {
            chan(y,i);
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i==x) continue;
        if(st[y][i])
        {
            chan(x,i);
        }
    }
}
int main()
{
    int a,b,num=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        if(i==0)
        {
            st[a][b]=1;
            st[b][a]=1;
            num++;
            continue;
        }
        else if(st[a][b]||a==b) continue;
        num++;
        chan(a,b);

    }
    printf("%d\n",n-num);
    return 0;
}
