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

int cnt;

int dfs(vvi &graph,int v,vb &vis,string &s)
{
    if(vis[v])
    return 0;
    vis[v]=1;
    int curr=(s[v]=='W'?1:-1);
    for(auto it:graph[v])
    {
        curr+=dfs(graph,it,vis,s);
    }
    if(curr==0)
    cnt++;
    return curr;
}

void solve()
{
    cnt=0;
    int n;
    cin>>n;
    vi a(n-1);
    for(auto &it:a)
    {
        cin>>it;
        it--;
    }
    string s;
    cin>>s;
    int curr=((s[0]=='W')?1:-1);
    vvi graph(n);
    for(int i=0;i<n-1;i++)
    {
        graph[i+1].push_back(a[i]);
        graph[a[i]].push_back(i+1);
    }
    vb vis(n);
    dfs(graph,0,vis,s);
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