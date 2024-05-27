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

vector<vii> adjvec()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    while(m--)
    {
        int v1,v2,w=1;
        cin>>v1>>v2;
        v1--;
        v2--;
        cin>>w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }
    return graph;
}

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

bool cycles(int v,int p,vector<bool> &vis,vector<set<int>> &graph)
{
    vis[v]=1;
    for(auto it:graph[v])
    {
        if(!vis[it])
        cycles(it,v,vis,graph);
        else if(it!=p)
        return 1;
    }
    return 0;
}

ll check(ll n,ll x,ll k,vl a)
{   
    ll diff=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<x)
        diff+=x-a[i];
    }
    // cout<<diff<<' '<<x<<' '<<k<<'\n';
    if(diff<=k)
    {
        k-=diff;
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>x)
            c++;
        }return k+c;
    }
    return -1;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vl a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    ll lo=0,hi=1e13;
    ll ans=0;
    while(lo<=hi)
    {
        ll x=(hi-lo)/2+lo;
        ll res=check(n,x,k,a);
        if(res!=-1)
        {
            ans=max(ans,1+res+n*(x-1));
            lo=x+1;
        }
        else
        hi=x-1;
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