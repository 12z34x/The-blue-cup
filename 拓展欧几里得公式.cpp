#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>//包含memset
#define N 10010
using  namespace std;
int dp[N];
int  gcb(int a,int b)
{
    int t;
    if(b<a)
    {
        swap(a,b);
    }
    if((b%a)==0) return a;
    return gcb(b%a,a);
}
int main()
{
    int n,s[100]={},m,a[100]={},ans=0;
    scanf("%d",&n);
    m=n;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&s[i]);
        a[i]=s[i];
    }
    if(n==1){printf("INF");return 0;}
    while(m>1)
    {
        for(int j=0;j<m-1;j++)
            {a[j]=gcb(a[j],a[j+1]);}
        m--;
    }
    if(a[0]!=1){printf("INF");return 0;}//最大公约数不为1，则必有无数种不满足
    memset(dp,0,sizeof(dp));
    dp[0]=1;//零时比为1
    for(int i=0;i<n;i++)//对于每个个数
        for(int j=0;j+s[i]<=N;j++)//若枚举了一定范围内（sum^2）的各种组合都可满足，则之后的都可满足
        {
            if(dp[j])
                dp[j+s[i]]=1;
        }
    for(int i=0;i<=N;i++)
        if(dp[i]!=1) ans++;
    printf("%d",ans);

}

