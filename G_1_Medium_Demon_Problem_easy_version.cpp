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

set<int>cycle;
int curr=0;

void cycles(vvi &graph,int v,vb &vis)
{
    if(vis[v])
    return;
    cycle.insert(v);
    vis[v]=1;
    for(auto it:graph[v])
    {
        cycles(graph,it,vis);
    }
}

void dfs(vvi &graph,int v,vb &vis)
{
    if(vis[v])
    {
        // cout<<v<<' ';
        vis[v]=0;
        if(!cycle.count(v))
        {vb vis1(graph.size());
        cycles(graph,v,vis1);}
        return;
    }
    if(cycle.count(v))
    return;
    curr++;
    vis[v]=1;
    for(auto it:graph[v])
    dfs(graph,it,vis);
    vis[v]=0;
}

void solve()
{
    cycle.clear();
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    {
        cin>>it;
        it--;
    }
    vvi graph(n);
    vector<set<int>> graphin(n);
    for(int i=0;i<n;i++)
    {
        graph[i].push_back(a[i]);
        graphin[a[i]].insert(i);
    }
    priority_queue<pii,vii,greater<pii>> leaf;
    for(int i=0;i<n;i++)
    {
        if(graphin[i].size()==0)
        leaf.push({1,i});
    }
    int ans=0;
    while(!leaf.empty())
    {
        int x=leaf.top().second;
        int y=leaf.top().first;
        ans=y;
        leaf.pop();
        for(auto it:graph[x])
        {
            graphin[it].erase(x);
            if(graphin[it].size()==0)
            leaf.push({y+1,it});
        }
    }
    cout<<ans+2<<'\n';
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