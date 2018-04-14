#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    long long a[10000]={},sum=0;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(n%2)
        {
            if(i%2==0&&i<n-1)
            sum+=a[i];
        }
        else
        {
            if(i%2==0&&i<n-2)
                sum+=a[i];
        }
    }
    if(n%2) printf("%lld\n",sum+a[n-1]);
    else printf("%lld\n",sum+(a[n-2]>a[n-1]?a[n-2]:a[n-1]));
    return 0;
}
