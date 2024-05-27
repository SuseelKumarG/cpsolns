#include<bits/stdc++.h>
using namespace std;
long long pow1(int a,int b)
{
    if(b==1)
    return a;
    long long po=pow1(a,(b>>1));
    if(b&1)
    {
        return a*po*po;
    }
    else{
        return po*po;
    }
}
long long pow2(int a,int b)
{
    long long ans=1;
    while(b)
    {
        if(b&1)
        ans*=a;
        a*=a;
        b>>=1;
    }
    return ans;
}
int main()
{
    int a,b;
    cin>>a>>b;
    cout<<pow1(a,b)<<'\n';
    cout<<pow2(a,b)<<'\n';
    cout<<pow(a,b)<<'\n';
}