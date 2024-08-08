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
typedef vector<pll> vll;
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
   int n,m;
   cin>>n>>m;
   vll a(n);
   vl c(m);
   for(int i=0;i<n;i++) cin>>a[i].first;
   for(int i=0;i<n;i++) cin>>a[i].second;
   // for(int i=0;i<m;i++) cin>>c[i];
   sort(a.begin(),a.end());
   // sort(c.begin(),c.end());
   map<ll,ll>dp;
   map<ll,ll>ans;
   for(int i=1;i<=a[n-1].first;i++)
   {
      dp[i]=LLONG_MAX;
   }
   for(int i=0;i<n;i++)
   {
    //   if(dp.find(a[i].first)==dp.end())
    //   dp[a[i].first]=LLONG_MAX;
      dp[a[i].first]=min(dp[a[i].first],a[i].first-a[i].second);
   }
   for(ll i=1;i<=a[n-1].first;i++)
   {
    //   if(dp.find(i)==dp.end())
    //   dp[i]=LLONG_MAX;
      dp[i]=min(dp[i],dp[i-1]);
   }
   for(int i=1;i<=a[n-1].first;i++)
   {
      if(i>=dp[i])
      ans[i]=2+ans[i-dp[i]];
   }

   ll tot=0;
   while(m--)
   {
      ll x;
      cin>>x;
      ll k;
      if(x>a[n-1].first)
      {
         // k=(x-a[n-1].first+dp[a[n-1].first])/dp[a[n-1].first];
         // tot+=2*k;
         // x-=k*dp[a[n-1].first];
      }
      tot+=ans[x];
   }
   cout<<tot<<'\n';
   for(auto it:dp)
   cout<<it.second<<' ';
   cout<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
   //  cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}