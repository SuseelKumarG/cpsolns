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
    int x=-1;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    vi b(n);
    for(auto &it:b)
    cin>>it;
    for(int i=0;i<n;i++)
    {
        if(b[i]!=-1)
        {
            x=a[i]+b[i];
            break;
        }
    }
    if(x!=-1)
    {
        for(int i=0;i<n;i++)
        {
            if(b[i]==-1)
            continue;
            if((a[i]+b[i])!=x)
            {
                cout<<0<<'\n';
                return;
            }
        }
    }
    int minm=*min_element(a.begin(),a.end());
    int maxm=*max_element(a.begin(),a.end());
    if((minm+k)<maxm)
    {
        cout<<0<<'\n';
        return;
    }
    bool ok=1;
    for(int i=0;i<n;i++)
    {
        ok&=(b[i]==-1);
    }
    if(ok)
    {
        cout<<(minm+k-maxm+1)<<'\n';
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(b[i]!=-1)
        continue;
        int add=x-a[i];
        b[i]=min(add,k);
    }
    for(int i=0;i<n;i++)
        {
            if(b[i]<0)
            {
                cout<<0<<'\n';
                return;
            }
            if((a[i]+b[i])!=x)
            {
                cout<<0<<'\n';
                return;
            }
        }
    cout<<1<<'\n';
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