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

void solve()
{
    ll m,f,c;
    cin>>m>>f>>c;
    ll n;
    cin>>n;
    vvi graph(n+1);
    for(int i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int s=0; // source vertex

    queue<int> q;
    vector<bool> used(n);
    vector<int> d(n), p(n);

    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : graph[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
    ll male=d[n-1];
    s=1;
    queue<int> q1;
    vector<bool> used1(n);
    vector<int> d1(n), p1(n);

    q1.push(s);
    used1[s] = true;
    p1[s] = -1;
    while (!q1.empty()) {
        int v = q1.front();
        q1.pop();
        for (int u : graph[v]) {
            if (!used1[u]) {
                used1[u] = true;
                q1.push(u);
                d1[u] = d1[v] + 1;
                p1[u] = v;
            }
        }
    }
    ll fem=d1[n-1];
    ll ans=male*m+fem*f;
    ll o=d[n-1]*c+d1[0]*f,h=d[1]*m+d1[n-1]*c;
    ans=min(ans,o);
    ans=min(ans,h);
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}