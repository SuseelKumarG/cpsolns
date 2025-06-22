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
vi parent(1000000);
int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}void make_set(int v) {
    parent[v] = v;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
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
ll lcml(ll a,ll b)
{
    a=(a*b)/gcdl(a,b);
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

void dfs(vvi&graph,vb&vis,int v,vb&poss,int &cnt)
{
    int n=poss.size();
    if(vis[v])
    return;
    vis[v]=1;
    if(v>=n&&v<2*n)
    {
        cnt++;
        poss[v-n]=1;
    }
    for(auto it:graph[v])
    dfs(graph,vis,it,poss,cnt);
}

void func(vvi&graph,vb&vis,int v,vb&one,vi&ok)
{
    int n=graph.size();
    if(v<0||v>=n)
    return;
    if(vis[v])
    return;
    ok.push_back(v);
    vis[v]=1;
    one[v]=1;
    for(auto it:graph[v])
    func(graph,vis,it,one,ok);
}

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<parent.size();i++)
    parent[i]=i;
    vi a(n);
    for(ll&i:a)
    cin>>i;
    int cnt=0;
    int ans=0;
    vb poss(n);
    vvi graph(4*n);
    for(int i=0;i<n-1;i++)
    {
        graph[i].push_back(i+1);
    }
    for(int i=2*n;i<3*n;i++)
    {
        graph[i+1].push_back(i);
    }
    for(int i=0;i<n;i++)
    {
        graph[a[i]+i+n].push_back(i+n);
        graph[i+n].push_back(a[i]+i+n);
        if(((a[i]+i)<n)&&((a[i]+i)>=0))
        {
            union_sets(a[i]+i,i);
        }
    }
    vb vis(4*n);
    dfs(graph,vis,3*n-1,poss,cnt);
    dfs(graph,vis,0,poss,cnt);
    graph.clear();
    vb one(n);
    graph.resize(n);
    vis.clear();
    vis.resize(n);
    for(int i=0;i<n;i++)
    {
        if((i+a[i]<n)&&(i+a[i]>=0))
        graph[i].push_back(i+a[i]);
    }
    vi ok;
    func(graph,vis,0,one,ok);
    vi in(n);
    for(auto i:ok)
    {
        for(auto it:graph[i])
        {
            in[it]++;
        }
    }
    set<int>temp(ok.begin(),ok.end());
    vi ord;
    queue<int>fin;
    for(int i=0;i<n;i++)
    {
        if(!in[i])
        fin.push(i);
    }
    while(!fin.empty())
    {
        int x=fin.front();
        fin.pop();
        if(!temp.count(x))
        continue;
        ord.push_back(x);
        for(auto it:graph[x])
        {
            in[it]--;
            if(!in[it])
            fin.push(it);
        }
    }
    cnt=0;
    for(int i=0;i<n;i++)
    {
        if(poss[i]&&!one[i])
        cnt++;
    }
    vi rem(n);
    for(auto it:ord)
    temp.erase(it);
    if(temp.size())
    ord.clear();
    // cout<<(find_set(0))<<'\n';
    // cout<<(find_set(ord.back()))<<'\n';
    // if(ord.size())
    // for(int i=0;i<n;i++)
    // {
    //     cout<<ord.back()<<' ';
    //     if((((poss[i])&&(!one[i]))&&(find_set(i)==find_set(ord.back()))))
    //     cnt--;
    // }
    for(auto &it:in)
    it=0;
    for(int i=0;i<n;i++)
    {
        for(auto it:graph[i])
        in[it]++;
    }
    for(int i=0;i<ok.size();i++)
    {
        rem[ok[i]]=in[ok[i]]-1;
        rem[ok[i]]=max(rem[ok[i]],0LL);
    }
    map<int,int>val;
    int x=ord.size();
    for(auto it:ord)
    {
        val[it]=--x;
    }
    for(int i=0;i<n;i++)
    {
        int x=0;
        if(!ord.size())
        {
            if(one[i])
            {
                ans+=n+1;
                ans+=cnt-rem[i];
            }
            continue;
        }
        if(one[i])
        {
            ans+=cnt;
            ans+=n+1;
            ans+=val[i]-rem[i];
            continue;
        }
        ans+=2*n+1;
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