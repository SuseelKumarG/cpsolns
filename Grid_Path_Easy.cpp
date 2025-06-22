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
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

long long gcd(long long a, long long b){
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
ll lcm(ll a,ll b)
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
    int n,q;
    cin>>n>>q;
    vector<string>a(2);
    cin>>a[0]>>a[1];
    vector<ll>x,y;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        if(a[0][i]=='1')
        {
            x.push_back(abs(i-ind));
            ind++;
        }
    }
    ind=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[1][i]=='1')
        {
            y.push_back(abs(n-ind-i-1));
            ind++;
        }
    }
    for(int i=1;i<x.size();i++) 
    x[i]+=x[i-1];
    for(int i=1;i<y.size();i++)
    y[i]+=y[i-1];
    ll ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        int j=n+1-i;        
        if(x.size()>=i&&y.size()>=j)
        ans=min(ans,x[i-1]+y[j-1]);
    }
    cout<<(ans==INT_MAX?-1:ans)<<'\n';
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