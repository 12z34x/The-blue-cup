#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()//较大数异或 
{
    long long a[30]={},p=0,q=0,ans=0;
    for(int i=0;i<30;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            if(j==i) continue;
            p=a[i]^a[j];
            for(int k=0;k<30;k++)
            {
                if(k==j||k==i) continue;
                q=p^a[k];
                if(q>ans)
                    ans=q;
            }
        }
    }
    cout<<ans;
    return 0;
}
