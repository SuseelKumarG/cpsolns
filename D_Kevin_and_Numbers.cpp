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

bool can(map<ll,ll>&a,ll val)
{
    if(val==1)
    {
        if(a[val]>0)
        {
            a[val]--;
            return 1;
        }
        else
        return 0;
    }
    if(a[val]>0)
    {
        a[val]--;
        return 1;
    }
    else
    {
        if(val&1)
        return (can(a,val/2)&&can(a,val/2+1));
        else
        return (can(a,val/2)&&can(a,val/2));
    }
}

void solve()
{
    int n,m;
    cin>>n>>m;
    map<ll,ll>a,b;
    for(ll i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        a[x]++;
    }
    for(ll i=0;i<m;i++)
    {
        ll x;
        cin>>x;
        b[x]++;
    }
    bool poss=1;
    for(auto &it:a)
    {
        if(b[it.first])
        {
            if(a[it.first]>=b[it.first])
            {
                a[it.first]-=b[it.first];
                b[it.first]=0;
            }
        }
    }
    for(auto &it:b)
    { 
        if(!poss)
        break;
        while(it.second--)
        {
            if(!can(a,it.first))
            {
                poss=0;
                break;
            }
        }
        if(!poss)
        break;
    }
    ll op=0;
    for(auto it:a)
    op=max(it.second,op);
    for(auto it:b)
    op=max(it.second,op);
    if(op)
    poss=0;
    cout<<(poss?"YES":"NO")<<'\n';
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