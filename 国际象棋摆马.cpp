#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define N 10010
using namespace std;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    if(n>m) swap(n,m);
    if(n==1) printf("%d",m);
    else if(n==2)//Ë«Ìï×Ö
    {
        if(m%4!=3)
            printf("%d",(m/4)*4+(m%4)*2);
        else printf("%d",(m/4)*4+4);
    }
    if(n>2)
        printf("%d",(n*m+1)/2);//ÆæÊı¸öÅĞ¶Ï
    return 0;
}
