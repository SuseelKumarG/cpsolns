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
    vi a(n);
    for(auto &it:a)
    cin>>it;
    vi b,c;
    b.push_back(a[0]);
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(!b.empty()&&!c.empty())
        {
            if(a[i]<=b.back()&&a[i]<=c.back())
            {
                if(b.back()<c.back())
                b.push_back(a[i]);
                else
                c.push_back(a[i]);
            }
            else if(a[i]<=b.back())
            b.push_back(a[i]);
            else if(a[i]<=c.back())
            c.push_back(a[i]);
            else
            {
                if(b.back()<c.back())
                b.push_back(a[i]);
                else
                c.push_back(a[i]);
                ans++;
            }
        }
        else
        {
            if(a[i]<=b.back())
            b.push_back(a[i]);
            else
            c.push_back(a[i]);
        }
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