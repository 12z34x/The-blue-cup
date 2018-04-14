#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long  a[100000],b[100000]={},c[100000]={};
int  gcb(int a,int b)
{
    int t;
    if(b<a)
    {
        t=a;
        a=b;
        b=t;
    }
    if((b%a)==0) return a;
    return gcb(b%a,a);
}
int main()//ÅÐ¶ÏºÃ¸ºÊý
{
    long long flag=0,ans=1,sum=0,no=-1;
    int n=0,m=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n);
     for(int i=0;i<n;i++)
    {
        b[i]=a[i];
    }
    for(int i=1,j=0;i<n;i++,j++)
    {
        b[j]=a[i]-a[i-1];
        c[j]=b[j];
    }
    if(n<=3)
    {
        printf("0");
        return 0;
    }
    m=n-1;
    for(int i=0;i<n-1;i++)
    {
        if(i==0)
            c[i]=c[i+1];
        else c[i]=c[i-1];
        //cout<<c[i]<<endl;
        while(m>1)
        {
            for(int j=0;j<m-1;j++)
            {
                c[j]=gcb(c[j],c[j+1]);
                //cout<<c[j];
            }
            m--;
        }
        if(c[0]!=1)
        {
            no=i;
            ans=c[0];
            //cout<<ans;
            break;
        }
        for(int k=0;k<n-1;k++)
            c[k]=b[k];
        m=n-1;
    }
    //cout<<ans;
    for(int i=0;i<n-1;i++)
    {
        if(i==no&&no!=(-1)) continue;
        sum+=(b[i]/ans)-1;
    }
    printf("%lld",sum);
    return 0;
}
