#include<stdio.h>
#include<string.h>
#include<iostream>
#include<math.h>
#define N 1000
using namespace std;
   int n,a[N]={},dp[N][N]={},st[N]={},t;
int main()
{

    scanf("%d",&n);
    st[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        st[i]=st[i-1]+a[i];//�ϲ�ǰi�Ļ���
        dp[i][i]=0;//��i��i����С����
    }
    for(int i=2;i<=n;i++)//�ϲ�����
    {
        for(int j=1;j+i-1<=n;j++)//�ϲ��յ�
        {
            int k=i+j-1;
            t=st[k]-st[j-1];//i��k�Ļ���
            dp[j][k]=dp[j][j]+dp[j+1][k]+t;
            for(int l=j+1;l<=k;l++)
                dp[j][k]=min(dp[j][k],dp[j][l]+dp[l+1][k]+t);
        }
    }
    printf("%d\n",dp[1][n]);
    return 0;
}

