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

void solve()
{
    
    int n,k;
    cin>>n>>k;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
 
    if(k > 2){
        cout<<0<<'\n';
        return;
    }
    sort(a.begin(),a.end());
    int ans = a[0];
    if(k == 2){
 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
 
                int diff = abs(a[j]-a[i]);
                ans = min(ans, diff);
                auto it = lower_bound(a.begin(),a.end(), diff);
                ans = min(ans, abs(*it - diff));
                if(it != a.begin()){
                    it--;
                    ans = min(ans, abs(*it - diff));
                }
            }
        }
        cout<<ans<<'\n';
    
    }else if(k == 1){
 
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = min(ans, abs(a[i]-a[j]));
            }
        }
        cout<<ans<<'\n';
    }
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