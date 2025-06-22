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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(auto&it:a)
    {
        cin>>it;
        it=((it<=k)?-1:1);
    }
    bool l=0,r=0;
    int curr=0;
    for(int i=0;i<n-1;i++)
    {
        curr+=a[i];
        if(l&&(curr<1))
        {
            if(a[i]<0)
            {
                cout<<"YES\n";
                return;
            }
        }
        if(curr<=0)
        l=1;
    }
    curr=0;
    for(int i=n-1;i>0;i--)
    {
        curr+=a[i];
        if(r&&(curr<1))
        {
            if(a[i]<0)
            {
                cout<<"YES\n";
                return;
            }
        }
        if(curr<=0)
        r=1;
    }
    l=0,r=0;
    int x,y;
    curr=0;
    for(int i=0;i<n;i++)
    {
        curr+=a[i];
        if(curr<=0)
        {
            l=1;
            x=i;
            break;
        }
    }
    curr=0;
    for(int i=n-1;i>=0;i--)
    {
        curr+=a[i];
        if(curr<=0)
        {
            r=1;
            y=i;
            break;
        }
    }
    if(l&&r)
    {
        if((y-x)>1)
        {
            cout<<"YES\n";
            return;
        }
    }
    cout<<"NO\n";
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