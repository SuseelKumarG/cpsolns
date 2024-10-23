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
    ll a,b,c;
    cin>>a>>b>>c;
    vi A,B,C;
    while(a)
    {
        A.push_back(a&1);
        a>>=1;
    }
    while(A.size()!=64)
    A.push_back(0);
    while(b)
    {
        B.push_back(b&1);
        b>>=1;
    }
    while(B.size()!=64)
    B.push_back(0);
    while(c)
    {
        C.push_back(c&1);
        c>>=1;
    }
    while(C.size()!=64)
    C.push_back(0);
    ll ans=0;
    map<pair<pii,int>,ll>x;
    x[{{0,0},0}]=0;
    x[{{0,1},0}]=0;
    x[{{1,0},1}]=0;
    x[{{1,1},1}]=0;
    x[{{0,0},1}]=1;
    x[{{0,1},0}]=1;
    x[{{1,1},0}]=1;
    x[{{1,0},1}]=1;
    for(ll i=0;i<64;i++)
    {
        if((A[i]&&!B[i]&&!C[i])||(!A[i]&&B[i]&&C[i]))
        {
            ans=-1;
            break;
        }
        ans+=(x[{{A[i],B[i]},C[i]}])<<i;
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