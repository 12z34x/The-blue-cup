#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{

    for(int i=1;i<=48;i++)
    {
        for(int j=i+2;j<=48;j++)
        {
                int ans=1225;
                ans-=i+i+1+j+j+1;
                ans+=i*(i+1)+j*(j+1);
                if(ans==2015)
                {
                    cout<<i<<endl;
                }
        }
    }
    return 0;
}
