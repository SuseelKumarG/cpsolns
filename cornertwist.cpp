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

int ans=1;

int rec(vi &a,int ind,vi &dp)
{
    if(dp[ind]!=-1)
    return dp[ind];
    int temp=0;
    for(int i=ind-1;i>=0;i--)
    {
        if(a[i]<a[ind])
        {
            temp=max(temp,rec(a,i,dp));
        }
    }
    dp[ind]=temp+1;
    return dp[ind];
}

void solve()
{
    bool poss=1;
    int n,m;
    cin>>n>>m;
    vs a(n);
    vs b(n);
    vvi act(n,vi(m));
    set<int>ax,bx;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(b[i][j]!=a[i][j])
            {
                if(b[i][j]<a[i][j])
                b[i][j]+=3;
                act[i][j]=b[i][j]-a[i][j];
            }
        }
    }
    for(int i=0;i<n&&poss;i++)
    {
        int sum=0;
        for(int j=0;j<m&&poss;j++)
        sum+=act[i][j];
        if(sum%3)
        poss=0;
    }
    for(int i=0;i<m&&poss;i++)
    {
        int sum=0;
        for(int j=0;j<n&&poss;j++)
        sum+=act[j][i];
        if(sum%3)
        poss=0;
    }
    cout<<(poss?"YES":"NO")<<'\n';
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