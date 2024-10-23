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

void fil(vvi &graph,map<int,map<int,set<int>>>&chk,int l,int d,int r)
{
    int x=l;
    while(x+d<=r)
    {
        graph[x].push_back(x+d);
        graph[x+d].push_back(x);
        chk[d][l%d].insert(x);
        chk[d][l%d].insert(x+d);
        x+=d;
    }
}

void dfs(vvi &graph,int v,vb &vis)
{
    vis[v]=1;
    for(auto it:graph[v])
    {
        if(vis[it])
        continue;
        dfs(graph,it,vis);
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vvi graph(n+1);
    vvi x(n+1,vi(11));
    for(int i=0;i<m;i++)
    {
        int a,d,k;
        cin>>a>>d>>k;
        x[a][d]=max(x[a][d],k);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=10;j++)
        {
            if(!x[i][j])
            continue;
            graph[i].push_back(i+j);
            graph[i+j].push_back(i);
            x[i+j][j]=max(x[i+j][j],x[i][j]-1);
        }
    }
    vector<bool> vis(n+1);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])
        continue;
        ans++;
        dfs(graph,i,vis);
    }
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