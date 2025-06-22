#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
// Other typedefs
#define MAX 1000000007
#define N 10010

// Utility functions (gcd, lcm, binexp) are left intact.
long long gcdl(long long a, long long b) {
    while(a > 0 && b > 0) {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}  

ll lcml(ll a, ll b) {
    return (a * b) / gcdl(a, b);
}

int gcd(int a, int b) {
    while(a > 0 && b > 0) {
        if(a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

int lcml(int a, int b) {
    return (a * b) / gcd(a, b);
}

ll binexp(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if(b & 1)
            ans = (ans * a) % MAX;
        b >>= 1;
        a = (a * a) % MAX;
    }
    return ans;
}

// The function num() returns a number based on the coordinates (x,y)
// and the level n. (Think of it as an encoding of a 2D point.)
ll num(int x, int y, int n) {
    ll len = 1;
    len <<= n;  // len = 2^n

    if(n == 1) {
        // Base mapping for 2x2 grid:
        // (1,1) => 1, (1,2) => 4, (2,1) => 3, (2,2) => 2
        if(x > 1 && y > 1)
            return 2;
        else if(x > 1 && y < 2)
            return 3;
        else if(x < 2 && y > 1)
            return 4;
        else  // (x < 2 && y < 2) means (1,1)
            return 1;
    }
    
    len >>= 1;  // Now len = 2^(n-1)
    ll curr = len * len;
    ll quad = 0;
    int a, b;
    
    // Determine quadrant based on the coordinate.
    // Quadrant numbering is chosen to be:
    // 0: top-left, 3: top-right, 2: bottom-left, 1: bottom-right.
    if(x <= len && y <= len) {
        quad = 0;
        a = x;
        b = y;
    } else if(x <= len && y > len) {
        quad = 3;
        a = x;
        b = y - len;
    } else if(x > len && y <= len) {
        quad = 2;
        a = x - len;
        b = y;
    } else { // (x > len && y > len)
        quad = 1;
        a = x - len;
        b = y - len;
    }
    
    ll add = num(a, b, n - 1);
    ll res = curr * quad + add;
    return res;
}

// The function pos() is the inverse of num(), mapping a number x to (row, col)
// on the grid of order 2^n.
pll pos(int x, int n) {
    ll len = 1;
    len <<= 1;  // Initially, len = 2.
    
    if(n == 1) {
        if(x == 1)
            return {1, 1};
        else if(x == 2)
            return {2, 2};
        else if(x == 3)
            return {2, 1};
        else if(x == 4)
            return {1, 2};
    }
    
    len >>= 1; // len = 2^(n-1)
    ll curr = len * len;
    // Fix: Use (x-1)/curr to compute correct quadrant (0-indexed)
    int quad = (x - 1) / curr;
    pll temp = pos(x - (quad * curr), n - 1);
    
    // Adjust the coordinates based on the quadrant.
    // According to our mapping in num():
    // Quadrant 0 (top-left): no change.
    // Quadrant 3 (top-right): increase column by len.
    // Quadrant 2 (bottom-left): increase row by len.
    // Quadrant 1 (bottom-right): increase both row and column by len.
    if(quad == 1) {
        temp.first += len;
        temp.second += len;
    } else if(quad == 2) {
        temp.first += len;
    } else if(quad == 3) {
        temp.second += len;
    }
    return temp;
}

void solve() {
    int n;
    cin >> n;
    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        if(s[1] == '>') {
            int x, y;
            cin >> x >> y;
            cout << num(x, y, n);
        } else {
            int x;
            cin >> x;
            pll temp = pos(x, n);
            cout << temp.first << " " << temp.second;
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
