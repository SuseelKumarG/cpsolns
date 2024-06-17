//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
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

ll sqr(ll x)
{
    ll lo=0,hi=x;
    ll mid;
    while(hi-lo>1)
    {
        mid=(hi-lo)/2+lo;
        if(mid*mid<x)
        lo=mid;
        else
        hi=mid;
    }
    if(hi*hi<=x)
    return hi;
    return lo;
    // cout<<lo<<' '<<hi<<'\n'; 
}

void solve()
{
    ll n;
    cin>>n;
    ll x=n;
    ll z;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        while(i*1LL*i+x*x>=n*n+1+2*n && x>0)
        x--;
        z=x;
        while(i*1LL*i+z*z>=n*n && z>0)
        {
            z--;
            ans++;
        }
    }
    ans++;
    ans*=4;
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