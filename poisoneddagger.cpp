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
    int n;
    ll h;
    cin>>n>>h;
    vector<ll>atk(n);
    for(int i=0;i<n;i++)
    cin>>atk[i];
    ll l=1,r=h;
    while (l <= r) {
      ll m = (l + r) / 2;
      ll sum = m;
      for (int i = 0; i < n - 1; ++i) 
        sum += min(m, atk[i + 1] - atk[i]);
      if (sum < h) l = m + 1;
      else r = m - 1;
    }
    cout << r + 1 << '\n';
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}