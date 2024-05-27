#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
#define MAX 1000000007



void solve()
{
    int n,k;
    cin>>n>>k;
    int ans=1;
    if(n%k)
    {for(int i=1;i*i<=n;i++)
    {
        if(!(n%i))
        {
            if(k<=i)
            ans=max(ans,n/i);
            if(k<=n/i)
            ans=max(ans,i);
        }
    }}
    else
    ans=n/k;
    cout<<ans<<'\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}