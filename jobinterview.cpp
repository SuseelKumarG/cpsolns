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
    int p,t;
    cin>>p>>t;
    int n=p+t+1;
    vi pc(p+t+1),tc;
    tc=pc;
    int ind=n-1;
    vb pr(n,0);
    ll ans=0;
    for(int i=0;i<n;i++)
    cin>>pc[i];
    for(int i=0;i<n;i++)
    cin>>tc[i];
    for(int i=0;i<n-1;i++)
    {
        if(pc[i]>tc[i])
        {
            if(p)
            {
                p--;
                pr[i]=1;
                ans+=pc[i];
            }
            else
            {
                if(ind==n-1)
                ind=i;
                t--;
                ans+=tc[i];
            }
        }
        else
        {
            if(t)
            {
                t--;
                ans+=tc[i];
            }
            else
            {
                if(ind==n-1)
                ind=i;
                p--;
                pr[i]=1;
                ans+=pc[i];
            }
        }
    }
    // cout<<ind<<' '<<pr[ind]<<'\n';
    for(int i=0;i<n-1;i++)
    {
        ll x=ans;
        if(pr[i])
        x-=pc[i];
        else
        x-=tc[i];
        if(i<ind && ind<n-1)
        {
            if(pr[ind]==pr[i])
            {
                if(pr[i])
                x+=pc[n-1];
                else
                x+=tc[n-1];
            }
            else
            {
                if(pr[ind])
                {
                    x-=pc[ind];
                    x+=tc[ind];
                    x+=pc[n-1];
                }
                else
                {
                    x-=tc[ind];
                    x+=pc[ind];
                    x+=tc[n-1];
                }
            }
        }
        else
        {
            if(pr[i])
            x+=pc[n-1];
            else
            x+=tc[n-1];
        }
        cout<<x<<' ';
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