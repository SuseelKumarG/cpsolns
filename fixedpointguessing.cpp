//in all subarrays of array a of length k have their or same then it is true for any sub array of length > k
//END
//to coprime numbers a and b can reproduce any number x greater than a*b-a-b as x= m*a+n*b
//END

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
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

vector<vii> adjvec()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    while(m--)
    {
        int v1,v2,w=1;
        cin>>v1>>v2;
        v1--;
        v2--;
        cin>>w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }
    return graph;
}

long long gcd(long long a, long long b){
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

ll v=0,k=0;

bool dfs(int i,int j,int n,int m,vector<string> &graph,vector<vector<bool>> &vis,vvi &dp)
{
    if(i<0||j<0)
    return 0;
    if(i>=n||j>=m)
    return 0;
    if(vis[i][j])
    return dp[i][j];
    vis[i][j]=1;
    if(graph[i][j]=='#')
    dp[i][j]=0;
    if(dp[i][j]==-1)
    {
        if(i==0||i==n-1||j==0||j==m-1)
        {
            if(graph[i][j]=='.')
            dp[i][j]=1;
        }
        if(dfs(i+1,j,n,m,graph,vis,dp)||dfs(i-1,j,n,m,graph,vis,dp)||dfs(i,j+1,n,m,graph,vis,dp)||dfs(i,j-1,n,m,graph,vis,dp))
        dp[i][j]=1;
    }
    return dp[i][j];
}

void numconnected(int i,int j,int n,int m,vector<string> &graph,vector<vector<bool>> &vis2)
{
    if(i<0||j<0)
    return;
    if(i>=n||j>=m)
    return;
    if(vis2[i][j])
    return;
    vis2[i][j]=1;
    if(graph[i][j]=='#')
    return;
    numconnected(i+1,j,n,m,graph,vis2);
    numconnected(i-1,j,n,m,graph,vis2);
    numconnected(i,j+1,n,m,graph,vis2);
    numconnected(i,j-1,n,m,graph,vis2);
}

bool outp(int l,int r)
{
    printf("? %d %d\n",l,r);
    fflush(stdout);
    int n=r-l+1;
    int x;
    int cnt=0;
    while(n--)
    {
        cin>>x;
        if(x>=l&&x<=r)
        cnt++;
    }
    return cnt%2;
}
void out(int i)
{
    printf("! %d\n",i);
    fflush(stdout);
}


void solve()
{
    int n;
    cin>>n;
    int l=1,r=n;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(outp(l,m))
        r=m;
        else
        l=m;
    }
    if(outp(r,r))
    out(r);
    else
    out(l);
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