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
int* st;
 
/*  A recursive function to get gcd of given
    range of array indexes. The following are parameters for
    this function.
 
    st    --> Pointer to segment tree
    si --> Index of current node in the segment tree.
   Initially 0 is passed as root is always at index 0 ss &
   se  --> Starting and ending indexes of the segment
                 represented by current node, i.e.,
   st[index] qs & qe  --> Starting and ending indexes of
   query range */
int findGcd(int ss, int se, int qs, int qe, int si)
{
    if (ss > qe || se < qs)
        return 0;
    if (qs <= ss && qe >= se)
        return st[si];
    int mid = ss + (se - ss) / 2;
    return __gcd(findGcd(ss, mid, qs, qe, si * 2 + 1),
                 findGcd(mid + 1, se, qs, qe, si * 2 + 2));
}
 
// Finding The gcd of given Range
int findRangeGcd(int ss, int se, int arr[], int n)
{
    if (ss < 0 || se > n - 1 || ss > se) {
        cout << "Invalid Arguments"
             << "\n";
        return -1;
    }
    return findGcd(0, n - 1, ss, se, 0);
}
 
// A recursive function that constructs Segment Tree for
// array[ss..se]. si is index of current node in segment
// tree st
int constructST(int arr[], int ss, int se, int si)
{
    if (ss == se) {
        st[si] = arr[ss];
        return st[si];
    }
    int mid = ss + (se - ss) / 2;
    st[si]
        = __gcd(constructST(arr, ss, mid, si * 2 + 1),
                constructST(arr, mid + 1, se, si * 2 + 2));
    return st[si];
}
 
/* Function to construct segment tree from given array.
   This function allocates memory for segment tree and
   calls constructSTUtil() to fill the allocated memory */
int* constructSegmentTree(int arr[], int n)
{
    int height = (int)(ceil(log2(n)));
    int size = 2 * (int)pow(2, height) - 1;
    st = new int[size];
    constructST(arr, 0, n - 1, 0);
    return st;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    ll a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int diff[n];
    diff[0]=0;
    for(int i=1;i<n;i++)
    diff[i]=abs(a[i]-a[i-1]);
    constructSegmentTree(diff,n);
    int l,r;
    // for(int i=0;i<n;i++)
    // cout<<a[i]<<' ';
    // cout<<'\n';
    while(q--)
    {
        cin>>l>>r;
        // l--;
        r--;
        cout<<findGcd(0, n - 1, l, r, 0)<<' ';
    }
    cout<<'\n';
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