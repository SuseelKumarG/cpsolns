#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int x=sqrt(n);
        cout<<x-1+ceil((n-x)/(float)x)<<'\n';
    }
}