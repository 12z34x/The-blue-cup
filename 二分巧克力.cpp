#include<stdio.h>
#include<iostream>
using namespace std;
int n,k,a[100000]={},b[100000]={};
bool chan(int x,int y)
{
    int sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=(a[j]/x)*(b[j]/y);//不足一块也不要
    }
    if(sum>=k) return 1;//若足够k块则满足
    else return 0;
}
int main()
{
    int low=1,high=100000,mid;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    while(low<high-1)//low尽快接近答案后将low输出。x^2可行，(x-1)(x+1)必定可行
    {
        mid=(low+high)/2;
        if(chan(low,high))
        {
            low=mid;//向上提
        }
        else high=mid;
    }
    printf("%d",low);
}
