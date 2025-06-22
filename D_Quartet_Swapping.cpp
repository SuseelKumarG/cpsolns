#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

int minSwaps(vector<int> &arr) {
    
    // Temporary array to store elements in sorted order
    vector<int> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());
    
  	// Hashing elements with their correct positions
  	unordered_map<int, int> pos; 
    for(int i = 0; i < arr.size(); i++)
        pos[arr[i]] = i;
    
  	int swaps = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(temp[i] != arr[i]) {
            
            // Index of the element that should be at index i.
            int ind = pos[temp[i]];
            swap(arr[i], arr[ind]);
            
            // Update the indices in the hashmap
            pos[arr[i]] = i; 
            pos[arr[ind]] = ind;
            
            swaps++; 
        }
    }
    return swaps; 
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(ll&i:a)
    cin>>i;
    vi o,e;
    for(int i=0;i<n;i++)
    {
        if(i&1)
        e.push_back(a[i]);
        else
        o.push_back(a[i]);
    }
    int x=minSwaps(o);
    int y=minSwaps(e);
    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    if((x&1)==(y&1))
    {
        int l=0,m=0;
        for(int i=0;i<n;i++)
        {
            if(i&1)
            cout<<e[l++]<<' ';
            else
            cout<<o[m++]<<' ';
        }
        cout<<'\n';
    }
    else
    {
        if(n&1)
        {
            vi temp=o;
            swap(temp[o.size()-1],temp[o.size()-2]);
            int l=0,m=0;
            for(int i=0;i<n;i++)
            {
                if(i&1)
                {
                    cout<<e[l++]<<' ';
                }
                else
                {
                    cout<<temp[m++]<<' ';
                }
            }
            cout<<'\n';
            return;
        }
        int l=0,m=0;
        swap(e[e.size()-1],e[e.size()-2]);
        for(int i=0;i<n;i++)
        {
            if(i&1)
            cout<<e[l++]<<' ';
            else
            cout<<o[m++]<<' ';
        }
        cout<<'\n';
    }
}

int32_t main()
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