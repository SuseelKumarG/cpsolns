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

bool poss(vvi &graph,vi &pro,int i,int x,int y)
{
    queue<pii>fin;
    fin.push({x,0});
    bool ans=1;
    while(!fin.empty())
    {
        int temp=fin.front().first;
        int lev=fin.front().second;
        fin.pop();
        if(lev>y)
        return 1;
        if(pro[temp])
        {
            if(pro[temp]!=i)
            return 0;
            continue;
        }
        pro[temp]=i;
        for(auto it:graph[temp])
        fin.push({it,lev+1});
    }
}

void solve()
{
    int n,m,r;
    cin>>n>>m>>r;
    vvi graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vi pro(n);
    bool ans=1;
    for(int i=1;i<=r;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        ans&=poss(graph,pro,i,x,y);
    }
    for(auto it:pro)
    {
        if(!it)
        ans=0;
    }
    cout<<(ans?"Yes":"No")<<'\n';
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