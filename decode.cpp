#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef const long long cll;
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
    string s;
    cin>>s;
    int n=s.size();
    vi a;
    for(auto it:s)
    {
        if(it=='0')
        a.push_back(-1);
        else
        a.push_back(1);
    }
    vi pre={0};
    int sum=0;
    for(auto it:a)
    {
        sum+=it;
        pre.push_back(sum);
    }
    map<ll,ll>ind;
    ll ans=0;
    for(int i=0;i<=n;i++)
    {
        ans+=((n-i+1LL)*(ind[pre[i]]*1LL))%MAX;
        ans%=MAX;
        ind[pre[i]]+=i+1;
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