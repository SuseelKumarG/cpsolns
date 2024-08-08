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

int cuts=0;

int dfs(vvi &graph,int v,int p,int fin)
{
    int curr=0;
    for(auto it:graph[v])
    {
        if(it!=p)
        curr+=dfs(graph,it,v,fin);
    }
    curr++;
    if(curr>=fin)
    {
        cuts++;
        return 0;
    }
    return curr;
}

bool poss(int fin,int k,int leaf,vvi &graph)
{
    cuts=0;
    if(dfs(graph,leaf,-1,fin)<fin)
    cuts--;
    if(cuts>=k)
    return 1;
    return 0;
}

void solve()
{
    int n,k;
    cin>>n>>k;
    vvi graph(n);
    for(int i=0;i<n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int leaf=-1;
    for(int i=0;i<n;i++)
    {
        if(graph[i].size()==1)
        {
            leaf=i;
            break;
        }
    }
    int lo=1,hi=n;
    while(hi-lo>1)
    {
        int mid=(hi-lo)/2+lo;
        if(poss(mid,k,leaf,graph))
        lo=mid;
        else
        hi=mid;
    }
    // if(poss(hi,k,leaf,graph))
    // cout<<hi<<'\n';
    // else
    cout<<lo<<'\n';
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