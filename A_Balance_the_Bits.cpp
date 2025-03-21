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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]!='1'||s[n-1]!='1')
    {
        cout<<"NO\n";
        return;
    }
    int cnt=0;
    for(auto it:s)
    {
        if(it=='0')
        cnt++;
    }
    if(cnt&1)
    {
        cout<<"NO\n";
        return;
    }
    cnt=0;
    for(auto it:s)
    {
        if(it=='1')
        cnt++;
    }
    vector<char> x(n),y(n);
    int temp=0;
    int temp1=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            temp++;
            if(temp<=cnt/2)
            {
                x[i]='(';
                y[i]='(';
            }
            else
            {
                x[i]=')';
                y[i]=')';
            }
        }
        else
        {
            if(temp1&1)
            {
                x[i]='(';
                y[i]=')';
            }
            else
            {
                y[i]='(';
                x[i]=')';
            }
            temp1++;
        }
    }
    cout<<"YES\n";
    for(auto it:x)
    cout<<it;
    cout<<'\n';
    for(auto it:y)
    cout<<it;
    cout<<'\n';
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