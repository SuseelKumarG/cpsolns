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

vl x(1000010);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n,q;
    cin>>n>>q;
    vl a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vl dp(n+1);
    for(int i=0;i<n;i++)
    dp[i+1]=dp[i]^x[a[i]];
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<((dp[l-1]==dp[r])?"YES":"NO")<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    for(int i=0;i<=1000000;i++)
    x[i]=rng();
    while(t--)
    {
        solve();
    }
    return 0;
}