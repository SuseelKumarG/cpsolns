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

void solve()
{
    ll n,m,k;
    cin>>n>>m>>k;
    ll mul=n*m;
    mul/=k;
    vvi ans(n+1,vi(m+1));
    vi ord;
    for(int i=0;i<mul;i++)
    {
        for(int j=1;j<=k;j++)
        ord.push_back(j);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans[i][j]=ord.back();
            ord.pop_back();
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((ans[i][j]!=ans[i-1][j])&&(ans[i][j]!=ans[i][j-1]))
            continue;
            int x=-1,y=-1;
            for(int l=j+1;j<=m;j++)
            {
                if((ans[i][l]!=ans[i-1][j])&&(ans[i][l]!=ans[i][j-1]))
                {
                    x=i,y=l;
                    break;
                }
            }
            for(int l=i+1;l<=n;l++)
            {
                for(int r=1;r<=m;r++)
                {
                    if((ans[i][l]!=ans[i-1][j])&&(ans[i][l]!=ans[i][j-1]))
                    {
                        x=l,y=r;
                        break;
                    }
                }
                if(x!=-1)
                break;
            }
            if(x!=-1)
            swap(ans[i][j],ans[x][y]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<ans[i][j]<<' ';
        cout<<'\n';
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