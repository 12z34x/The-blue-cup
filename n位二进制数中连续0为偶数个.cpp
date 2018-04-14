#include<iostream>
#include<stdio.h>
using namespace std;
int num=0,flag=0,st[10000]={},dp[10][1024];
void check(int m)
{
        for(int k=0;k<m;k++)
        {
            for(int j=0;j<=9;j++)
            {
                if((k>>j)%2==1)
                {
                    if(flag%2==0){continue;}
                    else break;
                }
                else
                {
                    flag++;
                }
            }
            if(flag%2!=0) {flag=0;continue;}
            else
            {
                st[num]=k;
                flag=0;
                cout<<st[num]<<endl;
                num++;
            }
        }
}
int main()
{
    int ans=0,n;
    scanf("%d",&n);
    check(2<<(n-1));//×óÒÆn-1Î»
    cout<<ans;
    return 0;
}
