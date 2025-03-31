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

ll ans=LLONG_MAX;

void dfs(vector<vll>&graph,vb&vis,ll x,int v)
{
    if(vis[v])
    return;
    vis[v]=1;
    if(v!=(graph.size()-1))
    ans=min(ans,x);
    for(auto it:graph[v])
    {
        dfs(graph,vis,x^it.second,it.first);
    }
    vis[v]=0;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vll> graph(n);
    for(int i=0;i<m;i++)
    {
        ll x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    vb vis(n);
    dfs(graph,vis,0,0);
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