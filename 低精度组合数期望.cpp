#include<iostream>
#include<stdio.h>
#include<math.h>//pow()对于浮点数,整数
#include<stdlib.h>
using namespace std;
long long sum=0;
int n;
long long num[20]={};
void chan(int i)//Cm^n
{
    num[0]=1;
    for(int j=1;j<=i/2;j++)
        num[j]=num[j-1]*(sum-j+1)/j;
}
int  main()
{
    double p=0,ans=0,total=0;
    scanf("%d%lf",&n,&p);
    if(n==1) {printf("1");return 0;}
    for(int j=1;j<n;j++)
        sum+=j;
    chan(n);
    for(int i=0;i<n-1;i++)
        ans+=num[i]*pow(p,i)*pow(1-p,sum-i);
    total=1-ans;
    if(total==0) printf("0");
    printf("%lf",total);
    return 0;
}