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

bool poss(vl &a,vl &b,int n,int x)
{
    for(int i=0;i<n-x;i++)
    {
        if(a[i]>=b[i+x])
        {
            return 0;
        }
    }
    return 1;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vl a(n-1),b(n);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    a.push_back(1);
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=0,r=n;
    while(r-l>1)
    {
        int x=(r-l)/2+l;
        if(poss(a,b,n,x))
        r=x;
        else
        l=x;
    }
    if(poss(a,b,n,l))
    cout<<l<<'\n';
    else
    cout<<r<<'\n';
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