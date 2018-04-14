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
    return p.value<q.value;//升序比较函数，>为降序
}
int unionsearch(int v)
{
    if(father[v]==v)//找到父节点
        return v;
    else return unionsearch(father[v]);
}

bool join(int x, int y)//合并x与y
{
    int root1, root2;
    root1 = unionsearch(x);//每个数据都有一个根（祖先）
    root2 = unionsearch(y);
    if (root1 == root2) //两个的祖先一样，说明已经属于同一颗树了，不用再合并了
        return false;
    else if (sonnum[root1] >= sonnum[root2]) //如果root1的儿子数目比较多，则把root2的祖先定为root1，同时root1的儿子数目更新
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
int main()//克鲁斯卡尔最小生成树
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
        sort(edge+1,edge+e+1,cmp);//其实sort默认即为升序
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
