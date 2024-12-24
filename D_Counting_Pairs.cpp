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
    ll n,d,u;
    cin>>n>>d>>u;
    vl a(n);
    for(auto&it:a)
    cin>>it;
    ll sum=accumulate(a.begin(),a.end(),0LL);
    int l=0,r=0;
    ll minm=max(0LL,sum-u),maxm=sum-d;
    if(sum<d)
    {
        cout<<0<<'\n';
        return;
    }
    sort(a.begin(),a.end());
    // map<int,int>hsh;
    // for(auto it:a)
    // hsh[it]++;
    // set<int>temp(a.begin(),a.end());
    // a.clear();
    // for(auto it:temp)
    // a.push_back(it);
    // n=a.size();
    // while(!a.empty())
    // {
    //     if(a.back()<maxm)
    //     break;
    //     a.pop_back();
    // }
    // n=a.size();
    vi b(n+1);
    for(int i=1;i<=n;i++)
    b[i]=b[i-1]+a[i-1];
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        int lo=lower_bound(a.begin(),a.end(),minm-a[i])-a.begin();
        lo=max(lo,i+1);
        int hi=upper_bound(a.begin(),a.end(),maxm-a[i])-a.begin()-1;
        // ll curr=b[hi+1]-b[lo];
        if(hi>=lo)
        ans+=hi-lo+1;
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