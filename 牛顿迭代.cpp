#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    long long a;
    double k=0;
    scanf("%lld",&a);
    if(a==0)
    {
        printf("0.000");
        return 0;
    }
    k=a;
    while(k*k-a>1e-9)
    {
        k=(k+a/k)/2;
    }
    //k-=0.0005;//不四舍五入
    printf("%.3lf",k);
    return 0;
}
