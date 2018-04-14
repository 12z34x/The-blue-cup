#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <algorithm>
#include<iostream>
using namespace std;
long long status[1024]={},num=0,ans=0,dp[10][1024]={};
void check()//求出所有每行合法状态，不能有相邻1
{
    for(long long i=0;i<1024;i++)
    {
        if((i<<1)&i)
        {
            continue;
        }
        else
        {
            status[num]=i;
            num++;
        }
    }
}
void initial()
{
    check();
    for(int i=0;i<num;i++)
    {
        dp[0][i]=1;
    }
}
void calculate()
{
    initial();
    for(int i=1;i<10;i++)
    {
        for(int j=0;j<num;j++)
        {
            for(int k=0;k<num;k++)
                if((status[k]&status[j])==0)//注意位运算符优先级
                    dp[i][k]+=dp[i-1][j];
        }
    }
}
int main()
{
    calculate();
    for(int j=0;j<num;j++)
        ans+=dp[9][j];
    cout<<ans<<endl;
    return 0;
}