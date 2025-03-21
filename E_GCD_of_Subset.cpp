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

vl mul(1e6+1);
vl ans(1e6+1);
vl hsh(1e6+1);

void solve()
{
    ll n,k;
    cin>>n>>k;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    for(auto it:a)
    hsh[it]++;
    for(int i=1;i<mul.size();i++)
    {
        ll x=i;
        for(int j=x;j<=mul.size();j+=i)
        {
            mul[x]+=hsh[j];
        }
    }
    for(int i=1;i<=mul.size();i++)
    {
        ll x=i;
        if(mul[x]>=k)
        {
            ans[x]=ans[x];
            for(int j=x;j<=mul.size();j+=x)
            {
                ans[j]=x;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<(ans[a[i]]?ans[a[i]]:1)<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}