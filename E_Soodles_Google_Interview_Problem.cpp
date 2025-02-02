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
    string a,b;
    cin>>a>>b;
    int n=a.length();
    set<char> nope1(a.begin(),a.end());
    set<char> nope2(b.begin(),b.end());
    bool nope=0;
    for(auto it:nope1)
    {
        if(nope2.count(it)==0)
        nope=1;
    }
    if(nope)
    {
        cout<<-1<<'\n';
        return;
    }
    map<char,int>fpos;
    map<char,int>lpos;
    map<char,vi>pos;
    for(int i=0;i<b.length();i++)
    {
        if(fpos.count(b[i])==0)
        {
            fpos[b[i]]=i;
        }
        lpos[b[i]]=i;
        pos[b[i]].push_back(i);
    }
    int cnt=1;
    int ind=-1;
    for(int i=0;i<n;i++)
    {
        auto x=upper_bound(pos[a[i]].begin(),pos[a[i]].end(),ind);
        if(x==pos[a[i]].end())
        {
            cnt++;
            ind=pos[a[i]].front();
        }
        else
        ind=*(x);
    }
    cout<<cnt<<'\n';
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