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

ll zer(vl &a)
{
    int n=a.size();
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i])
        {
            n=i+1;
            break;
        }
    }
    ll curr=accumulate(a.begin(),a.begin()+n,0LL);
    if(abs(curr)<n)
    ans+=n-abs(curr);
    if(curr<0)
    a[0]-=ans;
    else
    a[0]+=ans;
    for(auto it:a)
    cout<<it<<' ';
    cout<<'\n';
    curr=accumulate(a.begin(),a.begin()+n,0LL);
    for(int i=n-1;i>0;i--)
    {
        ans+=abs(a[i]);
        if(a[i]>0)
        {
            if(curr>0)
            {
                ans+=2*(a[i]-1);
            }
        }
        if(a[i]<0)
        {
            if(curr<0)
            {
                ans+=2*(abs(a[i])-1);
            }
        }
    }
    ans+=abs(a[0]);
    return ans;
}

ll one(vl &a)
{
    int n=a.size();
    ll ans=0;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]!=-1)
        {
            n=i+1;
            break;
        }
    }
    ll curr=accumulate(a.begin(),a.begin()+n,0LL);
    if(abs(curr)<n)
    ans+=n-abs(curr);
    if(curr<0)
    a[0]-=ans;
    else
    a[0]+=ans;
    curr=accumulate(a.begin(),a.begin()+n,0LL);
    for(int i=n-1;i>=0;i--)
    {
        ans+=abs(a[i]);
        if(a[i]<0)
        ans--;
        else
        ans++;
        if(a[i]>-1)
        {
            if(curr>0)
            ans+=a[i];
        }
        if(a[i]<-1)
        {
            if(curr<0)
            ans+=(abs(a[i])-2);
        }
    }
    ans+=abs(a[0]);
    for(auto it:a)
    cout<<it<<" ";
    cout<<'\n';
    return ans;
}

void solve()
{
    int n;
    cin>>n;
    vl a(n);
    for(auto &it:a)
    cin>>it;
    ll sum=accumulate(a.begin(),a.end(),0LL);
    if(!sum)
    {
        cout<<-1<<'\n';
        return;
    }
    ll ans=0;
    ans=min(zer(a),one(a));
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