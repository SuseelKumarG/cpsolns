#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<ull> vul;
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

ll p2(ull x,ull y)
{
    ull n=0;
    while(x<y)
    {
        x*=x;
        n++;
    }
    return n;
}
ll p1(ull x,ull y)
{
    ll n=0;
    while(x*x<=y)
    {
        x*=x;
        n++;
    }
    return n;
}

void solve()
{
    int n;
    cin>>n;
    vul a(n);
    for(auto &it:a)
    cin>>it;
    ll ans=0,curr=0;
    bool poss=1;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        {
            if(a[i]==1)
            {
                poss=0;
                break;
            }
            
            ll x=p2(a[i],a[i-1]);
            curr+=x;
        }
        else{
            if(a[i-1]==1)
            {
                if(curr)
                {
                    poss=0;
                    break;
                }
                else
                continue;
            }
            ll x=p1(a[i-1],a[i]);
            curr-=x;
            curr=max(0LL,curr);
        }
        ans+=curr;
    }
    cout<<(poss? ans:-1)<<'\n';
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