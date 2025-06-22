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
    int n,k;
    cin>>n>>k;
    map<int,int>hsh;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
    }
    vvi val(64);
    map<int,set<int>>setb;
    for(int i=0;i<64;i++)
    {
        for(int j=0;j<64;j++)
        {
            int cnt=0;
            bool poss=1;
            for(int x=0;x<7;x++)
            {
                if((i>>x)&1)
                {
                    cnt++;
                    if(((j>>x)&1)==0)
                    poss=0;
                }
            }
            setb[cnt].insert(i);
            if(poss)
            val[i].push_back(j);
        }
    }
    ll ans=0;
    for(int x:setb[k])
    {
        ll rem=0;
        ll cnt=0;
        for(auto it:val[x])
        {
            if(it!=x)
            {
                rem+=binexp(2,hsh[it]);
                rem--;
            }
            rem%=MAX;
        }
    }
    cout<<ans<<'\n';
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