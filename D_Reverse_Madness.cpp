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
// #define N 10010

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
void updateRange(vector<int>& count, int i, int j)
{
    count[i]++;
 
    // Check index out of bound
    if (j + 1 < count.size())
        count[j + 1]--;
}
 
// Prefix sum to finalise count value
// at each index
void finaliseCountArray(vector<int>& count)
{
    for (int i = 0; i < count.size(); i++)
        count[i] += count[i - 1];
}
 
// Function for reversing string according
// to each query
string reverseForAll(string S, int N, vector<int>& A, int M,vi &l,vi &r)
{
    vector<int> count(N, 0);
 
    // Traversal of query array
    for (int i = 0; i < M; i++) {
        int ind=(int)(upper_bound(r.begin(),r.end(),A[i])-r.begin())-1;

        int start = min(A[i],l[ind]+r[ind]-A[i]);
        int end = max(A[i],l[ind]+r[ind]-A[i]);
        // int end = A[i] <= (N + 1) / 2 ? N - A[i] : A[i] - 1;
 
        // Increment the value of all indices
        // between both indices
        updateRange(count, start, end);
    }
 
    // Finalising count array using prefix sum
    finaliseCountArray(count);
 
    // Storing the characters at indices with
    // odd no. of reversal queries in reverse
    // manner, this stores the required indices
    // to string temp as well as temp is
    // reversed at the same time
    string temp;
    for (int i = count.size() - 1; i >= 0; i--) {
        if (count[i] % 2 != 0)
            temp.push_back(S[i]);
    }
 
    // Storing the new characters in
    // original string
    int i = 0, j = 0;
    for (i = 0; i < count.size(); i++) {
 
        // For characters with odd reversal
        // queries character is taken from
        // string temp
        if (count[i] % 2 != 0)
            S[i] = temp[j++];
 
        // If count is even then there is no
        // need to update characters as those
        // characters do not take part
        // in reversal
    }
 
    // Return final string
    return S;
}
void solve()
{
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vi l(n),r(n);
    for(auto&it:l)
    {
        cin>>it;
        it--;
    }
    for(auto&it:r)
    {
        cin>>it;
        it--;
    }
    int q;
    cin>>q;
    vi cnt(n+1);
    for(auto &it:cnt)
    {
        int x;
        cin>>x;
        cnt[x-1]++;
    }
    cout<<reverseForAll(s,n,rev,q,l,r)<<'\n';
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