#include<stdio.h>
#include<iostream>
#include<queue>
#include<string.h>
#define N 9
using namespace std;
struct node//定义结构体存储步数以及字符串
{
    int num;
    char s[N+1];
}T;
queue<node>L;
char save[370000][N+1]={};//至少开37万
int snum=0;
bool chan(char *a)
{
    int flag=0;
    for(int i=0;i<snum;i++)
        if(strcmp(a,save[i])==0) {flag=1;break;}//检验是否完全相同
    if(flag) return false;
    return true;
}
int main()
{
    char a[N+1]="123456789",b[N+1]="876543219";
            char l[N+1],r[N+1],x[N+1],y[N+1];
    strcpy(T.s,a);
    T.num=1;
    L.push(T);
    strcpy(save[snum],T.s);
    snum++;
    char t;
    while(!L.empty())
    {
        //cout<<L.front().s<<endl;
        if(strcmp(L.front().s,b)==0) break;
        for(int i=0;i<N;i++)
        {
            if(L.front().s[i]!='9')
                continue;
            else
            {
                strcpy(l,L.front().s);
                strcpy(x,L.front().s);
                strcpy(r,L.front().s);
                strcpy(y,L.front().s);
                t=l[(i+N-2)%N];
                l[(i+N-2)%N]=l[i];
                l[i]=t;
                t=x[(i+N-1)%N];
                x[(i+N-1)%N]=x[i];
                x[i]=t;
                t=r[(i+2)%N];
                r[(i+2)%N]=r[i];
                r[i]=t;
                t=y[(i+1)%N];
                y[(i+1)%N]=y[i];
                y[i]=t;
                break;
            }
        }//重复情况不进队
        if(chan(l))
        {
            strcpy(save[snum],l);
            snum++;
            node ll;
            ll.num=1;
            strcpy(ll.s,save[snum-1]);
            ll.num+=L.front().num;
            L.push(ll);
        }
        if(chan(x))
        {
            strcpy(save[snum],x);
            snum++;
            node xx;
            xx.num=1;
            strcpy(xx.s,save[snum-1]);
            xx.num+=L.front().num;
            L.push(xx);
        }
        if(chan(r))
        {
            strcpy(save[snum],r);
            snum++;
            node rr;
            rr.num=1;
            strcpy(rr.s,save[snum-1]);
            rr.num+=L.front().num;
            L.push(rr);
        }
        if(chan(y))
        {
            strcpy(save[snum],y);
            snum++;
            node yy;
            yy.num=1;
            strcpy(yy.s,save[snum-1]);
            yy.num+=L.front().num;
            L.push(yy);
        }
        L.pop();
    }
    cout<<L.front().num-1<<"  "<<L.front().s;
    return 0;
}
