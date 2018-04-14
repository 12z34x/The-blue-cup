#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
long long a,mid,m;
long long  sea(long long x,long long y,long long n)
{
    while(x<y)
    {
        //cout<<mid;
        mid=(x+y)/2;
        m=mid+1;
        if(mid*mid==n) return mid;
        else if(m*m==n) return m;
        else if(mid*mid>n)
        {
          //  cout<<mid;
            y=mid-1;
           // cout<<y;
        }
        else if((mid*mid)<n&&m*m>n)
            return mid;
        else if(m*m<n)
        {
            x=m;
        }
    }
    return x;

}
int main()
{
    while(scanf("%lld",&a)!=EOF)
    {
        if(a==0) printf("0\n");
        else printf("%lld\n",sea(1,a,a));
    }
    return 0;
}
