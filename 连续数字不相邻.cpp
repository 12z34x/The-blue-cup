#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;
int ans=0,flag[10]={}, a[3][4]={};
void dfs(int x,int y,int num)//num为此时点
{

    if(x==2&&y==2) {ans++;flag[num]=0;return;}
    a[x][y]=num;
    //cout<<x<<y<<" "<<endl;
    flag[num]=1;

    for(int i=0;i<=9;i++)
    {
        if(flag[i]||abs(i-num)<=1)continue;
        else if(x==0)
        {
            if(y<3)
                dfs(x,y+1,i);
            else {if(abs(a[x][y-1]-i)<=1)continue;
            else dfs(x+1,y,i);}
        }
        else if(x==1)
        {
            if(y>1)
            {
                if(y==3)
                {
                    if(abs(a[x-1][y-1]-i)<=1||abs(a[x-1][y-2]-i)<=1||abs(a[x-1][y]-i)<=1)continue;

                else dfs(x,y-1,i);
                }
                else {if(abs(a[x-1][y-1]-i)<=1||abs(a[x-1][y]-i)<=1)continue;else dfs(x,y-1,i);

                }
            }
            else if(y==1){if(abs(a[x-1][y]-i)<=1)continue;else dfs(x,y-1,i);}
            else
            {
                if(abs(a[x][y+1]-i)<=1) continue;
                else dfs(x+1,y,i);
            }
        }
        else
        {
            if(y<2)
            {
                 //cout<<a[x-1][y-1]<<"  "<<i<<" !!!"<<endl;
                if(abs(a[x-1][y+1]-i)<=1||abs(a[x-1][y+2]-i)<=1||abs(a[x-1][y]-i)<=1)continue;
                else dfs(x,y+1,i);
            }

        }
    }
    flag[num]=0;
    a[x][y]=0;
}
int main()
{
    int num;
    for(int i=0;i<=9;i++)
    {
        dfs(0,1,i);
        flag[i]=0;
    }
    cout<<ans;
    return 0;
}











