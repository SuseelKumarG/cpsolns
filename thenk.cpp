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
        int ans=1;
        while(n>>=1)
        ans++;
        ans=(1<<ans-1)-1;
        cout<<ans<<'\n';
    }
}