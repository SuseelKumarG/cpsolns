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

vector<bool> is_prime(2000000, true);
vi prime;

bool poss(int y,vb&vis,int n)
{
    if(y>n)
    return 0;
    if(vis[y])
    return 0;
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    vb vis(n+1);
    vis[0]=1;
    vi a(n);
    int ind=0;
    if(n&1)
    {
        a[n/2]=1;
        vis[1]=1;
    }
    for(int i=n;i>0;i--)
    {
        if(vis[i])
        continue;
        vis[i]=1;
        int x=prime[upper_bound(prime.begin(),prime.end(),2*i)-prime.begin()];
        int y=prime[(upper_bound(prime.begin(),prime.end(),i)-prime.begin())];
        for(int j=x;j>=y;j--)
        {
            if(poss(prime[j]-i,vis,n))
            {
                a[ind]=i;
                a[n-ind-i]=prime[j]-i;
                vis[prime[j]-i]=1;
                ind++;
            }
        }
    }
    for(auto it:a)
    cout<<it<<' ';
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
is_prime[0] = is_prime[1] = false;
for (int i = 2; i <= 2000000; i++) {
    if (is_prime[i] && (long long)i * i <= 2000000) {
        prime.push_back(i);
        for (int j = i * i; j <= 2000000; j += i)
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