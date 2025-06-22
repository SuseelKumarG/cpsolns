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
    int n;
    cin>>n;
    vvd dp(n+10,vd(n+10));
    vd a(n+1);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j)
            dp[i][j]+=dp[i-1][j-1]*a[i];
            // if(j<i)
            dp[i][j]+=dp[i-1][j]*(1.0-a[i]);
        }
    }
    cout<<setprecision(10)<<accumulate(dp[n].begin()+((n+1)/2),dp[n].end(),0.0)<<'\n';
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