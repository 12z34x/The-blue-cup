#include<stdio.h>
int f(int a,int b,int c,int n)
{
    if(a<0||b<0||c<0) return 0;
    if(n==0) return 1;
     return f(a-1,b,c,n-1)+f(a,b-1,c,n-1)+f(a,b,c-1,n-1);//ȡ��ĳ�����֡���ÿ�����ֽ��еݹ�
}
int main()
{
    printf("%d",f(1,1,1,2));
    printf("%d",f(1,2,3,3));
    return 0;
}
