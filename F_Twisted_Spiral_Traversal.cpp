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

bool ok(int x,int y,int n,int m)
{
    return x<n&&x>-1&&y<m&&y>-1;
}

void solve()
{
    int n,m,q;
    cin>>n>>m>>q;
    vvi graph(n,vi(m,0));
    vvi vis(n,vi(m,0));
    set<pii>finder;
    while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        if(ok(x,y,n,m))
        {graph[x][y]=z;
        finder.insert({x,y});}
    }
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    int dir=1;
    map<int,int>change;
    change[1]=2;
    change[2]=3;
    change[3]=4;
    change[4]=1;
    map<int,pii>look;
    look[1]={0,1};
    look[2]={-1,0};
    look[3]={0,-1};
    look[4]={1,0};
    map<int,pii>path;
    look[1]={1,0};
    look[2]={0,1};
    look[3]={-1,0};
    look[4]={0,-1};
    while(ok(x, y, n, m)) {
        if(vis[x][y]) 
        break;
        vis[x][y] = 1;
        if(ok(x, y, n, m) && finder.count({x, y})) {
            cout << x+1 << ' ' << y+1 << ' ' << graph[x][y] << ' ' << dir << '\n';
        }
        pii add = look[dir];
        if(!ok(x+add.first, y+add.second, n, m) || vis[x+add.first][y+add.second]) {
            dir = change[dir];
        }
        x += look[dir].first;
        y += look[dir].second;
    }
    cout<<'\n';
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