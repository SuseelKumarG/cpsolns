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
    ll n,k;
    cin>>n>>k;
    ll a=2,b=4*k-2,c=(n*n-n)/2+n*k;
    c*=-1;
    ll x=((floor(sqrt(b*b-4.0*a*c))-2*k+1)/(2));
    ll y=((floor(sqrt(b*b-4.0*a*c))-2*k+1)/(2));
    ll ans=LLONG_MAX;
    for(int i=-5;i<=5;i++)
    {
        // if(y>0)
        ans=min(ans,abs(4*k*k+0LL+4*k*(n-1)+(2*n*n-2*n+1)));
        // if(x>0)
        ans=min(ans,abs(4*k*k+4*k*(n-1))+0LL+(2*n*n-2*n+1));
    }
    // cout<<ceil(-2.5)<<' ';
    cout<<x<<' '<<y<<' ';
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