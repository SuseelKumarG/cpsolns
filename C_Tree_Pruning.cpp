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

void dfs(vvi&graph,int p,int v,vi&deapth,vi &rem,vi&maxmd)
{
    maxmd[v]=deapth[v];
    for(auto it:graph[v])
    {
        if(it==p)
        continue;
        deapth[it]=deapth[v]+1;
        dfs(graph,v,it,deapth,rem,maxmd);
        maxmd[v]=max(maxmd[v],maxmd[it]);
    }
    rem[deapth[v]]++;
    if(maxmd[v]+1<rem.size())
    rem[maxmd[v]+1]--;
}

void solve()
{
    int n;
    cin>>n;
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
    vi deapth(n);
    vb vis(n);
    for(int i=0;i<n;i++)
    vis[i]=0;
    vi rem(n);
    vi maxmd(n);
    dfs(graph,-1,0,deapth,rem,maxmd);
    for(int i=1;i<n;i++)
    rem[i]+=rem[i-1];
    cout<<n-*max_element(rem.begin(),rem.end())<<'\n';
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