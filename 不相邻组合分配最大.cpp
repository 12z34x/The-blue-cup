#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<algorithm>
#define N 100005
using namespace std;
long long a,b,c,st[3];
bool chan(long long n)
{
    //�����ܵ�����������ܺ�
    st[0]=min(a-n,n);//��ͨ
    st[1]=min(b-n,n);//�Ż�
    st[2]=min(c,n);//����
    sort(st,st+3);
    if(min(st[0]+1+st[1],st[2])+st[0]+st[1]>=n)//�����ֻ���õ�һ���֣����������������Ҫ��С���ܺ�
        return true;
    return false;
}
int main()//���ֽϿ�
{
    int T,num=0;
    scanf("%d",&T);
    while(T--)
    {
        long long ans=0;
        scanf("%lld%lld%lld",&a,&b,&c);
        long long l=0,r=b;
        while(l<=r)
        {
            long long mid=(l+r);
            if(chan(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
