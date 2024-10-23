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

int chk(ll mid,bool curr,vl &a)
{
    int ans=0;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        if(curr)
        {
            ans++;
            curr=!curr;
        }
        else
        {
            if(a[i]<=mid)
            {
                ans++;
                curr=!curr;
            }
        }
    }
    return ans;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    ll l=0,r=1000000000;
    while(r-l>1)
    {
        ll mid=(r+l)/2;
        if((chk(mid,0,a)>=k)||(chk(mid,1,a)>=k))
        r=mid;
        else
        l=mid;
    }
    if((chk(l,0,a)>=k)||(chk(l,1,a)>=k))
    cout<<l<<'\n';
    else
    cout<<r<<'\n';
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