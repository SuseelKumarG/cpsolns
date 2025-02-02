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

bool poss(vl &a,int n,int m,ll k)
{
    ll cnt=1;
    ll curr=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>k)
        return 0;
        if(curr+a[i]>k)
        {
            curr=a[i];
            cnt++;
        }
        else
        curr+=a[i];
    }
    return cnt<=m;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    if(n<m)
    {
        cout<<-1<<'\n';
        return;
    }
    ll r=accumulate(a.begin(),a.end(),0LL);
    ll l=*min_element(a.begin(),a.end());
    while(r-l>1)
    {
        ll mid=(r-l)/2+l;
        if(poss(a,n,m,mid))
        r=mid;
        else
        l=mid;
    }
    // if(poss(a,n,m,l))
    // cout<<l<<'\n';
    // else
    cout<<r<<'\n';
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