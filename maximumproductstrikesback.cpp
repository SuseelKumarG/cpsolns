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
    int x=-1,y;
    vii poss;
    for(int i=0;i<n;i++)
    {
        if(a[i])
        {
            if(x==-1)
            x=i;
            y=i;
        }
        else
        {
            if(x!=-1)
            poss.push_back({x,y});
            x=-1;
        }
    }
    if(x!=-1)
    poss.push_back({x,y});
    x=-1;
    if(poss.empty())
    {
        cout<<n<<' '<<0<<'\n';
        return;
    }
    ll ans=0;
    pii op=poss[0];
    for(auto it:poss)
    {
        int l=it.first;
        int r=it.second;
        ll curr=0;
        for(int i=l;i<=r;i++)
        if(a[i]<0)
        curr++;
        // cout<<curr<<'\n';
        if(curr&1)
        {
            ll x=0,y=0;
            int i=l,j=r;
            bool neg=0;
            while(!neg)
            {
                if(abs(a[i])==2)
                x++;
                if(a[i]<0)
                neg=1;
                i++;
            }
            neg=0;
            while(!neg)
            {
                if(abs(a[j])==2)
                y++;
                if(a[j]<0)
                neg=1;
                j--;
            }
            if(x>y)
            r=j;
            else
            l=i;
        }
        curr=0;
        for(int i=l;i<=r;i++)
        {
            if(abs(a[i])==2)
            curr++;
        }
        if(ans<=curr)
        {
            ans=curr;
            op={l,r};
        }
    }
    // cout<<ans<<'\n';
    cout<<op.first<<' '<<n-op.second-1<<'\n';
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