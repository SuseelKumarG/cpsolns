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

vi d(1010,INT_MAX);

void solve()
{
    int n,k;
    cin>>n>>k;
    vi a(n,1);
    vi b(n),c(n);
    for(auto &it:b)
    cin>>it;
    for(auto &it:c)
    cin>>it;
    for(int i=0;i<n;i++)
    b[i]=d[b[i]];
    k=min(k,12*n);
    vi dp(k+10);
    for(int i=0;i<n;i++)
    {
        for(int j=k;j>=b[i];j--)
        dp[j]=max(dp[j],dp[j-b[i]]+c[i]);
    }    
    cout<<dp[k]<<'\n';
}

int main()
{
    d[0]=0;
    d[1]=0;
    for(int i=1;i<=1000;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int x=i+i/j;
            if(x<1001)
            d[x]=min(d[x],d[i]+1);
        }
    }
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