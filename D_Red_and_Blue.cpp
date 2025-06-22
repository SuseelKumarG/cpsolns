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
    vi a(n);
    for(ll&i:a)
    cin>>i;
    a.insert(a.begin(),0);
    int m;
    cin>>m;
    vi b(m);
    for(ll&i:b)
    cin>>i;
    b.insert(b.begin(),0);
    vvi dp(n+1,vi(m+1));
    vvi curr(n+1,vi(m+1));
    for(int i=1;i<=n;i++)
    {
        dp[i][0]+=dp[i-1][0]+a[i];
        curr[i][0]+=curr[i-1][0]+a[i];
    }
    for(int i=1;i<=m;i++)
    {
        dp[0][i]+=dp[0][i-1]+b[i];
        curr[0][i]+=curr[0][i-1]+b[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            curr[i][j]=max(curr[i-1][j]+a[i],curr[i][j-1]+b[j]);
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]=max(curr[i][j],dp[i][j]);
        }
    }
    cout<<max(0LL,dp[n][m])<<'\n';
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