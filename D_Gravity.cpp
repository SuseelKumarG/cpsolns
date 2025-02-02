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
    int n,w;
    cin>>n>>w;
    vl a(n,-1);
    vvl fin(w);
    map<pll,ll>pos;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        pos[{x,y}]=i;
        fin[x].push_back(y);
    }
    for(auto &it:fin)
    {
        sort(it.begin(),it.end());
        reverse(it.begin(),it.end());
    }
    ll prev=0;
    while(1)
    {
        ll curr=0;
        for(int i=0;i<w;i++)
        {
            if(fin[i].empty())
            {
                goto A;
            }
            ll x;
            if(fin[i].back()>=prev)
            x=0;
            else
            x=prev-fin[i].back();
            curr=max(curr,fin[i].back()+x);
        }
        prev=curr;
        for(int i=0;i<w;i++)
        {
            a[pos[{i,fin[i].back()}]]=curr+1;
            fin[i].pop_back();
        }
    }
    A:
    int q;
    cin>>q;
    while(q--)
    {
        int t,i;
        cin>>t>>i;
        i--;
        if(a[i]==-1)
        cout<<"Yes\n";
        else if(a[i]>t)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
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