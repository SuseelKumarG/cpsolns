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
vector<bool> is_prime(1000000, true);   
void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    int ans=3;
    int gc=0;
    for(int i=0;i<n;i++)
    {
        gc=gcd(gc,a[i]);
    }
    if(gc==1)
    ans=0;
    gc=0;
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
        {
            gc=gcd(gc,gcd(a[i],i+1));
        }
        else
        {
            gc=gcd(gc,a[i]);
        }
    }
    if(gc==1&&ans==3)
    ans=1;
    gc=0;
    for(int i=0;i<n;i++)
    {
        if(i==n-2)
        {
            gc=gcd(gc,gcd(a[i],i+1));
        }
        else
        {
            gc=gcd(gc,a[i]);
        }
    }
    if(gc==1&&ans==3)
    ans=2;
    cout<<ans<<'\n';
}

int main()
{
    int n=1000000;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; i++) {
        if (is_prime[i] && (long long)i * i < n) {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = false;
        }
    }
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