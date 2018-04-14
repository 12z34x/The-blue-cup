 #include<stdio.h>
 #include<iostream>
 using namespace std;
 long long  a[13]={},ans=0;
 void dfs(int x,int number)//每个数字number张
 {
    if(number>13) return;
    if(x==13)//总共x张
    {
        if(number==13)
            ans++;
        return;
    }
    else
    {
        //cout<<x<<" "<<num<<" "<<number<<" "<<ans<<endl;
        for(int j=0;j<5;j++)
            dfs(x+1,number+j);
    }
 }
 int main()
 {
     for(int i=0;i<5;i++)
        dfs(1,i);//第一张开始
    cout<<ans;
     return 0;
 }
