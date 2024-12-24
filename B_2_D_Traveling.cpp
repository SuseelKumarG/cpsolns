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
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    a--;
    b--;
    vll city(n);
    for(auto &it:city)
    cin>>it.first>>it.second;
    ll go1=LLONG_MAX/2,go2=LLONG_MAX/2;
    for(int i=0;i<k;i++)
    {
        go1=min(go1,abs(city[a].first-city[i].first)+abs(city[a].second-city[i].second));
        go2=min(go2,abs(city[b].first-city[i].first)+abs(city[b].second-city[i].second));
    }
    // if(go1>abs(city[a].first-city[b].first)+abs(city[a].second-city[b].second))
    // {
    //     go1=min(go1,abs(city[a].first-city[b].first)+abs(city[a].second-city[b].second));
    //     go2=0;
    // }
    // // cout<<go1<<' '<<go2<<'\n';
    // cout<<go1+go2<<'\n';
    cout<<min(go1+go2,abs(city[a].first-city[b].first)+abs(city[a].second-city[b].second))<<'\n';
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