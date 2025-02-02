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

bool poss(vl &l,vl &r,int i,int j,int m)
{
    return l[i-1]+r[j+1]>=m;
}

void solve()
{
    ll n,m,v;
    cin>>n>>m>>v;
    vl a(n+2);
    for(int i=1;i<=n;i++)
    cin>>a[i];
    vl l(n+2),r;
    r=l;
    ll curr=0;
    for(int i=1;i<=n;i++)
    {
        l[i]=l[i-1];
        curr+=a[i];
        if(curr>=v)
        {
            l[i]++;
            curr=0;
        }
    }
    curr=0;
    for(int i=n;i>0;i--)
    {
        r[i]=r[i+1];
        curr+=a[i];
        if(curr>=v)
        {
            r[i]++;
            curr=0;
        }
    }
    vl pre(n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]+=pre[i-1]+a[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int lo=i,hi=n;
        while(hi-lo>1)
        {
            int j=(hi-lo)/2+lo;
            if(poss(l,r,i,j,m))
            lo=j;
            else
            hi=j;
        }
        if(poss(l,r,i,hi,m))
        ans=max(ans,pre[hi]-pre[i-1]);
        else if(poss(l,r,i,lo,m))
        ans=max(ans,pre[lo]-pre[i-1]);
    }
    cout<<(l[n]>=m?ans:-1)<<'\n';
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