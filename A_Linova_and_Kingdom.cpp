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

void dep(vvi &graph,vb&vis,int v,int x,vvi&deapth,vi&d)
{
    if(vis[v])
    return;
    vis[v]=1;
    deapth[x].push_back(v);
    for(auto it:graph[v])
    {
        dep(graph,vis,it,x+1,deapth,d);
    }
}

ll ans=0;

void dfs(vvi&graph,vb&vis,vb&ind,int v,int i,int t,vi&d)
{
    if(vis[v])
    return;
    vis[v]=1;
    if(ind[v])
    i++;
    else
    t++;
    for(auto it:graph[v])
    {
        dfs(graph,vis,ind,it,i,t,d);
    }
    d[v]=i;
}
void func(vvi&graph,vb&vis,vb&ind,int v,int i,int t,vi&d)
{
    if(vis[v])
    return;
    vis[v]=1;
    if(ind[v])
    i++;
    else
    t++;
    for(auto it:graph[v])
    {
        dfs(graph,vis,ind,it,i,t,d);
    }
    if(graph[v].size()==1)
    {
        cout<<i<<' '<<t<<'\n';
        ans+=i*1LL*t;
    }
}

void solve()
{
    int n,k;
    cin>>n>>k;
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
    vb ind(n);
    vb vis(n);
    vvi deapth(n);
    vi d(n);
    dep(graph,vis,0,0,deapth,d);
    for(int i=0;i<n;i++)
    vis[i]=0;
    dfs(graph,vis,ind,0,0,0,d);
    for(int i=0;i<n;i++)
    {
        sort(deapth[i].begin(), deapth[i].end(), [&](int x, int y) {
            return d[x] > d[y];
        });
    }
    int x=k;
    for(int i=n-1;i>=0;i--)
    {
        while(!deapth[i].empty())
        {
            if(!x)
            break;
            x--;
            ind[deapth[i].back()]=1;
            deapth[i].pop_back();
        }
    }
    for(auto it:ind)
    cout<<it<<' ';
    cout<<'\n';
    for(int i=0;i<n;i++)
    vis[i]=0;
    func(graph,vis,ind,0,0,0,d);
    cout<<ans<<'\n';
    for(int i=0;i<n;i++)
    {
        if(graph[i].size()==1)
        cout<<i<<' ';
    }
    cout<<'\n';
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