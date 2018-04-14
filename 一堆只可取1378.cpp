#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 10010
using namespace std;
int main()
{
    int st[N]={},n,ans=0;
    st[0]=0;
    st[1]=0;
    st[2]=1;
    st[3]=0;
    st[4]=1;
    st[5]=0;
    st[6]=1;
    st[7]=0;
    st[8]=1;
    for(int i=9;i<N;i++)
        if(st[i-1]==0||st[i-3]==0||st[i-7]==0||st[i-8]==0)
            st[i]=1;
        else st[i]=0;
    scanf("%d",&n);
    if(st[n]) printf("WIN\n");
    else printf("LOSE\n");
    return 0;
}
