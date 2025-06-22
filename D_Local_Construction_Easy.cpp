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

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto&ti:a)
    cin>>ti;
    vi ans(n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==-1)
        ans[i]=1;
    }
    vi add;
    for(int i=2;i<=n;i++)
    add.push_back(i);
    for(int curr=1;;curr++)
    {
        bool found=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==curr)
            {
                found=1;
                ans[i]=add.back();
                add.pop_back();
            }
        }
        if(!found)
        break;
    }
    bool o=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]>1)
        o=0;
    }
    if(o)
    {
        int ind=n-1;
        for(int i=0;i<n;i++)
        {
            if(a[i]==-1)
            ind=i;
        }
        reverse(ans.begin()+ind+1,ans.end());
    }
    for(auto it:ans)
    cout<<it<<' ';
    cout<<'\n';
}

int32_t main()
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