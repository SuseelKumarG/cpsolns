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
    string s;
    cin>>s;
    string x,y;
    int o=-1;
    int z=-1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1'&&o==-1)
        {
            o=i;
        }
        if(s[i]=='0'&&z==-1)
        {
            z=i;
        }
    }
    if(o!=-1)
    {
        x.push_back('1');
        for(int i=o+1;i<n-1;i++)
        {
            if(s[i]!=x.back()&&s[i]!=s[i+1])
            continue;
            x.push_back(s[i]);
        }
        if(o!=n-1)
        x.push_back(s[n-1]);
    }
    if(z!=-1)
    {
        y.push_back('0');
        for(int i=z+1;i<n-1;i++)
        {
            if(s[i]!=y.back()&&s[i]!=s[i+1])
            continue;
            y.push_back(s[i]);
        }
        if(z!=n-1)
        y.push_back(s[n-1]);
    }
    int temp=0;
    int temp1=0;
    if(x.size()>1)
    for(int i=0;i<x.size()-1;i++)
    {
        if(x[i]==x[i+1])
        temp++;
    }
    if(y.size()>1)
    for(int i=0;i<y.size()-1;i++)
    {
        if(y[i]==y[i+1])
        temp1++;
    }
    cout<<max(temp,temp1)<<'\n';
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