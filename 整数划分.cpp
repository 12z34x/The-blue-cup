#include <iostream>
#include<math.h>
#include<stdio.h>
#define N 310
using namespace std;
int main() {
    long long dp[N][N]={},n,k;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;//��1�����i����һ��
        dp[i][1]=1;//��i�����1��Ҳ��һ��
    }
    for(int i=1;i<=n;i++)//��i�����j����dp[i][j]��
        for(int j=1;j<=k;j++)
        {
            if(j>i) dp[i][j]=dp[i][i];//�ͽ�i�ֳ�i������һ��
            else if(i==j) dp[i][j]=dp[i][j-1]+1;//��j�ݲ��ֻ��߾���
            else dp[i][j]=dp[i][j-1]+dp[i-j][j];//��j�ݲ��ֻ��߾��ֺ󣨾ݸ볲ԭ��������i-j�ݷ����j��
        }
    printf("%lld\n",dp[n][k]);
    return 0;
}
