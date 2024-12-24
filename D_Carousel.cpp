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
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    set<int>temp(a.begin(),a.end());
    if(temp.size()==1)
    {
        cout<<1<<'\n';
        for(int i=0;i<n;i++)
        cout<<1<<' ';
        cout<<'\n';
        return;
    }
    if(n%2==0)
    {
        cout<<2<<'\n';
        for(int i=0;i<n;i++)
        {
            if(i&1)
            cout<<1<<' ';
            else
            cout<<2<<' ';
        }
        cout<<'\n';
        return;
    }
    if(a[n-1]==a[0])
    {
        cout<<2<<'\n';
        for(int i=0;i<n;i++)
        {
            if(i&1)
            cout<<1<<' ';
            else
            cout<<2<<' ';
        }
        cout<<'\n';
        return;
    }
    bool ok=0;
    int ind=-1;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            ok=1;
            ind=i+1;
            break;
        }
    }
    if(ok)
    {
        cout<<2<<'\n';
        vi b(n);
        for(int i=0;i<ind;i++)
        {
            b[i]=1;
            if(i&1)
            b[i]=2;
        }
        b[ind]=b[ind-1];
        for(int i=ind+1;i<n;i++)
        {
            b[i]=2;
            if(i&1)
            b[i]=1;
        }
        for(auto it:b)
        cout<<it<<' ';
        cout<<'\n';
        return;
    }
    cout<<3<<'\n';
    for(int i=0;i<n-1;i++)
    {
        if(i&1)
        cout<<1<<' ';
        else
        cout<<2<<' ';
    }
    cout<<3<<'\n';
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