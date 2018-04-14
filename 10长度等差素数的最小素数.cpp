#include<stdio.h>
#include<iostream>
using namespace std;
#define N 100000
int flag[10000]={},su[10000]={},num=0,is=0,v[10000]={},number=0,are=0,a[1000]={};
void sushu()
{
    su[num]=2;
    num++;
    su[num]=3;
    num++;
    for(int i=4;i<=10000;i++)
    {
        for(int j=2;j<=i/2;j++)
        {
            if((i%j)==0) {is=1;break;}
        }
        if(is) {is=0;continue;}
        else {su[num]=i;num++;v[i]=1;}
    }
}
int main()
{
    sushu();//Ô¤´¦ÀíÃ¶¾Ù
    for(int i=0;i<num;i++)
        for(int j=1;j<500;j++)
        {
            for(int k=1;k<=9;k++)
            {
                if(!v[su[i]+j*k]){are=1;break;}
            }
            if(are){are=0;continue;}
            else {a[number]=j;number++;}
        }
    for(int i=0;i<number;i++)
        printf("%d",a[i]);
    return 0;
}
