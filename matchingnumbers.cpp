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
    bool poss;
    poss=n&1;
    cout<<(poss ? "YES":"NO")<<'\n';
    if(poss)
    {
        int j=2*n;
        for(int i=1;i<=n;i+=2)
        {
            cout<<i<<' '<<j<<'\n';
            j--;
        }
        for(int i=2;i<=n;i+=2)
        {
            cout<<i<<' '<<j<<'\n';
            j--;
        }
    }
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