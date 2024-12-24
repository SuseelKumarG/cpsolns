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

void dfs(int i,int j,vector<string>&graph,vvi &dp,vvi &vis)
{
    int n=graph.size();
    int m=graph[0].size();
    if(i<0||i>=n)
    return;
    if(j<0||j>=m)
    return;
    if(vis[i][j])
    return;
    vis[i][j]=1;
    dp[i][j]=1;
    if(graph[i-1][j]=='D')
    dfs(i-1,j,graph,dp,vis);
    if(graph[i+1][j]=='U')
    dfs(i+1,j,graph,dp,vis);
    if(graph[i][j-1]=='R')
    dfs(i,j-1,graph,dp,vis);
    if(graph[i][j+1]=='L')
    dfs(i,j+1,graph,dp,vis);
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string>graph(n+2);
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        graph[i]="*"+s+"*";
    }
    graph[0]=string(m+2,'*');
    graph[n+1]=string(m+2,'*');
    vvi dp(n+2,vi(m+2)),vis;
    for(int i=0;i<n+2;i++)
    {
        dp[i][0]=1;
        dp[i][m+1]=1;
    }
    for(int i=0;i<m+2;i++)
    {
        dp[0][i]=1;
        dp[n+1][i]=1;
    }
    vis=dp;
    for(int i=0;i<n+2;i++)
    {
        if(graph[i][1]=='L')
        dfs(i,1,graph,dp,vis);
        if(graph[i][m]=='R')
        dfs(i,m,graph,dp,vis);
    }
    for(int i=0;i<m+2;i++)
    {
        if(graph[1][i]=='U')
        dfs(1,i,graph,dp,vis);
        if(graph[n][i]=='D')
        dfs(n,i,graph,dp,vis);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(graph[i][j]=='?')
            {
                if(vis[i][j-1]&&vis[i][j+1]&&vis[i-1][j]&&vis[i+1][j])
                vis[i][j]=1;
            }
        }
    }
    ll ans=n*m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(vis[i][j])
            ans--;
        }
    }
    cout<<ans<<'\n';
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