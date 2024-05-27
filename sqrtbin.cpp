#include<bits/stdc++.h>
using namespace std;
#define eps 1e-5
int main()
{
    double n;
    cin>>n;
    double hi=n,lo=1;
    double mid=(hi+lo)/2;
    while(hi-lo>eps)
    {
        if((mid*mid)>n)
        {
            hi=mid;
        }
        else
        lo=mid;
        mid=(hi+lo)/2;
    }
    cout<<mid<<'\n';
}