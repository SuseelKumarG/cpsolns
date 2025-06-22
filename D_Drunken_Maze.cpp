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

ll bfs(pii s,pii t,vector<string>&graph)
{
    int n=graph.size();
    int m=graph[0].size();
    queue<vector<int>>fin[4];
    for(int i=0;i<4;i++)
    {
        fin[0].push({0,s.first,s.second,i});
    }
    vvi ans[4];
    vvi tem(n,vi(m,INT_MAX));
    for(int i=0;i<4;i++)
    ans[i]=tem;    
    while(1)
    {
        vi temp(4,-1);
        temp[0]=INT_MAX;
        int ind=-1;
        for(int i=0;i<4;i++)
        {
            if((!fin[i].empty())&&(temp>fin[i].front()))
            {
                temp=fin[i].front();
                ind=i;
            }
        }
        if(ind==-1)
        break;
        fin[ind].pop();
        if(ans[temp[3]][temp[1]][temp[2]]<=temp[0])
        continue;
        ans[temp[3]][temp[1]][temp[2]]=temp[0];
        for(int i=0;i<4;i++)
        {
            if(i==temp[3])
            continue;
            for(int j=1;j<4;j++)
            {
                int x=temp[1]+mov[i].first*j;
                int y=temp[2]+mov[i].second*j;
                if(graph[x][y]=='#')
                break;
                fin[j].push({temp[0]+j,x,y,i});
            }
        }
    }
    int curr=INT_MAX;
    for(int i=0;i<4;i++)
    {
        curr=min(curr,ans[i][t.first][t.second]);
    }
    return (curr==INT_MAX?-1:curr);
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
    cout<<bfs(s,t,graph);
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