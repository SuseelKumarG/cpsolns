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
    int n,q;
    cin>>n>>q;
    vi a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        a[i]--;
    }
    vi pos(n);
    for(int i=0;i<n;i++)
    pos[a[i]]=i;
    vi poss(n);
    for(int i=0;i<n;i++)
    {
        poss[min(i,pos[i])]++;
        poss[max(i,pos[i])]--;
    }
    ll x=0;
    for(int i=0;i<n;i++)
    {
        x+=poss[i];
        poss[i]=x;
    }
    set<int>cnt;
    string s;
    cin>>s;
    for(int i=0;i<n-1;i++)
    {
        if(s[i]=='L'&&s[i+1]=='R'&&poss[i])
        {
            cnt.insert(i);
        }
    }
    while(q--)
    {
        cin>>x;
        x--;
        if(s[x]=='R'&&s[x+1]=='R'&&poss[x])
        cnt.insert(x);
        if(s[x]=='L'&&s[x-1]=='L'&&poss[x-1])
        cnt.insert(x-1);
        if(s[x]=='L'&&s[x+1]=='R'&&poss[x])
        cnt.erase(x);
        if(s[x]=='R'&&s[x-1]=='L'&&poss[x-1])
        cnt.erase(x-1);
        if(s[x]=='L')
        s[x]='R';
        else
        s[x]='L';
        cout<<(cnt.empty()?"YES":"NO")<<'\n';
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