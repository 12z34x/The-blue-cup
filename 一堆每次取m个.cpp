#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#define N 110
using namespace std;
int main()
{
    int n,m=0,ans=0;
    scanf("%d%d",&n,&m);
    if(n%(m+1))printf("WIN\n");
    else printf("LOSE\n");
    return 0;
}
