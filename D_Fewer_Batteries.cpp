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

long long gcd(long long a, long long b){
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
ll lcm(ll a,ll b)
{
    a=(a*b)/gcd(a,b);
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

bool poss(int x,vector<vii>&graph,vi&a)
{
    int n=a.size();
    vi dp(n);
    dp[0]=a[0];
    for(int i=0;i<n;i++)
    {
        if(dp[i])
        for(auto it:graph[i])
        {
            if(dp[i]>=it.second&&x>=it.second)
            dp[it.first]=max(dp[it.first],dp[i]+a[it.first]);
        }
    }
    return dp[n-1];
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    vector<vii> graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        graph[x].push_back({y,z});
    }
    int r=accumulate(a.begin(),a.end(),0LL);
    int l=-1;
    while(r-l>1)
    {
        int mid=(r-l)/2+l;
        if(poss(mid,graph,a))
        r=mid;
        else
        l=mid;
    }
    cout<<((r==accumulate(a.begin(),a.end(),0LL))?-1:r)<<'\n';
}

int32_t main()
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