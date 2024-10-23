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

bool poss(vii &a,int k)
{
    int n=a.size();
    int x=0;
    for(int i=0;i<n;i++)
    {
        if(a[i].first>=k-x-1&&a[i].second>=x)
        x++;
    }
    if(x>=k)
    return 1;
    return 0;
}

void solve()
{
    int n;
    cin>>n;
    vii a(n);
    for(auto &it:a)
    cin>>it.first>>it.second;
    int l=0,r=n+1,m;
    while(r-l>1)
    {
        m=(r-l)/2+l;
        if(poss(a,m))
        l=m;
        else
        r=m;
    }
    if(poss(a,r))
    cout<<r<<'\n';
    else
    cout<<l<<'\n';
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