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

void bfs(vvi &graph,vi&deap,int v,vb &vis)
{
    queue<int>bf;
    bf.push(v);
    deap[v]=0;
    while(!bf.empty())
    {
        int x=bf.front();
        vis[v]=1;
        bf.pop();
        for(auto it:graph[x])
        {
            if(vis[it])
            continue;
            vis[it]=1;
            deap[it]=deap[x]+1;
            bf.push(it);
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    int s,t;
    cin>>s>>t;
    set<int>curse;
    vvi graph(n);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x)
        curse.insert(i);
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(curse.count(x)||curse.count(y))
        continue;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vi bf(n,-1);
    vb vis(n);
    bfs(graph,bf,s,vis);
    cout<<bf[t]<<'\n';
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