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

void recur(deque<deque<int>>&a,int n)
{
    if(n==1)
    {
        deque<int> temp={0};
        a.push_back(temp);
        return;
    }
    recur(a,n-1);
    int x=(n-1)*(n-1);
    int y=n*n-1;
    if(n&1)
    {   
        deque<int> temp;
        for(int i=0;i<n-1;i++)
        temp.push_back(x++);
        a.push_front(temp);
        for(int i=1;i<n;i++)
        a[i].push_front(x++);
        a[0].push_front(x++);
    }
    else
    {
        for(int i=0;i<n-1;i++)
        {
            a[i].push_back(x++);
        }
        deque<int>temp;
        for(int i=0;i<n;i++)
        temp.push_back(x++);
        a.push_back(temp);
    }
}

void solve()
{
    int n;
    cin>>n;
    deque<deque<int>> a;
    recur(a,n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        cout<<a[i][j]<<' ';
        cout<<'\n';
    }
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