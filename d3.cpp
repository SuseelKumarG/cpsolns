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

void solve()
{
    int n;
    cin>>n;
    map<int,int>cnt;
    int x,y;
    set<pii>u,l;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        cnt[x]++;
        if(y)
        u.insert({x,y});
        else
        l.insert({x,y});
    }
    int dou=0;
    for(auto it:cnt)
    {
        if(it.second==2)
        dou++;
    }
    ll ans=dou*1LL*(n-2);
    for(auto it:u)
    {
        if(u.find({it.first+2,1})!=u.end())
        {
            if(l.find({it.first+1,0})!=l.end())
            ans++;
        }
    }
    for(auto it:l)
    {
        if(l.find({it.first+2,0})!=l.end())
        {
            if(u.find({it.first+1,1})!=u.end())
            ans++;
        }
    }
    cout<<ans<<'\n';
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