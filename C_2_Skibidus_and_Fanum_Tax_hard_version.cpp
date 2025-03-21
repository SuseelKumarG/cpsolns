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

ll func(vl &b,ll x,ll y)
{
    return (lower_bound(b.begin(),b.end(),x+y)==b.end()?LLONG_MAX:*lower_bound(b.begin(),b.end(),x+y));
}


void solve()
{
    int n,m;
    cin>>n>>m;
    vl a(n),b(m);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    sort(b.begin(),b.end());
    reverse(a.begin(),a.end());
    a.push_back(INT_MIN);
    reverse(a.begin(),a.end());
    for(int i=1;i<=n;i++)
    {
        auto it=lower_bound(b.begin(),b.end(),a[i]+a[i-1]);
        ll x=(it==b.end()?-1:*it);
        if(x!=-1)
        {
            if(a[i]>=a[i-1])
            {
                a[i]=min(a[i],x-a[i]);
            }
            else
            {
                a[i]=x-a[i];
            }
        }
        if(a[i]<a[i-1])
        {
            cout<<"NO\n";
            return;
        }
    }
    cout<<"YES\n";
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