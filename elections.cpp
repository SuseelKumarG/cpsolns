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
    bool poss=1;
    ull n,k;
    cin>>n>>k;
    if(k&1||k>n*(n+1)/2)
    {
        cout<<"NO\n";
        return;
    }
    vi a(n+1);
    set<int>chk;
    for(int i=1;i<=n;i++)
    {
        a[i]=i;
        chk.insert(i);
    }
    // vb vis(n+1);
    for(int i=1;i<=n&&k;i++)
    {
        if(chk.find(i)!=chk.end())
        {if(2*1ull*abs(a[*(--(chk.end()))]-a[i])<=k)
        {
            k-=2*1ull*abs(a[*(--(chk.end()))]-a[i]);
            swap(a[*(--(chk.end()))],a[i]);
            chk.erase(i);
            chk.erase((--(chk.end())));
        }
        else
        {
            int x=i+k/2;
            int y=i-k/2;
            if(chk.find(y)!=chk.end())
            {
                chk.erase(i);
                chk.erase(y);
                swap(a[i],a[y]);
                k=0;
            }
            if(chk.find(x)!=chk.end())
            {
                chk.erase(i);
                chk.erase(x);
                swap(a[i],a[x]);
                k=0;
            }
        }}
    }
    if(!k)
    {
        cout<<"YES\n";
        for(int i=1;i<=n;i++)
        cout<<a[i]<<' ';
        cout<<'\n';
    }
    else
    cout<<"NO\n";
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