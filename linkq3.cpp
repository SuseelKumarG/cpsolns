

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
bool ok(int x,int y,int n,int m)
{
    return x<n&&min(x,y)>-1&&y<m;
}

void dfs(vector<string>&graph,vvi &vis,int i,int j,int n,int m,int curr)
{
    if(!ok(i,j,n,m))
    return;
    if(graph[i][j]!='1')
    return;
    if(vis[i][j])
    return;
    vis[i][j]=1;
    graph[i][j]=curr+'0';
    dfs(graph,vis,i+1,j,n,m,curr);
    dfs(graph,vis,i,j+1,n,m,curr);
    dfs(graph,vis,i,j-1,n,m,curr);
    dfs(graph,vis,i-1,j,n,m,curr);
}

void solve()
{
    int n;
    cin>>n;
    vector<string>a(n),b(n);
    for(auto &it:a)
    cin>>it;
    for(auto &it:b)
    cin>>it;
    int m=a[0].size();
    vvi visa,visb(n,vi(m));
    set<pii>match;
    int curr=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visa[i][j])
            dfs(a,visa,i,j,n,m,curr);
        }
    }
    curr=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!visb[i][j])
            dfs(b,visb,i,j,n,m,curr);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j]!='0'&&b[i][j]!='0')
            {
                match.insert({a[i][j]-'0',b[i][j]-'0'});
                match.insert({b[i][j]-'0',a[i][j]-'0'});
            }
            else if(a[i][j]!='0')
            {
                while(1)
                {
                    int x=a[i][j]-'0';
                    pii chk={a[i][j]-'0',0};
                    auto it=lower_bound(match.begin(),match.end(),chk);
                    if(it==match.end())
                    break;
                    if(it->first==x)
                    {
                        pii rem={it->second,x};
                        match.erase(chk);
                        match.erase(rem);
                    }
                    else 
                    break;
                }
            }
            else if(b[i][j]!='0')
            {
                while(1)
                {
                    int x=b[i][j]-'0';
                    pii chk={b[i][j]-'0',0};
                    auto it=lower_bound(match.begin(),match.end(),chk);
                    if(it==match.end())
                    break;
                    if(it->first==x)
                    {
                        pii rem={it->second,x};
                        match.erase(chk);
                        match.erase(rem);
                    }
                    else
                    break;
                }
            }
        }
    }
    cout<<match.size()/2<<'\n';
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