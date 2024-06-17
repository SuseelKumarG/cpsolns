//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
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
typedef vector<vl> vvl; 
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
    ll n,k;
    cin>>n>>k;
    vi a(n);
    ll temp=0;
    for(ll i=1;i<=n;i++)
    {
        a[i-1]=i;
        temp+=abs(i-(n-i+1));
    }
    if(k&1||k>temp)
    {
        cout<<"NO\n";
        return;
    }
    int ind=0;
    int x=n;
    while(k>(x-1)*2)
    {
        k-=(x-1)*2;
        x-=2;
        swap(a[ind],a[n-ind-1]);
        ind++;
    }
    k>>=1;
    swap(a[ind],a[ind+k]);
    cout<<"YES\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
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