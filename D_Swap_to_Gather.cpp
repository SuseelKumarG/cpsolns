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

int ans=0;

void merge(string &a,string &b,int l,int mid,int r,int o)
{
    int n1=mid-l+1;
    int n2=r-mid;
    for(int i=0;i<n1;i++)
    b[l+i]=a[l+i];
    for(int i=0;i<n1;i++)
    b[mid+1+i]=a[mid+i+1];
    int i=l,j=mid+1,k=l;
    if(o)
    {
        while(i<n1+l && j<n2+mid+1)
        {
            if(b[i]<=b[j])
            a[k++]=b[i++];
            else
            {
                ans+=j-i;
                a[k++]=b[j++];
            }
        }
        while(i<n1+l)
        {
            a[k++]=b[i++];
        }
        while(j<n2+mid+1)
        {
            a[k++]=b[j++];
        }
    }
    else
    {
        while(i<n1+l && j<n2+mid+1)
        {
            if(b[i]>=b[j])
            a[k++]=b[i++];
            else
            {
                ans+=j-i;
                a[k++]=b[j++];
            }
        }
        while(i<n1+l)
        {
            a[k++]=b[i++];
        }
        while(j<n2+mid+1)
        {
            a[k++]=b[j++];
        }
    }
}
void mergesort(string &a,string &b,int l,int r,int o)
{
    if(l>=r)
    return;
    int mid=(r-l)/2+l;
    mergesort(a,b,l,mid,o);
    mergesort(a,b,mid+1,r,o);
    merge(a,b,l,mid,r,o);
}

void solve()
{
    ll n;
    cin>>n;
    string a;
    cin>>a;
    deque<char>temp;
    for(auto it:a)
    temp.push_back(it);
    while(temp.size()&&(temp.front()=='0'))
    temp.pop_front();
    while(temp.size()&&(temp.back()=='0'))
    temp.pop_back();
    a.clear();
    for(auto it:temp)
    a.push_back(it);
    n=a.size();
    vl pre(n),suff(n);
    ll cnt=0;
    ll curr=0;
    ll prev=0;
    for(ll i=0;i<n;i++)
    {
        if(a[i]=='1')
        {
            cnt++;
            curr=0;
        }
        else
        {
            curr++;
            prev+=cnt;
        }
        pre[i]=prev;
    }
    cnt=0;
    curr=0;
    prev=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]=='1')
        {
            cnt++;
            curr=0;
        }
        else
        {
            curr++;
            prev+=cnt;
        }
        suff[i]=prev;
    }
    ll ans=min(suff[0],pre[n-1]);
    for(int i=1;i<n-1;i++)
    {
        ans=min(ans,pre[i-1]+suff[i]);
        ans=min(ans,pre[i]+suff[i+1]);
    }
    cout<<ans<<'\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}