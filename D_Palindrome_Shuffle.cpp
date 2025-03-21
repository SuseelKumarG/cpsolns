#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
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

bool poss(string &s,int k)
{
    int n=s.length();
    int ind=0;
    while(ind<n/2&&s[ind]==s[n-ind-1])
    ind++;
    if(ind>=n/2)
    return 1;
    vi cnt(26);
    int end=min(n,ind+k);
    for(int i=ind;i<min(n-ind,end);i++)
    {
        cnt[s[i]-'a']++;
    }
    for(int i=n-ind-1;i>=max(end,n-end);i--)
    cnt[s[i]-'a']--;
    for(auto it:cnt)
    {
        if(it<0)
        return 0;
        if(it&1)
        return 0;
    }
    for(int i=end;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        return 0;
    }
    return 1;
}

void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int l=0,r=n;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(poss(s,m))
        r=m;
        else
        l=m;
    }   
    int i; 
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        break;
    }
    if(i>=n/2)
    {
        cout<<0<<'\n';
        return;
    }
    int ans=INT_MAX;
    if(poss(s,l))
    ans=min(ans,l);
    else
    ans=min(ans,r);
    reverse(s.begin(),s.end());
    l=0,r=n;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(poss(s,m))
        r=m;
        else
        l=m;
    }   
    for(i=0;i<n/2;i++)
    {
        if(s[i]!=s[n-1-i])
        break;
    }
    if(i>=n/2)
    {
        cout<<0<<'\n';
        return;
    }
    if(poss(s,l))
    ans=min(ans,l);
    else
    ans=min(ans,r);
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