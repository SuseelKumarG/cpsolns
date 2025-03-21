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

bool ok(vi&nope,int x)
{
    for(auto it:nope)
    {
        if((x>>it)&1)
        return 0;
    }
    return 1;
}


void solve()
{
    int n,x;
    cin>>n>>x;
    if(n==1)
    {
        cout<<x<<'\n';
        return;
    }
    vi nope;
    for(int i=0;i<31;i++)
    {
        if((x>>i)&1)
        continue;
        nope.push_back(i);
    }
    vi ans(n);
    for(int i=0;i<n;i++)
    {
        if(ok(nope,i))
        ans[i]=i;
        else
        ans[i]=x;
    }
    int orr=0;
    for(auto it:ans)
    orr|=it;
    if(ans[n-1]!=x&&orr!=x)
    ans[n-1]=x;
    for(auto it:ans)
    cout<<it<<' ';
    cout<<'\n';
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