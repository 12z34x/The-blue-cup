#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<queue>
#define N 100005
using namespace std;
int ans=0,a[10]={};
long long  st[9]={};
void dfs(long long k,int t,long long st[9])
{
    a[k]=1;
    st[t]=k;
    if(t>=8)
    {
        if(st[1]*(st[6]*100+st[7]*10+st[8])+(st[3]*100+st[4]*10+st[5])*st[2]==(10-st[0])*(st[6]*100+st[7]*10+st[8])*st[2])
            ans++;
        /*for(int i=0;i<=8;i++)
            cout<<st[i]<<" ";
        cout<<ans<<endl;*/
        a[k]=0;
        t--;
        return;
    }
    for(long long i=1;i<=9;i++)
    {
        if(a[i]) continue;
        else
        {
            dfs(i,t+1,st);
        }
    }
    a[k]=0;
    t--;
    return ;
}
int main()
{
    for(long long i=1;i<=9;i++)
    {
        dfs(i,0,st);
    }
    printf("%d",ans);
    return 0;
}
