#include<stdio.h>
#include<iostream>
using namespace std;
long long dp[100010];
int main()
{
    long long n,k,a[100010]={};
    int ans=0;
    scanf("%lld%lld",&n,&k);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i)
        dp[i]=dp[i-1]+a[i-1];//Ԥ�������ǰ׺��
        else continue;
    }
    dp[n]=dp[n-1]+a[n-1];
    for(int j=n;j>0;j--)//��������0��
    {
        for(int l=0;l<j;l++)//ע���±�
            if((dp[j]-dp[l])%k==0)
                {ans++;}
    }
    printf("%d",ans);
    return 0;
}
