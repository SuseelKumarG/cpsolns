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

ll chk(vi &a,int i,int mid)
{
    ll curr=0;
    for(;i<a.size();i++)
    {
        if(a[i]>=mid)
        break;
        curr+=mid-a[i];
        mid--;
    }
    return curr;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    vi b(n);
    b[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        b[i]=max(b[i+1],a[i+1])+1;
    }
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<b[i])
        {
            int l=a[i],r=b[i];
            while(r-l>1)
            {
                int mid=(r-l)/2+l;
                ll curr=chk(a,i,mid);
                if(curr<=k)
                l=(r-l)/2+l;
                else
                r=(r-l)/2+l;
            }
            ll curr=chk(a,i,r);
            if(curr<=k)
            ans=max(ans,r+0ll);
            else
            ans=max(ans,l+0LL);
        }
        else
        ans=max(ans,a[i]+0ll);
    }
    cout<<ans<<'\n';
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