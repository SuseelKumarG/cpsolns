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

void solve()
{
    int n,s,x;
    cin>>n>>s>>x;
    vi a(n);
    for(ll&i:a)
    cin>>i;
    vi h={-1},l={-1};
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
        l.push_back(i);
        if(a[i]>x)
        h.push_back(i);
    }
    map<int,vi>pos;
    int sum=0;
    vi pre(n+1);
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        pre[i+1]=sum;
        if(!pos.count(sum))
        pos[sum].push_back(-1);
        pos[sum].push_back(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int prev=pre[i];
        int minm=(lower_bound(l.begin(),l.end(),i)!=l.end()?*lower_bound(l.begin(),l.end(),i):-1);
        int maxm=(lower_bound(h.begin(),h.end(),i)!=h.end()?*lower_bound(h.begin(),h.end(),i):n);
        maxm--;
        if(maxm==-1||minm==-1)
        continue;
        if(maxm<minm)
        continue;
        int lo=lower_bound(pos[s+prev].begin(),pos[s+prev].end(),minm)-pos[s+prev].begin();
        int hi=upper_bound(pos[s+prev].begin(),pos[s+prev].end(),maxm)-pos[s+prev].begin();
        if(lo==-1||hi==-1)
        continue;
        ans+=hi-lo;
    }
    cout<<ans<<'\n';
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