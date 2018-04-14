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
    //不可能单项礼包大于总和
    st[0]=min(a-n,n);//普通
    st[1]=min(b-n,n);//优惠
    st[2]=min(c,n);//豪华
    sort(st,st+3);
    if(min(st[0]+1+st[1],st[2])+st[0]+st[1]>=n)//最多者只能用到一部分，各部分最多礼包相加要不小于总和
        return true;
    return false;
}
int main()//二分较快
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
