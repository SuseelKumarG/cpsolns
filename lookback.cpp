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
typedef vector<ull> vul;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
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
    int n;
    cin>>n;
    vul a(n);
    vi bits(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    ll cnt=0;
    if(n==1)
    {
        cout<<0<<'\n';
        return;
    }
    ll curr=0;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        {
            int x=0;
            while((a[i]<<(x))<a[i-1])
            x++;
            curr+=x;
        }
        else{
            int x=0;
            while((a[i-1]<<(x+1))<=a[i])
            x++;
            curr-=x;
            curr=max(0LL,curr);
        }
        cnt+=curr;
    }
    cout<<cnt<<'\n';
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