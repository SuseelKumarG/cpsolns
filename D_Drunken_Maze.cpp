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

vii mov={{0,1},{-1,0},{0,-1},{1,0}};

ll bfs(vector<string>&graph,pii s,pii t)
{
    int n=graph.size();
    int m=graph[0].size();
    priority_queue<pair<ll,pair<ll,pair<ll,pair<ll,pii>>>>,vector<pair<ll,pair<ll,pair<ll,pair<ll,pii>>>>>, greater<pair<ll,pair<ll,pair<ll,pair<ll,pii>>>>>>fin;
    vector<vb>vis(n,vb(m));
    fin.push({0,{0,{0,{-1,s}}}});
    vvl ans(n,vl(m,LLONG_MAX));
    ans[0][0]=0;
    while(!fin.empty())
    {
        pair<ll,pair<ll,pair<ll,pair<ll,pii>>>>now=fin.top();
        if(now.second.second.second.second==t)
        {
            return now.first;
        }
        fin.pop();
        if(vis[now.second.second.second.second.first][now.second.second.second.second.second])
        continue;
        vis[now.second.second.second.second.first][now.second.second.second.second.second]=1;
        for(int i=0;i<4;i++)
        {
            pii temp=now.second.second.second.second;
            temp.first+=mov[i].first;
            temp.second+=mov[i].second;
            if(graph[temp.first][temp.second]=='#')
            continue;
            ll dir=i,dist=now.first+1;
            ll lim=now.second.first,curr=now.second.second.first;
            if(i!=now.second.second.second.first)
            {
                lim=3;
                curr=1;
            }
            else if(lim==curr)
            {
                lim=2;
                curr=1;
                dist+=2;
            }
            else
            {
                curr++;
            }
            if(ans[temp.first][temp.second]>=dist)
            fin.push({dist,{lim,{curr,{dir,temp}}}});
        }
    }
    return -1;
}

bool dfs(vector<string>&graph,pll s,pll t)
{
    
    int n=graph.size();
    int m=graph[0].size();
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>, greater<pair<ll,pll>>>fin;
    vector<vb>vis(n,vb(m));
    fin.push({0,s});
    vvl ans(n,vl(m,LLONG_MAX));
    ans[0][0]=0;
    while(!fin.empty())
    {
        pair<ll,pll>now=fin.top();
        if(now.second==t)
        {
            return 1;
        }
        fin.pop();
        if(vis[now.second.first][now.second.second])
        continue;
        vis[now.second.first][now.second.second]=1;
        for(int i=0;i<4;i++)
        {
            pii temp=now.second;
            temp.first+=mov[i].first;
            temp.second+=mov[i].second;
            if(graph[temp.first][temp.second]=='#')
            continue;
            ll dist=now.first;
            if(ans[temp.first][temp.second]>=dist)
            fin.push({dist,temp});
        }
    }
    return 0;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<string>graph(n);
    for(auto&it:graph)
    cin>>it;
    pii s,t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(graph[i][j]=='S')
            s={i,j};
            if(graph[i][j]=='T')
            t={i,j};
        }
    }
    if(dfs(graph,s,t))
    cout<<bfs(graph,s,t);
    else
    cout<<-1;
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