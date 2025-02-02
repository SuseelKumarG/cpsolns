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

void dfs(vvi &graph,int v,vb &vis)
{
    if(vis[v])
    return;
    vis[v]=1;
    for(auto it:graph[v])
    dfs(graph,it,vis);
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
    if(1)
    {
        int op=0;
        for(int i=0;i<n;i++)
        if(graph[i].size()==2)
        op++;
        if(op==n-2&&n>4)
        {
            cout<<3<<'\n';
            return;
        }
    }
    map<int,int>temp;
    for(int i=0;i<n;i++)
    {
        temp[i]=graph[i].size();
    }
    pii big={0,0};
    for(auto it:temp)
    {
        big=max(big,{it.second,it.first});
    }
    vb vis(n);
    vis[big.second]=1;
    for(auto it:graph[big.second])
    {
        temp[it]--;
    }
    temp.erase(big.second);
    big={0,0};
    for(auto it:temp)
    {
        big=max(big,{it.second,it.first});
    }
    vis[big.second]=1;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(graph,i,vis);
            cnt++;
        }
    }
    cout<<cnt<<'\n';
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