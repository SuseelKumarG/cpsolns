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

void solve()
{
    int n;
    cin>>n;
    string inp,exp;
    cin>>inp>>exp;
    int ans=0;
    for(int i=0;i<n;)
    {
        if(inp[i]!=exp[i])
        {
            if(inp[i]!=inp[i+1] && i<n-1 && inp[i+1]!=exp[i+1])
            {
                ans++;
                i+=2;
            }
            else
            {
                ans++;
                i++;
            }
        }
        else
        i++;
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // ll t=1;
    // cin>>t;
    // while(t--)
    // {
        solve();
    // }
    return 0;
}