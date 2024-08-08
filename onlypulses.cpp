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

ll binmul(ll a,ll b)
{
    ll ans=0;
    while(b)
    {
        if(b&1) ans=(ans+a)%MAX;
        a=(a+a)%MAX;
        b>>=1;
    }
}

vl pov(500001);

void solve()
{
    int a[3];
    cin>>a[0]>>a[1]>>a[2];
    for(int i=0;i<5;i++)
    {
        sort(a,a+3);
        a[0]++;
    }
    ll ans=1;
    for(int i=0;i<3;i++)
    ans*=a[i];
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
        // cout<<5%0<<'\n';
        solve();
    }
    return 0;
}