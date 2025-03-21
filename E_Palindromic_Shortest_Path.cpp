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

void solve()
{
    int n;
    cin>>n;
    vector<string>edge(n);
    for(auto &it:edge)
    cin>>it;
    vvi graph(n);
    vvi dp(n,vi(n,INT_MAX));
    vector<vvi> in(n,vvi(26)),out(n,vvi(26));
    queue<pair<ll,pll>>fin;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                dp[i][j]=0;
                fin.push({0,{i,j}});
            }
            if(edge[i][j]=='-')
            continue;
            graph[i].push_back(j);
            in[j][edge[i][j]-'a'].push_back(i);
            out[i][edge[i][j]-'a'].push_back(j);
            if(i!=j)
            {
                dp[i][j]=1;
                fin.push({1,{i,j}});
            }
        }
    }
    while(!fin.empty())
    {
        pair<ll,pll>temp=fin.front();
        fin.pop();
        int x=temp.second.first,y=temp.second.second;
        ll dist=temp.first;
        if(dp[x][y]<dist)
        continue;
        dp[x][y]=dist;
        for(int i=0;i<26;i++)
        {
            if(in[x][i].empty()||out[y][i].empty())
            continue;
            for(auto &it:in[x][i])
            {
                for(auto &tit:out[y][i])
                {
                    int l=it;
                    int r=tit;
                    int add=2;
                    if(dist+add<dp[l][r])
                    {
                        fin.push({dist+add,{l,r}});
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<(dp[i][j]==INT_MAX?-1:dp[i][j])<<' ';
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