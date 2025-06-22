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

bool poss(vi a,vi b,int k)
{
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        return 0;
        int x=k-a[i];
        a[i]+=min(b[i],x);
        b[i]-=min(x,b[i]);
    }
    int x=accumulate(b.begin(),b.end(),0LL)*2;
    int y=0;
    for(int i=0;i<n;i++)
    {
        int temp=k-a[i];
        if(temp&1)
        temp--;
        y+=temp;
    }
    return y>=x;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n),b(n);
    for(ll&i:a)
    cin>>i;
    for(ll&i:b)
    cin>>i;
    int l=0,r=INT_MAX;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(poss(a,b,m))
        r=m;
        else
        l=m;
    }
    cout<<r<<'\n';
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