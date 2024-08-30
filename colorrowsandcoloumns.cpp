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
    int n,k;
    cin>>n>>k;
    vii a(n);
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x>y)
        swap(x,y);
        a[i].first=x;
        a[i].second=y;
    }
    sort(a.begin(),a.end());
    // for(auto it:a)
    // cout<<it.first<<' '<<it.second<<'\n';
    ll ans=0;
    int i=0;
    while(k&&(i<n))
    {
        int x=a[i].first;
        int y=a[i].second;
        if(y+x<=k)
        {
            k-=x+y;
            ans+=x*y;
        }
        // else if(x+y-1==k)
        // {
        //     k-=x+y-1;
        //     ans+=x*y;
        // }
        else
        {
            int diff=y-x;
            if(diff<=k)
            {
                ans+=diff*x;
                k-=diff;
            }
            else
            {
                ans+=k*x;
                k=0;
            }
            // if(k)
            // {
            //     k--;
            //     ans+=x;
            //     x--;
            // }
            // while(k>1)
            // {
            //     ans+=2*x;
            //     k-=2;
            //     x--;
            //     // cout<<ans<<' '<<k<<'\n';
            // }
            // cout<<k<<' '<<x<<'\n';
            // if(k)
            // {
            //     if(!x)
            //     ans--;
            //     else
            //     ans+=x;
            //     k=0;
            // }
            // break;
            // cout<<ans<<'\n';
            y=x;
            while(k&&(x>1||y>1))
            {
                if(x>=y)
                {
                    x--;
                    ans+=y;
                    k--;
                }
                else
                {
                    y--;
                    ans+=x;
                    k--;
                }
                // cout<<ans<<' '<<k<<'\n';
            }
            // cout<<x<<' '<<y<<'\n';
            if(k)
            {
                if(x==1&&y==1)
                {
                    if(i==n-1)
                    ans++;
                }
                k=0;
            }
            // break;
        }
        i++;
    }
    // cout<<ans<<' '<<k<<'\n';
    cout<<(k>0?-1:ans)<<'\n';
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