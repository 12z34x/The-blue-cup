#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 10010
using namespace std;
int main()
{
    int st[N]={},n,m,k,ans=0;
    st[0]=0;
    st[1]=0;
    st[2]=1;
    st[3]=0;
    st[4]=1;
    st[5]=0;
    st[6]=1;
    st[7]=0;
    st[8]=1;
    st[9]=0;
    for(int i=10;i<N;i++)
        if(st[i-1]==0||st[i-3]==0||st[i-7]==0||st[i-9]==0)
            st[i]=1;
        else st[i]=0;
    scanf("%d%d%d",&n,&m,&k);
    if(st[n]==0) ans++;
    if(st[m]==0) ans++;
    if(st[k]==0) ans++;
    if(ans%2==0) printf("lose");
    else printf("win");
    return 0;
}
