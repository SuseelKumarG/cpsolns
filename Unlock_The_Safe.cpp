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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(auto&ti:a)
    {
        cin>>ti;
        ti--;
    }
    vi b(n);
    for(auto&ti:b)
    {
        cin>>ti;
        ti--;
    }
    int ans=0;
    int odd=INT_MAX;
    int eve=INT_MAX;
    for(int i=0;i<n;i++)
    {
        int x;
        if(a[i]<b[i])
        {
            x=min(b[i]-a[i],a[i]-b[i]+9);
            if((max(b[i]-a[i],a[i]-b[i]+9)-min(b[i]-a[i],a[i]-b[i]+9))&1)
            odd=min(odd,max(b[i]-a[i],a[i]-b[i]+9)-min(b[i]-a[i],a[i]-b[i]+9));
        }
        else
        {
            x=min(a[i]-b[i],b[i]+9-a[i]);
            if((max(a[i]-b[i],b[i]+9-a[i])-min(a[i]-b[i],b[i]+9-a[i]))&1)
            odd=min(odd,max(a[i]-b[i],b[i]+9-a[i])-min(a[i]-b[i],b[i]+9-a[i]));
        }
        ans+=x;
    }
    if(k>=ans)
    {
        if((k-ans)&1)
        {
            if((k-ans)>=odd)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
        else
        cout<<"YES\n";
    }
    else
    cout<<"NO\n";
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