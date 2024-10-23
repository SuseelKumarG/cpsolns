#include <bits/stdc++.h>
using namespace std;
 
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

vvi dp(100001,vi(101));

void chk(int i,int j,int m)
{
    int ans=dp[i+1][j];
    if(j-1>=0)
    ans+=dp[i+1][j-1];
    ans%=MAX;
    if(j+1<m)
    ans+=dp[i+1][j+1];
    ans%=MAX;
    dp[i][j]=ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    for(int i=n-1;i>=0;i--)
    {
        if(i==n-1)
        {
            for(int j=0;j<m;j++)
            dp[i][j]=1;
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                chk(i,j,m);
            }
        }
        if(a[i]>=0)
        {
            for(int j=0;j<m;j++)
            {
                if(j!=a[i])
                dp[i][j]=0;
            }
        }
    }
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        ans+=dp[0][i];
        ans%=MAX;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}