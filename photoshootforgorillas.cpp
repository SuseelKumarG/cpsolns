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
    int n,m,k;
    cin>>n>>m>>k;
    int w;
    cin>>w;
    vi a(w);
    for(auto &it:a)
    cin>>it;
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vl mulplr;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        mulplr.push_back((min(min(i+1,min(n-k+1,k)),min(n-i,k))*1LL*min(min(j+1,min(m-k+1,k)),min(m-j,k))));
    }
    sort(mulplr.begin(),mulplr.end());
    reverse(mulplr.begin(),mulplr.end());
    ll ans=0;
    for(int i=0;i<w;i++)
    ans+=mulplr[i]*a[i];
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