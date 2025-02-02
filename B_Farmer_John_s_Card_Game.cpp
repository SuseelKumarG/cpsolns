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
    int n,m;
    cin>>n>>m;
    vvi a(n,vi(m));
    for(int i=0;i<n;i++)
    {
        for(auto &it:a[i])
        cin>>it;
    }
    for(auto &it:a)
    sort(it.begin(),it.end());
    map<int,int>pos;
    for(int i=0;i<n;i++)
    pos[a[i][0]]=i;
    sort(a.begin(),a.end());
    bool poss=1;
    for(int i=0;i<n;i++)
    {
        if(a[i][0]!=i)
        poss=0;
        int curr=i;
        for(int j=1;j<m;j++)
        {
            curr+=n;
            if(curr!=a[i][j])
            poss=0;
        }
    }
    if(poss)
    for(auto it:a)
    {
        cout<<pos[it.front()]+1<<' ';
    }
    else
    cout<<-1;
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