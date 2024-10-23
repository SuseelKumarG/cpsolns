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
    ll n,x;
    cin>>n>>x;
    if(x>n)
    {
        cout<<-1<<'\n';
        return;
    }
    ll o=n;
    vi a;
    while(o)
    {
        if(o&1)
        a.push_back(1);
        else
        a.push_back(0);
        o>>=1;
    }
    a.push_back(0);
    reverse(a.begin(),a.end());
    o=x;
    vi b;
    while(o)
    {
        if(o&1)
        b.push_back(1);
        else
        b.push_back(0);
        o>>=1;
    }
    b.push_back(0);
    while(b.size()!=a.size())
    b.push_back(0);
    reverse(b.begin(),b.end());
    bool poss=1;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
        {
            if(a[i])
            {
                for(int j=i+1;j<a.size();j++)
                {
                    if(b[j]!=0)
                    poss=0;
                }
                if(a[i-1]==0)
                {
                    a[i-1]=1;
                    for(int j=i;j<a.size();j++)
                    a[j]=0;
                }
                else
                poss=0;
            }
            else
            poss=0;
        }
    }
     long long ans=0;
    reverse(a.begin(),a.end());
    for( long long i=0;i<a.size();i++)
    {
        if(a[i])
        ans+=(1LL<<i);
    }
    cout<<(poss?ans:-1)<<'\n';
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