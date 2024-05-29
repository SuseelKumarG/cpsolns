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
ll lcm(ll a,ll b)
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

void solve()
{
    int n;
    cin>>n;
    ll ans=0;
    map<ll,vl> arr;
    map<ll,int> cnt;
    set<ll> nope;
    for(int i=0;i<n;i++)
    {
        ll x;
        cin>>x;
        cnt[x]++;
        arr[x].push_back(x);
        nope.insert(x);
    }
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        ll a=it->first;
        auto sit=it;
        sit++;
        for(;sit!=arr.end();sit++)
        {
            ll b=sit->first;
            if(!(b%a))
            {
                vl m,n;
                m=arr[a];
                n=arr[b];
                vl o(m.size()+n.size());
                set_union(m.begin(),m.end(),n.begin(),n.end(),o.begin());
                while(o[o.size()-1]==0)
                o.pop_back();
                arr[b]=o;
            }
        }
    }
    for(auto it=arr.begin();it!=arr.end();it++)
    {
        ll a=it->first;
        auto sit=it;
        for(;sit!=arr.end();sit++)
        {
            ll b=sit->first;
            if(nope.find(a)!=nope.end() || nope.find(b)!=nope.end())
            {ll x=lcm(a,b);
            vl m,n,p;
            m=arr[a];
            n=arr[b];
            p=arr[x];
            vl o(m.size()+n.size());
            set_union(m.begin(),m.end(),n.begin(),n.end(),o.begin());
            while(o[o.size()-1]==0)
            o.pop_back();
            vl q(o.size()+p.size());
            set_union(o.begin(),o.end(),p.begin(),p.end(),q.begin());
            while(q[q.size()-1]==0)
            q.pop_back();
            arr[x]=q;}
        }
    }
    for(auto it:arr)
    {
        // cout<<it.first<<'\n';
        // for(auto sit:it.second)
        // cout<<sit<<' ';
        // cout<<'\n';
        if(nope.find(it.first)!=nope.end())
        continue;
        ll temp=it.second.size();
        ans=max(ans,temp);
    }
    cout<<ans<<'\n';
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