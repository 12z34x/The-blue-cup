#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#define N 100005
using namespace std;
int  gcb(int a,int b)
{
    int t;
    if(b<a)
    {
        t=a;
        a=b;
        b=t;
    }
    if((b%a)==0) return a;
    return gcb(b%a,a);
}
int main()
{
    int T,n,m;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                for(int k=1;k<=n;k++)
                    for(int l=1;l<=m;l++)
                    {
                        if(k==i&&l==j) continue;
                        else
                        {
                            int a=k-i;
                            int b=l-j;
                            if(a==0||b==0) continue;
                            if(gcb(abs(a),abs(b))!=1)continue;
                            else ans++;
                        }
                    }
            }
            printf("%d",ans/2+n+m);
    }
    return 0;
}
