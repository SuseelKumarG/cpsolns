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
// #include <bits/stdc++.h>
// using namespace std;
 
// typedef long long ll;
// typedef pair<int, int> pii;
// typedef pair<ll, ll> pll;
// typedef pair<string, string> pss;
// typedef vector<int> vi;
// typedef vector<vi> vvi;
// typedef vector<pii> vii;
// typedef vector<pll> vll;
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
//     int n,m;
//     cin>>n>>m;
//     vl a(n),b(n);
//     multiset<ll,greater<ll>>c;
//     for(int i=0;i<n;i++) cin>>a[i];
//     for(int i=0;i<n;i++) cin>>b[i];
//     for(int i=0;i<m;i++)
//     {
//         int x;
//         cin>>x;
//         c.insert(x);
//     }
//     map<ll,multiset<pll,greater<pll>>>diff;
//     for(int i=0;i<n;i++) diff[a[i]-b[i]].insert({a[i],b[i]});
//     ll ans=0;
//     ll x,y;
//     while(!c.empty())
//     {
//         ll curr=*(c.begin());
//         c.erase(c.begin());
//         x=-1,y=-1;
//         for(auto &it:diff)
//         {
//             // multiset<pll>temp=it.second;
//             for(auto &tit:it.second)
//             {
//                 if(tit.first<=curr)
//                 {
//                     x=tit.first;
//                     y=tit.second;
//                     goto A;
//                 }
//             }
//         }
//         A:
//         cout<<curr<<' '<<x<<' '<<y<<'\n';
//         if(x==-1)
//         break;
//         curr-=x;
//         curr+=y;
//         if(curr)
//         c.insert(curr);
//         ans+=2;
//     }
//     cout<<ans<<'\n';
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t=1;
//     // cin>>t;
//     // multiset<int>a={1,2,2,3,4,5,5};
//     // a.erase(2);
//     // for(auto it:a)
//     // cout<<it<<' ';
//     // cout<<'\n';
//     while(t--)
//     {
//         solve();
//     }
//     return 0;
// }
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
long long gcdl(long long a, long long b){ while(a > 0 && b > 0){ if(a > b){ a %= b; } else{ b %= a; } } return a + b; } ll lcml(ll a,ll b) { a=(a*b)/gcdl(a,b); return a; } int gcd(int a, int b){ while(a > 0 && b > 0){ if(a > b){ a %= b; } else{ b %= a; } } return a + b; } int lcml(int a,int b) { a=(a*b)/gcd(a,b); return a; } 
void solve() { int n,m; 
cin>>n>>m; 
vl a(n),b(n); 
multiset<ll,greater<ll>>c; 
for(int i=0;i<n;i++) cin>>a[i]; 
for(int i=0;i<n;i++) cin>>b[i]; 
for(int i=0;i<m;i++) { int x;
 cin>>x; 
c.insert(x); 
}
 map<float,multiset<pll,greater<pll>>,greater<float>>diff; 
ll zer=LLONG_MAX; 
for(int i=0;i<n;i++) 
{
     if(!b[i]) 
zer=min(zer,a[i]); 
else diff[(b[i]-0.0)/a[i]].insert({a[i],b[i]}); 
} 
ll ans=0;
 ll x,y;
 while
(
    !c.empty())
 { 
    ll curr=*(c.begin()); 
c.erase(c.begin());
 x=-1,y=-1; 
for(auto &it:diff) 
{ 
    // multiset<pll>temp=it.second;
 for(auto &tit:it.second) 
{ if(tit.first<=curr)
 { 
x=tit.first;
 y=tit.second;
 goto A; 
}
 }
 }
 A:
 cout<<curr<<' '<<x<<' '<<y<<'\n';
 if(x==-1) break;
 ll t=curr-x; 
ans+=t/(x-y)*2; 
curr-=t; 
if(curr>=x) 
ans+=2; 
curr-=x;
 curr+=y; 
if(curr)
 c.insert(curr);
 } 
while(!c.empty())
 { 
ll curr=*(c.begin());
 c.erase(c.begin()); 
if(curr<zer) 
break;
 ll t=curr-zer
;
 ans+=t/zer*2;
 curr-=t;
 if(curr>=zer)
 ans+=2;
 curr-=zer;
 if(curr) 
c.insert(curr);
 } 
cout<<ans<<'\n';
 }
 int main()
 { ios_base::sync_with_stdio(false); cin.tie(NULL); ll t=1; // cin>>t; // multiset<int>a={1,2,2,3,4,5,5}; // a.erase(2); // for(auto it:a) // cout<<it<<' '; // cout<<'\n'; 
 while(t--) { solve(); } return 0; }