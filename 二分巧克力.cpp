#include<stdio.h>
#include<iostream>
using namespace std;
int n,k,a[100000]={},b[100000]={};
bool chan(int x,int y)
{
    int sum=0;
    for(int j=0;j<n;j++)
    {
        sum+=(a[j]/x)*(b[j]/y);//����һ��Ҳ��Ҫ
    }
    if(sum>=k) return 1;//���㹻k��������
    else return 0;
}
int main()
{
    int low=1,high=100000,mid;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
    }
    while(low<high-1)//low����ӽ��𰸺�low�����x^2���У�(x-1)(x+1)�ض�����
    {
        mid=(low+high)/2;
        if(chan(low,high))
        {
            low=mid;//������
        }
        else high=mid;
    }
    printf("%d",low);
}
