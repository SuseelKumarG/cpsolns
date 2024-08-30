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
    int n,m;
    cin>>n>>m;
    ll mex=0;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        set<int>mexx;
        for(int i=0;i<t;i++)
        {
            int x;
            cin>>x;
            mexx.insert(x);
        }
        int x=0;
        for(ll j=0;j<=*(mexx.rbegin())+10&&x<2;j++)
        {
            if(mexx.find(j)==mexx.end())
            {
                mex=max(mex,j);
                x++;
            }
        }
    }
    ll ans=min(m+1LL,mex)*1LL*mex;
    if(m>=mex)
    ans+=(((m+1)*1LL*m)/2)-(((mex-1)*1LL*mex)/2);
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