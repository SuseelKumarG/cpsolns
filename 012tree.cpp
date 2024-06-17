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

int steps;

void dfs(int v,int p,vvi &graph)
{
    
}

void bfs(int x,vvi &graph,vi &lev,vector<bool> &vis)
{
    queue<int>q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
        if (!vis[u]) {
            vis[u] = 1;
            q.push(u);
            lev[u] = lev[v] + 1;
        }
        }
    }
}

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    int curr=0,prev=0;
    int lev=0;
    if(a)
    {
        prev=2;
        a--;
    }
    else if(b)
    {
        prev=1;
        b--;
    }
    else if(c)
    {
        prev=0;
        c--;
        if(c)
            cout<<"-1\n";
        else
            cout<<"0\n";
        return;
    }
    while(a||b||c){
        lev++;
        while(prev--)
        {
            if(a)
            {
                a--;
                curr+=2;
            }
            else if(b)
            {
                b--;
                curr++;
            }
            else if(c)
            {
                c--;
            }
            else
            {
                cout<<"-1\n";
                return;
            }
        }
        prev=curr;
        if(!prev)
        break;
        curr=0;
    }
    if(a||b||c||prev)
    {
        cout<<"-1\n";
        return;
    }
    cout<<lev<<'\n';
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