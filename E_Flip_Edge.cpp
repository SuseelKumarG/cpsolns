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

void solve()
{
    ll n,m,c;
    cin>>n>>m>>c;
    vector<vii> graph(n);
    multiset<pii>ass;
    multiset<pii>real;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back({y,1});
        real.insert({x,y});
        ass.insert({x,y});
        ass.insert({y,x});
    }
    for(auto it:real)
    {
        ass.erase(it);
    }
    for(auto it:ass)
    {
        graph[it.first].push_back({it.second,-1});
    }
    vl dist(n,LLONG_MAX);
    vb vis(n);
    priority_queue<pair<ll,pll>,vector<pair<ll,pll>>,greater<pair<ll,pll>>>fin;
    fin.push({0,{0,0}});
    while(!fin.empty())
    {
        ll curr=fin.top().first;
        ll v=fin.top().second.first;
        ll flip=fin.top().second.second;
        fin.pop();
        if(vis[v])
        continue;
        vis[v]=1;
        dist[v]=curr;
        if(dist[v])
        for(auto it:graph[v])
        {
            if(flip&1)
            {
                {
                    if(it.second==-1)
                    {
                        ll temp=curr+1;
                        ll nflip=flip;
                        if(dist[it.first]>temp)
                        {
                            dist[it.first]=temp;
                            fin.push({temp,{it.first,nflip}});
                        }
                    }
                    else
                    {
                        ll temp=curr+1+c;
                        ll nflip=flip+1;
                        if(dist[it.first]>temp)
                        {
                            dist[it.first]=temp;
                            fin.push({temp,{it.first,nflip}});
                        }
                    }
                }
            }
            else
            {
                {
                    if(it.second==1)
                    {
                        ll temp=curr+1;
                        ll nflip=flip;
                        if(dist[it.first]>temp)
                        {
                            dist[it.first]=temp;
                            fin.push({temp,{it.first,nflip}});
                        }
                    }
                    else
                    {
                        ll temp=curr+1+c;
                        ll nflip=flip+1;
                        if(dist[it.first]>temp)
                        {
                            dist[it.first]=temp;
                            fin.push({temp,{it.first,nflip}});
                        }
                    }
                }

            }
        }
    }
    cout<<dist[n-1]<<'\n';
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