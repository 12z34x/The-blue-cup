#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
int y[3]={},m[3]={},d[3]={},mm=0,yy=0,dd=0,nian[3]={},yue[3]={},ri[3]={};
void chan(int x)
{
    char c[3]={};
    if(x<10)
    {
        c[0]='0';
        c[1]=x+48;

    }
    else
    {
        c[0]=x/10+48;
        c[1]=x%10+48;
    }
    cout<<c[0]<<c[1];
    return;
}
//闰年判断：(y%400)==0||((y%4)==0&&(y%100)!=0)
//年月日1-12 28 29 30 31
int main()
{
    int b[3]={};
    char a[9]={};
    scanf("%s",a);
    b[0]=(a[0]-48)*10+(a[1]-48);
    b[1]=(a[3]-48)*10+(a[4]-48);
    b[2]=(a[6]-48)*10+(a[7]-48);
    for(int i=0;i<3;i++)
    {
        if(b[i]<60) b[i]+=100;
    }
    sort(b,b+2);
    for(int n=0;n<3;n++)
    {
        if(b[n]>100)b[n]-=100;
        if(b[n]>=1&&b[n]<=12)
        {
            m[mm]=b[n];
            yue[mm]=n;
            mm++;
        }
        if(1<=b[n]&&b[n]<=31) {d[dd]=b[n];ri[dd]=n;dd++;}
        y[yy]=b[n];
        nian[yy]=n;
        yy++;

    }
    for(int i=0;i<dd;i++)
        {
            for(int j=0;j<mm;j++)
            {

                if(yue[j]==ri[i])continue;
                for(int k=0;k<yy;k++)
                {

                    if(nian[k]==yue[j]||nian[k]==ri[i])continue;

		    if(y[k]%400==0||(y[k]%100!=0&&y[k]%4==0))
            {
                if((m[j]==4||m[j]==6||m[j]==9||m[j]==11)&&d[i]>30)continue;
                else if(m[j]==2&&d[i]>29)continue;
            }
            else {
                if((m[j]==4||m[j]==6||m[j]==9||m[j]==11)&&d[i]>30)continue;
                else if(m[j]==2&&d[i]>28)continue;
            }
                    if(0<=y[k]&&y[k]<=59)
                    {
                        printf("20");
                        chan(y[k]);
                        cout<<'-';
                        chan(m[j]);
                        cout<<'-';
                        chan(d[i]);
                        cout<<endl;
                    }
                    else
                    {
                        printf("19");
                        chan(y[k]);
                        cout<<'-';
                        chan(m[j]);
                        cout<<'-';
                        chan(d[i]);
                        cout<<endl;
                    }
                }
                }
        }
    return 0;

}
