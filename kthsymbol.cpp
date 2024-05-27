#include<bits/stdc++.h>
using namespace std;
int gen(int n,int k)
{
    if(n==1 && k==1)
    return 0;
    int mid=pow(2,n-2);
    if(k>mid)
    {
        int i=gen(n-1,k-mid);
        if(i)
        return 0;
        else
        return 1;
    }
    if(k<=mid)
    {
        return gen(n-1,k);
    }
}
int main()
{
    int n,k;
    cin>>n>>k;
    cout<<gen(n,k)<<'\n';
}