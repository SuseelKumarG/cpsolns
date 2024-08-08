#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 200010

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

vl fact(N);

ll binexp(ll a,ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}


ll c(ll a,ll b)
{
    if(a<b)
    return 0LL;
    return (fact[a]*binexp((fact[b]*fact[a-b])%MAX,MAX-2))%MAX;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    int one=0;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        one++;
    }
    int l=k/2+1;
    int r=min(one,k);
    ll ans=0;
    for(int i=l;i<=r;i++)
    {
        ull f1=c(one,i);
        ull f2=c(n-one,k-i);
        f1=(f1*f2)%MAX;
        ans+=f1;
        ans%=MAX;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fact[0]=1;
    for(ll i=1;i<N;i++)
    fact[i]=(fact[i-1]*i)%MAX;
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}