#include<stdio.h>
using namespace std;
int main()
{
    int n=0,ans=0;
    scanf("%d",&n);
    ans=n;
    while(n>=3)
    {
        ans+=n/3;
        n=n/3+n%3;//直接循环除3即可，剩余的留到下回
    }
    printf("%d",ans);
    return 0;
}
