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

void solve()
{
    ll n,m,x;
    cin>>n>>m>>x;
    vvl a(n+1,vl(m));
    vvl dp(n+1,vl(m,LLONG_MAX/2));
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        cin>>a[i][j];
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int k=0;k<m;k++)
        {
            vl b(m);
            for(int j=0;j<m;j++)
            b[j]=dp[i-1][j]+a[i][(j+k)%m]+k*x;
            b[0]=min(b[0],b[m-1]+a[i][k]);
            for(int j=1;j<m;j++)
            b[j]=min(b[j],b[j-1]+a[i][(j+k)%m]);
            for(int j=0;j<m;j++)
            dp[i][j]=min(dp[i][j],b[j]);
        }
    }
    cout<<dp[n][m-1]<<'\n';
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