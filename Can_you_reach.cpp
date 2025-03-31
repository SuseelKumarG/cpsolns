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
    vi a(n);
    for(auto&it:a)
    cin>>it;
    ll ans=(n*1LL*(n-1))/2;
    int curr=1;
    vi slopes;
    int prev=-1;
    if(a[1]>a[0])
    prev=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i-1])
        {
            if(prev==-1)
            {
                slopes.push_back(curr);
                curr=1;
                prev=1;
            }
        }
        else
        {
            if(prev==1)
            {
                slopes.push_back(curr);
                curr=1;
                prev=-1;
            }
        }
        curr++;
    }
    slopes.push_back(curr);
    n=slopes.size();
    vl pre(n+1);
    for(int i=1;i<=n;i++)
    {
        pre[i]=pre[i-1]+slopes[i-1];
    }
    ll rem=0;
    for(int i=3;i<=n;i++)
    {   
        rem+=(pre[n]-pre[i-1]-1)*(pre[i-2]-1);
    }
    cout<<ans-rem<<'\n';
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