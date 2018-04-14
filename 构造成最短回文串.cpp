#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
char a[1000]={};
int ans=0;
int chan()
{
    int i=0,j=strlen(a)-1;
    while(i<j)
    {
        if(a[i]==a[j])
        {
            i++;
            j--;
        }
        else
        {
            int x=j,y=i;
            while(a[i]!=a[x])
                x--;
            while(a[j]!=a[y])
                y++;
            if(x==i&&y==j)//当i、j之间都不同时，+2向中间靠
            {
                i++;
                j--;
                ans+=2;//不知道中间夹几个，不可一步到位
                continue;
            }
            if((y-i)<=(j-x))//移动距离比较
            {
                ans+=y-i;//取短者
                i=y;//一步到位
            }
            else
            {
                ans+=j-x;
                j=x;
            }

        }
    }
}
int main()
{
    int i=0, n=0;
    char b;
    b=getchar();
    while(b!='\n')
    {
        a[i]=b;
        i++;
        b=getchar();
    }
    chan();
    printf("%d",ans);
    return 0;
}