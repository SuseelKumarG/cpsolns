#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll,null_type,less_equal<ll>,rb_tree_tag,tree_order_statistics_node_update>
 
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
#define MAX 998244353
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

void solve()
{
    int n,q;
    cin>>n>>q;
    vl a(n),b(n);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    vl c,d;
    c=a;
    d=b;
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    ll ans=1;
    for(int i=0;i<n;i++)
    {
        ans*=min(c[i],d[i]);
        ans%=MAX;
    }
    cout<<ans<<' ';
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(x)
        {
            int ind=upper_bound(d.begin(),d.end(),b[y])-d.begin()-1;
            if(d[ind]<c[ind])
            {
                ans*=binexp(d[ind],MAX-2);
                ans%=MAX;
                ans*=d[ind]+1;
                ans%=MAX;
            }
            b[y]++;
            d[ind]++;
        }
        else
        {
            int ind=upper_bound(c.begin(),c.end(),a[y])-c.begin()-1;
            if(c[ind]<d[ind])
            {
                ans*=binexp(c[ind],MAX-2);
                ans%=MAX;
                ans*=c[ind]+1;
                ans%=MAX;
            }
            a[y]++;
            c[ind]++;
        }
        cout<<ans<<' ';
    }
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