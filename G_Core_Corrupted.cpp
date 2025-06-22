#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
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

ll binexp(ll a,ll b)
{
    ll ans=1;
    while (b)
    {
        if(b&1)
        ans=(ans*a)%MAX;
        b>>=1;
        a=(a*a)%MAX;
    }
    return ans;
}
vb useful(15000010,1);
vi ok;
void solve()
{
    int n;
    cin>>n;
    if((!useful[n]))
    {
        cout<<-1<<'\n';
        return;
    }
    cout<<*upper_bound(ok.begin(),ok.end(),n)<<'\n';
}

int32_t main()
{
    for(int i=1;i<=15000000;i++)
    {
        int x=i;
        bool is=0;
        while(x)
        {
            if((x%10)==7)
            is=1;
            x/=10;
        }
        if(is)
        {
            useful[i]=0;
            for(int j=2*i;j<=15000000;j+=i)
            {
                useful[j]=0;
            }
        }
    }
    for(int i=1;i<=15000000;i++)
    if(useful[i])
    ok.push_back(i);
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