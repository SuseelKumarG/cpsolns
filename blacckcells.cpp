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

bool poss(ll k,vl&a)
{
    int cnt=0;
    int n=a.size();
    if(n==1)
    return 1;
    // // if(n==2)
    // // {
    // //     if(a[1]-a[0]>k)
    // //     return 0;
    // //     else return 1;
    // // }
    // for(int i=1;i<n-1;i++)
    // {
    //     if((a[i]-a[i-1])>k&&(a[i+1]-a[i])>k)
    //     cnt++;
    // }
    // if(a[1]-a[0]>k)
    // cnt++;
    // if(a[n-1]-a[n-2]>k)
    // cnt++;
    // if(cnt>1)
    // return 0;
    // else
    // return 1;
    int x=0,y=0;
    int i=0;
    for(;i<n-1;)
    {
        if(a[i+1]-a[i]>k)
        {
            x++;
            i++;
        }
        else
        i+=2;
    }
    if(i==n-1)
    x++;
    i=n-1;
    for(;i>0;)
    {
        if(a[i]-a[i-1]>k)
        {
            y++;
            i--;
        }
        else
        i-=2;
    }
    if(i==0)
    y++;
    if(min(x,y)>1)
    return 0;
    else
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    ll lo=1,hi=1000000000000000000;
    // cout<<hi<<'\n';
    while(hi-lo>1)
    {
        ll m=(hi+lo)/2;
        if(poss(m,a))
        hi=m;
        else
        lo=m;
    }
    if(poss(lo,a))
    cout<<lo<<'\n';
    else
    cout<<hi<<'\n';
    // cout<<poss(2,a)<<'\n';
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