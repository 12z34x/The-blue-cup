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
            if(x==i&&y==j)//��i��j֮�䶼��ͬʱ��+2���м俿
            {
                i++;
                j--;
                ans+=2;//��֪���м�м���������һ����λ
                continue;
            }
            if((y-i)<=(j-x))//�ƶ�����Ƚ�
            {
                ans+=y-i;//ȡ����
                i=y;//һ����λ
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