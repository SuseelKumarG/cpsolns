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

ll ans=0;

void dfs(vvi &graph,vvi &fin,vb &vis,int v)
{
    vis[v]=1;
    for(auto it:graph[v])
    {
        if(vis[it])
        continue;
        fin[v].push_back(it);
        dfs(graph,fin,vis,it);
    }
}

int height(vvi&graph,vb &vis,int v,vi &hgt,vvi &sol)
{
    if(vis[v])
    return -1;
    vis[v]=1;
    for(auto it:graph[v])
    {
        hgt[v]=max(hgt[v],height(graph,vis,it,hgt,sol)+1);
        sol[v].push_back(hgt[it]);
    }
}

void dp(vvi )

void solve()
{
    int n,k;
    cin>>n>>k;
    vvi temp(n);
    vvi graph(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        temp[x].push_back(y);
        temp[y].push_back(x);
    }
    int v;
    for(int i=0;i<n;i++)
    {
        if(temp[i].size()==1)
        {
            v=i;
            break;
        }
    }
    vvi sol(n);
    vi hgt(n);
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