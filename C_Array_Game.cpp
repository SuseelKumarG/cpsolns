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

void solve()
{
    int n,k;
    cin>>n>>k;
    multiset<ll>s;
    vl a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    sort(a.begin(),a.end());
    ll ans=LLONG_MAX;
    if(k>2)
    {
        cout<<0<<'\n';
        return;
    }
    for(int i=0;i<n-1;i++)
    ans=min(ans,a[i+1]-a[i]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            continue;
            ans=min(ans,abs(a[i]-a[j]));
            if(k>1)
            {
                auto it=lower_bound(a.begin(),a.end(),abs(a[i]-a[j]));
                if(it!=a.begin())
                {
                    auto xit=it;
                    xit--;
                    ans=min(ans,abs(*xit-abs(a[i]-a[j])));
                }
                if(it!=a.end())
                {
                    ans=min(ans,*it-abs(a[i]-a[j]));
                }
                auto tit=it;
                tit++;
                if(tit!=a.end())
                {
                    ans=min(ans,*tit-abs(a[i]-a[j]));
                }
            }
        }
    }
    for(auto it:a)
    ans=min(ans,it);
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