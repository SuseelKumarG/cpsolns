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
    int l,r;
    cin>>l>>r;
    ll ans=0,curr=0,x=l;
    while(x)
    {
        x/=3;
        ans++;
        curr++;
    }
    // cout<<curr<<'\n';
    ans*=2;
    x=curr;
    ll temp=1;
    while(x--)
    temp*=3;
    for(int i=l+1;i<temp && i<=r;i++)
    ans+=curr;
    curr++;
    int i;
    for(i=temp;i*3<=r;i*=3)
    {
        ans+=i*2LL*curr;
        curr++;
    }
    if(r>=i)
    ans+=(r-i+1)*curr;
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