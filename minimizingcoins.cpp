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

void solve()
{
    int n,x;
    cin>>n>>x;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    sort(a.begin(),a.end());
    vi ans(x+1);
    for(int i=0;i<=x;i++)
    ans[i]=MAX;
    ans[0]=0;
    for(int i=a[0];i<=x;i++)
    {
        int x=MAX;
        for(auto it:a)
        if(i-it>=0)
        x=min(x,ans[i-it]);
        ans[i]=min(1+x,MAX);
    }
    ans[0]=1;
    cout<<((ans[x]==MAX)?-1:ans[x])<<'\n';
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