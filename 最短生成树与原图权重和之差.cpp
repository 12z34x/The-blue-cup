#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#define M 1000
using namespace std;
int father[M],sonnum[M];
struct Edge
{
    int from;
    int to;
    int value;
};
bool cmp(Edge p,Edge q)
{
    return p.value<q.value;//����ȽϺ�����>Ϊ����
}
int unionsearch(int v)
{
    if(father[v]==v)//�ҵ����ڵ�
        return v;
    else return unionsearch(father[v]);
}

bool join(int x, int y)//�ϲ�x��y
{
    int root1, root2;
    root1 = unionsearch(x);//ÿ�����ݶ���һ���������ȣ�
    root2 = unionsearch(y);
    if (root1 == root2) //����������һ����˵���Ѿ�����ͬһ�����ˣ������ٺϲ���
        return false;
    else if (sonnum[root1] >= sonnum[root2]) //���root1�Ķ�����Ŀ�Ƚ϶࣬���root2�����ȶ�Ϊroot1��ͬʱroot1�Ķ�����Ŀ����
    {
        father[root2] = root1;
        sonnum[root1]= sonnum[root1] + sonnum[root2];
    }
    else
    {
        father[root1] = root2;
        sonnum[root2]= sonnum[root1] + sonnum[root2];
    }
    return true;
}
int main()//��³˹������С������
{
    int v,e,a,b,c,T;
    scanf("%d",&T);
    while(T--)
    {
        int ans=0,sum=0,num=0,flag=0;
        Edge edge[M];
        scanf("%d%d",&v,&e);
        for(int i=1;i<=v;i++)
        {
            father[i]=i;
            sonnum[i]=1;
        }
        for(int i=1;i<=e;i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            edge[i].from=a;
            edge[i].to=b;
            edge[i].value=c;
            sum+=c;
        }
        sort(edge+1,edge+e+1,cmp);//��ʵsortĬ�ϼ�Ϊ����
        for(int i=1;i<=e;i++)
        {
            if(join(edge[i].from,edge[i].to))
            {
                num++;
                ans+=edge[i].value;
            }
            if(num==v-1)
            {
                flag=1;
                break;
            }
        }
        if(flag)
            cout<<sum-ans<<endl;
        else
            cout<<"ERROR DATE"<<endl;
    }
    return 0;
}
