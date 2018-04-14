#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
double a,b, c[1000],calculate[1000]={};
int number=0;
double gank(int i)
{
    if(i) calculate[i]=c[i];
    for(int j=2;j<=i;j++)
        calculate[j]=calculate[j-1]+c[j];
    return calculate[i];
}
int  main()
{
    long long anw=0;
    double ans=0,sum=0;
    scanf("%d",&number);
    scanf("%lf%lf",&a,&b);
    for(int i=1;i<=number;i++)
    {
        scanf("%lf",&c[i]);
        sum+=gank(i);
    }
    ans=((number)*a+b-2*sum)/(number+1);
    printf("%.2lf",ans);
    return 0;
}
