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

bool poss(vll &a,ll n,ll k,ll m)
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].second>=m&&a[i].first<m)
        cnt++;
    }
    return cnt<=k;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vl a(n),b(n);
    for(auto&it:a)
    cin>>it;
    for(auto&it:b)
    cin>>it;
    vl A=a;
    vl B=b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ll ind=lower_bound(b.begin(),b.end(),a[i])-b.begin();
        if(i-ind>k)
        continue;
        ind=n-ind;
        ans=max(ans,a[i]*ind);
    }
    for(int i=0;i<n;i++)
    {
        ll ind=lower_bound(a.begin(),a.end(),b[i])-a.begin();
        ll ind1=lower_bound(b.begin(),b.end(),b[i])-b.begin();
        if(ind-ind1>k)
        continue;
        ans=max(ans,b[i]*(n-i));
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