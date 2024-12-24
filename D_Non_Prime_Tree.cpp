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

vector<bool> is_prime(1000000, true);

bool poss(vi &a,int x)
{
    if(a.empty())
    return 1;
    for(auto it:a)
    {
        if(it!=0)
        if(is_prime[x-it])
        return 0;
    }
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
    set<int>chk;
    for(int i=1;i<=2*n;i++)
    chk.insert(i);
    vii temp;
    for(int i=0;i<n;i++)
    {
        temp.push_back({(int)graph[i].size(),i});
    }
    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());
    vi ok;
    for(int i=0;i<n;i++)
    ok.push_back(temp[i].second);
    set<int>used;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        vi temp;
        for(auto it:graph[ok[i]])
        if(a[it])
        temp.push_back(a[it]);
        if(chk.empty())
        {
            cout<<-1<<'\n';
            return;
        }
        int x=*chk.begin();
        while(used.count(x)!=0||!poss(temp,x))
        x++;
        used.insert(x);
        if(chk.count(x))
        chk.erase(x);
        a[ok[i]]=x;
    }
    if(*(--used.end())>2*n)
    {
        cout<<-1<<'\n';
        return;
    }   
    for(auto it:a)
    cout<<it<<' ';
    cout<<'\n';
}

int main()
{
    int n=1000000;
    is_prime[2]=1;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < n; i++) {
        if (is_prime[i] && (long long)i * i < n) {
            for (int j = i * i; j < n; j += i)
                is_prime[j] = false;
        }
    }
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