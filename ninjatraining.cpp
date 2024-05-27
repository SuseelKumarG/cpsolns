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
#define MAX 1000000007

int soln(int pos,int ind,vvi &track,vvi &dp)
{
    if(pos<0)
    return 0;
    int maxm=INT_MIN,j;
    if(dp[pos][ind]!=-1)
    return dp[pos][ind];
    for(int i=0;i<3;i++)
    {
        if(i!=ind)
        {
            if(track[pos][i]>maxm)
            {
                j=i;
                maxm=track[pos][i];
            }
        }
    }
    dp[pos][ind]=track[pos][j] + soln(pos-1,j,track,dp);
    return dp[pos][ind];
}

void solve()
{
    int n;
    cin>>n;
    vvi track(n);
    vvi dp(n);
    for(int i=0;i<n;i++)
    {
        vi temp(3,-1);
        dp[i]=temp;
        for(int i=0;i<3;i++)
        cin>>temp[i];
        track[i]=temp;
    }
    int a=INT_MIN;
    for(int i=0;i<3;i++)
    {
        int temp=track[n-1][i]+soln(n-2,i,track,dp);
        a=max(a,temp);
    }
    cout<<a<<'\n';
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