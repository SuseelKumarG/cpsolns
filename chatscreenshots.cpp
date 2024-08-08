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

void dfs(int v,vvi &graph,vb &vis,stack<int> &s)
{
    vis[v]=1;
    for(auto it:graph[v])
    {
        if(vis[it]!=1)
        dfs(it,graph,vis,s);
    }
    s.push(v);
}

bool cycle(stack<int> &s,vvi &graph)
{
    map<int,int>ord;
    int ind=0;
    while(!s.empty())
    {
        ord[s.top()]=ind++;
        s.pop();
    }
    for(int i=0;i<graph.size();i++)
    {
        for(auto it:graph[i])
        {
            if(ord[i]>ord[it])
            return 1;
        }
    }
    return 0;
}

void solve()
{
    bool poss=1;
    int n,k;
    cin>>n>>k;
    vvi a(k,vi(n));
    for(int i=0;i<k;i++)
    for(int j=0;j<n;j++)
    cin>>a[i][j],a[i][j]--;
    if(k==1)
    {
        cout<<"YES\n";
        return;
    }
    vvi graph(n);
    for(int i=0;i<k;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            int x=a[i][j];
            int y=a[i][j+1];
            graph[x].push_back(y);
        }
    }
    vb vis(n,0);
    stack<int> s;
    for(int i=0;i<n;i++)
    if(!vis[i])
    dfs(i,graph,vis,s);
    cout<<(cycle(s,graph)? "NO":"YES")<<'\n';
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