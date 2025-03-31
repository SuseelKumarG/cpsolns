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
    vi a(2*n);
    for(auto &it:a)
    {
        cin>>it;
        it--;
    }
    vector<set<int>>pos(n);
    for(int i=0;i<2*n;i++)
    {
        pos[a[i]].insert(i);
    }
    set<pii>ans;
    for(int i=1;i<2*n;i++)
    {
        if(a[i-1]==a[i])
        continue;
        if(i<(2*n-1))
        if(a[i]==a[i+1])
        continue;
        if(i>1)
        if(a[i-2]==a[i-1])
        continue;
        pos[a[i]].erase(i);
        if(pos[a[i]].empty())
        {
            continue;
        }
        int x=*pos[a[i]].begin();
        if((x)&&(a[x-1]==a[i-1]))
        {
            ans.insert({a[i-1],a[i]});
            ans.insert({a[i],a[i-1]});
        }
        if((x!=(2*n-1))&&(a[x+1]==a[i-1]))
        {
            ans.insert({a[i-1],a[i]});
            ans.insert({a[i],a[i-1]});
        }
    }
    cout<<ans.size()/2<<'\n';
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