#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define M 100
using namespace std;
int main()
{
    int n,dp[M][M];
    scanf("%d",&n);
    int N=n*(n+1)/4;//���Ϻ͵�һ��
    if(n*(n+1)%4!=0)
    {
        printf("0");
        return 0;
    }
    dp[1][1]=1;//dp[i][j]��ʾ1~i�к�Ϊj�������
    for(int i=2;i<=n;i++)
        for(int j=1;j<=N;j++)
        {
            if(j<i)dp[i][j]=dp[i-1][j];//����j��i�ò���
            else if(j==i) dp[i][j]=dp[i-1][j]+1;//����һ��ֻѡi�����
            else dp[i][j]=dp[i-1][j]+dp[i-1][j-i];/*�ɺ�Ϊj����Ϊj-i������Ӻ͡���Ϊʣ�µ�j-i���¼����i�����µ����*/
        }
    printf("%d",dp[n][N]/2);//ȥ���Գ����
    return 0;
}
