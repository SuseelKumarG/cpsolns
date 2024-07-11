//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<bool> vb;
typedef vector<string> vs;
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
int dp[5010][5010];
int chk(int i,int n,vi &a,int step)
{
    if(i==n)
    return 0;
    if(dp[i][step]!=-1)
    return dp[i][step];
    int ans=chk(i+1,n,a,step+1);
    if(a[i]<=step)
    ans=max(chk(i+1,n,a,step-a[i])+1,ans);
    return dp[i][step]=ans;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    vi unique;
    map<int,int>cnt;
    for(int i=0;i<n;i++)
        cin>>a[i],
        cnt[a[i]]++;
    for(auto it:cnt)
    unique.push_back(it.second);
    n=unique.size();
    for(int i=0;i<n+5;i++)
    for(int j=0;j<n+5;j++)
    dp[i][j]=-1;
    cout<<n-chk(0,n,unique,0)<<'\n';
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