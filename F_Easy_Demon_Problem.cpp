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
    ll n,m,q;
    cin>>n>>m>>q;
    vl a(n),b(m);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    set<int> A(a.begin(),a.end());
    set<int> B(b.begin(),b.end());
    ll x=accumulate(a.begin(),a.end(),0LL);
    ll y=accumulate(b.begin(),b.end(),0LL);
    ll sum=x*y;
    while(q--)
    {
        bool poss=0;
        ll curr;
        cin>>curr;
        curr=sum-curr;
        for(int i=0;i<n;i++)
        {
            if(x-a[i]==0)
            {
                if(y*a[i]==curr)
                poss=1;
                continue;
            }
            ll temp;
            temp=curr-y*a[i];
            temp/=(x-a[i]);
            if(x*temp+y*a[i]-a[i]*temp==curr)
            {
                if(B.count(temp))
                poss=1;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(y-b[i]==0)
            {
                if(x*b[i]==curr)
                poss=1;
                continue;
            }
            ll temp;
            temp=curr-x*b[i];
            temp/=(y-b[i]);
            if(x*b[i]+y*temp-b[i]*temp==curr)
            {
                if(A.count(temp))
                poss=1;
            }
        }
        cout<<(poss?"YES":"NO")<<"\n";
    }
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