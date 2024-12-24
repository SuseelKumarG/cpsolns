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
    string s;
    cin>>s;
    map<ll,set<pll>>xa,ya;
    pll curr={LLONG_MAX,LLONG_MAX};
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        if(curr.first==LLONG_MAX)
        curr={x,y};
        ll c=y-x;
        xa[c].insert({x,y});
        c=y+x;
        ya[c].insert({x,y});
    }
    for(auto it:s)
    {
        if(it=='A'||it=='D')
        {
            ll c=curr.second-curr.first;
            if(it=='A')
            {
                auto it=xa[c].upper_bound(curr);
                if(it!=xa[c].end())
                {
                    xa[c].erase(curr);
                    ya[curr.second+curr.first].erase(curr);
                    curr=*it;
                }
            }
            else
            {
                auto it=xa[c].lower_bound(curr);
                if(it!=xa[c].begin())
                {
                    it--;
                    xa[c].erase(curr);
                    ya[curr.second+curr.first].erase(curr);
                    curr=*it;
                }
            }
        }
        else
        {
            ll c=curr.second+curr.first;
            if(it=='B')
            {
                auto it=ya[c].upper_bound(curr);
                if(it!=ya[c].end())
                {
                    xa[curr.second-curr.first].erase(curr);
                    ya[c].erase(curr);
                    curr=*it;
                }
            }
            else
            {
                auto it=ya[c].lower_bound(curr);
                if(it!=ya[c].begin())
                {
                    it--;
                    xa[curr.second-curr.first].erase(curr);
                    ya[c].erase(curr);
                    curr=*it;
                }
            }
        }
    }
    cout<<curr.first<<' '<<curr.second<<'\n';
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