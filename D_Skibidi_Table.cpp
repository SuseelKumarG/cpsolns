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

ll num(int x,int y,int n)
{
    ll len=1;
    len<<=n;
    if(n==1)
    {
        if(x>1&&y>1)
        return 2;
        if(x>1&&y<1)
        return 3;
        if(x<2&&y>1)
        return 4;
        if(x<2&&y<2)
        return 1;
    }
    len>>=1;
    ll curr=len*len;
    ll quad=0;
    int a=x,b=y;
    if(x<=len&&y>len)
    {
        quad=3;
        a=x;
        b=y-len;
    }
    if(x>len&&y<=len)
    {
        quad=2;
        a=x-len;
        b=y;
    }
    if(x>len&&y>len)
    {
        quad=1;
        a=x-len;
        b=y-len;
    }
    ll add=num(a,b,n-1);
    curr*=quad;
    return curr+add;
}

pll pos(int x,int n)
{
    ll len=1;
    len<<=1;
    if(n==1)
    {
        if(x==1)
        return {1,1};
        if(x==2)
        return {2,2};
        if(x==3)
        return {2,1};
        if(x==4)
        return {1,2};
    }
    len>>=1;
    ll curr=len*len;
    int quad=(x-1)/curr;
    pll temp=pos(x-(curr*quad),n-1);
    if(quad==1)
    {
        temp.first+=len;
        temp.second+=len;
    }
    if(quad==2)
    {
        temp.first+=len;
    }
    if(quad==3)
    {
        temp.second+=len;
    }
    return temp;
}

void solve()
{
    int n;
    cin>>n;
    int q;
    cin>>q;
    // cout<<q<<'\n';
    while(q--)
    {
        cout<<1<<'\n';
        string k;
        cin>>k;
        if(k[1]=='>')
        {
            int x,y;
            cin>>x>>y;
            cout<<num(x,y,n);
        }
        else
        {
            int x;
            cin>>x;
            pll temp=pos(x,n);
            cout<<temp.first<<' '<<temp.second;
        }
        cout<<'\n';
    }
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