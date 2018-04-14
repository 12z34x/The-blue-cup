
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define M 100000
using namespace std;
int st[M*4+10]={},arr[M]={},lazy[M]={};
void pushdown(int node)//延迟标记
{
    if(lazy[node]==0) return;//对于不符合的区间，lazy为0，不会添加
    st[node*2]+=lazy[node];
    st[node*2+1]+=lazy[node];
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
}
void change(int node,int a,int b,int l,int r)//区间更新
{
    if(a>=l&&b<=r)
    {
        st[node]++;
        lazy[node]++;
        return;
    }
    pushdown(node);
    if(l<=(a+b)/2) change(2*node,a,(a+b)/2,l,r);
    if(r>=(a+b)/2+1) change(2*node+1,(a+b)/2,b,l,r);
    st[node]=min(st[node*2],st[node*2+1]);//改变子区间可能会影响到父区间
}
void update(int node,int a,int b,int c,int add)
{
    if(a==b)
    {
        st[node]=add;//通过二分区间找到此点，进行单点更新
        return ;
    }
    if(c>(a+b)/2)//二分区间
        update(2*node+1,(a+b)/2+1,b,c,add);
    else
        update(2*node,a,(b+a)/2,c,add);
    st[node]=min(st[2*node],st[2*node+1]);//回溯更新父节点
}
void build(int node,int a,int b)//查询区间最小值
{
    if(a==b)
        st[node]=arr[a];
    else
    {
        build(2*node,a,(b+a)/2);
        build(2*node+1,(a+b)/2+1,b);
        if(st[node*2]<=st[2*node+1])
            st[node]=st[node*2];
        else st[node]=st[2*node+1];
    }
}
int query(int node,int a,int b,int l,int r)//l、r的区间为查询区间
{
    int p,q;
    if(l>b||r<a)
        return -1;
    if(l<=a&&r>=b)
        return st[node];
    pushdown(node);//真正查询时才修改
    p=query(2*node,a,(a+b)/2,l,r);
    q=query(2*node+1,(a+b)/2+1,b,l,r);

    if(p==-1)
        return q;
    if(q==-1)
        return p;
    if(p<=q)
        return p;
    else return q;
}
int main()
{
    int n,m,x,y,f[M],p,num=0;
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }

    build(1,0,m-1);
    for(int j=0;j<n;j++)
    {
        scanf("%d%d%d",&p,&x,&y);
        if(p==1)
        {
            f[num]=query(1,0,m-1,x-1,y-1);
            num++;
        }
        else if(p==2)
        {
            update(1,0,m-1,x-1,y-1);
        }
        else change(1,0,m-1,x-1,y-1);
    }
    for(int j=0;j<num-1;j++)
        printf("%d ",f[j]);
    printf("%d",f[num-1]);
    return 0;
}
