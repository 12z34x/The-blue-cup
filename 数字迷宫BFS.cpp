#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#define N 100
using namespace std;
struct myth
{
    int x;
    int y;
    int lx;
    int ly;
    int num;
}S;
int main()
{
    int st[N][N]={},n,m,ans;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&st[i][j]);//0可行，1障碍，2出口
        }
    for(int i=0;i<=n+1;i++)
    {
        st[i][0]=1;
        st[i][m+1]=1;
    }
    for(int j=0;j<=m+1;j++)
    {
        st[0][j]=1;
        st[n+1][j]=1;
    }
    st[1][1]=0;
    S.x=1;
    S.y=1;
    S.lx=0;
    S.ly=0;
    S.num=0;
    queue<myth>E;
    E.push(S);
    while(!E.empty())
    {
        if(st[E.front().x][E.front().y]==2)
        {
            ans=E.front().num;
            break;
        }
        if(st[E.front().x+1][E.front().y]!=1&&E.front().lx!=(-1))
        {
            myth A;
            A.x=E.front().x+1;
            A.y=E.front().y;
            A.lx=1;
            A.ly=0;
            A.num=E.front().num+1;
            E.push(A);
        }
        if(st[E.front().x][E.front().y+1]!=1&&E.front().ly!=(-1))
        {
            myth A;
            A.x=E.front().x;
            A.y=E.front().y+1;
            A.lx=0;
            A.ly=1;
            A.num=E.front().num+1;
            E.push(A);
        }
        if(st[E.front().x][E.front().y-1]!=1&&E.front().ly!=1)
        {
            myth A;
            A.x=E.front().x;
            A.y=E.front().y-1;
            A.lx=0;
            A.ly=-1;
            A.num=E.front().num+1;
            E.push(A);
        }
        if(st[E.front().x-1][E.front().y]!=1&&E.front().lx!=1)
        {
            myth A;
            A.x=E.front().x-1;
            A.y=E.front().y;
            A.lx=-1;
            A.ly=0;
            A.num=E.front().num+1;
            E.push(A);
        }
        E.pop();
    }
    printf("%d",ans);
    return 0;
}
