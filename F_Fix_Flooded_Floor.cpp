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
typedef vector<vb> vvb;
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

bool valid(int i,int j,vector<string>&a)
{
    return (min(i,j)>=0&&i<a.size()&&j<a[0].size());
}

int cnt;
int ey;

void dfs(vector<string>&a,vvb &vis,int i,int j)
{
    if(!valid(i,j,a))
    return;
    if(a[i][j]=='#')
    return;
    if(vis[i][j])
    return;
    vis[i][j]=1;
    cnt++;
    ey=max(ey,j);
    dfs(a,vis,i+1,j);
    dfs(a,vis,i-1,j);
    dfs(a,vis,i,j+1);
    dfs(a,vis,i,j-1);
}

void change(vector<string>&a,int i,int j)
{
    for(int j=0;j<=a[0].size();j++)
    {
        for(int i=0;i<2;i++)
        {
            // if(a[i][j]=='#'&&a[!i][j]=='#')
            // continue;
            if(a[i][j]=='.'&&a[!i][j]=='#'&&a[i][j+1]=='.')
            a[i][j]='#',a[i][j+1]='#';
        }
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<string>a(2);
    for(auto &it:a)
    cin>>it;
    change(a,0,0);
    // vvb vis(2,vb(n));
    bool poss=1;
    // bool mul=0;
    // ey=0;
    // for(int j=0;j<n;j++)
    // {
    //     cnt=0;
    //     for(int i=0;i<2;i++)
    //     {
    //         if(vis[i][j]||a[i][j]=='#')
    //         continue;
    //         dfs(a,vis,i,j);
    //         if(cnt&1)
    //         poss=0;
    //         if(poss)
    //         change(a,vis,i,j);
    //     }   
    // }
    int ans=0;
    cnt=0;
    vi temp(n);
    for(int i=0;i<n;i++)
    {
        if(a[0][i]=='.'||a[1][i]=='.')
        if(a[0][i]==a[1][i]&&a[0][i]=='.')
        temp[i]=1;
        else
        poss=0;
    }
    bool start=0;
    // for(int i=0;i<2;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     cout<<a[i][j];
    //     cout<<'\n';
    // }
    for(int i=0;i<n;i++)
    {
        ans=max(ans,cnt);
        if(temp[i]==1)
        cnt++;
        else
        cnt=0;
    }
    ans=max(ans,cnt);
    if(poss)
    {
        if(ans>1)
        cout<<"Multiple\n";
        else
        cout<<"Unique\n";
    }
    else
    cout<<"None\n";
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