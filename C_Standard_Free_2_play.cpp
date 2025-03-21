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
    ll h,n;
    cin>>h>>n;
    vi a(n);
    for(auto &it:a)    
    cin>>it;
    a.push_back(0);
    if(n==h)
    {
        cout<<0<<'\n';
        return;
    }
    int curr=1;
    int ans=0;
    int l=1;
    for(int i=l;i<n;i++)
    {
        if(a[i]!=a[i-1]-1)
        break;
        curr++;
        l++;
    }
    if(!(curr&1))
    ans++;
    curr=1;
    int r=n;
        for(int i=r;i>0;i--)
        {
            if(a[r-1]!=a[r]+1)
            break;
            r--;       
        }
    if(l<r)
    {
        // ans++;
        for(int i=l+1;i<=r;i++)
        {
            if(a[i]!=a[i-1]-1)
            {
                if(curr&1)
                ans++;
                curr=1;
                continue;
            }
            curr++;
        }
        if((curr&1)&&(curr!=1))
        ans++;
    }
    cout<<ans<<'\n';
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