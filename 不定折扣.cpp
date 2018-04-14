#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char a[50][4],c[50][4];
    int num=0;
    double b[50]={},ans=0;
    int i=0;
    while(i<50)
    {
        scanf("%s%lf%s",&a[i],&b[i],&c[i]);
        if(c[i][0]<='9'&&c[i][0]>='0'&&strlen(c[i])!=3)//分三类
        {
            ans+=((c[i][0]-48)*0.1+(c[i][1]-48)*0.01)*b[i];
        }
        else if(strlen(c[i])==3)
            ans+=(c[i][0]-48)*0.1*b[i];
        else ans+=b[i]*0.5;

        i++;
    }
    num=(int)ans;
    if(num%100)
        printf("%d",num/100);
    else printf("%d",num/100+1);//整除100
}
