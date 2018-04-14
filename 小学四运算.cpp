#include<stdio.h>
#include<iostream>
using namespace std;
int ans=0,flag[14]={};
void chan(int i)//注意小学除法
{
    int j,k,sum=0;
    for(j=1;j<=13;j++)
    {
        if(flag[j])continue;
        for( k=1;k<=13;k++)
        {
            if(flag[k]||j==k) continue;
            if(i==0)
            {
                sum=j+k;
                if(sum>=1&&sum<=13&&sum!=j&&sum!=k)
                {
                    flag[j]=1;
                    flag[k]=1;
                    flag[sum]=1;
                    chan(1);
                    flag[j]=0;
                    flag[k]=0;
                    flag[sum]=0;
                }
            }
            else if(i==1)
            {
                 sum=j-k;
                if(sum>=1&&sum<=13&&flag[sum]==0&&sum!=j&&sum!=k)
                {
                    flag[j]=1;
                    flag[k]=1;
                    flag[sum]=1;
                    chan(2);
                    flag[j]=0;
                    flag[k]=0;
                    flag[sum]=0;
                }
            }
            else if(i==2)
            {
                 sum=j*k;
                if(sum>=1&&sum<=13&&flag[sum]==0&&sum!=j&&sum!=k)
                {
                    flag[j]=1;
                    flag[k]=1;
                    flag[sum]=1;
                    chan(3);
                    flag[j]=0;
                    flag[k]=0;
                    flag[sum]=0;
                }
            }
            else
            {
                 sum=j/k;
                if(sum>=1&&sum<=13&&flag[sum]==0&&sum!=j&&sum!=k&&sum*k==j)
                {
                    ans++;
                }
            }
        }
    }
    return ;
}
int main()
{
    int num=0;
    chan(0);
    cout<<ans;
    return 0;
}