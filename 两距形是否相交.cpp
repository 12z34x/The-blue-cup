#include<stdio.h>
#include<iostream>
using namespace std;
bool is(double a1,double a2,double b1,double b2)//函数类型可为布尔型
{
    return a2>=b1&&a1<=b2;
}
int main()//X、Y双区间判断满足通式即可。
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        double x1,y1,x2,y2,x3,y3,x4,y4;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(x1>x2)
            swap(x1,x2);
        if(y1>y2)
            swap(y1,y2);
        if(x3>x4)
            swap(x3,x4);
        if(y3>y4)
            swap(y3,y4);
        if(is(x1,x2,x3,x4)&&is(y1,y2,y3,y4))
            printf("YES");
        else printf("NO");
    }
    return 0;
}
