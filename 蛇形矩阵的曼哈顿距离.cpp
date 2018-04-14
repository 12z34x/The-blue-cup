#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long  w,m,n,l=1,i=1,j=0,a=0,b=0,c=0,d=0;
    scanf("%lld%lld%lld",&w,&m,&n);
    if(m<n) swap(m,n);
    for(long long k=1;k<=10000;k++)
    {
        if(k%w==1&&k!=1)
        {
            i++;
            l=-l;
        }
        else j+=l;
        if(k==n)
        {
            a=i;
            b=j;
        }
        if(k==m)
        {
            c=i;
            d=j;
        }
    }
    printf("%lld",c-a+d-b);
    return 0;
}
