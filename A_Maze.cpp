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

vii sums={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(vector<string>&graph,int i,int j,int &end)
{
    if(!end)
    return;
    graph[i][j]='O';
    end--;
    for(auto it:sums)
    {
        if(graph[i+it.first][j+it.second]=='.')
        dfs(graph,i+it.first,j+it.second,end);
    }
}

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int s=0;
    vector<string>graph(n+2);
    string temp(m+2,'#');
    graph[0]=temp;
    graph[n+1]=temp;
    for(int i=1;i<=n;i++)
    {
        cin>>graph[i];
        graph[i]='#'+graph[i]+'#';
    }
    int x=-1,y=-1;
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<m+2;j++)
        {
            if(graph[i][j]=='.')
            {
                s++;
                if(x==-1)
                {
                    x=i;
                    y=j;
                }
            }
        }
    }
    s-=k;
    dfs(graph,x,y,s);
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<m+2;j++)
        {
            if(graph[i][j]=='.')
            {
                graph[i][j]='X';
            }
        }
    }
    for(int i=0;i<n+2;i++)
    {
        for(int j=0;j<m+2;j++)
        {
            if(graph[i][j]=='O')
            {
                graph[i][j]='.';
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cout<<graph[i][j];
        cout<<'\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}