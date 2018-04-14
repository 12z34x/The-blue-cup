#include<stdio.h>
#include<iostream>
using namespace std;
int  chan(long long x)
{
    int t=0;
    while(x!=0)
    {
        t++;
        x/=10;
    }
    return t;
}
int main()
{
    long long flag[10]={},m,n,ans;
    bool vis;
    for(long long i=9;i<10000;i++)
    {
        m=i*i;
        n=i*i*i;
        if(chan(m)+chan(n)!=10) continue;//排除位数过多的
        else
        {
            while(m!=0)
            {
                if(flag[m%10]!=1)
                {
                    flag[m%10]=1;
                    m/=10;
                }
                else {vis=true;break;}
            }
            if(!vis)//提前排除不合理的m
           {
               while(n!=0)
            {
                if(flag[n%10]!=1)
                {
                    flag[n%10]=1;
                    n/=10;
                }
                else {vis=true;break;}
            }
           }
        }
        if(vis)
        {
            vis=0;
            for(int j=0;j<10;j++)
                flag[j]=0;
            continue;
        }
        else {ans=i;break;}
    }
    printf("%lld",ans);
    return 0;
}
