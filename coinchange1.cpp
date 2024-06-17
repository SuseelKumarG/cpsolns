//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
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

int ans=1;

int rec(vi &a,int n,int x,vi &dp)
{
    if(dp[n]!=-1)
    return dp[n];
    ll temp=INT_MAX;
    for(int i=0;i<x;i++)
    {
        if(n-a[i]>=0)
        temp=min(temp+0LL,rec(a,n-a[i],x,dp)+1LL);
    }
    dp[n]=temp;
    return dp[n];
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    int x;
    cin>>x;
    vi dp(x+10,-1);
    dp[0]=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=x)
        dp[a[i]]=1;
    }
    ll ans=rec(a,x,n,dp);
    cout<<((ans<INT_MAX)? ans:-1)<<'\n';
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