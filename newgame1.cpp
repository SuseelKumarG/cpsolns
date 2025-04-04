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
    map<int,int>cnt;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
    }
    vi a;
    for(auto it:cnt)
    a.push_back(it.first);
    int i=0,j=1;
    ll curr=cnt[a[0]],ans=curr;
    n=a.size();
    while(j<n)
    {
        if(j-i+1<=k&&a[j]<=a[j-1]+1)
        curr+=cnt[a[j]];
        else if(a[j]>a[j-1]+1)
        {
            curr=cnt[a[j]];
            i=j;
        }
        else
        {
            curr-=cnt[a[i]];
            curr+=cnt[a[j]];
            i++;
        }
        ans=max(ans,curr);
        j++;
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
        solve();
    }
    return 0;
}