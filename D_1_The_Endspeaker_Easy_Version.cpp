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
    int n,m;
    cin>>n>>m;
    vi pre(n+1);
    vi b(m+1);
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        pre[i]=pre[i-1]+x;
    }
    for(int i=1;i<=m;i++)
    cin>>b[i];
    vvi dp(n+10,vi(m+10,MAX));
    dp[0][0]=0;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(j!=0)
            dp[i][j]=min(dp[i][j],dp[i][j-1]);
            int ind=(--upper_bound(pre.begin(),pre.end(),pre[i]+b[j]))-pre.begin();
            int l=i,h=n;
            while(h>=l)
            {
                ind=(h-l)/2+l;
                if(b[j]>=pre[ind]-pre[i])
                {
                    dp[ind][j]=min(dp[ind][j],dp[i][j]+m-j);  
                    l=ind+1;
                }
                else
                h=ind-1;
            }
            if(pre[h]-pre[i]<=b[j])
            ind=h;
            else
            ind=l;
        }
    }
    cout<<(dp[n][m]==MAX?-1:dp[n][m])<<'\n';
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