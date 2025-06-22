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
    int n,m;
    cin>>n>>m;
    if(m<n)
    {
        cout<<-1<<'\n';
        return;
    }
    if(m>((n*(n+1))/2))
    {
        cout<<-1<<'\n';
        return;
    }
    vi a(n);
    int curr=n-1;
    int tot=(n*(n+1))/2;
    while((tot>m)&&curr>=0)
    {
        if((tot-m)>=curr)
        {
            a[curr]=curr+1;
            tot-=curr;
            curr--;
        }
        else
        {
            a[tot-m]=curr+1;
            tot=m;   
            curr--; 
        }
    }
    for(int i=0;i<n;i++)
    {
        if(!a[i])
        {
            a[i]=curr+1;
            curr--;
        }
    }
    cout<<a[0]<<'\n';
    for(int i=1;i<n;i++)
    cout<<a[i-1]<<' '<<a[i]<<'\n';

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