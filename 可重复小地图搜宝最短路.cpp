#include<stdio.h>
#include<iostream>
#include<cstring>
#include<queue>
#define N 15
#define sum 5
using namespace std;
struct myth
{
    int x;
    int y;
    int num;
    int sweet;
    int b[N][N];
}S;
int main()//小地图BFS寻宝
{
    int st[N][N]={},n,m,ans;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&st[i][j]);//0表示可行，1表示不可，2表示宝藏
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
    st[1][1]=3;
    S.x=1;
    S.y=1;
    S.num=0;
    S.sweet=sum;
    int flag=0;
    queue<myth>E;
    E.push(S);
    while(!E.empty())
    {
        //cout<<E.front().x<<" "<<E.front().y<<" "<<E.front().num<<" "<<E.front().sweet<<" "<<endl;
        if(st[E.front().x][E.front().y]==2&&E.front().sweet!=0)
        {
            E.front().sweet--;
            E.front().b[E.front().x][E.front().y]=1;
        }
        if(st[E.front().x][E.front().y]==3&&E.front().sweet==0)
        {
            ans=E.front().num;
            break;
        }
        else if(st[E.front().x][E.front().y]==3&&E.front().sweet!=0&&flag!=0)
        {
            E.pop();
            continue;
        }
        if(st[E.front().x+1][E.front().y]!=1&&E.front().b[E.front().x+1][E.front().y]!=1)
        {
            myth A;
            A.x=E.front().x+1;
            A.y=E.front().y;
            A.num=E.front().num+1;
            A.sweet=E.front().sweet;
            memcpy(A.b,E.front().b,sizeof(A.b));
            E.push(A);
        }
        if(st[E.front().x][E.front().y+1]!=1&&E.front().b[E.front().x][E.front().y+1]!=1)
        {
            myth A;
            A.x=E.front().x;
            A.y=E.front().y+1;
            A.num=E.front().num+1;
            A.sweet=E.front().sweet;
            memcpy(A.b,E.front().b,sizeof(A.b));
            E.push(A);
        }
        if(st[E.front().x][E.front().y-1]!=1&&E.front().b[E.front().x][E.front().y-1]!=1)
        {
            myth A;
            A.x=E.front().x;
            A.y=E.front().y-1;
            A.num=E.front().num+1;
            A.sweet=E.front().sweet;
            memcpy(A.b,E.front().b,sizeof(A.b));
            E.push(A);
        }
        if(st[E.front().x-1][E.front().y]!=1&&E.front().b[E.front().x-1][E.front().y]!=1)
        {
            myth A;
            A.x=E.front().x-1;
            A.y=E.front().y;
            A.num=E.front().num+1;
            A.sweet=E.front().sweet;
            memcpy(A.b,E.front().b,sizeof(A.b));
            E.push(A);
        }
        E.pop();
        flag=1;
    }
    printf("%d",ans);
    return 0;
}
/*
3 0 0 0 0 0 0 2 0 1
0 0 0 1 0 0 2 0 0 1
0 1 0 0 2 0 0 1 0 1
0 2 0 0 0 1 0 0 2 1
0 1 0 0 2 0 1 0 0 1
0 0 1 0 0 0 0 1 0 1
0 0 0 0 0 1 0 0 2 1
0 1 0 1 0 0 2 0 0 1
0 2 0 0 0 0 1 1 0 1
0 0 1 0 0 1 2 0 0 1


3 0 0 0 0 1
0 2 0 1 0 0
2 0 1 2 0 2
*/
