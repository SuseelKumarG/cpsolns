#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pi pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep(i, a, b) for (ll i = (a); i < (b); ++i)
#define rrep(i, a, b) for (ll i = (a); i >= (b); --i)
#define yes cout << "YES\n";
#define no cout << "NO\n";

#define loop(v) for (ll i = 0; i < sz(v); ++i) {}

const ll mod = 1e9 + 7;
const ll INF = 1e18;

#define lb lower_bound
#define ub upper_bound
#define debug(x) cerr << #x << " = " << x << endl

ll binExp(ll base, ll exp, ll mod) {
    ll res = 1;
    while (exp) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

template<typename T>
void readVector(vector<T>& v) {
    for (auto& i : v) cin >> i;
}

template<typename T>
void printVector(const vector<T>& v) {
    for (auto& i : v) cout << i << " ";
    cout << endl;
}

// -> read the question again carefully
// -> reset and think simple
// -> DONT ASSUME and try to DISPROVE EVERYTHING!!
// -> maybe there is some observation around which the whole question bends?
// -> rule out approaches and move forward !!!
// -> maybe brute force can work?
// -> think backwards?
// -> most q involve just one clever insight what is it?
const int N=1e6+1;
vi Count(N,0);
vi ans(N,0);
void create(){

    for(int i=2; i<=N; i++){
        for(int j=i; j<=N; j+=i){
            if(Count[j]&1){//count is odd but actually even if we consider 1 as well so this give is actually odd and odd must be added
                ans[j]+=i;


            }
            else {
                ans[j]-=i;
            }
            Count[j]++;
        }
    }
}
void solve() {
    int n;
    cin >> n;
    cout << ans[n]+1 << endl;;
}

signed main() {
    fastio;
    create();
    int tc=1;
    cin >> tc;
    while(tc--)
    solve();
}