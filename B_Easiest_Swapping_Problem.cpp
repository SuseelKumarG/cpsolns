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
 
    // We re-index rows: row 0 (our DP) is the bottom row,
    // row n-1 is the top row. (Input row 0 is the top.)
    // For each DP row i, let S[i] be the sorted list of columns (0-indexed) where there is a hold.
    vector<vector<int>> S(n);
    for (int i = 0; i < n; i++){
        int orig = n - 1 - i;  // original row index
        for (int j = 0; j < m; j++){
            if(grid[orig][j] == '#')
                S[i].push_back(j);
        }
        sort(S[i].begin(), S[i].end());
        if(S[i].empty()){
            cout << 0 << "\n";
            return 0;
        }
    }
 
    // dp[i] will be a vector corresponding to S[i]: 
    // dp[i][k] = number of ways to form a valid route from row 0 (bottom) up to row i
    // ending with connection column S[i][k] on row i.
    vector<vector<ll>> dp(n);
    for (int i = 0; i < n; i++){
        dp[i].assign(S[i].size(), 0);
    }
 
    // Base: bottom row. For every hold in row 0, one way to start.
    for (int k = 0; k < S[0].size(); k++){
        dp[0][k] = 1;
    }
 
    // H: allowed horizontal difference when moving from one row to the next.
    int H = 0;
    if(d * d > 1)
        H = (int)floor(sqrt(d * d - 1));
 
    // Process each row from 1 to n-1 (bottom-up)
    for (int i = 1; i < n; i++){
        // Precompute prefix sums for dp[i-1] over S[i-1] for fast range queries.
        int sizePrev = S[i-1].size();
        vector<ll> pref(sizePrev + 1, 0);
        for (int j = 0; j < sizePrev; j++){
            pref[j+1] = pref[j] + dp[i-1][j];
        }
 
        // For each candidate "first" hold f in the current row S[i]
        for (int idx = 0; idx < S[i].size(); idx++){
            int f = S[i][idx];  // candidate first hold in row i
            // Compute G = sum_{x in S[i-1] with |x - f| <= H} dp[i-1][x]
            int lo = int(lower_bound(S[i-1].begin(), S[i-1].end(), f - H) - S[i-1].begin());
            int hi = int(upper_bound(S[i-1].begin(), S[i-1].end(), f + H) - S[i-1].begin());
            ll G = pref[hi] - pref[lo];
 
            // For the pattern chosen in row i, the climber can pick any "last" hold L in S[i]
            // satisfying |f - L| <= d.
            int Llo = int(lower_bound(S[i].begin(), S[i].end(), f - d) - S[i].begin());
            int Lhi = int(upper_bound(S[i].begin(), S[i].end(), f + d) - S[i].begin());
            for (int j = Llo; j < Lhi; j++){
                dp[i][j] += G;
            }
        }
    }
 
    // The final answer is the sum of all ways in the top row (row n-1).
    ll ans = 0;
    for (ll ways : dp[n-1])
        ans += ways;
    cout << ans << "\n";
    }
}
