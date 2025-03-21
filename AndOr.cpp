#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

long long gcdl(long long a, long long b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}  
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
    return a;
}
int gcd(int a, int b){
    while(a > 0 && b > 0){
        if(a > b){
            a %= b;
        }
        else{
            b %= a;
        }
    }
    return a + b;
}
int lcml(int a,int b)
{
    a=(a*b)/gcd(a,b);
    return a;
}


constexpr static int MAXSIZE = 1000;
constexpr static int INF = numeric_limits<int>::max();
 
// Segment Tree array
int64_t tree[MAXSIZE];
 
// Lazy Update array
int64_t lazy[MAXSIZE];
 
// This tuple will hold tree state
// the stacks
using QueryAdaptor = tuple<int64_t, int64_t, int64_t>;
 
// Build our segment tree
void build_tree(int64_t* arr, int64_t arr_size)
{
 
    // Stack will use to update
    // the tree value
    stack<QueryAdaptor> st;
 
    // Emplace the root of the tree
    st.emplace(1, 0, arr_size - 1);
 
    // Repeat until empty
    while (!st.empty()) {
 
        // Take the indexes at the
        // top of the stack
        int64_t currnode, curra, currb;
 
        // value at the top of the
        // stack
        tie(currnode, curra, currb) = st.top();
 
        // Pop the value from the
        // stack
        st.pop();
 
        // Flag with INF ranges are merged
        if (curra == INF && currb == INF) {
            tree[currnode] = tree[currnode * 2]
                             + tree[currnode * 2 + 1];
        }
 
        // Leaf node
        else if (curra == currb) {
            tree[currnode] = arr[curra];
        }
 
        else {
 
            // Insert flag node inverse
            // order of evaluation
            st.emplace(currnode, INF, INF);
            int64_t mid = (curra + currb) / 2;
 
            // Push children
            st.emplace(currnode * 2, curra, mid);
            st.emplace(currnode * 2 + 1, mid + 1, currb);
        }
    }
}
 
// A utility function that propagates
// updates lazily down the tree
inline void push_down(int64_t node, int64_t a, int64_t b)
{
    if (lazy[node] != 0) {
        tree[node] += lazy[node] * (b - a + 1);
 
        if (a != b) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
 
        lazy[node] = 0;
    }
}
 
// Iterative Range_Update function to
// add val to all elements in the
// range i-j (inclusive)
void update_tree(int64_t arr_size, int64_t i, int64_t j,
                 int64_t val)
{
 
    // Initialize the stack
    stack<QueryAdaptor> st;
 
    // Emplace the root of the tree
    st.emplace(1, 0, arr_size - 1);
 
    // Work until empty
    while (!st.empty()) {
 
        // Take the indexes at the
        // top of the stack
        int64_t currnode, curra, currb;
        tie(currnode, curra, currb) = st.top();
        st.pop();
 
        // Flag with INF ranges are merged
        if (curra == INF && currb == INF) {
            tree[currnode] = tree[currnode * 2]
                             + tree[currnode * 2 + 1];
        }
 
        // Traverse the previous updates
        // down the tree
        else {
            push_down(currnode, curra, currb);
 
            // No overlap condition
            if (curra > currb || curra > j || currb < i) {
                continue;
            }
 
            // Total overlap condition
            else if (curra >= i && currb <= j) {
 
                // Update lazy array
                tree[currnode] += val * (currb - curra + 1);
 
                if (curra != currb) {
                    lazy[currnode * 2] += val;
                    lazy[currnode * 2 + 1] += val;
                }
            }
 
            // Partial Overlap
            else {
 
                // Insert flag node inverse
                // order of evaluation
                st.emplace(currnode, INF, INF);
 
                int64_t mid = (curra + currb) / 2;
 
                // Push children
                st.emplace(currnode * 2, curra, mid);
                st.emplace(currnode * 2 + 1, mid + 1,
                           currb);
            }
        }
    }
}
 
// A function that find the sum of
// all elements in the range i-j
int64_t query(int64_t arr_size, int64_t i, int64_t j)
{
 
    // Initialize stack
    stack<QueryAdaptor> st;
 
    // Emplace root of the tree
    st.emplace(1, 0, arr_size - 1);
 
    int64_t result = 0;
 
    while (!st.empty()) {
 
        // Take the indexes at the
        // top of the stack
        int64_t currnode, curra, currb;
        tie(currnode, curra, currb) = st.top();
        st.pop();
 
        // Traverse the previous updates
        // down the tree
        push_down(currnode, curra, currb);
 
        // No overlap
        if (curra > currb || curra > j || currb < i) {
            continue;
        }
 
        // Total Overlap
        else if (curra >= i && currb <= j) {
            result += tree[currnode];
        }
 
        // Partial Overlap
        else {
            std::int64_t mid = (curra + currb) / 2;
 
            // Push children
            st.emplace(currnode * 2, curra, mid);
            st.emplace(currnode * 2 + 1, mid + 1, currb);
        }
    }
 
    return result;
}


void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    vl ans(n);
    ans[0]=1;
    if(n>1)
    ans[1]=1;
    for(int i=2;i<n;i++)
    {
        ans[i]=0;
        if(i&1)
        ans[i]=1;
    }
    set<int>ind;
    for(int i=n-1;i>=0;i--)
    {
        if(ans[i]&&a[i])
        ind.insert(i);
        else if(!ans[i])
        ind.insert(i);
        else
        break;
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        x--;
        if(ans[x]&&!a[x])
        {
            if(y==1)
            {
                if(*(--(ind.lower_bound(x)))+1==x)
                ind.insert(x);
            }
        }
        if(ans[x]&&a[x])
        {
            if(y==0)
            ind.erase(x);
        }
        a[x]=y;
        cout<<(ind.count(n-1)?1:0)<<'\n';
    }
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