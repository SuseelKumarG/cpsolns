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

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<vii>dp(n);
    for(int i=0;i<s.length();i++)
    {
        dp[0].push_back({s[i]-'0',1});
    }
    ll curr=s.length();
    ll mul=1;
    for(int i=1;i<n;i++)
    {
        curr/=3;
        for(int j=0;j<curr;j++)
        {
            int x=dp[i-1][j*3].first;
            int y=dp[i-1][j*3+1].first;
            int z=dp[i-1][j*3+2].first;
            int a=dp[i-1][j*3].second;
            int b=dp[i-1][j*3+1].second;
            int c=dp[i-1][j*3+2].second;
            if(x==y&&y==z)
            {
                dp[i].push_back({x,a+b+c-max({a,b,c})});
            }
            else if(x==y)
            {
                dp[i].push_back({x,min({a,b})});
            }
            else if(x==z)
            {
                dp[i].push_back({x,min({a,c})});
            }
            else
            {
                dp[i].push_back({y,min({b,c})});
            }
        }
    }
    int x=dp[n-1][0].first;
    int y=dp[n-1][0+1].first;
    int z=dp[n-1][0+2].first;
    int a=dp[n-1][0].second;
    int b=dp[n-1][0+1].second;
    int c=dp[n-1][0+2].second;
    if(x==y&&y==z)
    {
        cout<<a+b+c-max({a,b,c})<<'\n';
    }
    else if(x==y)
    {
        cout<<min({a,b})<<'\n';
    }
    else if(x==z)
    {
        cout<<min({a,c})<<'\n';
    }
    else
    {
        cout<<min({b,c})<<'\n';
    }
}

int main()
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