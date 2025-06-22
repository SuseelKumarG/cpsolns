#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
#define int long long
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl; 
typedef vector<pll> vll; 
typedef vector<bool> vb;
#define MAX 1000000007
#define N 10010

long long gcd(long long a, long long b){
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
ll lcm(ll a,ll b)
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

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vii> graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        x--;
        y--;
        graph[x].push_back({y,z});
        graph[y].push_back({x,z});
    }
    priority_queue<vector<int>,vvi,greater<vi>>fin;
    vi dist(n,INT_MAX);
    dist[0]=0;
    for(auto it:graph[0])
    {
        pii temp=it;
        fin.push({2*it.second,it.second,it.second,it.first});
    }
    vvi smol(n,{INT_MAX,INT_MAX});
    while(fin.size())
    {
        vi temp=fin.top();
        fin.pop();
        if(dist[temp.back()]<temp.front())
        continue;
        vi smo={temp[1],temp[2]};
        if(dist[temp.back()]==temp.front())
        {
            if(smol[temp.back()]==smo)
            continue;
        }
        smol[temp.back()]=min(smol[temp.back()],smo);
        dist[temp.back()]=temp.front();
        for(auto it:graph[temp.back()])
        {
            vi mo={min(smo[0],it.second),max(smo[1],it.second)};
            if((mo[0]+mo[1])<=dist[it.first])
            {
                fin.push({mo[0]+mo[1],mo[0],mo[1],it.first});
            }
        }
    } 
    int ans=smol[n-1][0]+smol[n-1][1];
    for(auto it:smol)
    {
        ans=min(ans,min(it[0],smol[n-1][0])+max(it[1],smol[n-1][1]));
    }
    cout<<ans<<'\n';
}

int32_t main()
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