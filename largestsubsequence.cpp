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
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n==1)
    {
        cout<<1<<'\n';
        return;
    }
    // if(n==2)
    // {
    //     if(s=="ab"||s=="ba")
    //     cout<<1<<'\n';
    //     else
    //     cout<<2<<'\n';
    //     return;
    // }
    int cnt=0;
    int fs=-1,ls=-1;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]!=s[i+1])
        {
            cnt++;
            if(fs==-1)
            fs=i;
            // else
            ls=i;
        }
    }
    if(cnt&1)
    cout<<max(n-fs-1,ls+1)<<'\n';
    else
    cout<<n<<'\n';
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