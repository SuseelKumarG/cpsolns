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
    int n;
    cin>>n;
    map<int,int>hsh;
    int ok=-1;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        hsh[x]++;
        if(hsh[x]>1)
        ok=x;
    }
    int cnt=0;
    if(ok==-1)
    {
        cout<<-1<<'\n';
        return;
    }
    hsh[ok]-=2;
    vi x;
    for(auto it:hsh)
    if(it.second)
    {
        while(it.second--)
        x.push_back(it.first);
    }
    int minm=INT_MAX;
    pii ans;
    for(int i=0;i<x.size()-1;i++)
    {
        if(minm>x[i+1]-x[i])
        {
            minm=x[i+1]-x[i];
            ans={x[i+1],x[i]};
        }
    }
    if(minm>=2*ok)
    {
        cout<<-1<<'\n';
        return;
    }
    cout<<ok<<' '<<ok<<' ';
    cout<<ans.first<<' '<<ans.second<<' ';
    // for(auto it:hsh)
    // {
    //     // if(it.first==ok)
    //     // continue;
    //     if(cnt>2)
    //     break;
    //     while(it.second--&&cnt<2)
    //     {
    //         cnt++;
    //         cout<<it.first<<' ';
    //     }
    // }
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