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
#define MAX 998244353
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

vi fact(10000000,1);

int func(int n,int r)
{
    if(n<r)
    return 0;
    int curr=fact[n];
    curr*=binexp(fact[r],MAX-2);
    curr%=MAX;
    curr*=binexp(fact[n-r],MAX-2);
    curr%=MAX;
    return curr;
}

void solve()
{
    vi a(26);
    for(ll&i:a)
    cin>>i;
    int ans=0;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    while(!a.back())
    a.pop_back();
    int n=accumulate(a.begin(),a.end(),0LL);
    int o=(n+1)/2;
    int e=n/2;
    int occ=0,ecc=0;
    vi dp(o+10,0);
    dp[0]=1;
    for(int i=0;i<a.size();i++)
    {
        for(int j=o;j>=a[i];j--)
        {
            dp[j]+=dp[j-a[i]];
            dp[j]%=MAX;
        }
    }
    ans=dp[o];
    ans*=fact[o];
    ans%=MAX;
    ans*=fact[e];
    ans%=MAX;
    for(auto it:a)
    {
        ans*=binexp(fact[it],MAX-2);
        ans%=MAX;
    }
    cout<<ans<<'\n';
}

int32_t main()
{
    for(int i=1;i<fact.size();i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MAX;
    }
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