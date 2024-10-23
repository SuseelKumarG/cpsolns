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
#define MAX 998244353
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

vl fact(100000);

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
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    ll ans=1;
    for(int i=0;i<n;i+=3)
    {
        int minm=*min_element(a.begin()+i,a.begin()+i+3);
        ans*=1LL*count(a.begin()+i,a.begin()+i+3,minm);
        ans%=MAX;
    }
    ans*=fact[n/3];
    ans%=MAX;
    ans*=binexp(fact[n/6],MAX-2);
    ans%=MAX;
    ans*=binexp(fact[n/6],MAX-2);
    ans%=MAX;
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    fact[1]=1;
    for(int i=2;i<=100000;i++)
    {
        fact[i]=(fact[i-1]*1LL*i)%MAX;
    }
    while(t--)
    {
        solve();
    }
    return 0;
}