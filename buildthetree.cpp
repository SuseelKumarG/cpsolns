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
    int n,d,l;
    cin>>n>>d>>l;
    vi main;
    main.push_back(1);
    int curr=2;
    for(int i=0;i<d;i++)
    main.push_back(curr++);
    if(d==1)
    {
        if(n==2&&l==2)
        {
            cout<<1<<' '<<2<<'\n';
        }
        else
        {
            cout<<-1<<'\n';
        }
        return;
    }
    int mid=(((int)main.size())+1)/2;
    int maxm=mid;
    vvi child;
    l-=2;
    int i=0;
    while(curr<=n&&l>0)
    {
        l--;
        child.push_back({mid,curr++});
    }
    i=0;
    while(i<(int)child.size()&&child[i].size()<maxm&&curr<=n)
    {
        child[i].push_back(curr++);
        if(child[i].size()==maxm)
        i++;
    }
    if(curr<=n||l>0)
    {
        cout<<-1<<'\n';
        return;
    }
    for(int i=1;i<(int)main.size();i++)
    {
        cout<<main[i-1]<<" "<<main[i]<<'\n';
    }
    for(int i=0;i<(int)child.size();i++)
    {
        for(int j=1;j<(int)child[i].size();j++)
        cout<<child[i][j-1]<<' '<<child[i][j]<<'\n';
    }
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