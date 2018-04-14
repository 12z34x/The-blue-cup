#include<cstdio>
#include<iostream>
#include<cstring>
#define N 110
using namespace std;
char S[N]={},T[N]={};
int next[N];
int getnext()
{
    int j=0,k=-1;
    next[0]=-1;
    while(j<strlen(T))
    {
        if(k==-1||T[j]==T[k])
            next[++j]=++k;
        else k=next[k];
    }
}
int KMP()
{
    int ans=0,j=0;
    if(strlen(S)==1&&strlen(T)==1)
        if(S[0]==T[0]) return 1;
        else return 0;
    for(int i=0;i<strlen(S);i++)
    {
        while(j>0&&S[i]!=T[j])
            j=next[j];
        if(T[j]==S[i])
                j++;
        if(j==strlen(T))
        {
            ans++;
            j=next[j];
        }
    }
    return ans;
}
int main()
{
    int s=0,t=0;
    char c;
    c=getchar();
    while(c!='\n')
    {
        S[s]=c;
        s++;
        c=getchar();
    }
    c=getchar();
    while(c!='\n')
    {
        T[t]=c;
        t++;
        c=getchar();
    }
    printf("%d",KMP());
    return 0;
}
