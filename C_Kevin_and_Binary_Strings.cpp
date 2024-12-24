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

string uni;
ll soln(string &s,int a,int b,int c,int d)
{
    string x=s.substr(a,b-a+1);
    string y=s.substr(c,d-c+1);
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    int n=min(x.length(),y.length());
    ll curr=1;
    ll ans=0;
    string ris;
    for(int i=0;i<n;i++)
    {
        if(x[i]!=y[i])
        {
            ris.push_back('1');
        }
        else
        ris.push_back('0');
    }
    reverse(ris.begin(),ris.end());
    // cout<<x<<'\n';
    // cout<<y<<'\n';
    // cout<<ris<<'\n';
    // cout<<uni<<'\n';
    for(int i=0;i<n;i++)
    {
        if(ris[i]!=uni[i])
        {
            if(ris[i]=='1')
            {
                uni=ris;
                return 1;
            }
            else
            return 0;
        }
    }
    return 0;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.length();
    int fz=-1;
    int fo=-1;
    for(int i=fo;i<n;i++)
    if(s[i]=='0'&&fz==-1)
    fz=i;
    int l,r;
    ll curr=MAX;
    int x=n-fz;
    if(fz==-1)
    {
        cout<<1<<' '<<n<<' ';
        cout<<1<<' '<<1<<'\n';
        return;
    }
    uni.clear();
    for(int i=0;i<x;i++)
    uni.push_back('0');
    for(int i=0;i<fz;i++)
    {
        int temp=soln(s,0,n-1,i,i+x-1);
        if(temp)
        {
            curr=temp;
            l=i,r=i+x;
        }
    }
    cout<<1<<' '<<n<<' '<<l+1<<' '<<r<<'\n';
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