#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 10010
using namespace std;
int main()
{
    int st[N]={},n,ans=0,a,b,flag1=0,flag2=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&st[i]);
        if(st[i]==0) flag1=1;
        if(flag1) continue;
        else a++;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(st[i]==0) flag2=1;
        if(flag2) break;
        else b++;
    }
    if(a%2||b%2) printf("YES\n");
    else printf("NO\n");
    return 0;
}
