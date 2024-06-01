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

int cnt=0;

void dfs(int v,int p,vvi &graph)
{
    for(auto it:graph[v])
    {
        if(it!=p)
        {
            cnt++;
            dfs(it,v,graph);
        }
    }
}

void bfs(int x,vvi &graph,vi &lev,vector<bool> &vis)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
        if (!vis[u]) {
            vis[u] = 1;
            q.push(u);
            lev[u] = lev[v] + 1;
        }
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vvi graph(n);
    vi lev(n);
    vector<bool>vis(n);
    int a,b;
    cin>>a>>b;
    a--;
    b--;
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    // cnt--;
    dfs(a,-1,graph);
    bfs(b,graph,lev,vis);
    cout<<cnt<<'\n';
    cout<<lev[a]<<'\n';
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