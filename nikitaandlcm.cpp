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
    map<int,vi>arr;
    map<int,int>cnt;
    int ans=0;
    set<int>nope;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        cnt[x]++;
        if(nope.find(x)==nope.end())
        {
            nope.insert(x);
            arr[x].push_back(x);
        }
    }
    int lc=1;
        for(auto it=arr.begin();it!=arr.end();it++)
        {
            int a=it->first;
            auto sit=it;
            sit++;
            for(;sit!=arr.end();sit++)
            {
                int b=sit->first;
                if(!(b%a))
                {
                    vi m=arr[a];
                    vi n=arr[b];
                    vi o(m.size()+n.size());
                    set_union(m.begin(),
                   m.end(),
                   n.begin(),
                   n.end(),
                   o.begin());
                   arr[b]=o;
                //    arr[b].push_back(b);
                }
            }
        }
    // int ans=0;
    for(auto it=nope.begin();it!=nope.end();it++)
    {
        ll a=*it;
        auto sit=it;
        sit++;
        for(;sit!=nope.end();sit++)
        {
            ll b=*sit;
            ll g=gcd(a,b);
            ll x=a*b;
            x/=g;
            if(nope.find(x)==nope.end())
            {
                int temp=0;
                vi m,n;
                m=arr[a];
                n=arr[b];
                vi o(m.size()+n.size());
                set_union(m.begin(),
                   m.end(),
                   n.begin(),
                   n.end(),
                   o.begin());
                for(auto it:o)
                temp+=cnt[it];
                ans=max(ans,temp);
                nope.insert(x);
                // o.push_back(x);
                // arr[x]=o;
                // cnt[x]++;
            }

        }
    }
    // for(auto it:arr)
    // {
    //     cout<<it.first<<'\n';
    //     for(auto sit:it.second)
    //     cout<<sit<<' ';
    //     cout<<'\n';
    // }
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