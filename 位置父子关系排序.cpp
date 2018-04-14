/*最好使用区间第k大实现*/
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
using namespace std;
struct Tree
{
    int next;
    int number;
    int flag[1000];
    int un;
}T[1000];
int p,n;
void bfs(int i,int j)
{
    if(j==p||i==p||i==n)return;
    else if(T[i].next>j) T[T[i].next].number++;
    bfs(T[i].next,j);
}
void affirm(int n)
{
    for(int i=0;i<T[n].un;i++)
    {
        if(T[T[n].flag[i]].next==0)
        {
            T[T[n].flag[i]].next=n;
            affirm(T[n].flag[i]);
        }
    }
    T[n].un=0;
}
int  main()
{
    int x,y;
    scanf("%d%d",&n,&p);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d%d",&x,&y);

        if(x==p) {T[y].next=p;
        affirm(y);
        }
        else if(y==p) {T[x].next=p;
        affirm(x);}
        else if(T[x].next!=0) {T[y].next=x;
        affirm(y);}
        else if(T[y].next!=0) {T[x].next=y;
        affirm(x);}
        else
        {
            T[x].flag[T[x].un]=y;
            T[x].un++;
            T[y].flag[T[y].un]=x;
            T[y].un++;
        }
    }
    for(int j=1;j<=n;j++)
    {
        bfs(j,j);
        printf("%d",T[j].number);
        if(j!=n)printf(" ");
       // else cout<<endl;
    }
    return 0;
}
