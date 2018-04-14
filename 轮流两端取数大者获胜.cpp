#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 110
using namespace std;
int a[N]={},st[N][N]={};
int dfs(int x,int y,int who)
{
    if(st[x][y]) return st[x][y];//已经选过则及时返回
    if(x==y&&!who)
    {
        st[x][y]+=a[x];
        return a[x];
    }
    else if(x==y&&who)
    {
        return 0;
    }
    if(!who)
        st[x][y]=max(dfs(x+1,y,who^1)+a[x],dfs(x,y-1,who^1)+a[y]);//此次会选择较大的情况
    else st[x][y]=min(dfs(x+1,y,who^1),dfs(x,y-1,who^1));//此次被迫选最小
    return st[x][y];
}
int main()
{
    int n,sum=0,ans=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    ans=dfs(0,n-1,0);
    printf("%d %d\n",ans,sum-ans);
    return 0;
}
