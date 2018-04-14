#include<iostream>
#include<cstring>
#include<stdio.h>
#define N 1000
using namespace std;
int dp[N]={},ans[N]={},mx=0,a[N]={},num=0;//上次初始位置为0
void print(int x)
{
    if(x)
    {
        if(ans[x]!=0)
            print(ans[x]);
        else
        {
            if(a[0]>a[x]) printf("%d ",a[0]);
            num++;
        }
        num++;
        if(x!=mx)
            printf("%d ",a[x]);
        else printf("%d",a[x]);
    }
    return ;
}
void chan(int n)
{
    int t=0;//记录最远位置
    for(int i=0;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[i]&&dp[i]<dp[j]+1)
            {
                dp[i]+=dp[j]+1;
                ans[i]=j;
            }
        }
        if(dp[i]>dp[t])
            t=i;
    }
    mx=t;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    chan(n);
    print(mx);
    cout<<endl<<num;
}
