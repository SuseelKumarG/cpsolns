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

int rec(vi &a,vvi &dp,int x,int n)
{
    if(n==0)
    return 1;
    if(x==dp.size())
    return 0;
    if(dp[x][n]!=-1)
    return dp[x][n];
    int ways=0;
    for(int i=0;i<=n;i+=a[x])
    {
        ways+=rec(a,dp,x+1,n-i);   
    }
    dp[x][n]=ways;
    return dp[x][n];
}

void solve()
{
    int x;
    cin>>x;
    vi a(x);
    for(int i=0;i<x;i++)
    cin>>a[i];
    sort(a.begin(),a.end());
    int n;
    cin>>n;
    vvi dp(x+5,vi(n+1,-1));
    cout<<rec(a,dp,0,n)<<'\n';
    // cout<<1<<'\n';
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