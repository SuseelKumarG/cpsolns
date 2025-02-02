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
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt=1;
    int l=-1,r=-1;
    int curr=0;
    bool came=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='1')
        {
            came=1;
        }
        else if(came)
        {
            came=0;
            if(k==cnt+1)
            {
                l=i-1;
            }
            if(k==cnt)
            r=i-1;
            cnt++;
        }
    }
    if(cnt==k&&s[n-1]=='1')
    r=n-1;
    int x=r;
    cnt=0;
    while(s[x]!='0'&&x>=0)
    {
        cnt++;
        x--;
    }
    for(int i=0;i<=l;i++)
    cout<<s[i];
    for(int i=0;i<cnt;i++)
    cout<<'1';
    for(int i=l+cnt+1;i<=r;i++)
    cout<<0;
    for(int i=r+1;i<n;i++)
    cout<<s[i];
    cout<<'\n';
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