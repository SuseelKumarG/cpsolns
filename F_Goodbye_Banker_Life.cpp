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

void hope(ll n,ll k,vl&ans)
{
    if(!n)
    return;
    if(n==1)
    {
        ans.push_back(k);
        return;
    }
    if(n==2)
    {
        ans.push_back(k);
        ans.push_back(k);
        return;
    }
    if(n==3)
    {
        ans.push_back(k);
        ans.push_back(0);
        ans.push_back(k);
        return;
    }
    if((1LL<<((int)log2(n)))==n)
    {
        for(int i=0;i<n;i++)
        ans.push_back(k);
        return;
    }
    ll temp=n-(1LL<<((int)log2(n)));
    hope(temp,k,ans);
    ll waste=n-2*temp;
    for(int i=0;i<waste;i++)
    ans.push_back(0);
    for(int i=0;i<temp;i++)
    ans.push_back(ans[i]);
    return;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    vl ans;
    hope(n,k,ans);
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