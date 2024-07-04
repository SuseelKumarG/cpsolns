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
typedef vector<pll> vll; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define all(x) x.begin(),x.end()
#define MAX 1000000007
#define N 20015

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
    int n,x,y;
    cin>>n>>x>>y;
    vi a(x);
    for(int i=0;i<x;i++)
    cin>>a[i];
    sort(all(a));
    ull ans=0;
    if(x>2)
    ans+=(x-2);
    vi odd,eve;
    for(int i=1;i<x;i++)
    {
        int dist=a[i]-a[i-1]-1;
        if(dist)
        {
            if(dist>1)
            if(dist&1)
            odd.push_back(dist);
            else
            eve.push_back(dist);
            else
            ans++;
        }
    }
    int dist=n+a[0]-a[x-1]-1;
    if(dist)
    {
        if(dist>1)
        if(dist&1)
        odd.push_back(dist);
        else
        eve.push_back(dist);
        else
        ans++;
    }
    sort(all(odd));
    sort(all(eve));
    for(int i=0;i<odd.size();i++)
    {
        int k=odd[i]>>1;
        if(y>=k)
        {
            ans+=odd[i];
            y-=k;
        }
        else
        {
            ans+=y<<1;
            y=0;
        }
    }
    for(int i=0;i<eve.size();i++)
    {
        int k=eve[i]>>1;
        if(y>=k)
        {
            ans+=eve[i];
            y-=k;
        }
        else
        {
            ans+=y<<1;
            y=0;
        }
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
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}