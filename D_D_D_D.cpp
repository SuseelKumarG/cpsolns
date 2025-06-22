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
typedef vector<long double> vd;
typedef vector<vd> vvd;
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

void bfs(vvi&graph,vi&dist,int x)
{
    int n=graph.size()/2;
    queue<pii>fin;
    fin.push({x,0});
    dist[x]=0;
    vb vis(2*n);
    while(fin.size())
    {
        int x=fin.front().first;
        int y=fin.front().second;
        fin.pop();
        if(vis[x])
        continue;
        vis[x]=1;
        dist[x]=y;
        for(auto it:graph[x])
        fin.push({it,y+1});
    }
}

void solve()
{
    int n,m,l;
    cin>>n>>m>>l;
    vvi graph(2*n+10);
    vi o,e;
    for(int i=0;i<l;i++)
    {
        int x;
        cin>>x;
        if(x&1)
        o.push_back(x);
        else
        e.push_back(x);
    }
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    int sum=accumulate(o.begin(),o.end(),0LL);
    sum+=accumulate(e.begin(),e.end(),0);
    int sumo=sum,sume=sum;
    if(sum&1)
    {
        if(o.size())
        sume-=o[0];
        else
        sume=-1;
    }
    else
    {
        if(o.size())
        sumo-=o[0];
        else
        sumo=-1;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y+n);
        graph[y+n].push_back(x);
        graph[x+n].push_back(y);
        graph[y].push_back(x+n);
    }
    vi disto(2*n,-1);
    bfs(graph,disto,0);
    for(int i=0;i<n;i++)
    {
        bool poss=0;
        int x=disto[i+n];
        int y=disto[i];
        if(x!=-1)
        {
            if(x&1)
            {
                if(x<=sumo)
                poss=1;
            }
            else
            {
                if(x<=sume)
                poss=1;
            }
        }
        if(y!=-1)
        {
            if(y&1)
            {
                if(y<=sumo)
                poss=1;
            }
            else
            {
                if(y<=sume)
                poss=1;
            }
        }
        cout<<poss;
    }
    cout<<'\n';
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