// //in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
// //END
// //to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
// //END
// #include <bits/stdc++.h>
// using namespace std;
 
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<ll> vl;
// typedef vector<vl> vvl; 
// typedef vector<bool> vb;
// #define MAX 998244353
// #define N 10010

// long long gcdl(long long a, long long b){
//     while(a > 0 && b > 0){
//         if(a > b){
//             a %= b;
//         }
//         else{
//             b %= a;
//         }
//     }
//     return a + b;
// }  
// ll lcml(ll a,ll b)
// {
//     a=(a*b)/gcdl(a,b);
//     return a;
// }
// int gcd(int a, int b){
//     while(a > 0 && b > 0){
//         if(a > b){
//             a %= b;
//         }
//         else{
//             b %= a;
//         }
//     }
//     return a + b;
// }
// int lcml(int a,int b)
// {
//     a=(a*b)/gcd(a,b);
//     return a;
// }

// void solve()
// {
//     int n;
//     cin>>n;
//     vl a(n);
//     vl dp(n,0);
//     for(int i=0;i<n;i++)
//     cin>>a[i];
//     ll sum=a[0];
//     dp[0]=abs(a[0]);
//     for(int i=1;i<n;i++)
//     {
//         sum+=a[i];
//         dp[i]=max(dp[i-1]+a[i],abs(sum));
//     }
//     cout<<dp[n-1]<<'\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t=1;
//     cin>>t;
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
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
#define MAX 998244353
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
    int n;
    cin>>n;
    vl a(n),mx(n);
    ll c=0;
    for(int i=0;i<n;i++) cin>>a[i],c+=a[i],mx[i]=c;
    c=INT_MAX;
    int ind=-1;
    for(int i=0;i<n;i++)
    {
        if(c>mx[i]) c=mx[i],ind=i;
    }
    c=abs(c);
    a[ind]=c;
    c=0;
    for(int i=ind;i<n;i++) c+=a[i],a[i]=c;
    cout<<a[n-1]<<'\n';
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