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
    string s;
    cin>>s;
    int n=s.length();
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1] &&s[i-1]!='1')
        {
            s[i]='1';
            ans++;
        }
        if(i>=2)
        {
            if(s[i]==s[i-2] && s[i-2]!='1')
            {
                s[i]='1';
                ans++;
            }
        }
    }
    cout<<ans<<'\n';
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