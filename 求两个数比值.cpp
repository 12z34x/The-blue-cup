#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
long long zhanzhuan(long long a,long long b)
{
    long long  t=0;
    if(a>b)
    {
        t=a;
        a=b;
        b=t;
    }
    if((b%a)==0) return a;
    else return zhanzhuan(b%a,a);
}
int main()
{
    long long m[1000]={},p=0,q=0,flag=0;
    scanf("%lld%lld",&p,&q);
        printf("%lld/%lld",p/zhanzhuan(q,p),q/zhanzhuan(q,p));
    return 0;
}
