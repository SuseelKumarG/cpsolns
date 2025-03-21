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

void dfs(vvi &graph,vi &a,vb&vis,int v,vb&ans,int p)
{
    if(vis[v])
    return;
    vis[v]=1;
    map<int,int>hsh;
    for(auto it:graph[v])
    {
        if(vis[it])
        continue;
        if(a[v]==a[it])
        ans[a[v]]=1;
        if(it!=p)
        hsh[a[it]]++;
        for(auto tit:graph[it])
        {
            if(tit!=v) {
                if(a[v]==a[it]||a[v]==a[tit]) 
                ans[a[v]]=1;
                if(a[it]==a[tit])
                ans[a[it]]=1;
            }
        }
        dfs(graph,a,vis,it,ans,v);
    }
    for(auto x:hsh)
    {
        if(x.second>1)
        ans[x.first]=1;
    }
}

void solve()
{
    int n;
    cin>>n;
    vi a(n+1);
    for(int i=1;i<=n;i++)
    cin>>a[i];
    a[0]=-1;
    vvi graph(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vb vis(n+1),ans(n+1);
    dfs(graph,a,vis,1,ans,0);
    for(int i=1;i<=n;i++)
    cout<<ans[i];
    cout<<'\n';
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