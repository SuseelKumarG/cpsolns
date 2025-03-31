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
#define N 10000000

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
vector<bool> is_prime(N+1, true);
vector<ll>prime;
vector<ll>primesq;
void solve()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(auto it:prime)
    {
        if(n<it)
        break;
        ans+=n/it;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (int j = 2*i; j <= N; j += i)
                is_prime[j] = false;
        }
    }
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}