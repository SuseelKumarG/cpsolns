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

void dfs(int v,vi &a,vvi &graph,vb &vis)
{
    if(vis[v])
    return;
    vis[v]=1;
}

void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    if(x>y)
    swap(x,y);
    x--;
    y--;
    vvi graph(n);
    for(int i=1;i<n-1;i++)
    {
        graph[i].push_back(i+1);
        graph[i].push_back(i-1);
    }
    graph[0].push_back(1);
    graph[0].push_back(n-1);
    graph[n-1].push_back(0);
    graph[n-1].push_back(n-2);
    graph[x].push_back(y);
    graph[y].push_back(x);
    vi a(n);
    for(int i=0;i<n;i++)
    {
        if(i&1)
        a[i]=1;
        else
        a[i]=0;
    }
    if(n&1)
    {
        a[x]=2;
        if(x==0)
        {
            a[1]=1;
        }
        else
        {
            if(a[x-1])
            a[x+1]=0;
            else
            a[x+1]=1;
        }
        for(int i=x+2;i<n;i++)
        {
            if(a[i-1])
            a[i]=0;
            else
            a[i]=1;
        }
    }
    else
    {
        if((y-x-1)&1)
        a[x]=2;
    }
    for(auto it:a)
    cout<<it<<' ';
    cout<<'\n';
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