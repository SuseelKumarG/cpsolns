#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

long long gcdl(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}  
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
    return a;
}

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int q;
    cin>>q;
    vi dp(n+10,INT_MAX);
    vvi pos(k);
    for(int i=0;i<n;i++) 
    {
        pos[s[i]-'a'].push_back(i);
    }
    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<k;j++)
        {
            auto it=upper_bound(pos[j].begin(),pos[j].end(),i);
            if(it==pos[j].end())
            {
                dp[i]=1;
                continue;
            }
            dp[i]=min(dp[i],dp[*it]+1);
        }
    }
    while(q--)
    {
        string x;
        cin>>x;
        int ind=-1;
        bool ok=1;
        for(int i=0;i<x.length();i++)
        {
            auto it=upper_bound(pos[x[i]-'a'].begin(),pos[x[i]-'a'].end(),ind);
            if(it==pos[x[i]-'a'].end())
            {
                cout<<0<<'\n';
                ok=0;
                break;
            }
            ind=*it;
        }
        if(ok)
        cout<<dp[ind]<<'\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}