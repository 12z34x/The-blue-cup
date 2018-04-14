#include<stdio.h>
#include<string.h>
#include<iostream>
#define N 100000
using namespace std;
int sum1[N]={},sum2[2*N]={},carry=0,length=0;
char ans[N]={};
void pluser(char a[N])//大数加法
{
    for(int i=strlen(a)-1,j=0;i>=0;i--,j++)
    {
        sum1[j]+=a[i]-'0';
        if(sum1[j]>10)
        {
            sum1[j]-=10;
            sum1[j+1]++;
        }
    }
}
void re(char z[N])//字符串逆序
{
    char t;
    int n=strlen(z)-1;
    for(int i=0;i<(n/2+1);i++)
    {
        t=z[i];
        z[i]=z[n-i];
        z[n-i]=t;
    }

}
void  Multi(char c[N],char d[N])//大数乘法
{
    re(c);
    re(d);
    int m1,m2;
    m1=strlen(c);
    m2=strlen(d);
    length=m1+m2;
    for(int i=0;i<m1;i++)
        for(int j=0;j<m2;j++)
        {
            carry=sum2[i+j]+((c[i]-'0')*(d[j]-'0'));
            sum2[i+j]=carry%10;
            sum2[i+j+1]+=carry/10;
        }
}
void except(char p[N],int q)//大数除法
{
    int cmp=0,ok=0;
    for(int i=0,j=0;i<strlen(p);i++)
    {
        cmp=cmp*10+p[i]-48;
        if(cmp>=q)
        {
            ok=1;
            ans[j]=cmp/q+48;
            j++;
            cmp%=q;
        }
        else
        {
            if(ok)
            {
                ans[j]='0';
                j++;
            }

        }
    }
}
using namespace std;
int main()
{
    char a[N]={},b[N]={},x[N]={},y[N]={},E[2*N];
    int num=0,number=0,many=0,much=0,flag=1,fu=0;
    while(scanf("%s",&a)==1)
    {
        if(a[0]=='0') break;
        else if(a[0]=='-')//消除负号
        {
            fu++;
            for(int i=0;i<strlen(a);i++)
                a[i]=a[i+1];
        }
        //pluser(a);
        if(number==0)
        {
            strcpy(x,a);
            number++;
        }
        else if(number==1)
        {
            strcpy(y,a);
            number++;
        }
    }

    /*Multi(x,y);
    for(many=length;many>=1;many--)
    {
        if(flag)
        {
            if(sum2[many])
            {
                E[much]=sum2[many]+48;
                much++;
                flag=0;
            }
        }
        else
        {
            E[much]=sum2[many]+48;
            much++;
        }
    }
    E[much]=sum2[0]+48;
    if(fu%2==1)
        putchar('-');
    printf("%s",E);*/
    except(x,5);
    printf("%s",ans);
    /*for(num=N;num>=0&&(sum1[num]==0);num--);
    if(num>=0)
    {
        for(int i=0;num>=0;num--,i++)
            b[i]=sum1[num]+48;
    }
    printf("%s",b);*/
    return 0;
}

