#include<iostream>
#include<stdio.h>
#include<cstring>
#include<math.h>
#define N 100
using namespace std;
int main()
{
    char S[N]={},T[N]={};
    int dp1[N][N],dp2[N][N],M1=0,M2=0;
    char c;
    c=getchar();
    int s=0,t=0;
    while(c!='\n')
    {
        S[s]=c;
        c=getchar();
        s++;
    }
    c=getchar();
    while(c!='\n')
    {
        T[t]=c;
        c=getchar();
        t++;
    }
    memset(dp1,0,sizeof(dp1));
    for(int i=1;i<=s;i++)
        for(int j=1;j<=t;j++)
        {
            if(S[i-1]==T[j-1])
            {
                dp1[i][j]=dp1[i-1][j-1]+1;
            }
            if(M1<dp1[i][j]) M1=dp1[i][j];
        }
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=s;i++)
        for(int j=1;j<=t;j++)
        {
            if(S[i-1]==T[j-1])
            {
                dp2[i][j]=dp2[i-1][j-1]+1;
                if(M2<dp2[i][j]) M2=dp2[i][j];
            }
            else
            {
                dp2[i][j]=max(dp2[i][j-1],dp2[i-1][j]);
            }
        }
    cout<<M1<<" "<<M2<<endl;
    return 0;
}
