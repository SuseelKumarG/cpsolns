//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END
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

ll sol(vii &a,vii&b,vii&c,int n)
{
    ll sum=a[0].first;
    set<int> ind;
    ind.insert(a[0].second);
    int i=0;
    while(ind.find(b[i].second)!=ind.end())
    i++;
    sum+=b[i].first;
    ind.insert(b[i].second);
    i=0;
    while(ind.find(c[i].second)!=ind.end())
    i++;
    sum+=c[i].first;
    ind.insert(c[i].second);
    i=0;
    return sum;
}

void solve()
{
    int n;
    cin>>n;
    vii a(n),b(n),c(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i].first;
        b[i].second=i;
    }
    for(int i=0;i<n;i++)
    {
        cin>>c[i].first;
        c[i].second=i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    sort(c.begin(),c.end());
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    reverse(c.begin(),c.end());
    ll ans=0;
    ans=max(ans,sol(a,b,c,n));
    ans=max(ans,sol(a,c,b,n));
    ans=max(ans,sol(b,a,c,n));
    ans=max(ans,sol(b,c,a,n));
    ans=max(ans,sol(c,b,a,n));
    ans=max(ans,sol(c,a,b,n));
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
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}