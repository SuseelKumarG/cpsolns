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

bool all_same(priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>> a)
{
    ll x=a.top().first;
    while(!a.empty())
    {
        if(a.top().first!=x)
        return 0;
        a.pop();
    }
    return 1;
}

void solve()
{
    string s;
    cin>>s;
    vl t(3);
    for(auto it:s)
    {
        if(it=='B')
        t[0]++;
        if(it=='S')
        t[1]++;
        if(it=='C')
        t[2]++;
    }
    vll n(3);
    for(auto &it:n)
    cin>>it.first;
    for(auto &it:n)
    cin>>it.second;
    ll r;
    cin>>r;
    ll T=t[0]*n[0].second+t[2]*n[2].second+t[1]*n[1].second;
    ll ans=0;
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>>ness;
    for(int i=0;i<3;i++)
    {
        ll x;
        ll z;
        if(t[i]==0)
        continue;
        x=n[i].first/t[i];
        z=n[i].first%t[i];
        pair<ll,pll>y;
        y={x,{t[i]-z,i}};
        ness.push(y);   
    }for(int i=0;i<3;i++)
    {
        ll x=ness.top().first;
        pair<ll,pll>y=ness.top();
        if(r>=y.second.first*n[y.second.second].second)
        {
            r-=y.second.first*n[y.second.second].second;
            ness.pop();
            ness.push({x+1,{t[y.second.second],y.second.second}});
        }
        else
        break;
    }
    while(r>0&&!all_same(ness))
    {
        ll x=ness.top().first;
        pair<ll,pll>y=ness.top();
        if(r>=y.second.first*n[y.second.second].second)
        {
            r-=y.second.first*n[y.second.second].second;
            ness.pop();
            ness.push({x+1,{t[y.second.second],y.second.second}});
        }
        else
        break;
    }
    ans=ness.top().first;
    ans+=r/T;
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}