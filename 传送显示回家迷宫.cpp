#include<stdio.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#define M 12
int c[M][M][2]={},t;
bool first;
bool ans;
char a[M][M],b[M][M];
using namespace std;
void dfs(int x,int y,int which)
{
    if(ans)return;
    if(which)
    {
        if(b[x][y]=='P')
        {
            ans=true;
            return ;
        }
    }
    else
    {
        if(a[x][y]=='P')
        {
            ans=true;
            return ;
        }
    }
    if(t==0) return ;
    if(first)
    {
        if(c[x][y][which]==1) return;
        c[x][y][which]=1;
        if(!which)
        {
            if(a[x][y]=='*') return;
        }
        else
        {
            if(b[x][y]=='*') return;
        }
    }
    else first=true;

    if(!which)
    {
        if(a[x][y]=='#'&&b[x][y]=='#')
        {
            return;
        }
        else if(a[x][y]=='#')
        {
            which=1;
            dfs(x,y,which);
            c[x][y][0]=0;
            return;
        }
    }
    else
    {
        if(b[x][y]=='#'&&a[x][y]=='#')
        {
            return;
        }
        else if(b[x][y]=='#')
        {
            which=0;
            dfs(x,y,which);
            c[x][y][1]=0;
            return;
        }
    }
    t--;
    dfs(x-1,y,which);
    dfs(x+1,y,which);
    dfs(x,y-1,which);
    dfs(x,y+1,which);
    t++;
    c[x][y][which]=0;
    return ;
}
int main()
{
   int C,m,n;
   char ch;
   scanf("%d",&C);
   while(C--)
   {
       int x,y;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        scanf("%d%d%d",&n,&m,&t);
        getchar();//吃掉上次的回车
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m+1;j++)//暂时牺牲m+1列
            {
                ch=getchar();
                if(ch=='.'||ch=='*'||ch=='#'||ch=='P')
                    a[i][j]=ch;
                else if(ch=='S')
                {
                    x=i;
                    y=j;
                    a[i][j]=ch;
                }
            }

        }
        for(int i=0;i<=m+1;i++)
        {
            a[0][i]='*';
            a[n+1][i]='*';
        }
        for(int j=0;j<=n+1;j++)
        {
            a[j][0]='*';
            a[j][m+1]='*';
        }
        //这次不用吃掉上次的回车
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m+1;j++)//暂时牺牲m+1列
            {
                ch=getchar();
                if(ch=='.'||ch=='*'||ch=='#'||ch=='P')
                    b[i][j]=ch;
                else if(ch=='S')
                {
                    x=i;
                    y=j;
                    b[i][j]=ch;
                }
            }

        }
        for(int i=0;i<=m+1;i++)
        {
            b[0][i]='*';
            b[n+1][i]='*';
        }
        for(int j=0;j<=n+1;j++)
        {
            b[j][0]='*';
            b[j][m+1]='*';
        }
        c[x][y][0]=1;
        dfs(x,y,0);
        cout<<ans<<endl;
    if(ans) printf("YES");
    else printf("NO");
   }
    return 0;
}
/*for(int i=0;i<=n+1;i++)
        {
            for(int j=0;j<=m+1;j++)
                putchar(b[i][j]);
            putchar('\n');
        }
5 5 14
S*#*.
.#...
.....
****.
...#.
..*.P
#.*..
***..
...*.
*.#..

        */
