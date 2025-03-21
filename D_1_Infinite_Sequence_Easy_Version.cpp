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

int rec(vi&a,ll k,ll ans)
{
    // cout<<k<<'\n';
    if(k<a.size())
    return a[k];
    if((k/2)&1)
    return 0;
    ll temp=rec(a,k/2,ans);
    cout<<(ans^temp)<<'\n';
    return ans^temp;
    // if(k>=n)
    // return rec(n,a,k/2);
    // return a[k];
}

void solve()
{
    ll n,l,r;
    cin>>n>>l>>r;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    if(!(n&1))
    {
        a.push_back(0);
        for(int i=0;i<n/2;i++)
        a[n]^=a[i];
        n++;
    }
    // for(int i=n-1;i<2*n;i++)
    // {
    //     if(i&1)
    //     a.push_back(a.back());
    //     else
    //     a.push_back(a[i]^a[i/2]);
    // }
    ll ans=accumulate(a.begin(),a.begin()+n,0LL)&1;
    // ans^=rec(a,l);
    cout<<rec(a,l,ans)<<'\n';
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