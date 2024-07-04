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
typedef vector<pll> vll; 
typedef vector<bool> vb;
typedef vector<vb> vvb;
#define all(x) x.begin(),x.end()
#define MAX 1000000007
#define N 20015

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

bool poss=0;

void dfs(vector<string> &graph,int i,int j,int n,vvb &vis,bool choose)
{
    if(i<0||i>1)
    return;
    if(j<0||j>=n)
    return;
    if(vis[i][j])
    return;
    if(i==1&&j==n-1)
    {
        poss=1;
        return;
    }
    vis[i][j]=1;
    if(choose)
    {
        if(graph[i][j]=='>')
        dfs(graph,i,j+1,n,vis,0);
        else
        dfs(graph,i,j-1,n,vis,0);
    }
    else
    {dfs(graph,i,j+1,n,vis,1);
    dfs(graph,i,j-1,n,vis,1);
    dfs(graph,i+1,j,n,vis,1);
    dfs(graph,i-1,j,n,vis,1);}
}

void solve()
{
    int n;
    cin>>n;
    vector<string> graph(2);
    vvb vis(2,vb(n,0));
    for(int i=0;i<2;i++)
    cin>>graph[i];
    // cout<<graph[0]<<'\n'<<graph[1]<<'\n';
    // cout<<'\n';
    poss=0;
    dfs(graph,0,0,n,vis,0);
    dfs(graph,0,0,n,vis,1);
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
        // cout<<t<<0<<'\n';
        solve();
    }
    return 0;
}