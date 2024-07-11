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
#define MAX 998244353
#define N 10    010

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

vl pov(500001);

void solve()
{
    int n;
    cin>>n;
    vl a(n),mx(n);
    ll c=0;
    for(int i=0;i<n;i++) cin>>a[i];
    ll minm=INT_MAX;
    for(int i=0;i<n;i++)
    {
        c+=a[i];
        minm=min(minm,c);
    }
    c=0;
    ll ans=0;
    int cnt=0;
    if(minm>=0)
    {
        cout<<pov[n]<<'\n';
        return;
    }
    for(int i=0;i<n;i++)
    {
        c+=a[i];
        if(c==minm)
        ans=(ans+pov[n-i-1+cnt])%MAX;
        if(c>=0)
        cnt++;
    }
    cout<<ans<<'\n';    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pov[0]=1;
    for(int i=1;i<500001;i++)
    pov[i]=(pov[i-1]*2)%MAX;            
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}