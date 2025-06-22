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
    string s;
    cin>>s;
    vi dp(n,0),dp1(n,0);
    if(s[0]=='0')
    {
        dp[0]=0;
        dp1[0]=n-1;
    }
    else
    {
        dp[0]=1;
        dp1[0]=1;
    }
    for(int i=1;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(s[i-1]=='0')
            {
                dp[i]=dp1[i-1]+1;
                dp1[i]=dp1[i-1]+1;
            }
            else
            {
                dp[i]=1;
                dp1[i]=1;
            }
            continue;
        }
        dp[i]=dp[i-1]+i;
        if(s[i-1]=='0')
        {
            dp1[i]=dp1[i-1]+n-i-1;
        }
        else
        {
            dp1[i]=n-i-1;
        }
    }
    cout<<max(*max_element(dp.begin(),dp.end()),*max_element(dp1.begin(),dp1.end()))<<'\n';
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