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

int edges=0;

void dfs(int v,vvi &graph,vector<bool> &vis)
{
    vis[v]=1;
    edges++;
    for(auto it:graph[v])
    {
        if(!vis[it])
        dfs(it,graph,vis);
    }
}

void solve()
{
    int n;
    cin>>n;
    vvi graph(n);
    bool poss=1;
    map<int,int>cnt;
    vector<bool> vis(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
        if(x==y)
        poss=0;
        cnt[x]++;
        cnt[y]++;
    }
    for(auto it:cnt)
    {
        if(it.second!=2)
        poss=0;
    }
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            edges=0;
            dfs(i,graph,vis);
            if(edges&1)
            poss=0;
        }
    }
    cout<<(poss?"YES":"NO")<<'\n';
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