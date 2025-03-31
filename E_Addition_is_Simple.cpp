#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, d;
    cin >> n >> m >> d;
    vector<string> grid(n);
    for (int i = 0; i < n; i++){
        cin >> grid[i];
    }
 
    // Re-index rows: let row 0 be the bottom row, row n-1 the top.
    // For each row i (0-indexed in our DP), S[i] holds the sorted list of column indices with a hold.
    vector<vector<int>> S(n);
    for (int i = 0; i < n; i++){
        int orig = n - 1 - i; // original row index (0-indexed)
        for (int j = 0; j < m; j++){
            if(grid[orig][j] == '1')
                S[i].push_back(j);
        }
        sort(S[i].begin(), S[i].end());
        if(S[i].empty()){
            cout << 0 << "\n";
            return 0;
        }
    }
 
    // dp[i] corresponds to S[i]: dp[i][j] = number of ways to route through row i ending at column S[i][j].
    vector<vector<ll>> dp(n);
    for (int i = 0; i < n; i++){
        dp[i].assign(S[i].size(), 0);
    }
 
    // Base: bottom row (row 0)
    for (int j = 0; j < S[0].size(); j++){
        dp[0][j] = 1;
    }
 
    // H is the allowed horizontal difference when moving up one row.
    int H = 0;
    if(d*d > 1)
        H = (int)floor(sqrt(d*d - 1));
 
    // Process rows 1 through n-1
    for (int i = 1; i < n; i++){
        int szPrev = S[i-1].size();
        // Build prefix sum over dp[i-1] for S[i-1]
        vector<ll> pref(szPrev+1, 0);
        for (int j = 0; j < szPrev; j++){
            pref[j+1] = pref[j] + dp[i-1][j];
        }
 
        int szCurr = S[i].size();
        // Phase 1: For each candidate "first" hold f in S[i], compute T(f)
        // T(f) = sum_{x in S[i-1] with |x - f| <= H} dp[i-1][x].
        vector<ll> T(szCurr, 0);
        for (int j = 0; j < szCurr; j++){
            int f = S[i][j];
            int lo = int(lower_bound(S[i-1].begin(), S[i-1].end(), f - H) - S[i-1].begin());
            int hi = int(upper_bound(S[i-1].begin(), S[i-1].end(), f + H) - S[i-1].begin());
            T[j] = pref[hi] - pref[lo];
        }
 
        // Phase 2: For each candidate "last" hold L in S[i], sum T(f) for all f in S[i] with |f - L| <= d.
        vector<ll> prefT(szCurr+1, 0);
        for (int j = 0; j < szCurr; j++){
            prefT[j+1] = prefT[j] + T[j];
        }
        // Reset dp[i] (it was already zeroed by assign)
        for (int j = 0; j < szCurr; j++){
            int L = S[i][j];
            int lo = int(lower_bound(S[i].begin(), S[i].end(), L - d) - S[i].begin());
            int hi = int(upper_bound(S[i].begin(), S[i].end(), L + d) - S[i].begin());
            dp[i][j] = prefT[hi] - prefT[lo];
        }
    }
 
    ll ans = 0;
    for (ll x : dp[n-1])
        ans += x;
    cout << ans << "\n";
    }
    return 0;
}
