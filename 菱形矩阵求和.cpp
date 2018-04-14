#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
int main()
{
    long long  num=1,ans1=0,ans2=0,ans3=0,a[105][105]={};
    for(int i=1;i<=101;i++)
    {
        for(int j=1;j<=101;j++)
        {
            a[i][j]=num;
            num++;
            //cout<<a[i][j]<<" ";
        }
        //cout<<endl;
    }
    for(int i=1;i<=50;i++)
    {
        for(int j=51-(i-1);j<=51+(i-1);j++)
            ans1+=a[i][j];
    }
    for(int i=101;i>=52;i--)
    {
        for(int j=51-(101-i);j<=51+(101-i);j++)
            ans3+=a[i][j];
    }
    for(int i=1;i<=101;i++)
        ans2+=a[51][i];
    printf("%lld",ans1+ans2+ans3);
    return 0;
}
