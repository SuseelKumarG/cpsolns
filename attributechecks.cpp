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

void solve()
{
    int n,m;
    cin>>n>>m;
    vi a(n);
    vvi dp(m+10,vi(m+10));
    for(auto &it:a)
    cin>>it;
    vi x,y;
    int t=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>0)
        x.push_back(a[i]);
        else if(a[i]<0)
        y.push_back(-a[i]);
        else
        {
            sort(x.begin(),x.end());
            sort(y.begin(),y.end());
            t++;
            for(int j=0;j<=t;j++)
            {
                if(j)
                {
                    int w=j-1,s=t-j;
                    int add=(int)((upper_bound(x.begin(),x.end(),w)-x.begin())+(upper_bound(y.begin(),y.end(),s)-y.begin()));
                    dp[t][j]=max(dp[t][j],dp[t-1][j-1]+add);
                }
                if(j<t)
                {
                    int w=j,s=t-1-j;
                    int add=(int)((upper_bound(x.begin(),x.end(),w)-x.begin())+(upper_bound(y.begin(),y.end(),s)-y.begin()));
                    dp[t][j]=max(dp[t][j],dp[t-1][j]+add);
                }
            }
            x.clear();
            y.clear();
        }
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int ans=0;
    for(int j=0;j<=t;j++)
    {
        int w=j,s=t-j;
        int add=(int)((upper_bound(x.begin(),x.end(),w)-x.begin())+(upper_bound(y.begin(),y.end(),s)-y.begin()));
        ans=max(ans,dp[t][j]+add);
    }
    cout<<ans<<'\n';
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