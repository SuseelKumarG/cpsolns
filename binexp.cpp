#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000007
int binexp(int a,int b);
int binmul(int a,int b);
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<binexp(a,b);
}
int binexp(int a, int b)
{
    int ans=1;
    while(b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        a=(a*a)%MAX;
        b>>=1;
    }
    return ans;
}
int binmul(int a,int b)
{
    int ans=0;
    while(b)
    {
        if(b&1)
        ans=(ans+a)%MAX;
        a=(a+a)%MAX;
        b>>=1;
    }
    return ans;
}