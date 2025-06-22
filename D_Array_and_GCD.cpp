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

vb isprime(10000000,1);
vi primes;

bool poss(int k,vi&a)
{
    int n=a.size();
    int i=k;
    int sum=0;
    int curr=0;
    for(int j=0;(i+j)<n;j++)
    {
        sum+=a[i+j];
        curr+=primes[j];
    }
    return curr<=sum;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(ll&i:a)
    cin>>i;
    sort(a.begin(),a.end());
    int l=-1,r=n;
    while(r-l>1)
    {
        int m=(r+l)/2;
        if(poss(m,a))
        r=m;
        else
        l=m;
    }
    cout<<r<<'\n';
}

int32_t main()
{
    isprime[0]=isprime[1]=0;
    for(int i=2;i<10000000;i++)
    {
        if(isprime[i])
        {
            primes.push_back(i);
            for(int j=2*i;j<10000000;j+=i)
            {
                isprime[j]=0;
            }
        }
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