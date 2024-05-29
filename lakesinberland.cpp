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

int cnt=0;

bool islake(int i,int j,int n,int m,vector<string> &graph,vector<vector<bool>> &vis,vvi &dp)
{
    if(i<0||j<0||i>=n||j>=m)
    return 1;
    if(vis[i][j])
    return dp[i][j];
    vis[i][j]=1;
    if(graph[i][j]=='*')
    return 1;
    if(i==0||i==n-1||j==0||j==m-1)
    {
        if(graph[i][j]=='.')
        {
            dp[i][j]=0;
            return 0;
        }
    }
    cnt++;
    bool ans=(islake(i+1,j,n,m,graph,vis,dp)&&islake(i-1,j,n,m,graph,vis,dp)&&islake(i,j+1,n,m,graph,vis,dp)&&islake(i,j-1,n,m,graph,vis,dp));
    if(ans)
    dp[i][j]=1;
    else
    dp[i][j]=0;
    return dp[i][j];
}

void filllake(int i,int j,int n,int m,vector<string> &graph)
{
    if(i<0||j<0||i>=n||j>=m)
    return;

    if(graph[i][j]=='*')
    return;
    graph[i][j]='*';
    filllake(i+1,j,n,m,graph);
    filllake(i-1,j,n,m,graph);
    filllake(i,j+1,n,m,graph);
    filllake(i,j-1,n,m,graph);
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> graph;
    vector<vector<bool>> vis;
    vvi dp;
    vi bp(m,-1);
    vector<bool> temp(m,0);
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        graph.push_back(s);
        vis.push_back(temp);
        dp.push_back(bp);
    }
    vector<pair<int,pii>> lake;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && graph[i][j]=='.')
            {
                cnt=0;
                if(islake(i,j,n,m,graph,vis,dp))
                {
                    lake.push_back({cnt,{i,j}});     
                }
            }
        }
    }
    sort(lake.begin(),lake.end());
    reverse(lake.begin(),lake.end());
    int ans=0;
    while(lake.size()!=k)
    {
        ans+=lake.back().first;
        int i=lake.back().second.first;
        int j=lake.back().second.second;
        filllake(i,j,n,m,graph);
        lake.pop_back();
    }
    cout<<ans<<'\n';
    for(int i=0;i<n;i++)
    cout<<graph[i]<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}