#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.rbegin(),a.rend());
    map<int,int>need;
    map<int,int>hsh;
    for(int i=0;i<k;i++)
    need[a[i]]++;
    for(int i=0;i<n;i++)
    hsh[a[i]]++;
    ll ans=1;
    vl fact={1};
    ll curr=1;
    for(int i=1;i<=10000;i++)
    {
        curr*=i;
        curr%=MAX;
        fact.push_back(curr);
    }
    for(auto it:need)
    {
        ans*=fact[hsh[it.first]];
        ans%=MAX;
        ans*=binexp(fact[need[it.first]],MAX-2);
        ans%=MAX;
        ans*=binexp(fact[hsh[it.first]-need[it.first]],MAX-2);
        ans%=MAX;
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