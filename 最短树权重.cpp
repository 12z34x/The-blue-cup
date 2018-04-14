#include<stdio.h>
#include<iostream>
#include<math.h>
#include<algorithm>
#define N 100
using namespace std;
int father[N],sonnum[N];
struct Edge
{
    int from;
    int to;
    int w;
}E[N];
bool cmp(Edge a,Edge b)
{
    return a.w<b.w;
}
int  chan(int x)
{
    if(father[x]!=x)
        chan(father[x]);
    return x;
}
bool join(int x,int y)
{
    int l=chan(x);
    int r=chan(y);
    if(father[x]==father[y])
        return false;
    else
    {
        if(sonnum[l]>=sonnum[r])
        {
            father[r]=l;
            sonnum[l]+=sonnum[r];
        }
        else
        {
            father[l]=r;
            sonnum[r]+=sonnum[l];
        }
    }
    return true;
}
int main()
{
    int v,e,a,b,sum=0,c,num=0,flag=0,ans=0;
    scanf("%d%d",&v,&e);
    for(int i=0;i<v;i++)
    {
        father[i]=i;
        sonnum[i]=1;
    }
    for(int j=0;j<e;j++)
    {
        scanf("%d%d%d",&a,&b,&c);
        E[j].from=a;
        E[j].to=b;
        E[j].w=c;
        sum+=c;
    }
    sort(E,E+e,cmp);
    for(int i=0;i<e;i++)
    {
        if(join(E[i].from,E[i].to))
        {
            ans+=E[i].w;
            num++;
        }
        else
        {
            continue;
        }
        if(num==v-1)
        {
            flag=1;
            break;
        }
    }
    if(flag) cout<<sum-ans;
    else cout<<"ERROR";
    return 0;
}
