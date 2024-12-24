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

void solve()
{
    ll n,k;
    cin>>n>>k;
    map<ll,ll>chk;
    chk[0]=n;
    int x=n-1;
    ll curr=1;
    vl ok;
    k--;
    while(curr<=k)
    {
        ok.push_back(curr);
        chk[curr]=x--;
        curr*=2;
    }
    if(x<0)
    {
        cout<<-1<<'\n';
        return;
    }
    ok.push_back(curr);
    set<int>cnt;
    for(int i=1;i<=n;i++)
    cnt.insert(i);
    vi ans;
    while(k)
    {
        int x=(--upper_bound(ok.begin(),ok.end(),k))-ok.begin();
        k-=ok[x];
        ans.push_back(chk[ok[x]]);
        cnt.erase(chk[ok[x]]);
    }
    while(!cnt.empty())
    {
        ans.push_back(*(--(cnt.end())));
        cnt.erase(*(--(cnt.end())));
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
    cout<<it<<' ';
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