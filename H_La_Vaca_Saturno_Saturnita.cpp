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

vvi factors(100010);

int pop(int k,int x)
{
    int l=0,r=35;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(!(k%binexp(x,m)))
        l=m;
        else
        r=m;
    }
    return l;
}

void solve()
{
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int &i:a)
    cin>>i;
    map<int,vi>pos;
    for(int i=0;i<n;i++)
    {
        pos[a[i]].push_back(i);
    }
    while(q--)
    {
        int k,l,r;
        cin>>k>>l>>r;
        r--;
        l--;
        vi fact=factors[k];
        ll ans=0;
        while(1)
        {
            int curr=r+1;
            for(auto i:fact)
            {
                if(k%i)
                continue;
                auto it=lower_bound(pos[i].begin(),pos[i].end(),l);
                if(it!=pos[i].end())
                curr=min(curr,*it);
            }
            if(curr>r)
            {
                ans+=(r-l+1)*k;
                break;
            }
            ans+=((curr-l)*k);
            k*=binexp(binexp(a[curr],pop(k,a[curr])),MAX-2);
            k%=MAX;
            l=curr;
        }
        cout<<ans<<'\n';
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=1;i<factors.size();i++)
    {
        for(int j=i;j<factors.size();j+=i)
        factors[j].push_back(i);
    }
    ll t=1;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}