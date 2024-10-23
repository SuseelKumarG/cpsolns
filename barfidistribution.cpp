#include <bits/stdc++.h>
using namespace std;
 
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

bool poss(ll mid,vi &a,int k)
{
    int i=0;
    int n=a.size();
    ll curr=0;
    while(k&&i<n)
    {
        while(curr<mid&&i<n)
        curr+=a[i++];
        if(curr>=mid)
        {
            curr=0;
            k--;
        }
        else
        break;
    }
    if(k)
    return 0;
    return 1;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    ll sum=accumulate(a.begin(),a.end(),0);
    // cout<<sum<<'\n';
    ll l=0,r=sum;
    while(r-l>1)
    {
        ll mid=(r+l)/2;
        if(poss(mid,a,k))
        {
            l=mid;
            // cout<<mid<<' '<<'r'<<'\n';
        }
        else
        {
            r=mid;
            // cout<<mid<<' '<<'r'<<'\n';
        }
    }
    if(poss(r,a,k))
    cout<<r<<'\n';
    else
    cout<<l<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}