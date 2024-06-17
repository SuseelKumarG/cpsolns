//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
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

void dijkstra(vector<vii> &graph,vl &dist,vb &vis,vi &par)
{
    set<pair<pair<ll,int>,int>>q;
    q.insert({{0,0},-1});
    par[0]=-1;
    dist[0]=0;
    while(q.size()>0)
    {
        int p=q.begin()->second;
        pair<ll,int> x=q.begin()->first;
        int v=x.second;
        int z=x.first;
        q.erase(q.begin());
        if(vis[v])
        continue;
        vis[v]=1;
        par[v]=p;
        dist[v]=z;
        for(auto it:graph[v])
        {
            int c=it.first;
            int wt=it.second;
            if(dist[v]+wt<dist[c])
            q.insert({{dist[v]+wt,c},v});
        }
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    vl dist(n,LONG_LONG_MAX);
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        x--;
        y--;
        graph[x].push_back({y,w});
        graph[y].push_back({x,w});
    }
    vb vis(n);
    vi par(n);
    dijkstra(graph,dist,vis,par);
    vi path;
    path.push_back(n-1);
    while(par[path.back()]!=-1)
    {
        path.push_back(par[path.back()]);
    }
    if(dist[n-1]==LONG_LONG_MAX)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(path.begin(),path.end());
    for(auto it:path)
    cout<<it+1<<' ';
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