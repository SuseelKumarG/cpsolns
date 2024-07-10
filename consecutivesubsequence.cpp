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

int rec(vi &a,int ind,vi &dp)
{
    if(dp[ind]!=-1)
    return dp[ind];
    int temp=0;
    for(int i=ind-1;i>=0;i--)
    {
        if(a[i]==a[ind]-1)
        {
            temp=max(temp,rec(a,i,dp));
        }
    }
    return dp[ind]=temp+1;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    map<int,int>ext,dp;
    for(int i=0;i<n;i++) ext[a[i]]=i;
    
    // for(int i=n-1;i>-1;i--)
    // rec(a,i,dp);
    vi tt;
    int ans=0;
    int ind=0;
    for(int i=0;i<n;i++)
    {
        dp[a[i]]=dp[a[i]-1]+1;
        if(dp[a[i]]>ans)   
        {
            ans=dp[a[i]];
            ind=a[i];
        }
    }
    cout<<ans<<'\n';
    for(int i=n-1;i>-1;i--)
    {
        if(a[i]==ind)
        {
            tt.push_back(i);
            ind--;
        }
    }
	reverse(tt.begin(), tt.end());
    for(auto it:tt)
    cout<<it+1<<' ';
    cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        // cout<<t<<"YO\n";
        solve();
    }
    return 0;
}