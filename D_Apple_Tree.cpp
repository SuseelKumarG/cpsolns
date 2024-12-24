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

void dfs(int v,vvi &graph,vi &leaf,vb &vis)
{
    vis[v]=1;
    bool lef=1;
    for(auto it:graph[v])
    {
        if(!vis[it])
        {dfs(it,graph,leaf,vis);
        leaf[v]+=leaf[it];
        lef=0;}
    }
    if(graph[v].size()>1)
    lef=0;
    leaf[v]+=lef;
}

void solve()
{
    int n;
    cin>>n;
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
    int q;
    cin>>q;
    vi leaf(n);
    vb vis(n);
    dfs(0,graph,leaf,vis);
    // for(auto it:leaf)
    // cout<<it<<' ';
    // cout<<'\n';
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        cout<<leaf[x]*1LL*leaf[y]<<'\n';
    }
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