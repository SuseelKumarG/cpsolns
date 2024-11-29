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

void solve()
{
    int n;
    cin>>n;
    vl a(n),b(n);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    vi pos,neg;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=b[i])
        pos.push_back(a[i]-b[i]);
        if(a[i]<b[i])
        neg.push_back(b[i]-a[i]);
    }
    sort(pos.begin(),pos.end());
    reverse(pos.begin(),pos.end());
    sort(neg.begin(),neg.end());
    ll ans=accumulate(a.begin(),a.end(),0LL);
    ll p=accumulate(pos.begin(),pos.end(),0LL);
    ll niggative=accumulate(neg.begin(),neg.end(),0LL);
    ans-=p-niggative;
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