#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<queue>
using namespace std;
int main()//×î¶àN-1´Î
{
    int n=0,a[10010]={},ans=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==i)
            continue;
        else
        {
            int j=0;
            for( j=i+1;j<=n;j++)
            {
                if(a[j]==i) break;
            }
            swap(a[i],a[j]);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
