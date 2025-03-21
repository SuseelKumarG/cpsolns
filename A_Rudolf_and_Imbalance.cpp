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
    int n,m,k;
    cin>>n>>m>>k;
    vl a(n);
    vl b(m);
    vl c(k);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    for(auto &it:c)
    cin>>it;
    multiset<ll>diff;
    ll maxm=-1,prev=-1;
    vi ind;
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    for(int i=1;i<n;i++)
    {
        if(maxm<(a[i]-a[i-1]))
        {
            prev=max(prev,maxm);
            maxm=max(maxm,a[i]-a[i-1]);
            ind.clear();
            ind.push_back(i);
        }
        else if(maxm==(a[i]-a[i-1]))
        {
            prev=maxm;
            ind.push_back(i);
        }
        else if(prev<(a[i]-a[i-1]))
        {
            prev=(a[i]-a[i-1]);
        }
        diff.insert(a[i]-a[i-1]);
    }
    if(ind.size()>1)
    {
        cout<<maxm<<'\n';
        return;
    }
    int in=ind.back();
    int mid=(a[in]+a[in-1])/2;
    int curr=a[in-1];
    ll ans=a[in]-a[in-1];
    for(int i=0;i<m;i++)
    {
        int l=0,r=k-1;
        while(r-l>1)
        {
            int m=(r-l)/2+l;
            if(b[i]+c[m]<=mid)
            l=m;
            else
            r=m; 
        }
        ans=min(ans,max({prev,abs(a[in]-(b[i]+c[l])),abs(a[in-1]-(b[i]+c[l]))}));
        ans=min(ans,max({prev,abs(a[in]-(b[i]+c[r])),abs(a[in-1]-(b[i]+c[r]))}));
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