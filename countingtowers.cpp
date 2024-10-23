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

vl dpa(1000000),dpb(1000000);

void solve()
{
    int n;
    cin>>n;
    cout<<(dpa[n-1]+dpb[n-1])%MAX<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    cin>>t;
    dpa[0]=1;
    dpb[0]=1;
    for(int i=1;i<1000000;i++)
    {
        dpa[i]=((2*dpa[i-1])%MAX+dpb[i-1])%MAX;
        dpa[i]%=MAX;
        dpb[i]=((4*dpb[i-1])%MAX+dpa[i-1])%MAX;
        dpb[i]%=MAX;
    }
    while(t--)
    {
        solve();
    }
    return 0;
}