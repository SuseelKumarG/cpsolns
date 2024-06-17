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

int cnt=0;
vii mov={{-1,0},{1,0},{0,-1},{0,1},{-1,1},{-1,-1},{1,1},{1,-1}};
void dfs(int i,int j,int n,int m,vector<string>&graph,vvb&vis)
{
    if(i<0||j<0)
    return;
    if(i>=n||j>=m)
    return;
    if(vis[i][j])
    return;
    vis[i][j]=1;
    if(graph[i][j]!='*')
    return;
    cnt++;
    for(auto it:mov)
    {
        dfs(i+it.first,j+it.second,n,m,graph,vis);
    }
}

int xax=0,yax=0;
vii movd={{-1,0},{1,0},{0,-1},{0,1}};

void ora(int i,int j,int n,int m,vector<string>&graph,vvb&vis)
{
    if(i<0||j<0)
    return;
    if(i>=n||j>=m)
    return;
    if(vis[i][j])
    return;
    vis[i][j]=1;
    if(graph[i][j]!='*')
    return;
    cnt++;
    for(auto it:movd)
    {
        ora(i+it.first,j+it.second,n,m,graph,vis);
    }
}

void solve()
{
    bool poss=1;
    int n,m;
    cin>>n>>m;
    vii fin;
    vector<string>graph(n);
    for(int i=0;i<n;i++)
    cin>>graph[i];
    vvb vis(n,vb(m,0));
    vvb vis1(n,vb(m,0));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(graph[i][j]=='*'&&!vis[i][j])
            {
                cnt=0;
                dfs(i,j,n,m,graph,vis);
                if(cnt!=3)
                poss=0;
                else
                fin.push_back({i,j});
            }
        }
    }
    for(auto it:fin)
    {
        int x=it.first,y=it.second;
        cnt=0;
        ora(x,y,n,m,graph,vis1);
        if(cnt!=3)
        poss=0;
    }
    for(auto it:fin)
    {
        int x=it.first,y=it.second;
        int tempx=0;
        for(int i=y;i<y+3&&i<m;i++)
        {
            if(graph[x][i]=='*')
            tempx++;
        }
        int tempy=0;
        for(int i=x;i<x+3&&i<n;i++)
        {
            if(graph[i][y]=='*')
            tempy++;
        }
        if(tempy!=2&&tempx!=2)
        poss=0;
    }
    cout<<(poss?"YES":"NO")<<'\n';
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