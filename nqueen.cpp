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

void chk(vector<string>&graph,vector<vector<string>>&ans)
{
    
}

void gen(vector<string>&graph,int ind,vector<vector<string>>&ans)
{
    if(ind==graph.size())
    {
        chk(graph,ans);
    }
    for(int i=0;i<graph[0].size();i++)
    {
        graph[ind][i]='Q';
        gen(graph,ind+1,ans);
        graph[ind][i]='.';
    }

}

void solve()
{
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>graph;
    string ro(n,'.');
    for(int i=0;i<n;i++)
    graph.push_back(ro);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {

        }
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