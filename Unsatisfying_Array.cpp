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
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;i++)
    a[i]=n;
    map<pii,set<int>>ind;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        ind[{x,y}].insert(z);
    }
    bool poss=1;
    for(auto it:ind)
    {
        if(it.second.size()==n)
        {
            poss=0;
            break;
        }
        int curr=1;
        for(auto tit:it.second)
        {
            if(tit==curr)
            curr++;
            else break;
        }
        cout<<it.first.first<<' '<<it.first.second<<' '<<curr<<'\n';
        for(int i=it.first.first;i<=it.first.second;i++)
        {
            a[i]=curr;
        }
    }
    if(poss)
    {
        for(auto it:a)
        cout<<it<<' ';
        cout<<'\n';
    }
    else
    cout<<-1<<'\n';
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