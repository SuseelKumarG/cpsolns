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

bool poss(int l,int r)
{
    cout<<"? 1 "<<r-l+1<<' ';
    for(int i=l;i<=r;i++)
    cout<<i<<' ';
    cout<<endl;
    int x;
    cin>>x;
    cout<<"? 2 1"<<endl;
    cout<<"? 1 "<<r-l+1<<' ';
    for(int i=l;i<=r;i++)
    cout<<i<<' ';
    cout<<endl;
    int y;
    cin>>y;
    cout<<"? 2 1"<<endl;
    if(abs(y-x)==2*(r-l+1))
    return 0;
    return 1;
}

void solve()
{
    int n;
    cin>>n;
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
    vi val(n);
    int x;
    cout<<"? 1 1 1"<<endl;
    cin>>x;
    if(x==1||x==-1)
    {
        val[0]=x;
        for(int i=1;i<n;i++)
        {
            cout<<"? 1 1 "<<i+1<<endl;
            cin>>val[i];
            val[i]-=x;
        }
        cout<<"! ";
        for(auto it:val)
        cout<<it<<" ";
        cout<<endl;
        return;
    }
    int l=2,r=n;
    while(r-l>1)
    {
        int m=(r-l)/2+l;
        if(poss(l,m))
        r=m;
        else
        l=m+1;
    }
    if(poss(r,r))
    l=r;
    int y;
    cout<<"? 1 1 "<<l<<endl;
    cin>>y;
    val[0]=x-y;
    for(int i=1;i<n;i++)
    {
        if(i==(l-1))
        {
            val[i]=y;
            continue;
        }
        int z;
        cout<<"? 1 1 "<<i+1<<endl;
        cin>>z;
        val[i]=z-x;
    }
    cout<<"! ";
    for(auto it:val)
    cout<<it<<' ';
    cout<<endl;
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