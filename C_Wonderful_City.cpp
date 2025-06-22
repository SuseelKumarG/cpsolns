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

void solve()
{
    int n;
    cin>>n;
    vvi buil(n+1,vi(n+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        cin>>buil[i][j];
    }
    vi a(n);
    vi b(n);
    for(auto&it:a)
    cin>>it;
    for(auto&it:b)
    cin>>it;
    bool poss=1;
    vvi dpr(n+1,vi(2,1e18));
    vvi dpl(n+1,vi(2,1e18));
    dpr[0][0]=0;
    dpr[0][1]=0;
    dpr[1][0]=0;
    dpr[1][1]=a[0];
    dpl[0][0]=0;
    dpl[0][1]=0;
    dpl[1][0]=0;
    dpl[1][1]=b[0];
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                bool ok=1;
                for(int x=1;x<=n;x++)
                {
                    if((buil[i][x]+j)==(buil[i-1][x]+k))
                    ok=0;
                }
                if(!ok)
                continue;
                if(j==0)
                dpr[i][0]=min(dpr[i][0],dpr[i-1][k]);
                else
                dpr[i][1]=min(dpr[i][1],dpr[i-1][k]+a[i-1]);
            }
        }
        int minm=min(dpr[i][1],dpr[i][0]);
        if(minm==1e18)
        {
            cout<<-1<<'\n';
            return;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<2;j++)
        {
            for(int k=0;k<2;k++)
            {
                bool ok=1;
                for(int x=1;x<=n;x++)
                {
                    if((buil[x][i]+j)==(buil[x][i-1]+k))
                    ok=0;
                }
                if(!ok)
                continue;
                if(j==0)
                 dpl[i][0]=min(dpl[i][0],dpl[i-1][k]);
                else
                dpl[i][1]=min(dpl[i][1],dpl[i-1][k]+b[i-1]);

            }
        }
        int minm=min(dpl[i][1],dpl[i][0]);
        if(minm==1e18)
        {
            cout<<-1<<'\n';
            return;
        }
    }
    cout<<min(dpr[n][1],dpr[n][0])+min(dpl[n][0],dpl[n][1])<<'\n';
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