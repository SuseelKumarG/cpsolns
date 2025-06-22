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

void zer(vvi&lev,int n,int i)
{
    if(n>=lev.size())
    return;
    lev[n][i]=0;
    zer(lev,n+1,i*2+1);
}
void one(vvi&lev,int n,int i)
{
    if(n>=lev.size())
    return;
    lev[n][i]=1;
    one(lev,n+1,2*i);
    one(lev,n+1,2*i+1);
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vvi lev;
    for(int i=0;i<=n;i++)
    {
        vi temp((1<<(i)),-1);
        lev.push_back(temp);
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<lev[i].size();j++)
        {
            if(lev[i][j]==-1)
            {
                int x=(1<<(n-i+1))-1;
                if(x>k||k==0)
                {
                    zer(lev,i,j);
                }
                else
                {
                    k-=x;
                    one(lev,i,j);
                }
            }
        }
    }
    if(k)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for(auto it:lev[n])
    cout<<it;
    cout<<'\n';
}

int32_t main()
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