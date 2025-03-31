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

void dfs(vvi &graph,vll&a,vb&vis,int v,vl&dp,vl&dp1)
{
    vis[v]=1;
    dp[v]=dp1[v]=0;
    for(auto it:graph[v])
    {
        if(vis[it])
        continue;
        dfs(graph,a,vis,it,dp,dp1);
        dp[v]+=max(dp[it]+abs(a[v].first-a[it].first),dp1[it]+abs(a[v].first-a[it].second));
        dp1[v]+=max(dp[it]+abs(a[v].second-a[it].first),dp1[it]+abs(a[v].second-a[it].second));
    }
}

void solve()
{
    int n;
    cin>>n;
    vll a(n);
    for(auto &it:a)
    cin>>it.first>>it.second;
    vvi graph(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vb vis(n);
    int s=-1;
    for(int i=0;i<n;i++)
    {
        if(graph[i].size()==1)
        {
            s=i;
            break;
        }
    }
    vl dp(n),dp1(n);
    dfs(graph,a,vis,0,dp,dp1);
    cout<<max(dp[0],dp1[0])<<'\n';
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