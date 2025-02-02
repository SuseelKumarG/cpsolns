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
    int n,q;
    cin>>n>>q;
    vl a(n+2);
    for(int i=1;i<=n;i++)
    cin>>a[i];
    deque<ll> ans(n+2);
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        ans[l]+=1;
        ans[r+1]+=-1;
    }
    for(int i=1;i<n+2;i++)
    ans[i]+=ans[i-1];
    ans.pop_back();
    ans.pop_front();
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    a.pop_back();
    a.pop_back();
    reverse(a.begin(),a.end());
    sort(ans.begin(),ans.end());
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=ans[i]*1LL*a[i];
    }
    cout<<sum<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}