#include<stdio.h>
#include<iostream>
using namespace std;//Ë®Ìâ
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int X,H,M,S,a=0,b=0,c=0,d=0;
        scanf("%d%d%d%d",&X,&H,&M,&S);
        a=32-X;
        if(H>0)
        {
            a--;
            b=24-H;
        }
        if(M>0)
        {
            if(b>0)
                b--;
            else
            {
                a--;
                b=23;
            }
            c=60-M;
        }
        if(S>0)
        {
            if(c>0)
            {
                c--;
            }
            else
            {
                if(b>0)
                    b--;
                else
                {
                    a--;
                    b=23;
                }
                c=59;
            }
            d=60-S;
        }
        printf("%d %d% d %d",a,b,c,d);
    }
    return 0;
}
