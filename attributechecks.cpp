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
    int n,m;
    cin>>n>>m;
    vvi dp(m+10,vi(m+10));
    vi a,b;
    int curr=0;
    for(int k=0;k<n;k++)
    {
        int x;
        cin>>x;
        if(x>0)
        a.push_back(x);
        else if(x<0)
        b.push_back(-x);
        else
        {
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            curr++;
            for(int i=0;i<=curr;i++)
            {
                int add=0;
                add+=upper_bound(a.begin(),a.end(),i)-a.begin()-(upper_bound(a.begin(),a.end(),i)!=a.begin());
                add+=upper_bound(b.begin(),b.end(),curr-i)-b.begin()-(upper_bound(b.begin(),b.end(),curr-i)!=b.begin());
                if(i)
                {
                    dp[i][curr]=max(dp[i][curr],dp[i-1][curr-1]+add);
                }
                if(i<curr)
                {
                    dp[i][curr]=max(dp[i][curr],dp[i][curr-1]+add);
                }
            }
            a.clear();
            b.clear();
        }
    }
    {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        curr++;
        curr=min(curr,m);
        for(int i=0;i<=curr;i++)
        {
            int add=0;
            add+=upper_bound(a.begin(),a.end(),i)-a.begin();
            add+=upper_bound(b.begin(),b.end(),curr-i)-b.begin();
            if(i)
            {
                dp[i][curr]=max(dp[i][curr],dp[i-1][curr-1]+add);
            }
            if(i<curr)
            {
                dp[i][curr]=max(dp[i][curr],dp[i][curr-1]+add);
            }
        }
        a.clear();
        b.clear();
    }
    int ans=0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        cout<<dp[i][j]<<' ';
        cout<<'\n';
    }
    cout<<ans<<'\n';
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