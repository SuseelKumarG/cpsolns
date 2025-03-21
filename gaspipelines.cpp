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
    ll n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll ans=n*a+n*b+b;
    int fo=-1,lo=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            if(fo==-1)
            fo=i;
            lo=i;
        }
    }
    if(fo>=0)
    {
        ll zer=0,one=0;
        ans+=2*a+b;
        for(int i=fo;i<=lo;i++)
        {
            if(s[i]=='0')
            zer++;
            else
            {
                ans+=min(2*a+b,zer*b);
                zer=0;
            }
            if(s[i]=='1')
            ans+=b;
        }
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