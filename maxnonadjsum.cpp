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
// const  long long N=2*100010;
// vector<int>factrl(N);

int ans(int i,vector<int> &arr,vector<int> &dp){
    if(i<=0)
    return 0;
    int take,notake;
    take=arr[i]+ans(i-2,arr,dp);
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n),dp(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t;
    // cin>>t;
    // while(t--)
    {
        solve();
    }
    return 0;
}