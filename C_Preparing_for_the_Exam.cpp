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
    vi a(m);
    for(auto &it:a)
    cin>>it;
    set<int>s;
    // for(int i=1;i<=n;i++)
    // s.insert(i);
    for(int i=0;i<k;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    if(k<n-1)
    {
        for(int i=0;i<m;i++)
        cout<<0;
        cout<<'\n';
        return;
    }
    if(k==n)
    {
        for(int i=0;i<m;i++)
        cout<<1;
        cout<<'\n';
        return;
    }
    for(auto it:a)
    {
        if(s.count(it))
        cout<<0;
        else
        cout<<1;
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