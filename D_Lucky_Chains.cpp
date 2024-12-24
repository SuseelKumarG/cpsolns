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

void factor(ll x,vl &fact)
{
    fact.push_back(x);
    for(ll i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            fact.push_back(i);
            fact.push_back(x/i);
        }
    }
}
#define MAXN 10000000
vector<ll> spf(MAXN + 1, 1);

// Calculating SPF (Smallest Prime Factor) for every
// number till MAXN.
// Time Complexity : O(nloglogn)
void sieve()
{
    // stores smallest prime factor for every number

    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) { // if the number is prime ,mark
                           // all its multiples who havent
                           // gotten their spf yet
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) // if its smallest prime factor is
                          // 1 means its spf hasnt been
                          // found yet so change it to i
                    spf[j] = i;
            }
        }
    }
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
void facto(ll x,vl &ret)
{
    while (x != 1) {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
}
void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a>b)
    swap(a,b);
    ll diff=b-a;
    if(diff==1)
    {
        cout<<-1<<'\n';
        return;
    }
    if(gcdl(a,b)!=1)
    {
        cout<<0<<'\n';
        return;
    }
    vl fact;
    facto(diff,fact);
    // for(auto it:fact)
    // cout<<it<<' ';
    // cout<<'\n';
    ll ans=LLONG_MAX;
    for(auto it:fact)
    {
        ll x=a/it;
        x+=(x*it!=a);
        x=x*it-a;
        ll y=b/it;
        y+=(y*it!=b);
        y=y*it-b;
        ans=min(ans,max(x,y));
    }
    cout<<ans<<'\n';
}

int main()
{
    sieve();
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