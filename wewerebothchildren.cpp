#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef pair<ll, ll> pll;
typedef map<ll, ll> mll;
typedef unordered_map<ll, ll> umll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
#define MAX 1000000007
#define eps 0.000000001

void solve()
{
    int n;
    cin>>n;
    vi arr(n+1),cnt(n+1);
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        if(x<=n)
        arr[x]++;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j+=i)
            cnt[j]+=arr[i];
    }
    int max=INT_MIN;
    for(int i=0;i<=n;i++)
    {
        if(max<cnt[i])
        max=cnt[i];
    }
    cout<<max<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    while(t--)
    solve();
    return 0;
}