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

bool poss(vi &a,int ok,set<int>&used,int ind)
{
    int n=a.size();
    int maxm=0;
    for(int i=1;i<n-1;i++)
    {
        if(used.count(i))
        continue;
        int temp=min(abs(i-*used.upper_bound(i)),abs(i-*(--used.lower_bound(i))));
        maxm=max(maxm,temp);
    }
    int curr=min(abs(ind-*used.upper_bound(ind)),abs(ind-*(--used.lower_bound(ind))));
    return curr==maxm;
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    if(n<3)
    {
        cout<<"YES\n";
        return;
    }
    if(a[0]!=1&&a[n-1]!=1)
    {
        cout<<"NO\n";
        return;
    }
    if(a[0]!=2&&a[n-1]!=2)
    {
        cout<<"NO\n";
        return;
    }
    map<int,int>ind;
    for(int i=0;i<n;i++)
    ind[a[i]]=i;
    set<int>used={0,n-1};
    for(int i=3;i<=min(n,(int)log2(n)+5);i++)
    {
        if(!poss(a,i,used,ind[i]))
        {
            cout<<"NO\n";
            return;
        }
        used.insert(ind[i]);
    }
    cout<<"YES\n";
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