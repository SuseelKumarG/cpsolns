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

vector<vii> adjvec()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    while(m--)
    {
        int v1,v2,w=1;
        cin>>v1>>v2;
        v1--;
        v2--;
        cin>>w;
        graph[v1].push_back({v2,w});
        graph[v2].push_back({v1,w});
    }
    return graph;
}

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

void solve()
{
    int n,m;
    cin>>n>>m;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans+=(n/i+1)/i;
    }
    cout<<ans-1<<'\n';
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