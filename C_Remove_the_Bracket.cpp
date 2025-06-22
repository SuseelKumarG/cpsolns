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
    int n,s;
    cin>>n>>s;
    vi a(n);
    for(ll&i:a)
    cin>>i;
    vi l,r;
    for(int i=0;i<n;i++)
    {
        int x,y;
        if(a[i]>=s)
        {
            x=s;
            y=a[i]-s;
        }
        else
        {
            x=a[i];
            y=0;
        }
        if(x>y)
        swap(x,y);
        l.push_back(x);
        r.push_back(y);
    }
    vi dp(n+1,LLONG_MAX);
    vi dp1(n+1,LLONG_MAX);
    dp[0]=0;
    dp1[0]=0;
    l[0]=a[0];
    r[0]=a[0];
    for(int i=1;i<n-1;i++)
    {
        dp[i]=min(dp[i-1]+r[i-1]*l[i],dp1[i-1]+l[i-1]*l[i]);
        dp1[i]=min(dp[i-1]+r[i-1]*r[i],dp1[i-1]+l[i-1]*r[i]);
    }
    cout<<min(dp[n-2]+r[n-2]*a[n-1],dp1[n-2]+l[n-2]*a[n-1])<<'\n';
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