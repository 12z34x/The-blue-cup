#include<stdio.h>
#include<iostream>
#include<iostream>
using namespace std;
int main()
{
    int n,flag,ans=2;
    scanf("%d",&n);
    if(n==2)
        printf("1\n");
    else if(n==3)
        printf("2\n");
    else
    {
        for(int i=4;i<=n;i++)
        {
            int flag=0;
            for(int j=2;j<=i/2;j++)
            {
                if(i%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(!flag)
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
