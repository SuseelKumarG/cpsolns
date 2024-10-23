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

vvi dp(502,vi(502,MAX));

void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<dp[a][b]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    for(int i=1;i<502;i++)
    {
        dp[i][1]=i-1;
        dp[i][i]=i-1;
        dp[i][i]=0;
    }
    for(int i=1;i<502;i++)
    {
        for(int j=1;j<502;j++)
        {
            if(i==j)
            continue;
            for(int k=1;k<j;k++)
            dp[i][j]=min({dp[i][j],dp[i][j-k]+dp[i][k]+1});
            for(int k=1;k<i;k++)
            dp[i][j]=min({dp[i][j],dp[i-k][j]+dp[k][j]+1});
        }
    }
    while(t--)
    {
        solve();
    }
    return 0;
}