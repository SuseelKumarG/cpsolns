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

void add(ll x,vi&a) {
    int n=a.size();
    for(int i=n-1;i>=0;i--)
    {
        int k=(x>>i)&1;
        if(!k)
        continue;
        if(!a[i])
        {
            a[i]=x;
            return;
        }
        x^=a[i];    
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        graph[x].push_back({y,z});
    }
    queue<pii>fin;
    vi xo(n,-1);
    fin.push({0,0});
    while(fin.size())
    {
        pii x=fin.front();
        fin.pop();
        if(xo[x.first]!=-1)
        continue;
        xo[x.first]=x.second;
        for(auto it:graph[x.first])
        {
            fin.push({it.first,x.second^it.second});
        }
    }  
    vi basis(11);
    for(int i=0;i<n;i++)
    {
        for(auto it:graph[i])
        {
            if(xo[i]!=-1&&xo[it.first]!=-1)
            {
                int x=xo[i]^xo[it.first]^it.second;
                if(x)
                add(x,basis);
            }
        }
    }
    int ans=xo[n-1];
    if(ans<0)
    {
        cout<<-1<<'\n';
        return;
    }
    reverse(basis.begin(),basis.end());
    for(auto it:basis)
    {
        if((ans^it)<ans)
        ans^=it;
    }
    cout<<ans<<'\n';
}

int32_t main()
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