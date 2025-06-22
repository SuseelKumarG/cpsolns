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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string>graph(n+2);
    string temp(m+2,'#');
    graph[0]=graph[n+1]=temp;
    for(int i=1;i<=n;i++)
    {
        cin>>temp;
        temp="#"+temp+"#";
        graph[i]=temp;
    }
    vii pos;
    queue<vector<int>>fin;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(graph[i][j]=='E')
            fin.push({i,j,0});
        }
    }
    vvi vis(n+2,vi(m+2,INT_MAX));
    vvi mav={{0,1},{0,-1},{1,0},{-1,0}};
    while(!fin.empty())
    {
        vi temp=fin.front();
        fin.pop();
        int i=temp[0],j=temp[1],z=temp[2];
        for(auto &it:mav)
        {
            int x=i+it[0];
            int y=j+it[1];
            if(x>=graph.size()||x<0||y<0||y>=graph[0].size())
            continue;
            if(graph[x][y]=='#'||graph[x][y]=='E')
            continue;
            if(vis[x][y]>z)
            {
                if(it[0])
                graph[x][y]=((it[0]>0)?'^':'v');
                else
                graph[x][y]=((it[1]>0)?'<':'>');
                vis[x][y]=z;
                fin.push({x,y,z+1});
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

int32_t main()
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