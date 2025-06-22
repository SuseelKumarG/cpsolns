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
vi is_prime(1000010,1);
int minm(int x,int k)
{
    vi a;
    for(int i=1;i*i<=x;i++)
    {
        if(!(x%i))
        {
            a.push_back(i);
            if((i*i)!=x)
            a.push_back(x/i);
        }
    }
    sort(a.begin(),a.end());
    int n=a.size();
    vi dp(n,INT_MAX);
    map<int,int>pos;
    for(int i=0;i<n;i++)
    pos[a[i]]=i;
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(a[i]<=k)
        dp[i]=1;
        for(int j=i;j>0;j--)
        {
            if(a[i]%a[j])
            continue;
            dp[i]=min(dp[i],dp[j]+dp[pos[a[i]/a[j]]]);
        }
    }
    return ((dp[n-1]==INT_MAX)?-1:dp[n-1]);
}

void solve()
{
    int x,y,k,z;
    cin>>x>>y>>k;
    z=gcd(x,y);
    int op=1;
    op=minm(x/z,k);
    int pq=1;
    pq=minm(y/z,k);
    cout<<(((op!=-1)&&(pq!=-1))?(op+pq):-1)<<'\n';
}

int32_t main()
{
    is_prime[1]=is_prime[0]=0;
    int n=is_prime.size();
    for(int i=2;i<n;i++)
    {
        if(is_prime[i])
        for(int j=2*i;j<n;j+=i)
        is_prime[j]=0;
    }
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