#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>//����memset
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
    if(a[0]!=1){printf("INF");return 0;}//���Լ����Ϊ1������������ֲ�����
    memset(dp,0,sizeof(dp));
    dp[0]=1;//��ʱ��Ϊ1
    for(int i=0;i<n;i++)//����ÿ������
        for(int j=0;j+s[i]<=N;j++)//��ö����һ����Χ�ڣ�sum^2���ĸ�����϶������㣬��֮��Ķ�������
        {
            if(dp[j])
                dp[j+s[i]]=1;
        }
    for(int i=0;i<=N;i++)
        if(dp[i]!=1) ans++;
    printf("%d",ans);

}

