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

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    if(n&1||n<=7)
    {
        for(int i=0;i<n;i++)
        a[i]=i+1;
        swap(a[0],a[1]);
    }
    else
    {
        int x=1;
        int t=log2(n);
        set<int>need={1,3,n,(1<<t)-1,(1<<t)-2};
        for(int i=0;i<n-5;i++)
        {
            while(need.count(x))
            x++;
            a[i]=x++;
        }
        a[n-5]=1;
        a[n-4]=3;
        a[n-3]=(1<<t)-2;
        a[n-2]=(1<<t)-1;
        a[n-1]=n;
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        if(i&1)
        k|=a[i];
        else
        k&=a[i];
    }
    cout<<k<<'\n';
    for(int i=0;i<n;i++)
    cout<<a[i]<<' ';
    cout<<'\n';

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