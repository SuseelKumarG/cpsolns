#include <bits/stdc++.h>
using namespace std;
 
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

pll A(set<pll>&leaf,ll x,ll y)
{
    ll a=x,b=y;
    // ll z=1;
    while(leaf.find({a,b})==leaf.end()&&a<=INT_MAX&&b<=INT_MAX&&a>=INT_MIN&&b>=INT_MIN)
    {
        a++;
        b++;
    }
    if(leaf.find({a,b})!=leaf.end())
    {
        leaf.erase({x,y});
        return {a,b};
    }
    return {x,y};
}

pll B(set<pll>&leaf,ll x,ll y)
{
    ll a=x,b=y;
    // ll z=1;
    while(leaf.find({a,b})==leaf.end()&&a<=INT_MAX&&b<=INT_MAX&&a>=INT_MIN&&b>=INT_MIN)
    {
        a++;
        b--;
    }
    if(leaf.find({a,b})!=leaf.end())
    {
        leaf.erase({x,y});
        return {a,b};
    }
    return {x,y};
}

pll C(set<pll>&leaf,ll x,ll y)
{
    ll a=x,b=y;
    // ll z=1;
    while(leaf.find({a,b})==leaf.end()&&a<=INT_MAX&&b<=INT_MAX&&a>=INT_MIN&&b>=INT_MIN)
    {
        a--;
        b++;
    }
    if(leaf.find({a,b})!=leaf.end())
    {
        leaf.erase({x,y});
        return {a,b};
    }
    return {x,y};
}

pll D(set<pll>&leaf,ll x,ll y)
{
    ll a=x,b=y;
    // ll z=1;
    while(leaf.find({a,b})==leaf.end()&&a<=INT_MAX&&b<=INT_MAX&&a>=INT_MIN&&b>=INT_MIN)
    {
        a--;
        b--;
    }
    if(leaf.find({a,b})!=leaf.end())
    {
        leaf.erase({x,y});
        return {a,b};
    }
    return {x,y};
}

void solve()
{
    int n,m;
    cin>>n>>m;
    string moves;
    cin>>moves;
    map<ll,set<pll>>pos;
    ll x,y;
    cin>>x>>y;
    pos[x+y].insert({x,y});
    pos[x-y].insert({x,y});
    for(int i=1;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        pos[a+b].insert({a,b});
        pos[a-b].insert({a,b});
    }
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}