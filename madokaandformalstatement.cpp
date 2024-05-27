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
    vi arr(n),brr(n);
    for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
    cin>>brr[i];
    bool poss=1,done=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>brr[i])
        poss=0;
        if(arr[i]!=brr[i])
        done=0;
    }
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]!=brr[i] && brr[i]>brr[i+1]+1)
        poss=0;
    }
    if(arr[n-1]!=brr[n-1] && -brr[0]+brr[n-1]>1)
    poss=0;
    cout<<((poss || done)?"YES":"NO")<<'\n';
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