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

long long gcd(long long a, long long b){
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
ll lcm(ll a,ll b)
{
    a=(a*b)/gcd(a,b);
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

void dfs(int v,int p,vvi&graph,vi&deapth)
{
    for(ll i:graph[v])
    {
        if(i==p)
        continue;
        dfs(i,v,graph,deapth);
        deapth[v]=max(deapth[i]+1,deapth[v]);
    }
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
    int leaf=0;
    for(int i=1;i<n;i++)
    {
        if(graph[i].size()==1)
        leaf++;
    }
    if(leaf>2)
    {
        cout<<0<<'\n';
        return;
    }
    int deg=-1;
    for(int i=0;i<n;i++)
    {
        if(graph[0].size()==2)
        {
            deg=i;
            break;
        }
        if(graph[i].size()==3)
        {
            deg=i;
            break;
        }
    }
    if(deg==-1)
    {
        cout<<binexp(2,n)<<'\n';
        return;
    }
    int l=-1,r;
    vi deapth(n,1);
    dfs(0,-1,graph,deapth);
    for(auto it:graph[deg])
    {
        if(deapth[it]>deapth[deg])
        continue;
        if(l==-1)
        l=deapth[it];
        else
        r=deapth[it];
    }
    // cout<<deg<<' '<<l<<' '<<r<<'\n';
    if(l>r)
    swap(l,r);
    if(l!=r)
    {
        cout<<(binexp(2,r-l)+binexp(2,r-l-1))*(binexp(2,deapth[0]-deapth[deg]+1))<<'\n';
        return;
    }
    cout<<binexp(2,r-l+1+deapth[0]-deapth[deg]+1)<<'\n';
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