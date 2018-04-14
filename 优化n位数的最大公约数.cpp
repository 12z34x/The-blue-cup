#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
#define N 100
using namespace std;
int gcb(int a,int b)
{
    if(a>b)
        swap(a,b);
    if(b%a==0)
    {
        return a;
    }
    return gcb(b%a,a);
}
int main()
{
    int n,a[N]={};
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
        {
            printf("1");
            return 0;
        }
    }
    if(n==0)
    {
        printf("%d\n",&a[0]);
        return 0;
    }

    while(n>1)
    {
        for(int i=0;i<n-1;i++)
        {
            a[i]=gcb(a[i],a[i+1]);
            if(a[i]==1)
            {
                printf("1\n");
                return 0;
            }
        }
        n--;
    }
    printf("%d\n",a[0]);
    return 0;
}
