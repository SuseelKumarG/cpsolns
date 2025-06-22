#include <bits/stdc++.h>
#include <cstdint>
#include <stdint.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
typedef long long ll;
// using  ll=__int128 ;
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
#define MAX 998244353
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

vi fact(10000000,1);

void solve()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int ans=0;
    for(int i=0;i<=c;i++)
    {
        int x=fact[d+i-1];
        x*=binexp(fact[d-1],MAX-2);
        x%=MAX;
        x*=binexp(fact[i],MAX-2);
        x%=MAX;
        int y=fact[a+b+c-i];
        y*=binexp(fact[a+c-i],MAX-2);
        y%=MAX;
        y*=binexp(fact[b],MAX-2);
        y%=MAX;
        x*=y;
        x%=MAX;
        ans+=x;
        ans%=MAX;
    }
    cout<<ans<<'\n';
}

int32_t main()
{
    for(int i=1;i<fact.size();i++)
    {
        fact[i]=fact[i-1]*i;
        fact[i]%=MAX;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}