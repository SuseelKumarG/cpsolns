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

bool poss(ll l,ll r,vll &a,ll k){
    for(auto it:a)
    {
        l-=k;
        r+=k;
        if(it.first>r||it.second<l)
        return 0;
        l=max(l,it.first);
        r=min(r,it.second);
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    vll a(n);
    ll maxm=0;
    for(auto &it:a)
    {
        cin>>it.first>>it.second;
        maxm=max(it.second,maxm);
    }
    ll l=0,r=MAX;
    ll mid;
    while(r-l>1)
    {
        mid=(r-l)/2+l;
        if(poss(0,0,a,mid))
        r=mid;
        else
        l=mid;
    }
    if(poss(0,0,a,l))
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