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
    vl a(n);
    for(auto &it:a)
    cin>>it;
    map<int,int>pos;
    for(int i=0;i<n;i++)
    pos[a[i]]=i;
    vl temp1(n),temp2(n);
    for(int i=1;i<n-1;i++)
    {
        if(i&1)
        temp1[i]+=a[i];
        temp1[i]+=temp1[i-1];
    }
    for(int i=n-2;i>0;i--)
    {
        if(!(i&1))
        temp2[i]+=a[i];
        temp2[i]+=temp2[i+1];
    }
    ll curr=0;
    ll ind=0;
    for(int i=3;i<n-1;i+=2)
    {
        if(temp1[i-1]+temp2[i+1]>curr)
        {
            ind=i;
            curr=temp1[i-1]+temp2[i+1];
        }
    }
    for(int i=n-4;i>0;i-=2)
    {
        if(temp1[i-1]+temp2[i+1]>curr)
        {
            ind=-i;
            curr=temp1[i-1]+temp2[i+1];
        }
    }
    if(temp1[n-2]>curr)
    {
        curr=temp1[n-2];
        ind=MAX;
    }
    if(temp2[1]>curr)
    {
        curr=temp2[1];
        ind=-MAX;
    }
    set<int>use;
    if(abs(ind)<n)
    {
        if(ind>0)
        {
            for(int i=1;i<ind;i+=2)
            use.insert(a[i]);
            for(int i=ind+1;i<n-1;i+=2)
            use.insert(a[i]);
        }
        else
        {
            ind*=-1;
            for(int i=1;i<ind;i+=2)
            use.insert(a[i]);
            for(int i=ind+2;i<n-1;i+=2)
            use.insert(a[i]);
        }
    }
    else
    {
        if(ind>0)
        {
            for(int i=1;i<n-1;i+=2)
            use.insert(a[i]);
        }
        else
        {
            for(int i=2;i<n-1;i+=2)
            use.insert(a[i]);
        }
    }
    deque<int>giv;
    for(int i=1;i<=n;i++)
    giv.push_back(i);
    map<int,int>ans;
    set<pair<int,pii>>ord;
    for(auto it:use)
    {
        ord.insert({a[pos[it]]-a[pos[it]+1]-1,{pos[it],pos[it]+1}});
        ord.insert({a[pos[it]]-a[pos[it]-1]-1,{pos[it],pos[it]-1}});
    }
    int o=1,p=n;
    for(auto it:ord)
    {
        int x,y;
        x=it.second.first;
        y=it.second.second;
        if(!ans.count(a[x]))
        {
            ans[a[x]]=p--;
        }
        if(!ans.count(a[y]))
        {
            ans[a[y]]=o++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[i]!=0)
        continue;
        ans[i]=o++;
    }
    for(auto it:a)
    cout<<ans[it]<<' ';
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