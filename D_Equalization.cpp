#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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
int gcd(int a, int b){
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
int lcml(int a,int b)
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

vvl dp(64,vl(64,LLONG_MAX));

void func()
{
    dp[0][0]=0;
    for(int i=1;i<64;i++)
    {
        for(int j=63;j>=0;j--)
        {
            for(int k=63;k>=0;k--)
            {
                if((k>=i)&&(dp[k-i][j]!=LLONG_MAX))
                dp[k][j]=min(dp[k-i][j]+(1LL<<i),dp[k][j]);
                if((j>=i)&&(dp[k][j-i]!=LLONG_MAX))
                dp[k][j]=min(dp[k][j-i]+(1LL<<i),dp[k][j]);
            }
        }
    }
}

void solve()
{
    ll x,y;
    cin>>x>>y;
    ll ans=LLONG_MAX;
    for(int i=0;i<63;i++)
    {
        for(int j=0;j<63;j++)
        {
            if((x>>i)==(y>>j))
            ans=min(ans,dp[i][j]);
        }
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    func();
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}