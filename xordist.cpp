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
typedef vector<bool> vb;
#define MAX 1000000007

void solve()
{
    ll a,b,r;
    cin>>a>>b>>r;
    if(a==b)
    {
        cout<<0<<'\n';
        return;
    }
    if(a<b)
    {
        swap(a,b);
    }
    vi x,y;
    // cout<<a<<' '<<b<<'\n';
    while(a)
    {
        x.push_back(a&1);
        a>>=1;
    }
    while(b)
    {
        y.push_back(b&1);
        b>>=1;
    }
    int n=x.size();
    for(int i=y.size();i<n;i++)
    y.push_back(0);
    bool firstbit=1;
    ll c=0;
    for(int i=n-1;i>=0;i--)
    {
        if(y[i])
        b+=(1LL<<i);
        if(x[i])
        a+=(1LL<<i);
        if(x[i]!=y[i])
        {
            if(firstbit)
                firstbit=0;
            else
            {
                // a+=(1LL<<i);
                if(x[i] && c+(1LL<<i)<=r)
                {
                    c+=(1LL<<i);
                }
            }
        }
    }
    // cout<<a<<' '<<b<<' '<<c<<'\n';
    cout<<abs((a^c) - (b^c))<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}