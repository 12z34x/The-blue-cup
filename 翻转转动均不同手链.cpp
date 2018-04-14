#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>//包含全排列库
#define N 12
using namespace std;
int num=0;
char str[10000][N]={};
bool chan(int anw[N])
{
    int flag=0;
    for(int i=0;i<num;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(anw[j]==str[i][j])
            {
                flag++;
            }
        }
        if(flag==12) {return false;}//检验是否完全重复
        else flag=0;
    }
    return true;
}
//手链翻转后也不在时,才可要。
int main()
{
    int  a[N]={1,1,1,2,2,2,2,3,3,3,3,3},b[N]={},vis=0;
    for(int j=0;j<N;j++)
    {
        str[num][j]=a[j];
    }
    num++;//数量
    do
    {
        int c[N]={},vis=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                c[(j+i)%N]=a[j];//左右平移j次
            }
            if(!chan(c))
            {
                vis=1;
                break;
            }
        }
        if(vis) continue;
        for(int j=0;j<N;j++)
        {
            b[j]=a[j];
        }
        reverse(b,b+12);//翻转reverse()函数
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                c[(j+i)%N]=b[j];
            }
            if(!chan(c))
            {
                vis=1;
                break;
            }
        }
        if(vis) continue;
        else
        {
            for(int j=0;j<N;j++)
            {
                str[num][j]=a[j];
            }
            num++;
        }
    }
    while(next_permutation(a,a+N));//下一个全排列
    cout<<num;
    return 0;
}
