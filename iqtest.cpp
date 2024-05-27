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
#define eps 0.000000001

void solve()
{
    int n;
    cin>>n;
    vi arr(n);
    int oddi=-1;
    int eveni=-1;
    int odd=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]&1)
        {
            odd++;
            oddi=i+1;
        }
        else
        eveni=i+1;
    }
    if(odd>1)
    cout<<eveni<<'\n';
    else
    cout<<oddi<<'\n';
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    solve();
    return 0;
}