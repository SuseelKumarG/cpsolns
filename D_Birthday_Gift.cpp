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

int soln(vi &bitss,vi &bit,vl &a)
{
    int n=a.size();
    int ans=-1;
    for(int ind=31;ind>=0;ind--)
    {
        if(bitss[ind]&1)
        {
            if(bit[ind])
            continue;
            else
            return ans;
        }
        else
        {
            if(bit[ind])
            ans=max(ans,bitss[ind]/2+1);
        }
    }
    return ans;
}

void solve()
{
    ll n,x;
    cin>>n>>x;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    for(int i=1;i<n;i++)
    a[i]^=a[i-1];
    vi bitss(32);
    int ans=-1;
    for(int ind=30;ind>=0;ind--)
    {
        for(int i=0;i<n;i++)
        {
            if(!(a[i]&(1LL<<ind))&&(x&(1LL<<ind)))
            bitss[ind]++;
            // else if((a[i]&(1LL<<ind))&&!(x&(1LL<<ind)))
            // {
            //     cout<<-1<<'\n';
            //     return;
            // }
        }
    }
    for(int i=30;i>=0;i--)
    {
        if((x&(1LL<<i))&&!(a[n-1]&(1LL<<i)))
        ans=max(ans,bitss[i]);
    }
    cout<<(ans==-1?-1:ans)<<'\n';
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