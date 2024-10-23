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
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    int gc=0;
    for(auto it:a)
    gc=gcd(gc,it);
    ll ans=0;
    vi divs;
    for(int i=1;i*i<=n;i++)
    {
        if(!(n%i))
        {
            divs.push_back(i);
            if(n/i!=i)
            divs.push_back(n/i);
        }
    }
    // sort(divs.begin(),divs.end());
    if(gc!=1)
    {
        cout<<divs.size()<<'\n';
        return;
    }
    int act;
    for(auto it:divs)
    {
        int k=it;
        int g=0;
        for(int i=0;i<n-k;i++)
        g=gcd(g,abs(a[i]-a[i+k]));
        if(g!=1)
        ans++;
    }
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