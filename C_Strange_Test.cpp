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
    int x,y;
    cin>>x>>y;
    ll add=INT_MAX;
    vi a,b;
    for(int i=31;i>=0;i--)
    {
        if((x>>i)&1)
        a.push_back(1);
        else
        a.push_back(0);
        if((y>>i)&1)
        b.push_back(1);
        else
        b.push_back(0);
    }
    int ind=-1;
    for(int i=0;i<32;i++)
    {
        if((!b[i])&&a[i])
        {
            ind=i;
            break;
        }
    }
    if(ind==-1)
    {
        cout<<1<<'\n';
        return;
    }
    int last=-1;
    for(int i=0;i<ind;i++)
    {
        if(b[i]&&!a[i])
        last=i;
    }
    ll temp=31-last;
    ll temp1=0;
    for(int i=last;i<32;i++)
    {
        if(a[i])
        temp1+=(1LL<<(31-i));
    }
    add=min(add,(1LL<<temp)-temp1+((x+(1LL<<temp)-temp1)!=y));
    temp=0;
    temp1=0;
    for(int i=ind;i<32;i++)
    {
        if(a[i])
        temp+=1LL<<(31-i);
        if(b[i])
        temp1+=1LL<<(31-i);
    }
    add=min(add,temp-temp1+1);
    cout<<add<<'\n';
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