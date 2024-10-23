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

bool chk(int ind,int n,vi&inp,vii&b)
{
    vi a(n+1);
    for(int i=0;i<ind;i++)
    a[inp[i]]=1;
    for(int i=1;i<=n;i++)
    a[i]+=a[i-1];
    for(auto it:b)
    {
        int l=it.first,r=it.second;
        int one=abs(a[r]-a[l-1]);
        int len=r-l+1;
        int zer=len-one;
        if(one>zer)
        return 1;
    }
    return 0;
}

void solve()
{
    int m,n;
    cin>>n>>m;
    vii b;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        b.push_back({x,y});
    }
    int q;
    cin>>q;
    vi inp;
    for(int i=0;i<q;i++)
    {
        int x;
        cin>>x;
        inp.push_back(x);
    }
    int l=0,r=q;
    while(r-l>1)
    {
        int mid=(r-l)/2+l;
        if(chk(mid,n,inp,b))
        r=mid;
        else
        l=mid;
    }
    if(chk(r,n,inp,b))
    cout<<r<<'\n';
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