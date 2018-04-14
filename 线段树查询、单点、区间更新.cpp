
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#define M 100000
using namespace std;
int st[M*4+10]={},arr[M]={},lazy[M]={};
void pushdown(int node)//�ӳٱ��
{
    if(lazy[node]==0) return;//���ڲ����ϵ����䣬lazyΪ0���������
    st[node*2]+=lazy[node];
    st[node*2+1]+=lazy[node];
    lazy[node*2]+=lazy[node];
    lazy[node*2+1]+=lazy[node];
    lazy[node]=0;
}
void change(int node,int a,int b,int l,int r)//�������
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
    st[node]=min(st[node*2],st[node*2+1]);//�ı���������ܻ�Ӱ�쵽������
}
void update(int node,int a,int b,int c,int add)
{
    if(a==b)
    {
        st[node]=add;//ͨ�����������ҵ��˵㣬���е������
        return ;
    }
    if(c>(a+b)/2)//��������
        update(2*node+1,(a+b)/2+1,b,c,add);
    else
        update(2*node,a,(b+a)/2,c,add);
    st[node]=min(st[2*node],st[2*node+1]);//���ݸ��¸��ڵ�
}
void build(int node,int a,int b)//��ѯ������Сֵ
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
int query(int node,int a,int b,int l,int r)//l��r������Ϊ��ѯ����
{
    int p,q;
    if(l>b||r<a)
        return -1;
    if(l<=a&&r>=b)
        return st[node];
    pushdown(node);//������ѯʱ���޸�
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
