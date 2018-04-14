#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
long long st[9]={},a[9]={};
void dfs(int k,int t)
{
    a[k]=1;
    st[t]=k;
    if(t==8)
    {
        if(st[0]*1000+st[1]*100+st[2]*10+st[3]+1000*st[4]+100*st[5]+10*st[6]+st[7]==st[4]*10000+st[5]*1000+st[2]*100+st[7]*10+st[8])
            cout<<st[0]*1000+st[1]*100+st[2]*10+st[3]<<"+"<<1000*st[4]+100*st[5]+10*st[6]+st[7]<<"="<<st[4]*10000+st[5]*1000+st[2]*100+st[7]*10+st[8]<<endl;
        a[k]=0;
        return ;
    }
    for(int i=0;i<=9;i++)
    {
        if(a[i])continue;
        dfs(i,t+1);
    }
    a[k]=0;
    return;
}
int main()
{
    for(int i=1;i<=9;i++)
    {
        dfs(i,0);
    }
    return 0;
}
