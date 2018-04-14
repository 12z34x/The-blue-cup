#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
   int T,m,n;
   scanf("%d",&T);
   while(T--)
   {
       scanf("%d%d",&m,&n);
       n*=3;
       m*=2;
       for(int i=6;i<=max(m,n);i+=6)//6的倍数需要判断
       {
           if(m<=n) m+=2;
           else n+=3;
       }
       printf("%d",max(n,m));
   }
    return 0;
}
