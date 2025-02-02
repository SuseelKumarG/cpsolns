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

void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(auto&it:a)
    cin>>it;
    if(n==1)
    {
        cout<<a[0]<<'\n';
        return;
    }
    ll ans=accumulate(a.begin(),a.end(),0LL);
    for(int i=0;i<n-1;i++)
    {
        vl b;
        for(int i=0;i<a.size()-1;i++)
        {
            b.push_back(a[i+1]-a[i]);
        }
        ll curr=0;
        ll x=0,y=0;
        for(int i=0;i<b.size();i++)
        {
            curr+=abs(b[i]);
            if(curr>=MAX)
            x++;
            curr%=MAX;
        }
        vl c;
        reverse(a.begin(),a.end());
        for(int i=0;i<a.size()-1;i++)
        {
            c.push_back(a[i+1]-a[i]);
        }
        ll curr0=0;
        for(int i=0;i<b.size();i++)
        {
            curr0+=abs(c[i]);
            if(curr0>=MAX)
            y++;
            curr0%=MAX;
        }
        ans=max(ans,curr);
        ans=max(ans,curr0);
        if(x>y)
        a=b;
        else if(x==y)
        {
            if(curr>curr0)
            a=b;
            else
            a=c;
        }
        else
        a=c;
    }
    cout<<ans<<'\n';
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