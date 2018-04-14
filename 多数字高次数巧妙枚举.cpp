#include<cstdio>
#include<iostream>
#include<cstring>
#define N 110
using namespace std;
int  b[10]={},a[6]={};
bool ok()
{
    memset(b,0,sizeof(b));
    for(int i=0;i<=4;i++)
    {
        b[a[i]%10]++;
        b[(a[i]/10)%10]++;
        b[(a[i]/100)]++;
    }
    b[a[5]%10]++;
    b[(a[5]/10)%10]++;
    b[(a[5]/100)%10]++;
    b[(a[5]/1000)%10]++;
    b[(a[5]/10000)]++;
    for(int i=0;i<=9;i++)
    {
        if(b[i]!=2) return false;
    }
    return true;
}
int main()
{
    for(int i=100;i<=999;i++)
    {
        for(int j=100;j<=999;j++)
        {
            if(i*j>99999)
                break;
            a[0]=j;
            a[1]=i;
            a[4]=a[0]*(a[1]/100);
            a[3]=a[0]*((a[1]/10)%10);
            a[2]=a[0]*(a[1]%10);
            a[5]=i*j;
            if(ok())
            {
                cout<<a[0]<<"*"<<a[1]<<"="<<a[2]<<endl;
                cout<<a[2]<<"+"<<a[3]<<"+"<<a[4]<<"="<<a[5]<<endl;
            }
        }
    }
    return 0;
}
