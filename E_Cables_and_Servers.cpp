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

void dfs(vvi &graph,vb &vis,int v,multiset<pii>&ins)
{
    if(vis[v])
    return;
    vis[v]=1;
    for(auto it:graph[v])
    {
        ins.insert({v,it});
        dfs(graph,vis,it,ins);
    }
}

void prim(vvi &graph,vb&vis,int v,map<pii,vi>&edge,set<pair<int,pii>>&ans,vector<multiset<pii>>&conedge)
{
    set<int>used;

}

void solve()
{
    int n,m;
    cin>>n>>m;
    vvi graph(n);
    map<pii,vi>edge;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        edge[{x,y}].push_back(i);
        edge[{y,x}].push_back(i);
    }
    set<int> con;
    vector<multiset<pii>>conedge;
    vb vis(n);
    multiset<pii>ins;
    for(int i=0;i<n;i++)
    {
        if(vis[i])
        continue;
        ins.clear();
        con.insert(i);
        dfs(graph,vis,i,ins);
        conedge.push_back(ins);
    }
    set<pair<int,pii>>ans;
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