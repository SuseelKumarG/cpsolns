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

void kad(set<int>&x,vi &a)
{
    int n=a.size();
    int curr=0,maxm=0;
    for(int i=0;i<n;i++)
    {
        curr+=a[i];
        maxm=max(maxm,curr);
        if(curr<0)
        curr=0;
    }
    int minm=0;
    curr=0;
    for(int i=0;i<n;i++)
    {
        curr+=a[i];
        minm=min(minm,curr);
        if(curr>0)
        curr=0;
    }
    for(int i=minm;i<=maxm;i++)
    {
        x.insert(i);
    }
}

void solve()
{
    int n;
    cin>>n;
    vi a(n);
    for(auto &it:a)
    cin>>it;
    int ind=-1;
    vi l,r;
    set<int>x;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=1&&a[i]!=-1)
        {
            ind=i;
            break;
        }
        l.push_back(a[i]);
    }
    if(ind!=-1)
    for(int i=ind+1;i<n;i++)
    {
        r.push_back(a[i]);
    }
    kad(x,l);
    kad(x,r);
    reverse(l.begin(),l.end());
    int maxm1=0;
    int minm1=0;
    int maxm2=0;
    int minm2=0;
    vi pre(n),t(n,0);
    int curr=0;
    for(int i=0;i<l.size();i++)
    {
        curr+=l[i];
        pre[i]=curr;
    }
    maxm1=max(0,*max_element(pre.begin(),pre.end()));
    minm1=min(*min_element(pre.begin(),pre.end()),0);
    curr=0;
    pre=t;
    for(int i=0;i<r.size();i++)
    {
        curr+=r[i];
        pre[i]=curr;
    }
    maxm2=max(0,*max_element(pre.begin(),pre.end()));
    minm2=min(*min_element(pre.begin(),pre.end()),0);
    if(ind!=-1)
    {
        int minm;
        int maxm;
        minm=minm1+minm2+a[ind];
        maxm=maxm1+maxm2+a[ind];
        for(int i=minm;i<=maxm;i++)
        x.insert(i);
    }
    x.insert(0);
    cout<<x.size()<<'\n';
    for(auto it:x)
    cout<<it<<' ';
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