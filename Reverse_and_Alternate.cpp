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

bool can(string &s)
{
    int n=s.length();
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        return 0;
    }
    return 1;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int f=-1,l=-1;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]==s[i+1])
        {
            if(f==-1)
            f=i+1;
        }
    }
    for(int i=n-1;i>0;i--)
    {
        if(s[i]==s[i-1])
        {
            if(l==-1)
            l=i-1;
        }
    }
    string a,b,c;
    bool poss=0;
    if(f==-1)
    poss=1;
    if(f!=-1)
    {
        for(int i=f-1;i>=0;i--)
        {
            a.push_back(s[i]);
        }
        for(int i=0;i<f;i++)
        {
            b.push_back(s[i]);
            c.push_back(s[i]);
        }
        for(int i=l;i>=f;i--)
        {
            b.push_back(s[i]);
        }
        for(int i=f;i<=l;i++)
        {
            a.push_back(s[i]);
            c.push_back(s[i]);
        }
        for(int i=l+1;i<n;i++)
        {
            a.push_back(s[i]);
            b.push_back(s[i]);
        }
        for(int i=n-1;i>l;i--)
        {
            c.push_back(s[i]);
        }
    }
    if(can(a)||can(b)||can(c))
    poss=1;
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