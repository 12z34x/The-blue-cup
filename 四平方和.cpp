#include<stdio.h>
#include<iostream>
#include<math.h>//求平方根函数sqrt();
using namespace std;
long long  store[2300]={};
void chan()
{
    for(int i=0;i<2300;i++)
        store[i]=i*i;
}
int main()
{
    long long n=0;
    int d=0;
    scanf("%lld",&n);
    chan();
    for(int i=0;store[i]<n;i++)
         for(int j=0;store[j]<n;j++)
             for(int k=0;store[k]<n;k++)//节省循环次数
            {
                 d=(int)sqrt(n-store[i]-store[j]-store[k]);
                if(store[i]+store[j]+store[k]+store[d]==n) {printf("%d,%d,%d,%d",i,j,k,d);return 0;}
            }
    return 0;
}