#include<stdio.h>
#include<iostream>
#define N 12
using namespace std;
long long dp[N][2<<N]={};//��ֹ��int
int n,m;
void dfs(int c,int from,int to,int j)
{
    if(c>m)//����
        return;
    else if(c==m)
        dp[j][from]+=dp[j-1][to];//�����и�����һ�е�״̬
    else
    {
        dfs(c+1,(from<<1)+1,to<<1,j);//����
        dfs(c+1,from<<1,(to<<1)+1,j);//����
        dfs(c+2,(from<<2)+3,(to<<2)+3,j);//���
    }
    return ;
}
int main()
{
    scanf("%d%d",&n,&m);
    if((n*m)%2)//��������������
    {
        printf("0\n");
        return 0;
    }
    dp[0][(1<<m)-1]=1;//��0�зⶥ
    for(int i=1;i<=n;i++)
        dfs(0,0,0,i);//ÿһ�о���һ��״̬
    printf("%lld",dp[n][(1<<m)-1]);//���һ��ֻ��ȫΪ1
    return 0;
}

