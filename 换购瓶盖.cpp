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
        n=n/3+n%3;//ֱ��ѭ����3���ɣ�ʣ��������»�
    }
    printf("%d",ans);
    return 0;
}
