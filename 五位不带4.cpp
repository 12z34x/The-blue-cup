#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
int main()
{
    long long ans=0;
    for(long long  i=10000;i<=99999;i++)
    {
        if(i%10==4) continue;
        if((i/10)%10==4)continue;
        if((i/100)%10==4) continue;
        if((i/1000)%10==4) continue;
        if(i/10000==4) continue;
        ans++;
    }
    printf("%lld\n",ans);
    return 0;
}
