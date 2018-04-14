#include<stdio.h>
#include<iostream>
using namespace std;
int main()//±©Á¦Ä£Äâ
{
    char str[101]={};
    int sum=0,a[5][50]={};
    int flag=0,step=0;
    int  sw[10]={},t=0;
    scanf("%s",str);
    int i=0;
    while(str[i]=='x'||str[i]=='|'||str[i]=='('||str[i]==')')
    {
        switch(str[i])
        {
        case 'x':
            {
                a[flag][sw[flag]]++;
                cout<<a[flag][sw[flag]]<<"  "<<sw[flag]<<"  "<<flag<<endl;
                break;
            }
        case '(':
               {
                    flag++;
                    a[flag][sw[flag]]=0;
                    break;
               }
        case ')':
            {
                t=a[flag][0];
                for(int j=0;j<=sw[flag];j++)
                {
                    if(a[flag][j]>t)t=a[flag][j];
                }
                a[flag][sw[flag]]=0;
                sw[flag]=0;
                flag--;
                a[flag][sw[flag]]+=t;
                break;
            }
        case '|':
            {
                sw[flag]++;
                break;
            }
            default:break;
        }
        i++;
    }
    t=a[flag][0];
    for(int j=0;j<=sw[flag];j++)
    {
        cout<<a[flag][j];
        if(a[flag][j]>t)t=a[flag][j];
    }
    sum=t;
    printf("%d",sum);
}
//xxx|()|(xx|x)||xx(x)  ((xx|xxx)x|(x|xx))xx
