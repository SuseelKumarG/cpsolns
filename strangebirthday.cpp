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

void solve()
{
    int n,m;
    cin>>n>>m;
    vi j(n),k(m),arr(n);
    for(int i=0;i<n;i++)
        cin>>j[i];
    for(int i=0;i<m;i++)
        cin>>k[i];
    for(int i=0;i<n;i++)
        arr[i]=k[j[i]-1];
    sort(k.begin(),k.end());
    reverse(k.begin(),k.end());
    sort(arr.begin(),arr.end());
    ll ans=0;
    while(n--)
    {
        if(!(k.empty()))
        {
            if(k.back()>arr.back())
            {
                ans+=arr.back();
                arr.pop_back();
            }
            else
            {
                ans+=k.back();
                arr.pop_back();
                k.pop_back();
            }
        }
        else
        {
            ans+=arr.back();
            arr.pop_back();
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