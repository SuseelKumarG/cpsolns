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

void dfs(vector<set<int>> &graph,set<int> &ind,int v,vb&vis)
{
    if(vis[v])
    return;
    vis[v]=1;
    ind.insert(v);
    for(auto it:graph[v])
    dfs(graph,ind,it,vis);
}

void solve()
{
    int n,m1,m2;
    cin>>n>>m1>>m2;
    vector<set<int>> f(n),g(n);
    int a=-1;
    for(int i=0;i<m1;i++)
    {
        int x,y;
        cin>>x>>y;
        a=x-1;
        x--;
        y--;
        f[x].insert(y);
        f[y].insert(x);
    }
    int b=-1;
    for(int i=0;i<m2;i++)
    {
        int x,y;
        cin>>x>>y;
        b=x-1;
        x--;
        y--;
        g[x].insert(y);
        g[y].insert(x);
    }
    set<int> indf,indg;
    vb visf(n),visg(n);
    for(int i=0;i<n;i++)
    {
        if(!visf[i]&&f[i].size())
        {
            dfs(f,indf,i,visf);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!visg[i]&&g[i].size())
        {
            dfs(g,indg,i,visg);
        }
    }
    int ans=0;
    for(auto it:indf)
    {
        if(!indg.count(it))
        {
            ans+=f[it].size();
            for(auto tit:f[it])
            {
                f[tit].erase(it);
            }
            f[it].clear();
        }
    }
    set<int>finf;
    vb donef(n);
    bool once=0;
    for(int i=0;i<n;i++)
    {
        if(f[i].size()&&!donef[i])
        {
            dfs(f,finf,i,donef);
            if(once) ans++;
            once=1;
        }
    }
    if(finf.size()>0&&indg.size()>0)
    for(auto it:indg)
    {
        if(!finf.count(it))
        ans++;
    }
    else if(indg.size())
    ans+=indg.size()-1;
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