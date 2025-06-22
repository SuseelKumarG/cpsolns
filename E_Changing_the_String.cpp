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
    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vector<set<int>> ord(4);
    map<pair<char,char>,int>val={{{'b','a'},0},{{'b','c'},1},{{'c','a'},2},{{'c','b'},3}};
    for(int i=0;i<q;i++)
    {
        char x,y;
        cin>>x>>y;
        if(!val.count({x,y}))
        continue;
        ord[val[{x,y}]].insert(i);
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a')
        continue;
        if(s[i]=='b')
        {
            if(ord[0].size())
            {
                s[i]='a';
                ord[0].erase(ord[0].begin());
                continue;
            }
            if(ord[1].size())
            {
                int x=*ord[1].begin();
                if(ord[2].lower_bound(x)!=ord[2].end())
                {
                    s[i]='a';
                    ord[1].erase(x);
                    ord[2].erase(ord[2].lower_bound(x));
                }
            }
            continue;
        }
        if(ord[2].size())
        {
            s[i]='a';
            ord[2].erase(ord[2].begin());
            continue;
        }
        if(ord[3].size())
        {
            int x=*ord[3].begin();
            if(ord[0].lower_bound(x)!=ord[0].end())
            {
                s[i]='a';
                ord[3].erase(x);
                ord[0].erase(ord[0].lower_bound(x));
            }
            else
            {
                s[i]='b';
                ord[3].erase(x);
            }
        }
    }
    cout<<s<<'\n';
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