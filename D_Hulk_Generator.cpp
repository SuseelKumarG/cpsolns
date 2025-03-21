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
    ll n,d;
    cin>>n>>d;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    if(d==1)
    {
        sort(a.begin(),a.end());
        int ind=-1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]+1==a[i+1])
            {
                ind=i;
                break;
            }
        }
        if(ind!=-1&&a[ind]+1==a[ind+1])
        cout<<a[ind]<<' '<<a[ind+1]<<'\n';
        else
        cout<<a[0]<<'\n';
        return;
    }
    set<ll>temp(a.begin(),a.end());
    set<ll>ans={*temp.begin()};
    if(d==2)
    {
        sort(a.begin(),a.end());
        for(ll op=d;op<=*(--temp.end());op*=d)
        {
            for(auto it:temp)
            {
                set<ll>curr;
                curr.insert(it);
                if(temp.count(it+op))
                {
                    curr.insert(it+op);
                    if(temp.count(it+2*op))
                    curr.insert(it+2*op);
                }
                if(curr.size()>ans.size())
                ans=curr;
                else if(curr.size()==ans.size())
                {
                    if(*curr.begin()<*ans.begin())
                    ans=curr;
                }
            }
        }
        for(auto it:ans)
        cout<<it<<' ';
        cout<<'\n';
        return;
    }
    for(ll op=d;op<=*(--temp.end());op*=d)
    {
        for(auto it:temp)
        {
            set<ll>curr;
            curr.insert(it);
            if(temp.count(it+op))
            curr.insert(it+op);
            if(curr.size()>ans.size())
            ans=curr;
            else if(curr.size()==ans.size())
            {
                if(*curr.begin()<*ans.begin())
                ans=curr;
            }
        }
    }
    for(auto it:ans)
    {
        cout<<it<<' ';
    }
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