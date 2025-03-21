#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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
    string a;
    string b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    a='.'+a;
    b='*'+b;
    vvi dp(n+1,vi(m+1));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]+=(a[i]==b[j]?dp[i-1][j-1]+1:0);
            dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
        }
    }
    string s;
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            s.push_back(a[i]);
            i--;
            j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1])
        i--;
        else
        j--;
    }
    reverse(s.begin(),s.end());
    cout<<s<<'\n';
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