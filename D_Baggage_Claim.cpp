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

int ans=0;

void dfs(pii v,map<pii,vii>&graph,set<pii>&vis,pii fin)
{
    if(vis.count(v))
    return;
    vis.insert(v);
    if(v==fin)
    {
        ans++;
        vis.erase(v);
        return;
    }
    for(auto it:graph[v])
    {
        dfs(it,graph,vis,fin);
    }
    vis.erase(v);
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vi x(k+1),y(k+1);
    set<pii>po;
    for(int i=0;i<=k;i++)
    {
        cin>>x[i]>>y[i]; 
        po.insert({x[i],y[i]});
    }
    map<pii,vii>graph;
    for(int i=0;i<k;i++)
    {
        int dist=abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
        if(dist!=2)
        {
            cout<<0<<'\n';
            return;
        }
        if(x[i]==x[i+1])
        {
            if(po.count({x[i],y[i]+1}))
            {
                cout<<0<<'\n';
                return;
            }
            graph[{x[i],y[i]}].push_back({x[i],y[i]+1});
            graph[{x[i],y[i]+1}].push_back({x[i+1],y[i+1]});
            continue;
        }
        if(y[i]==y[i+1])
        {
            if(po.count({x[i]+1,y[i]}))
            {
                cout<<0<<'\n';
                return;
            }
            graph[{x[i],y[i]}].push_back({x[i]+1,y[i]});
            graph[{x[i]+1,y[i]}].push_back({x[i+1],y[i+1]});
            continue;
        }
        if(!po.count({x[i+1],y[i]}))
        {
            graph[{x[i],y[i]}].push_back({x[i+1],y[i]});
            graph[{x[i+1],y[i]}].push_back({x[i+1],y[i+1]});
        }
        if(!po.count({x[i],y[i+1]}))
        {
            graph[{x[i],y[i]}].push_back({x[i],y[i+1]});
            graph[{x[i],y[i+1]}].push_back({x[i+1],y[i+1]});
        }
        if(po.count({x[i+1],y[i]})&&po.count({x[i],y[i+1]}))
        {
            cout<<0<<'\n';
            return;
        }
    }
    set<pii>vis;
    ans=0;
    dfs({x[0],y[0]},graph,vis,{x[k],y[k]});
    cout<<ans<<'\n';
}

int32_t main()
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