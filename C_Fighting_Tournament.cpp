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
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(auto&it:a)
    cin>>it;
    int x=a[0];
    map<int,vi>ans;
    for(int i=1;i<2*n;i++)
    {
        if(x>a[i])
        {
            ans[x].push_back(i);
            a.push_back(a[i]);
        }
        else
        {
            a.push_back(x);
            x=a[i];
            ans[x].push_back(i);
        }
    }
    int maxm=*max_element(a.begin(),a.end());
    while(q--)
    {
        int i,k;
        cin>>i>>k;
        i--;
        if(a[i]!=maxm)
        {
            cout<<upper_bound(ans[a[i]].begin(),ans[a[i]].end(),k)-ans[a[i]].begin()<<'\n';
            continue;
        }
        if(k<i)
        {
            cout<<0<<'\n';
            continue;
        }
        if(a[0]!=maxm)
        cout<<k-i+1<<'\n';
        else
        cout<<k-i<<'\n';
    }
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