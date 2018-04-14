#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int a[1000],c,num=1;
    int i=0;
    scanf("%d",&c);
    for(int i=0;i<c;i++)
    {
        scanf("%d",&a[i]);
        if(i==0) continue;
        else
        {
            if(a[i-1]!=a[i])
                num++;
        }
    }
    printf("%d\n",num);
    return 0;
}
