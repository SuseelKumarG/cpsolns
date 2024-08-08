#include <bits/stdc++.h>
using namespace std;
 
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

int x=0,y=0;

void chk(vi &a,int i,int j,int k,int l)
{
    x=0,y=0;
    if(a[i]>a[j])
    x++;
    if(a[i]<a[j])
    y++;
    if(a[k]>a[l])
    x++;
    if(a[k]<a[l])
    y++;
}

void solve()
{
    vi a(4);
    for(int i=0;i<4;i++)
    cin>>a[i];
    int ans=0;
    chk(a,0,2,1,3);
    if(x>y)
    {
        ans++;
        // cout<<1<<' ';
    }
    chk(a,0,3,1,2);
    if(x>y)
    {
        ans++;
        // cout<<2<<' ';
    }
    chk(a,1,3,0,2);
    if(x>y)
    {
        ans++;
        // cout<<3<<' ';
    }
    chk(a,1,2,0,3);
    if(x>y)
    {
        ans++;
        // cout<<4<<' ';
    }
    cout<<ans<<'\n';
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