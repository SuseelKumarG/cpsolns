#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
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

vi primes(2000001);
vi palindrome(2000001);
vi is_prime(2000001,1);

bool is_p(int x)
{
    vi temp;
    while(x)
    {
        temp.push_back(x%10);
        x/=10;
    }
    int n=temp.size();
    for(int i=0;i<n/2;i++)
    {
        if(temp[i]!=temp[n-1-i])
        return 0;
    }
    return 1;
}

void solve()
{
    int x,y;
    cin>>x>>y;
    int curr=1;
    for(int i=1;i<primes.size();i++)
    {
        if((y*primes[i])<=(x*palindrome[i]))
        curr=i;
    }
    cout<<curr<<'\n';
}

int32_t main()
{
    is_prime[0]=0;
    is_prime[1]=0;
    for(int i=2;i<is_prime.size();i++)
    {
        if(is_prime[i]&&(i*i)<is_prime.size())
        {
            for(int j=i*i;j<is_prime.size();j+=i)
            is_prime[j]=0;
        }
    }
    for(int i=1;i<primes.size();i++)
    {
        primes[i]=primes[i-1];
        palindrome[i]=palindrome[i-1];
        if(is_prime[i])
        primes[i]++;
        if(is_p(i))
        palindrome[i]++;
    }
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}